# GDB

## **Análisis de ejecución y depuración en GDB**

### **Descripción del programa**

El programa desarrollado en C++ tiene como objetivo ejecutar una operación aritmética simple dentro de una función llamada `funcion1`. Sin embargo, contiene una instrucción que realiza una división entre un número entero y cero, lo cual genera un error en tiempo de ejecución.

Código relevante:

```cpp
int a = 5;
int b = 0;
int c = a / b; // Error: División por cero
```

### **Compilación y preparación para depuración**

Para permitir la depuración con GDB, el programa fue compilado utilizando la opción `-g`, que incluye información de depuración en el ejecutable:

```bash
g++ -g -o programa programa.cpp
```

### **Ejecución de GDB**

A continuación, se utilizó GDB para analizar el comportamiento del programa paso a paso. Se siguió la siguiente secuencia de comandos:

```bash
gdb programa
(gdb) run
(gdb) break funcion1
(gdb) continue
(gdb) next
(gdb) print a
(gdb) step
(gdb) backtrace
(gdb) continue
```

### **Explicación de los comandos utilizados**

| Comando GDB      | Función                                                                                                    |
| ---------------- | ---------------------------------------------------------------------------------------------------------- |
| `run`            | Inicia la ejecución del programa dentro del entorno de depuración.                                         |
| `break funcion1` | Establece un punto de interrupción en la función `funcion1`, deteniendo la ejecución al entrar en ella.    |
| `continue`       | Reanuda la ejecución del programa hasta el próximo punto de interrupción o hasta que ocurra una excepción. |
| `next`           | Ejecuta la siguiente instrucción sin entrar en llamadas a funciones (si el programa sigue activo).         |
| `print a`        | Muestra el valor actual de la variable `a`.                                                                |
| `step`           | Avanza a la siguiente instrucción y entra en funciones llamadas (si las hay).                              |
| `backtrace`      | Muestra la pila de llamadas activa en el momento actual (call stack).                                      |
| `continue`       | Intenta reanudar la ejecución del programa.                                                                |

### **Resultado de la depuración**

![image](https://github.com/user-attachments/assets/27719a41-f3f6-4735-aaf8-31d4544afa50)


Durante la ejecución con GDB, el programa generó una señal `SIGFPE` (Floating Point Exception) al intentar realizar la división entre 5 y 0. Esta excepción provocó la terminación inmediata del programa. Posteriormente, los comandos `next`, `step`, `backtrace` y `continue` no produjeron resultados útiles, ya que el programa ya no se encontraba en ejecución.

Se pudo verificar, mediante el comando `print a`, que la variable `a` tenía el valor esperado de 5 antes del fallo.

# Valgrind

## **Análisis de errores de memoria con Valgrind**

### **Descripción del entorno y comandos utilizados**

El programa fue compilado con información de depuración utilizando:

```bash
g++ -g -o programa programa_valgrind.cpp
```

Luego, se ejecutó el programa utilizando **Valgrind** con las siguientes opciones:

```bash
valgrind --leak-check=yes ./programa
```

Estas opciones permiten a Valgrind verificar fugas de memoria (`--leak-check=yes`) y mostrar un resumen al finalizar la ejecución.

---

### **Salida y diagnóstico de Valgrind**

![image](https://github.com/user-attachments/assets/83bc8bf3-0b54-4b63-9a9d-9061a60d4b1d)

Valgrind generó varias advertencias relevantes, entre ellas:

#### 1. **Uso de valores no inicializados**

```
==89867== Conditional jump or move depends on uninitialised value(s)
```

Valgrind detectó que se utilizó una variable que no había sido inicializada. En este caso, se refiere al uso de `p2[0]`, cuyo valor fue accedido sin haber sido asignado previamente.

```cpp
int* p2 = new int[10];
std::cout << "Valor de p2[0] (no inicializado): " << p2[0] << std::endl;
```

Esto representa un comportamiento indefinido en tiempo de ejecución.

---

#### 2. **"Stack smashing detected"**

```
*** stack smashing detected ***: terminated
```

Este mensaje indica que hubo una escritura fuera de los límites del arreglo, lo cual corrompió la pila de ejecución. En el código, este error se debe al acceso fuera de rango:

```cpp
int array[10];
array[10] = 5; // Error: índice fuera de rango (índices válidos: 0-9)
```

Esto causa una falla grave en la ejecución, detectada por el sistema como "stack smashing".

---

#### 3. **Resumen del heap**

```
==89867== HEAP SUMMARY:
==89867==    in use at exit: 73,768 bytes in 3 blocks
==89867==  total heap usage: 4 allocs, 1 frees, 73,808 bytes allocated
```

El resumen indica que hubo **una fuga de memoria**, ya que se realizaron 4 asignaciones dinámicas (`allocs`), pero solo una fue liberada (`frees`). Esto significa que parte de la memoria reservada con `new` no fue liberada con `delete[]`.


## **AddressSanitizer**

### **Descripción del entorno y comandos utilizados**

Para detectar errores de acceso a memoria en tiempo de ejecución, se utilizó la herramienta **AddressSanitizer**, integrada en el compilador `g++`. La compilación del programa se realizó con la opción `-fsanitize=address`:

```bash
g++ -fsanitize=address -g -o programa programa_sanitize.cpp
./programa
```

---

### **Error detectado**

![image](https://github.com/user-attachments/assets/a5df6f9c-a3b4-4862-ad57-db1215dabd91)


Durante la ejecución, AddressSanitizer generó el siguiente mensaje de error:

```
==91175==ERROR: AddressSanitizer: heap-buffer-overflow ...
WRITE of size 4 at 0x604000000038 thread T0
```

Este mensaje indica que se produjo un **desbordamiento de búfer en el heap** (*heap-buffer-overflow*). Específicamente, el programa intentó escribir en una dirección justo **fuera del límite asignado dinámicamente**:

```cpp
int* p = new int[10];
p[10] = 5; // ERROR: acceso fuera de los límites válidos
```

El índice válido para un arreglo de tamaño 10 va de `0` a `9`. Acceder a `p[10]` está fuera de este rango y constituye un comportamiento indefinido.

---

### **Análisis detallado**

AddressSanitizer indica claramente:

* La ubicación del error: `programa_sanitize.cpp:5`, dentro de la función `funcion1()`.
* La región de memoria que fue excedida: `0x604000000010` hasta `0x604000000038` (40 bytes), siendo `0x604000000038` el byte fuera del límite.
* El error fue una escritura (`WRITE of size 4`) en una posición no válida de memoria.

Además, se proporciona un resumen del estado de la memoria y las zonas de protección (`redzones`), lo cual permite ver con precisión dónde ocurrió la violación.

---

### **Conclusión**

La herramienta **AddressSanitizer** fue eficaz para detectar un error de escritura fuera de los límites del arreglo dinámico. Este tipo de error, aunque no siempre produce un fallo inmediato, puede provocar corrupción de memoria, errores lógicos o vulnerabilidades de seguridad.

Su uso es altamente recomendable en fases de desarrollo para garantizar la corrección y seguridad del manejo de memoria en programas C++.


Claro. Aquí tienes una **explicación elaborada** del comando que estás ejecutando, por qué **no funcionó en tu entorno local**, y qué **debería haber mostrado** si se hubiera ejecutado correctamente en un entorno compatible.

---

# Sanitize thread

## 🧪 Comando ejecutado

```bash
g++ -fsanitize=thread -g -pthread -o programa programa_sanitize_thread.cpp
./programa
```

![image](https://github.com/user-attachments/assets/b76cd4cb-222b-42d9-bcb8-c5e2b12a81e1)

---

## 🛠️ ¿Qué hace este comando?

1. `g++`: El compilador de C++.
2. `-fsanitize=thread`: Activa **ThreadSanitizer**, una herramienta para detectar condiciones de carrera (data races) entre hilos.
3. `-g`: Agrega información de depuración (útil para ver la traza del error).
4. `-pthread`: Habilita el uso de hilos (`std::thread`).
5. `-o programa`: Nombra el ejecutable como `programa`.
6. `programa_sanitize_thread.cpp`: Código fuente, que contiene dos hilos que modifican una misma variable global (`counter`), generando una condición de carrera intencional.

---

## ❌ ¿Por qué **no funcionó** al ejecutarlo localmente?

Al correr el ejecutable con:

```bash
./programa
```

Se obtuvo este error:

```
FATAL: ThreadSanitizer: unexpected memory mapping 0x653f6a47b000-0x653f6a47c000
```

### 🧨 ¿Qué significa este error?

Este mensaje viene directamente del runtime de **ThreadSanitizer** e indica que:

> **El entorno donde estás ejecutando el programa mapea memoria de forma incompatible con ThreadSanitizer.**

En otras palabras: **el entorno local (tu sistema operativo, kernel o configuración de memoria)** no es compatible con cómo `ThreadSanitizer` espera controlar el acceso a la memoria.

### ⚠️ Esto puede deberse a:

* Un **kernel Linux demasiado nuevo** con cambios en cómo gestiona las regiones de memoria.
* Cambios en el comportamiento de `mmap()` o protecciones de seguridad activadas (como `mmap_rnd_bits`).
* Uso de librerías o entornos que usan memoria compartida incompatible (como drivers, controladores o ciertas versiones de glibc).
* Aunque estás usando `g++ 14.2.0`, que es muy moderno, esto también puede causar **problemas de compatibilidad con `libtsan`** en sistemas donde no se ha actualizado todo el stack.

---

Perfecto, a continuación te presento una explicación **enfocada únicamente en la salida esperada** al ejecutar correctamente el programa en un entorno compatible con `ThreadSanitizer`:

---

## ✅ ¿Qué **salida específica** deberíamos haber obtenido?

Si el programa se hubiera ejecutado en un entorno compatible (como Ubuntu 22.04 con GCC 11 o 12 y configuración de memoria estándar), la herramienta `ThreadSanitizer` habría detectado una condición de carrera y mostrado una salida **muy característica y detallada** similar a esta:

```
==================
WARNING: ThreadSanitizer: data race (pid=12345)
  Write of size 4 at 0x7f9e14c0b000 by thread T1:
    #0 increment programa_sanitize_thread.cpp:6
    #1 std::thread::_State_impl<...>::_M_run() ...
    #2 ...

  Previous write of size 4 at 0x7f9e14c0b000 by thread T2:
    #0 increment programa_sanitize_thread.cpp:6
    #1 std::thread::_State_impl<...>::_M_run() ...
    #2 ...

  Location is global 'counter' at programa_sanitize_thread.cpp:3

SUMMARY: ThreadSanitizer: data race in increment
==================
Counter: 173842
```

---

### 📌 Componentes clave de esta salida:

1. **Encabezado de advertencia:**

   ```
   WARNING: ThreadSanitizer: data race
   ```

   Indica que se ha detectado una condición de carrera.

2. **Detalles de los accesos conflictivos:**

   * `Write of size 4` → Dos escrituras concurrentes sobre la misma dirección de memoria.
   * Información de las llamadas (stack trace) de ambos hilos (T1 y T2).
   * Línea exacta en tu código fuente donde ocurre el acceso conflictivo:

     ```
     programa_sanitize_thread.cpp:6
     ```

3. **Ubicación del conflicto:**

   ```
   Location is global 'counter' at programa_sanitize_thread.cpp:3
   ```

4. **Resumen claro al final:**

   ```
   SUMMARY: ThreadSanitizer: data race in increment
   ```

5. **Valor final del contador (opcional):**
   El programa muestra algo como:

   ```
   Counter: 173842
   ```

   Este valor puede variar entre ejecuciones, reflejando el comportamiento no determinista de la condición de carrera.

---

### ✅ Recomendación final

Para ver el comportamiento esperado, ejecuta el mismo código en:

* Una máquina virtual Ubuntu 22.04.
* Un contenedor Docker basado en Ubuntu 22.04 (con `g++`, `libtsan`, etc.).
* Cualquier sistema con **kernel y glibc estables y probados con GCC 11–12**.

Perfecto. Vamos a desglosar y explicar detalladamente el comando y la salida que se muestra en la imagen, como lo hemos hecho antes.

---

# Hellgrind

```bash
g++ -g -o programa programa_valgrind_thread.cpp
valgrind --tool=helgrind ./programa
```

![image](https://github.com/user-attachments/assets/5deea9f1-da72-44df-a41e-9864787ae0a7)


## 🛠️ ¿Qué hace este comando?

1. **`g++ -g -o programa programa_valgrind_thread.cpp`**
   Compila el archivo `programa_valgrind_thread.cpp` con información de depuración (`-g`) y genera un ejecutable llamado `programa`.

2. **`valgrind --tool=helgrind ./programa`**
   Ejecuta el programa bajo **Valgrind**, usando el **tool Helgrind**, que es una herramienta específica para detectar:

   * Condiciones de carrera en programas multihilo.
   * Uso incorrecto de sincronización.
   * Accesos simultáneos a memoria sin protección.

---

## 🧾 Explicación de la salida generada

### 🧵 Creación de hilos

La salida muestra primero la creación de dos hilos:

```
==98062== Thread #3 was created
...
==98062== Thread #2 was created
```

Esto confirma que el programa está utilizando múltiples hilos (como esperábamos).

---

### ⚠️ Detección de condición de carrera

Luego aparece la advertencia más importante:

```
==98062== Possible data race during read of size 4 at 0x10C154 by thread #3
==98062== Locks held: none
```

Esto indica que:

* Se detectó una **posible condición de carrera**: dos o más hilos están accediendo a la misma dirección de memoria (`0x10C154`), y al menos una operación es de escritura.
* En este caso, **ningún candado o sincronización** (`Locks held: none`) estaba presente para proteger esa operación.

---

### 🔍 Trazas de las llamadas (stack traces)

Se muestran las rutas de ejecución (stack trace) para cada hilo involucrado en la carrera:

```text
==98062==    at 0x109C1DA: increment (programa_valgrind_thread.cpp:8)
...
==98062==    by 0x10935A2: main (programa_valgrind_thread.cpp:13)
```

Estas líneas indican:

* La carrera ocurrió en la función `increment()` en la línea 8.
* Esa función fue llamada desde el `main()` (línea 13), al lanzar los hilos.

---

### 🎯 Conclusión sobre esta salida

Si el entorno y el código están correctamente configurados, **Helgrind identifica y reporta con detalle** los siguientes elementos:

* Qué hilo accedió la memoria en conflicto.
* Dónde en el código ocurrió el acceso (líneas específicas del `.cpp`).
* Qué hilos estuvieron involucrados en la posible condición de carrera.
* El hecho de que **no había sincronización activa** (mutex, locks, etc.).

## 📌 Resumen

| Elemento                   | Significado                                                                 |
| -------------------------- | --------------------------------------------------------------------------- |
| `valgrind --tool=helgrind` | Ejecuta análisis de hilos y sincronización.                                 |
| "Possible data race"       | Detecta acceso simultáneo a memoria compartida sin sincronización.          |
| Stack trace                | Muestra en qué parte exacta del código ocurre el conflicto.                 |
| "Locks held: none"         | No había ninguna protección (como mutex) al momento del acceso conflictivo. |





