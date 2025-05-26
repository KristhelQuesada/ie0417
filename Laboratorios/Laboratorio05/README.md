# Laboratorio #5: Django con Docker

---

# Descripción

En este laboratorio se estudia Docker, por medio de una aplicación Django con PostgreSQL, en Ubuntu Linux. Para esto, se creó, usando ChatGPT, una aplicación de notas en Django con conexión a PostgreSQL, y se generó el flujo de Docker para desplegar esta aplicación. Adicionalmente, se agrega un archivo FYI.txt que explica los pasos que se realizaron para el setup de Djando y Docker.

Este trabajo fue colaborativo por:
- Kristhel Quesada López - C06153
- Jorge Meneses Garro - C14742

<br>

# Requisitos

Para este laboratorio, se necesita tener Docker instalado en la máquina donde se ejecute. Para descargar Docker en Ubuntu, se deben seguir los siguientes pasos:

1. Configurar el repositorio apt de Docker

    ``` bash
    # Add Docker's official GPG key:
    $ sudo apt-get update
    $ sudo apt-get install ca-certificates curl
    $ sudo install -m 0755 -d /etc/apt/keyrings
    $ sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc
    $ sudo chmod a+r /etc/apt/keyrings/docker.asc

    # Add the repository to Apt sources:
    $ echo \
        "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
        $(. /etc/os-release && echo "${UBUNTU_CODENAME:-$VERSION_CODENAME}") stable" | \
        sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
    $ sudo apt-get update
    ```

2. Instalar Docker y paquetes necesarios:

    ``` bash
    $ sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
    ```

3. Probar la instalación:

    ```bash
    $ sudo docker run hello-world
    ```

# Arquitectura

A continuación se muestra la arquitectura diseñada para el despliegue de esta aplicación Django. Se puede ver:

- Un cliente, que obtuvo archivos esenciales de Git, y ejecuta un `docker compose`
- Un Docker daemon
- Dos contenedores, uno para base de datos y otro para app, generando dos imágenes.
- Una red, que habilita la comunicación entre esos dos contenedores.

![Imgur](https://i.imgur.com/yKtCZNn.jpeg)

# Archivos y directorios

A continuación, se muestra una explicación para cada archivo y directorio, al igual que su importancia en el despliegue de la app con Docker.

- **init/dump_notas.sql**
  - Este archivo funciona como un 'backup' para la DB, pues la carga o reconstruye en el momento que fue exportada.
- **notas/ & notas_project/**
  - Esto corresponde al projecto en Django propiamente.
- **.env**
  - Este archivo no se subiría comúnmente, pues es el que contiene las credenciales de acceso a APIs, bases de datos, etc.
  - En este caso, este archivo representa todas las credenciales de acceso y conexión con la base de datos PostgreSQL.
  - En el contexto de este laboratorio, este archivo puede subirse sin problema, al ser algo más arbitrario, y no haber problema que estas credenciales estén en un repositorio.
- **docker-compose.yml**
  - Este es el archivo encargado de orquestrar el funcionamiento de múltiples contenedores.
  - En este caso, este archivo se encarga de administrar dos contenedores/servicios, `web`(Django) y `db`(PostgreSQL). Dentro de esto se encuentra la configuración del archivo `.env`, la red de comunicación, los puertos, los volúmenes, comandos y dependencias. Cabe destacar que para `db`, se usa una imagen pre-definida para POstgreSQL.

    ``` yml
    services:
    db:
      image: postgres:14
      container_name: postgres_nota
      env_file:
        - .env
      volumes:
        - pgdata:/var/lib/postgresql/data
        - ./init:/docker-entrypoint-initdb.d
      networks:
        - notas_net

    web:
      build: .
      container_name: django_nota
      command: sh -c "/wait-for-it.sh db:5432 -t 60 -- python manage.py migrate && python manage.py runserver 0.0.0.0:8000"
      volumes:
        - .:/app
      ports:
        - "8000:8000"
      env_file:
        - .env
      depends_on:
        - db
      networks:
        - notas_net
      ```

  - A su vez, definen las redes de contenedores y los volúmenes de datos.
  
    ```yml
    volumes:
        pgdata:

    networks:
        notas_net:
    ```

- **Dockerfile**
  - Este archivo se encarga de generar la imagen personalizada para el servicio `web`, para que Django pueda ejecutarse correctamente.
  - Para no empezar "de cero", se usa una base preexistente.
  
    ``` docker
    FROM python:3.10-slim
    ```
  - Establece el directorio de trabajo de la app
  
    ``` docker
    WORKDIR /app
    ```
  - Instala las dependencias
  
    ``` docker
    COPY requirements.txt . .
    RUN pip install --no-cache-dir -r requirements.txt
    ```
  - Copia el código fuente
  
    ``` docker
    COPY . .
    ```
  - Comando si se ejecuta la imagen directamente
  
    ``` docker
    CMD ["sh", "-c", "python manage.py migrate && python manage.py runserver 0.0.0.0:8000"]
    ```
  - Usa un script para esperar la base de datos
  
    ```docker
    COPY wait-for-it.sh /wait-for-it.sh
    RUN chmod +x /wait-for-it.sh
    ```
- **manage.py**
  - Este archivo permite manipular, via CLI, la aplicación Django.
  - Dentro de las funcionalidades de este, están:
    - `runserver`
    - `migrate`
    - `makemigrations`
    - `createsuperuser`
    - `shell`
    - `test`
    - `collectstatic`
- **requirements.txt**
  - Este archivo contiene los paquetes y versiones necesarios para correr la aplicación Django.
  - Este archivo es usado por el Dockerfile para instalar las dependencias necesarias y así la app pueda ser ejecutada.
- **wait-for-it.sh**
  - Este script es usado para evitar conflictos a la hora de correr Docker.
  - Esto porque se encontraron problemas donde se ejecutaba el contenedor antes de que estuviera la base de datos, lo que generaba errores. Entonces, este script permite controlar la ejecución para esperar que la DB esté lista.

# Instrucciones de uso

Para levantar la aplicación Django en cuestión, solo se necesita un comando `docker`, como se muestra a continuación.

``` bash
$ cd <path/to/repo/laboratorios/laboratorio5>
$ docker compose up
```

# Funcionamiento

Para verificar y evidenciar el funcionamiento, se muestran a continuación distintos pasos para poder usar la aplicación, al igual que la ejecución de Docker.

1. Primero, se intenta acceder a l adirección donde está hosteada la app. En este caso, es `localhost:8000`. Se puede ver que, sin ejecutar el Docker, no se tiene nada activo.

![Imgur](https://i.imgur.com/Qw4ocm9.png)

1. Ejecución de `docker compose up`

![Imgur](https://i.imgur.com/wOrdkuq.png)
![Imgur](https://i.imgur.com/gSdEbIS.png)

3. Una vez con eso ejecutado, ya la aplicación está disponible para visitar. En este caso, se programó para estar en `localhost:8000`, por lo que se va a Mozilla Firefox y se busca esta dirección.
   - La nota que se aprecia una vez iniciada la app, corresponde  aun valor inicial que se incluyó en la DB, pues esto permite confirmar la conexión con PostgreSQL.

![Imgur](https://i.imgur.com/2j2vLQp.png)

4. Se crea una nueva nota. Para esto, seleccionar la opción que lo indica. Una vez se rellene el espacio deseado, pulsar 'Guardar'

![Imgur](https://i.imgur.com/BagsmjZ.png)

5. Una vez hecho eso, se puede ver como la nueva nota está enlistada en la página inicial.

![Imgur](https://i.imgur.com/XezEFkz.png)