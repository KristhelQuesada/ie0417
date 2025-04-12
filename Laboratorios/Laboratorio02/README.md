# Laboratorio 02: Control de Versiones y Documentación Automática

### Tabla de contenidos
1. [Control de Versiones](#control-de-versiones)

    - [Sección Principal](#seccion-principal)

    - [Sección Remota](#seccion-remota)
2. [Documentación Automática](#documentacion-automatica)

    - [Doxygen](#doxygen)

    - [Sphinx](#sphinx)

<br>

## Control de Versiones

### Sección Principal

<div align="center"><strong>Sección Introductoria</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 1  | ![Evidencia1](images/image1.png) | `git commit` | Navegación entre directorios. |
| 2  | ![Evidencia2](images/image2.png) | `git branch <branch name>` <br> </br> `git checkout -b <branch name>` <br> </br> `git checkout <branch name>`| Crea una rama con nombre `<branch name>` <br> </br> Crea una rama con nombre `<branch name>` <br> </br> Cambia a una rama con nombre `<branch name>` |
| 3  | ![Evidencia3](images/image3.png) | `git merge <branch>` | Agregar commits de una rama a otra con un historial más transparente pero puede verse desorganizado. |
| 4  | ![Evidencia4](images/image4.png) | `git rebase <branch>` |  Agregar commits de una rama otra en una secuencia lineal y organizada pero no conserva el historial original. |

<br>
<div align="center"><strong>Acelerando</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 5  | ![Evidencia5](images/image5.png) | `git checkout <commit>` | Hace un detached del HEAD, moviendolo del branch actual a un commit especifico. |
| 6  | ![Evidencia6](images/image6.png) | `git checkout <branch>^` | Hace un detached del HEAD, moviendolo un commit arriba del branch actual. |
| 7  | ![Evidencia7](images/image7.png) | `git branch -f main HEAD~4` | Fuerza al branch `main` a moverse cuatro commits arriba de HEAD. |
| 8  | ![Evidencia8](images/image8.png) | `git reset HEAD~1` <br> </br> `git revert HEAD` | Revierte el estado de la rama un commit arriba de HEAD como si nunca si hubiera hecho <br> </br> Revierte el estado de la rama haciendo un nuevo commit para compartir los cambios. |

<br>
<div align="center"><strong>Working around</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 9  | ![Evidencia9](images/image9.png) | `git cherry-pick <commit1> <commit2> ... <commit n>` | Aplica commits específicos de otras ramas. |
| 10 | ![Evidencia10](images/image10.png) | `git rebase -i HEAD~4` | Reescribe los últimos 4 commits de forma interactiva. |


<br>
<div align="center"><strong>Un poco de todo</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 11 | ![Evidencia11](images/image11.png) | - | - |
| 12 | ![Evidencia12](images/image12.png) | `git commit --amend` | Modifica el último commit. |
| 13 | ![Evidencia13](images/image13.png) | - | - |
| 14 | ![Evidencia14](images/image14.png) | `git tag <tag_name> <commit to tag>` | Crea una etiqueta en un commit específico. |
| 15 | ![Evidencia15](images/image15.png) | `git describe <branch/commit>` | Transferencia de archivos entre equipos. |

<br>
<div align="center"><strong>Temas avanzados</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 16 | ![Evidencia16](images/image16.png) | - | - |
| 17 | ![Evidencia17](images/image17.png) | - | - |
| 18 | ![Evidencia18](images/image18.png) | - | - |

<br>

|  RESUMEN DE LOS EJERCICIOS COMPLETADOS  |
|:-----------:|
|![Evidencia11](images/image19.png) |


<br>

### Sección Remota

<div align="center"><strong>Push y Pull</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 1  | ![Evidencia20](images/image20.png) | `git clone` | Clona un repositorio remoto. |
| 2  | ![Evidencia21](images/image21.png) | `git checkout origin/main` | Cambia a la rama remota sin crear rama local. |
| 3  | ![Evidencia22](images/image22.png) | `git fetch` | Descarga los cambios del remoto sin aplicarlos. |
| 4  | ![Evidencia23](images/image23.png) | `git pull` | Descarga y aplica cambios del remoto. |
| 5  | ![Evidencia24](images/image24.png) | - | - |
| 6  | ![Evidencia25](images/image25.png) | `git push` | Envía los cambios al repositorio remoto. |
| 7  | ![Evidencia26](images/image26.png) | `git pull --rebase` | Aplica los cambios remotos sobre los locales. |
| 8  | ![Evidencia27](images/image27.png) | `git branch -f main origin/main` <br> </br> `git checkout -b <branch> <commit>` <br> </br> `git push origin <branch>` | Fuerza una rama al estado remoto. <br> </br> Crea una rama desde un commit. <br> </br> Sube una nueva rama al remoto. |


<br>
<div align="center"><strong>Hasta el origen y más allá</strong></div>

---

| N° | Evidencia | Comandos | Descripción |
|----|-----------|----------|-------------|
| 9  | ![Evidencia28](images/image28.png) | `git rebase <local commit> <local branch>` <br> </br> `git rebase <local branch> <local branch>` | Aplica los commits desde el commit indicado sobre la rama actual. <br> </br> Reorganiza una rama encima de sí misma, útil para reordenar o limpiar historial. |
| 10 | ![Evidencia29](images/image29.png) | - | - |
| 11 | ![Evidencia30](images/image30.png) | `git checkout -b <local branch> origin/main` | Crea una nueva rama local basada en la rama remota `origin/main`. |
| 12 | ![Evidencia31](images/image31.png) | `git push origin <local branch>` | Sube una rama local al repositorio remoto con el mismo nombre. |
| 13 | ![Evidencia32](images/image32.png) | `git push origin <local branch>:<remote branch>` | Sube una rama local al remoto, pero con un nombre diferente al local. |
| 14 | ![Evidencia33](images/image33.png) | `git fetch origin <remote branch>` <br> </br> `git fetch origin <remote commit>:<local branch>` | Trae una rama remota completa y actualiza el tracking local. <br> </br> Descarga un commit específico del remoto y lo guarda en una nueva rama local. |
| 15 | ![Evidencia34](images/image34.png) | `git pull origin :<branch>` <br> </br> `git fetch origin :<branch>` | Elimina la rama `<branch>` tanto local como remotamente. <br> </br> Crea una rama local vacía con el nombre especificado. |
| 16 | ![Evidencia35](images/image35.png) | `git pull origin <branch>` <br> </br> `git pull origin <remote branch>:<local branch>`<br> </br> `git pull origin <remote commit>:<local branch>` | Descarga y fusiona una rama remota con la rama actual. <br> </br> Trae una rama remota y la fusiona con una rama local distinta. <br> </br> Trae un commit específico del remoto y lo aplica en una rama local. |

<br>

|  RESUMEN DE LOS EJERCICIOS COMPLETADOS  |
|:-----------:|
|![Evidencia36](images/image36.png) |

<br>

## Documentación Automática

### Doxygen
La documentación de Doxygen puede encontrarse disponible en: https://ie0417-hashtable.netlify.app/files

### Sphinx
La documentación de Sphinx puede encontrarse disponible en: https://ie0417-sismos.netlify.app/main