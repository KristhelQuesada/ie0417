# Laboratorio 06: Programacion paralela/concurrente

### Estudiantes:
- Gabriel Gamboa Vargas, B73098
- Kristhel Quesada López, C06153


### Tabla de contenidos

1. [Compilación y Ejecución](#1-compilación-y-ejecución)
2. [Resumen Teórico](#2-resumen-teórico)



----
<br>

## 1. Compilación y Ejecución


### Compila y ejecuta todos los programas
Esto ejecutará cada uno de los programas, mostrando un mensaje `[OK]` si la ejecución fue exitosa, o `[Error]` en caso contrario. El archivo `6_deadlock` se ejecuta al final porque puede bloquearse debido a una condición de interbloqueo intencional.

```bash
make run-all
```

> [!TIP]
> Profesor/asistente, se realizó esta funcionalidad en el Makefile para facilitar la revisión de este laboratorio con un solo comando, por ende se recomienda su uso.

### Compilar todos los programas
Esto compilará todos los archivos `.cpp` dentro del directorio `src/` y generará ejecutables con el mismo nombre en el directorio raíz del proyecto.

```bash
make
```

### Ejecutar un programa individual
Por ejemplo, para ejecutar el archivo `3_racecond_semaphore.cpp`:

```bash
make run-<nombre>
make run-3_racecond_semaphore
```

### Compilar y ejecutar un programa individual
Por ejemplo, para compilar y ejecutar el archivo `5_sync_barriers`:
```bash
make build-run-<nombre>
make build-run-5_sync_barriers
```

### Limpiar todos los ejecutables
Esto eliminará todos los ejecutables generados en la raíz del proyecto.
```bash
make clean
```

<br> 

## 2. Resumen Teórico
| Archivo                     | Tema Principal                            | Descripción teórica                                                                                                                                                                                                                                                                         |
| --------------------------- | ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `1_racecond_nosync.cpp`     | Condición de carrera (**Race condition**) | Ocurre cuando dos o más hilos o procesos intentan acceder y modificar al mismo tiempo un **recurso compartido** (como una variable), y la falta de **sincronización** causa resultados erráticos o inesperados. Es un problema común en programación concurrente.                           |
| `2_racecond_mutex.cpp`      | **Mutex** para sincronización             | Un **mutex** (mutual exclusion) es un mecanismo que permite que solo un hilo acceda a una **sección crítica** o recurso compartido a la vez. Esto evita que los datos se corrompan por accesos simultáneos. Básicamente, un mutex es un “candado” para proteger recursos.                   |
| `3_racecond_semaphore.cpp`  | **Semáforos**                             | Un **semáforo** es un contador protegido que controla el acceso a un recurso limitado (por ejemplo, un buffer con espacio fijo). Permite que un número determinado de hilos entren simultáneamente a una sección crítica, gestionando así la concurrencia y el uso eficiente de recursos.   |
| `4_condition_vars.cpp`      | **Condition Variables**                   | Una **condition\_variable** es un mecanismo que permite a un hilo esperar (bloquearse) hasta que otro hilo le notifique que una **condición** específica se ha cumplido. Es útil para sincronizar eventos y evitar que un hilo revise continuamente un estado (polling).                    |
| `5_sync_barriers.cpp`       | **Barreras de sincronización**            | Una **barrera** es un punto donde varios hilos deben esperar hasta que todos hayan llegado antes de continuar. Esto asegura que todos los hilos avancen sincronizados, útil para etapas de trabajo que dependen unas de otras.                                                              |
| `6_deadlock.cpp`            | **Deadlocks**                             | Un **deadlock** es un bloqueo permanente donde dos o más hilos esperan indefinidamente por recursos que están bloqueados entre sí. Esto sucede cuando cada hilo sostiene un recurso y espera otro, y ninguno puede avanzar, causando un bloqueo total.                                      |
| `7_final_example.cpp`       | Productor-consumidor (con fallos)         | Patrón clásico donde **productores** generan datos y los colocan en un buffer, y **consumidores** los procesan. En esta versión inicial, faltan mecanismos correctos para la sincronización y para señalizar el final, lo que puede generar bloqueos o pérdida de datos.                    |
| `8_final_example_fixed.cpp` | Productor-consumidor (versión corregida)  | Versión mejorada del patrón **productor-consumidor** usando **semáforos** para controlar espacios y elementos, **mutex** para proteger el buffer, y **condition variables** para la comunicación entre hilos, además de una **señal de parada** para cerrar los consumidores ordenadamente. |

