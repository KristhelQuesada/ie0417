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
| Archivo                     | Tema Principal                           | Descripción teórica                                                            |
| --------------------------- | ---------------------------------------- | ------------------------------------------------------------------------------ |
| `1_racecond_nosync.cpp`     | Condición de carrera (Race condition)    | *(explicar sobre accesos simultáneos sin sincronización...)* |
| `2_racecond_mutex.cpp`      | Mutex para sincronización                | *(explicar cómo los mutex protegen secciones críticas...)*                     |
| `3_racecond_semaphore.cpp`  | Semáforos                                | *(definir el uso de semáforos para control de acceso...)*                    |
| `4_condition_vars.cpp`      | Condition Variables                      | *(uso de `condition_variable` para esperar y notificar eventos...)*            |
| `5_sync_barriers.cpp`       | Barreras de sincronización               | *(coordinación de hilos que deben avanzar juntos...)*                          |
| `6_deadlock.cpp`            | Deadlocks                                | *(condiciones para un deadlock, ejemplo clásico con mutex cruzados...)*        |
| `7_final_example.cpp`       | Productor-consumidor (con fallos)        | *(explicar cómo se intenta implementar el patrón con errores de diseño...)*    |
| `8_final_example_fixed.cpp` | Productor-consumidor (versión corregida) | *(versión correcta con semáforos, mutex y señalización de parada...)*          |
