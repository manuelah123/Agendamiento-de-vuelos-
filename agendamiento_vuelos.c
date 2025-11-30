#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar el tiempo
struct Time {
    int hora;
    int minuto;
};

// Estructura para representar un vuelo
typedef struct Vuelo {
    char numeroVuelo[20];        // Número de vuelo (cadena de caracteres)
    char destino[50];            // Destino (cadena de caracteres)
    struct Time horaSalida;       // Hora de salida (estructura Time)
    int duracion;                 // Duración del vuelo en minutos (entero)
    struct Vuelo* siguiente;      // Puntero al siguiente vuelo en la lista
} Vuelo;

// Puntero global a la cabeza de la lista enlazada
Vuelo* cabeza = NULL;

// Función para crear un nuevo vuelo usando punteros
Vuelo* crearVuelo(const char* numero, const char* destino, struct Time* hora, int duracion) {
    // Asignar memoria dinámicamente usando punteros
    Vuelo* nuevoVuelo = (Vuelo*)malloc(sizeof(Vuelo));
    
    if (nuevoVuelo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    
    // Copiar los datos usando punteros
    strcpy(nuevoVuelo->numeroVuelo, numero);
    strcpy(nuevoVuelo->destino, destino);
    nuevoVuelo->horaSalida.hora = hora->hora;
    nuevoVuelo->horaSalida.minuto = hora->minuto;
    nuevoVuelo->duracion = duracion;
    nuevoVuelo->siguiente = NULL;
    
    return nuevoVuelo;
}

// Función auxiliar para agregar un vuelo sin mostrar mensajes (usando punteros)
void agregarVueloSilencioso(Vuelo** cabezaLista, const char* numero, const char* destino, struct Time* hora, int duracion) {
    Vuelo* nuevoVuelo = crearVuelo(numero, destino, hora, duracion);
    
    if (nuevoVuelo == NULL) {
        return;
    }
    
    // Si la lista está vacía, el nuevo vuelo es la cabeza
    if (*cabezaLista == NULL) {
        *cabezaLista = nuevoVuelo;
    } else {
        // Buscar el último nodo usando punteros
        Vuelo* actual = *cabezaLista;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoVuelo;
    }
}

// Función para agregar un vuelo a la lista enlazada (usando punteros)
void agregarVuelo(Vuelo** cabezaLista, const char* numero, const char* destino, struct Time* hora, int duracion) {
    agregarVueloSilencioso(cabezaLista, numero, destino, hora, duracion);
    printf("Vuelo agendado correctamente.\n");
}

// Función para eliminar un vuelo de la lista por número de vuelo (usando punteros)
void eliminarVuelo(Vuelo** cabezaLista, const char* numero) {
    if (*cabezaLista == NULL) {
        printf("No hay vuelos en la lista.\n");
        return;
    }
    
    Vuelo* actual = *cabezaLista;
    Vuelo* anterior = NULL;
    
    // Buscar el vuelo usando punteros
    while (actual != NULL) {
        if (strcmp(actual->numeroVuelo, numero) == 0) {
            // Encontrado, eliminar de la lista
            if (anterior == NULL) {
                // Es el primer nodo
                *cabezaLista = actual->siguiente;
            } else {
                // No es el primer nodo
                anterior->siguiente = actual->siguiente;
            }
            
            // Liberar memoria usando punteros
            free(actual);
            printf("Vuelo con numero %s eliminado correctamente.\n", numero);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    
    printf("No se encontro un vuelo con el numero %s.\n", numero);
}

// Función para buscar un vuelo por número de vuelo y mostrar su información (usando punteros)
void buscarVuelo(Vuelo* cabezaLista, const char* numero) {
    Vuelo* actual = cabezaLista;
    
    // Buscar el vuelo usando punteros
    while (actual != NULL) {
        if (strcmp(actual->numeroVuelo, numero) == 0) {
            // Vuelo encontrado, mostrar información
            printf("\n=== Vuelo Encontrado ===\n");
            printf("Numero de vuelo: %s\n", actual->numeroVuelo);
            printf("Destino: %s\n", actual->destino);
            printf("Hora de salida: %02d:%02d\n", actual->horaSalida.hora, actual->horaSalida.minuto);
            printf("Duracion: %d minutos\n", actual->duracion);
            printf("=======================\n");
            return;
        }
        actual = actual->siguiente;
    }
    
    printf("No se encontro un vuelo con el numero %s.\n", numero);
}

// Función para listar todos los vuelos mostrando su información (usando punteros)
void listarVuelos(Vuelo* cabezaLista) {
    if (cabezaLista == NULL) {
        printf("No hay vuelos agendados.\n");
        return;
    }
    
    Vuelo* actual = cabezaLista;
    int contador = 1;
    
    printf("\n=== Lista de Vuelos ===\n");
    while (actual != NULL) {
        printf("\n--- Vuelo %d ---\n", contador);
        printf("Numero de vuelo: %s\n", actual->numeroVuelo);
        printf("Destino: %s\n", actual->destino);
        printf("Hora de salida: %02d:%02d\n", actual->horaSalida.hora, actual->horaSalida.minuto);
        printf("Duracion: %d minutos\n", actual->duracion);
        
        actual = actual->siguiente;
        contador++;
    }
    printf("\n=======================\n");
}

// Función para liberar toda la memoria de la lista (usando punteros)
void liberarLista(Vuelo** cabezaLista) {
    Vuelo* actual = *cabezaLista;
    Vuelo* siguiente;
    
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    *cabezaLista = NULL;
}

// Función para mostrar el menú y obtener la opción
int mostrarMenu() {
    int opcion;
    printf("\n========================================\n");
    printf("    SISTEMA DE GESTION DE VUELOS\n");
    printf("========================================\n");
    printf("1. Agendar vuelo\n");
    printf("2. Eliminar vuelo\n");
    printf("3. Buscar vuelo\n");
    printf("4. Listar vuelos\n");
    printf("5. Salir\n");
    printf("========================================\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función principal
int main() {
    int opcion;
    char numero[20];
    char destino[50];
    struct Time hora;
    int duracion;
    
    printf("Bienvenido al Sistema de Gestion de Vuelos\n");
    
    // Agregar 15 vuelos de ejemplo usando punteros (sin mostrar mensajes)
    struct Time hora1 = {15, 30};
    agregarVueloSilencioso(&cabeza, "1234", "Lima", &hora1, 180);
    
    struct Time hora2 = {8, 0};
    agregarVueloSilencioso(&cabeza, "9876", "Bogota", &hora2, 120);
    
    struct Time hora3 = {10, 40};
    agregarVueloSilencioso(&cabeza, "2345", "Canada", &hora3, 300);
    
    struct Time hora4 = {23, 35};
    agregarVueloSilencioso(&cabeza, "2187", "Tokio", &hora4, 430);
    
    struct Time hora5 = {16, 10};
    agregarVueloSilencioso(&cabeza, "9203", "Medellin", &hora5, 50);
    
    struct Time hora6 = {6, 0};
    agregarVueloSilencioso(&cabeza, "8603", "San Andres", &hora6, 80);
    
    struct Time hora7 = {18, 45};
    agregarVueloSilencioso(&cabeza, "0194", "Peru", &hora7, 150);
    
    struct Time hora8 = {21, 25};
    agregarVueloSilencioso(&cabeza, "1326", "Cali", &hora8, 230);
    
    struct Time hora9 = {12, 15};
    agregarVueloSilencioso(&cabeza, "4567", "Madrid", &hora9, 480);
    
    struct Time hora10 = {14, 30};
    agregarVueloSilencioso(&cabeza, "5678", "Paris", &hora10, 520);
    
    struct Time hora11 = {7, 20};
    agregarVueloSilencioso(&cabeza, "6789", "New York", &hora11, 360);
    
    struct Time hora12 = {19, 50};
    agregarVueloSilencioso(&cabeza, "7890", "Buenos Aires", &hora12, 240);
    
    struct Time hora13 = {5, 45};
    agregarVueloSilencioso(&cabeza, "3456", "Mexico DF", &hora13, 200);
    
    struct Time hora14 = {11, 0};
    agregarVueloSilencioso(&cabeza, "2341", "Santiago", &hora14, 190);
    
    struct Time hora15 = {22, 10};
    agregarVueloSilencioso(&cabeza, "8765", "Rio de Janeiro", &hora15, 280);
    
    do {
        opcion = mostrarMenu();
        
        switch (opcion) {
            case 1: {
                // Agendar vuelo
                printf("\n--- Agendar Nuevo Vuelo ---\n");
                printf("Ingrese el numero de vuelo: ");
                scanf("%s", numero);
                
                printf("Ingrese el destino: ");
                scanf(" %49[^\n]", destino);
                
                printf("Ingrese la hora de salida (formato 24h, hh mm): ");
                scanf("%d %d", &hora.hora, &hora.minuto);
                
                // Validar hora
                if (hora.hora < 0 || hora.hora > 23 || hora.minuto < 0 || hora.minuto > 59) {
                    printf("Error: Hora invalida. Use formato 24h (0-23 para horas, 0-59 para minutos).\n");
                    break;
                }
                
                printf("Ingrese la duracion del vuelo (en minutos): ");
                scanf("%d", &duracion);
                
                if (duracion <= 0) {
                    printf("Error: La duracion debe ser un numero positivo.\n");
                    break;
                }
                
                agregarVuelo(&cabeza, numero, destino, &hora, duracion);
                break;
            }
            
            case 2: {
                // Eliminar vuelo
                printf("\n--- Eliminar Vuelo ---\n");
                printf("Ingrese el numero de vuelo que desea eliminar: ");
                scanf("%s", numero);
                eliminarVuelo(&cabeza, numero);
                break;
            }
            
            case 3: {
                // Buscar vuelo
                printf("\n--- Buscar Vuelo ---\n");
                printf("Ingrese el numero de vuelo que desea buscar: ");
                scanf("%s", numero);
                buscarVuelo(cabeza, numero);
                break;
            }
            
            case 4: {
                // Listar vuelos
                listarVuelos(cabeza);
                break;
            }
            
            case 5: {
                printf("\nSaliendo del programa...\n");
                liberarLista(&cabeza);
                printf("Memoria liberada. Hasta luego!\n");
                break;
            }
            
            default: {
                printf("\nOpcion no valida. Por favor, seleccione una opcion del 1 al 5.\n");
                break;
            }
        }
        
        if (opcion != 5) {
            printf("\nPresione Enter para continuar...");
            getchar();
            getchar();
        }
        
    } while (opcion != 5);
    
    return 0;
}

