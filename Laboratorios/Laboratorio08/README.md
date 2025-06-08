# Laboratorio 08: Software Testing

### Estudiantes:
- Gabriel Gamboa Vargas, B73098
- Kristhel Quesada López, C06153


### Tabla de contenidos

1. [Compilación y Ejecución](#1-compilación-y-ejecución)
2. [Procedimiento](#2-procedimiento)

    2.1 [Semillas en Software Testing](#21-semillas-en-software-testing)

    2.2 [Unit Testing](#22-unit-testing)

    2.3 [Functional Testing](#23-functional-testing)

    2.4 [GitHub Actions](#24-github-actions)


----
<br>

## 1. Compilación y Ejecución (Local)

#### Requisitos previos
```bash
sudo apt-get update && sudo apt-get install -y cmake
```

#### Ejecutar todos los ejemplos
```bash
chmod u+x run-test.sh
```

```bash
./run-test.sh
```

> [!TIP]
> Profesor/asistente, se implementa el script anterior con la finalidad de que los ejemplos del laboratorio puedan ser ejecutados en un solo comando para su facilidad. No obstante, de requerir las pruebas por individual refierase a los comandos siguientes.

<br>

#### Ejecutar ejemplo de la semilla

```bash
g++ -o random_example random_example.cpp
```

```bash
./exe
```

<br>

#### Ejecutar ejemplos con gtest y gmock

```bash
cd src/
mkdir build
cd build/
cmake ..
make
./test_calculator
./test_authentication
```

<br>

<br>

## 2. Procedimiento

### 2.1. Semillas en Software Testing
Inicialmente, se realiza un micro-experimento que busca ilustrar la reproducibilidad determinística (*deterministic reproducibility*). Al usar una semilla constante, se garantiza que la secuencia de números generados sea siempre la misma, lo que es fundamental para pruebas reproducibles y debugging efectivo. Esto se puede visualizar en la siguiente imagen, donde se muestran dos ejecuciones con resultados idénticos.

| ![1](images/Lab08_Seed.png) |
|:--:|
| **Figura 1. Ejemplo de la semilla.** |


### 2.2. Unit Testing
En este ejemplo se emplea **CMake** para gestionar la construcción y ejecución de pruebas unitarias utilizando Google Test y Google Mock. Como se muestra en la *Figura 2*, este es el resultado obtenido tras ejecutar el archivo `CMakeLists.txt` que configura dos ejecutables: uno para probar funciones de una calculadora (test_calculator) y otro para un sistema de autenticación simulado (test_authentication). Sin embargo, la imagen muestra la compilación únicamente para el archivo de Unit Testing.

| ![2](images/Lab08_CalcTestSetup.png) |
|:--:|
| **Figura 2. Set-up del uso de cmake para el ejemplo de la calculadora.** |

La *Figura 3* muestra los resultados obtenidos tras ejecutar los comandos `cmake ..` y `make`. En este caso, se observa que dos pruebas pasaron exitosamente (`AddTest`, `SubstractTest`) y una falló (`FailingTest`). Esta última emplea `ASSERT_EQ`, el cual interrumpe el flujo de ejecución de la prueba si falla, por lo que la instrucción siguiente (`EXPECT_EQ`) no se ejecuta. Este comportamiento permite detener pruebas cuando se detectan errores críticos, ayudando a identificar fallos específicos de manera precisa.
| ![3](images/Lab08_CalcTest.png) |
|:--:|
| **Figura 3. Resultados del ejemplo de Unit Testing (`test_calculator`).** |


### 2.3. Functional Testing
El segundo conjunto de pruebas utiliza Google Mock para simular el comportamiento de una base de datos durante el proceso de autenticación. Esto permite aislar el módulo que se desea probar (la lógica de autenticación) de las dependencias externas (como una base de datos real), asegurando así pruebas más controladas, rápidas y reproducibles. El enfoque facilita validar si el sistema interactúa correctamente con la base de datos, sin necesidad de depender de una implementación real. Los resultados del testing se muestran en la siguiente figura:
| ![4](images/Lab08_AuthTest.png) |
|:--:|
| **Figura 4. Resultados del ejemplo de Functional Testing (`test_authentication`).** |


### 2.4. GitHub Actions
GitHub Actions es una herramienta de integración continua (CI) y entrega continua (CD) integrada en GitHub que permite automatizar tareas como compilación, pruebas y despliegue de código mediante workflows definidos en archivos YAML.

En este caso, se siguen los siguientes pasos para la configuración de su entorno:

1. Crear repositorio en GitHub y subir los archivos de `src/`.
2. Ir a la pestaña **Actions** en el repositorio, seleccionar "**New workflow**" y luego "**Set up a workflow yourself**".
3. Se abrirá una pestaña para que coloques el contenido del archivo YAML, tal como se observa en la siguiente figura.

| ![5](images/Lab08_GA.png) |
|:--:|
| **Figura 5. Configuración del archivo de workflow.** |

> [!WARNING]
> Sin embargo, debido a que hubo errores con la implementación inicial que se muestra en la imagen, a continuación se aclara el código YAML implementado. Los cambios fueron en instalar `cmake` desde el sistema, en vez de la acción `get-cmake` publicada por `lukka`.

```yaml
name: CI/CD Pipeline

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v2

      - name: Install CMake (if needed)
        run: sudo apt-get update && sudo apt-get install -y cmake


      - name: Build and run tests
        run: |
          cd Laboratorios/Laboratorio08/src/
          mkdir build
          cd build
          cmake ..
          make
          ctest --output-on-failure

  deploy:
    needs: build
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v2

      - name: Deploy to production
        run: echo "Se ejecutan las pruebas, listas para el deployment."
```

Luego de aceptar los cambios, GitHub Actions inicia su flujo como se muestra en la *Figura 6.*

| ![6](images/Lab08_yml1.png) |
|:--:|
| **Figura 6. Vista del workflow actual de GitHub Actions.** |

También se puede revisar lo que pasa dentro de cada tarea del workflow, al clickear en `Details`, lo cual despliega una serie de pestañas con logs. Esta vista se muestra a continuación-

| ![7](images/Lab08_ymllog.png) |
|:--:|
| **Figura 7. Vista de los logs del workflow actual de GitHub Actions.** |

Inicialmente, se pusheó al repositorio la prueba de `test_calculator` que forzaba un error, para observar la reacción de GitHub Actions, tal respuesta se muestra en la siguiente imagen.

| ![8](images/Lab08_GA_fail.png) |
|:--:|
| **Figura 8. Log del workflow tras el error inicial de `test_calculator`.** |

Finalmente, tras pushear la versión de `test_calculator` que incluía el error forzado, se observa en la *Figura 9* como el resultado de GitHub Actions fue exitoso.

| ![9](images/Lab08_GA_succs.png) |
|:--:|
| **Figura 9. Resultado éxitoso del workflow tras correción del error inicial de `test_calculator`.** |