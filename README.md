# Proyecto KMP - Algoritmo de Búsqueda de Patrones

Este proyecto implementa el **Algoritmo de Knuth-Morris-Pratt (KMP)**, un eficiente algoritmo de búsqueda de patrones en cadenas de texto.

## Descripción

El algoritmo KMP es un método de búsqueda de patrones que evita comparaciones innecesarias utilizando información sobre las coincidencias parciales del patrón. Este proyecto incluye dos tareas:

### FirstTask.cpp - Función de Fallos (Failure Function)

Calcula el **arreglo de fallos** para un patrón dado. Este arreglo es fundamental en el algoritmo KMP y contiene información sobre los prefijos que coinciden con sufijos en cada posición del patrón.

**Función principal:**
- `FailureFunction(std::string keyword)` - Calcula e imprime el arreglo de fallos para la palabra clave ingresada

**Ejemplo de uso:**
```cpp
FailureFunction("ababaa");  // Imprime: 0 0 1 2 3 0
```

### SecondTask.cpp - Algoritmo KMP Completo

Implementación completa del algoritmo KMP que busca un patrón dentro de una cadena de texto.

**Funciones principales:**
- `FailureFunction(std::string keyword)` - Calcula el arreglo de fallos
- `KMP(std::string chain, std::string keyword)` - Busca el patrón en la cadena y retorna "yes" o "no"

**Ejemplo de uso:**
```cpp
KMP("abababaab", "ababaa")    // Retorna "yes"
KMP("abababbaa", "ababaa")    // Retorna "no"
```

## Compilación y Ejecución

### FirstTask
```bash
cd /Users/jerovelez/Trabajo-LF
g++ -o FirstTask FirstTask.cpp
./FirstTask
```

### SecondTask
```bash
cd /Users/jerovelez/Trabajo-LF
g++ -o SecondTask SecondTask.cpp
./SecondTask
```

## Complejidad

- **Tiempo:** O(n + m), donde n es la longitud del patrón y m es la longitud de la cadena
- **Espacio:** O(n) para almacenar el arreglo de fallos

## Ventajas del Algoritmo KMP

- No requiere búsquedas exhaustivas
- Muy eficiente para textos grandes
- Ideal para búsquedas en flujos de datos
- Mejor desempeño que búsqueda lineal ingenua en muchos casos
