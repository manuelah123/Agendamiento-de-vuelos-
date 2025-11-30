# Sistema de Gestión de Vuelos en C

Este proyecto es un **sistema de gestión de vuelos** desarrollado en **C**. Permite agendar, eliminar, buscar y listar vuelos utilizando **listas enlazadas** y manejo de memoria dinámica con punteros.  

## Características

- Agendar nuevos vuelos con número, destino, hora de salida y duración.  
- Eliminar vuelos existentes por número de vuelo.  
- Buscar vuelos específicos y mostrar su información completa.  
- Listar todos los vuelos agendados.  
- Validación de entradas para hora y duración de vuelo.  
- Manejo eficiente de memoria, liberando recursos al finalizar el programa.  

## Estructura de Datos

- **Struct Time**: Representa la hora de salida de un vuelo.  
- **Struct Vuelo**: Contiene información de cada vuelo y un puntero al siguiente vuelo para la lista enlazada.  

## Uso

**1. Clonar el repositorio:**

```bash
git clone https://github.com/tu-usuario/nombre-repo.git
```
**2. Compilar el programa:**
```bash
gcc -o gestion_vuelos main.c
```
**3. Ejecutar el programa:**
```bash
./gestion_vuelos
```
**4. Seguir el menú para agendar, eliminar, buscar o listar vuelos.**
- El sistema incluye 15 vuelos de ejemplo con distintos destinos y horarios, listos para interactuar.

## Tecnologías Usadas
- Lenguaje: C
- Compilador: GCC (compatible con Linux, Windows y macOS)
- Paradigma: Estructurado y uso de punteros para manejo dinámico de memoria.

## Autor
**Manuela Henao Bedoya**

## Licencia
Este proyecto está bajo la licencia MIT.
