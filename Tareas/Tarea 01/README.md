# Tarea 1: Modelos ágiles y herramientas de gestión de proyectos en la industria del software

### Tabla de contenidos
- [1. Herramientas de gestión de proyectos de software](#1-herramientas-de-gestión-de-proyectos-de-software)
- [2. Marco teórico profundo de Scrum y Kanban](#2-marco-teórico-profundo-de-scrum-y-kanban)
- [3. Casos reales de aplicación en la industria](#3-casos-reales-de-aplicación-en-la-industria)

<br></br>

# 1. Herramientas de gestión de proyectos de software

> Investigue al menos tres herramientas utilizadas para la planficación, seguimiento y ejecución de proyectos de software. La investigación debe incluir:
>
> - Breve descripción de cada herramienta.
> - Principales funcionalidades.
> - Relación con metodologías ágiles (por ejemplo: cómo se implementan Scrum o Kanban en la herramienta).
> - Comparación entre ellas en cuanto a facilidad de uso, integración con otras plataformas, popularidad, entre otros.

## 1.1. Jira
<!-- ==================================================================================================== -->
<details>
<summary> <strong> Descripción </strong> </summary>

Jira es un software de gestión de proyectos que fue lanzado en 2002 por Atlassian, para profesionales de diseño institucional y de software. Su objetivo es permitir que equipos trabajen juntos de manera más eficiente al facilitar la colaboración entre los miembros del equipo, de tal forma que lleven un registro continuo del progreso del proyecto. Es una herramienta ampliamente utilizada en ambientes ágiles para asegurar una cultura colaborativa y flexible en los métodos de trabajo, y a su vez, responder al cambio de manera efectiva y rápida tanto en el entorno, como con los clientes y el mercado. Actualmente, es certificada como una de las herramientas más preferidas por empresas globalmente. [^1]

No obstante, Jira no es una única plataforma, sino que ofrece diferentes productos como: Jira Service Management, Jira Software, Jira Product Discovery y Jira Work Management. En lo que respecta al interés del curso, nos enfocaremos principalmente en destacar las diferencias de solo dos de ellos: Jira Software y Jira Work Management. En lo que respecta a los otros dos productos restantes, Jira Service Management se enfoca más en TI, soporte y atención al cliente, mientras que Jira Product Discovery se enfoca más en la planificación de ideas de productos, gestión de productos o marketing. [^2]

Ahora bien, a modo de resumir los dos productos de interés, se presenta el siguiente cuadro comparativo: [^2]

| | **Jira Software**                       | **Jira Work Management** |
|----------------------------|----------------------------|------------|
|**Descripción**| Está diseñado para equipos de software. | Está diseñado para equipos empresariales en general|
|**Capacidades**| Planear, tracking, desplieges y soporte durante el ciclo completo de desarrollo del proyecto.| Espacios compartidos para organizar, documentar y monitorear el trabajo |
|**Dise;ado para los siguientes equipos**| - Agiles <br> - Bug Support  <br> - DevOps <br> - Product Managemnet <br> - Project Management <br> - Software Development| - Marketing  <br> - Operations <br> - Sales <br> - Recursos Humanos <br> - FInanzas <br> - Legal <br> - Design |

</details>

<!-- ==================================================================================================== -->
<details>
<summary> <strong> Funcionalidades </strong> </summary>

Las funcionalidades de Jira pueden ser utilizadas en una serie de equipos, compañías y casos como: [^3]

-	**Jira para equipos con metodologías Agile**: Jira provee tableros Srum y Kanban con workflows personalizables; también genera reportes (burn-up/down charts, sprint reports, velocity charts) y timeline para mapear y dar seguimiento al progreso del proyecto.

-	**Jira para equipos de gestión de proyectos:** Jira es versátil para cualquier tipo de proyecto y para ello se ofrecen templates o workflows personalizables. Pueden agregarse issues y permisos personalizables.
-	**Jira para equipos de desarrollo de software:** Jira incluye integraciones CI/CD para facilitar la transparencia durante todo el SDLC. Adicionalmente, Jira cuentas con herramientas de flagging y junto con Jira Service Managemente permite que los equipos de desarrollo, operaciones y IT puedan acelerar su rendimiento antes cambios o nuevas actualizaciones.
-	**Jira para equipos de DevOps:** Jira integra herramientas de primeros y terceros las cuales incluyen plataformas de VCS como Bitbucket, GitHub o Gitlab. Además, ofrece herramientas de documentación como Confluence, al igual que herramientas de monitoreo y operaciones como Opsgenie.
-	**Jira para equipos de gestión de productos:** Jira ofrece Jira Product Discovery para gestionar la entrega de nuevas ideas relacionadas a un producto.
-	Jira para el manejo de tareas
-	Jira para el seguimiento de bugs
-	Jira para la gestión de requerimientos y casos de pruebas.

<br>

| ![Principales funcionalidades de Jira Work Managemente y Jira Software](images/1_Jira.png "Principales funcionalidades de Jira Work Managemente y Jira Software") | 
|:--:| 
| *Fig 1. Principales funcionalidades de Jira Work Managemente y Jira Software* |

<br>


No obstante, a continuación se resumen las características exclisivas que aportan cada uno de los productos de interés de Jira: [^3]
| **Jira Software**                       | **JIra Work Management** |
|----------------------------|------------|
| Tableros (Kanban y Scrum, completamente configurables) | Tableros (solo uno basico)|
| Timeline (completamente configurable) | Timeline (basico) |
| Sprints y reportes DevOps | Multiples vistas (resumen, lista y calendario) |
| Codigo (Integracion de herramientas como GIthub o BitBucket) | Formularios |
| Seguridad | Overviews |
| Deployments | Aprobaciones |
| On-call | - |

<br>

</details>


<!-- ==================================================================================================== -->
<details>
<summary> <strong> En el contexto de metodologias agiles </strong></summary>

En lo que respecta a metodologías agiles, Jira Software es la que explícitamente se considera un producto basado en ellas. Esto porque al momento de crear un nuevo proyecto ofrecen una serie de plantillas para su utilización y las cuales refleja el verdadero uso de metodologías agiles. Así para el caso de <strong>Jira Software</strong>, este ofrece las siguientes plantillas: [^2]

<br>

1. **Top-level planning:** Para monitorear el trabajo de múltiples proyectos y crear planificaciones para stakeholders fáciles de compartir.
2. **Kanban:** Para priorizar el trabajo más fácilmente, visualizar y avanzar en el proyecto mediante *issues* en un tablero.
3. **Scrum:** Para manejar el trabajo mediante *sprints* mediante tableros, backlogs y timelines.
4. **Bug tracking:** Para el seguimiento de errores, mediante el manejo de una lista de tareas de desarrollo y bugs.

Así, Jira Software incluye dos tipos de tableros configurables: Kanban y Scrum, los cuales incluyen filtros, columnas de status, creación de *swimlanes*, identificadores para diferentes espacios. En lo que respecta a los timelines, estos pueden ser activados o desactivados y configurados por sprint (si trabajamos con Scrum) o por fechas.

| ![Vista Jira Software](images/3_JiraSW_Agile.png "Vista Jira Software") | 
|:--:| 
| *Fig 2. Vista Jira Software* [^2] |

En lo que respecta a Jira Work Management, existen más de 20 plantillas organizadas acorde a diferentes equipos de trabajo. En general, el board de Jira Work Management es mucho más sencillo, y aunque no se base explicitamente en un marco ágil, su estructura e implementación es muy similar al marco Kanban; siendo una versión más sencilla ya que no existen configuraciones complejas, debido a que solo pueden realizarse solo 3 acciones: [^2]

-	Filtrar mediante configuraciones predefinidas por el board.
-	Agrupar para ver fichas por status, prioridad, asignación o categoría.
-	Personalizar los afiches para modificar la visualización de los campos que se quieren apreciar en cada uno de ellos.

| ![Vista Jira Work Management](images/4_JiraWM_Agile.png "Vista Jira Work Management") | 
|:--:| 
| *Fig 3. Vista Jira Work Managemente* [^2] |

</details>



## 1.2. Azure DevOps

<details>
<summary> <strong> Descripcion </strong> </summary>

Azure DevOps, antes conocido como Microsoft Visual Studio Team Services (VSTS), es una de las herramientas más poderosas de gestión de proyectos, y contiene casi todas las funcionalidades requeridas para mantener un equipo Scrum, tablas Kanban flexibles, trazabilidad excepcional mediante un inventario, dashboards personalizables, tablas Scrum inherentes, integración extendida y client support de Git, todo hospedado en la nube. Esta herramienta hace posible manejar control de versiones para código, documentos de prueba y otros elementos de trabajo como escenarios, test de prueba, bugs y riesgos automáticos. Otras características importantes son el manejo de backlog, capacidad de gestión y una interfaz atractiva y de fácil uso. [^1][^4]

<br>
</details>


<details>
<summary> <strong> Funcionalidades </strong> </summary>

Entre sus funcionalidades se destacan: [^5][^6]

- **Azure Repos:** Este es el lugar donde los equipos pueden almacenar el código fuente de sus aplicaciones. Microsoft ofrece repositorios privados de Git alojados en la nube para proyectos de desarrollo de software. Repos es un servicio dedicado que reemplaza la función de código en VSTS.

- **Azure Pipelines:** Los desarrolladores pueden usar este servicio para orquestar un flujo de trabajo CI/CD para sus aplicaciones. Los equipos pueden conectar cualquier repositorio Git o GitHub a su pipeline y desplegar su código de manera continua a diferentes plataformas, incluyendo AWS y Google Cloud Platform. Este servicio ofrece la misma funcionalidad que la función "build and release" en VSTS.
- **Azure Boards:** Este servicio permite a los equipos hacer seguimiento de su progreso con tableros Kanban, backlogs, paneles de control e informes personalizados. Anteriormente, VSTS ofrecía esta funcionalidad a través de la función "work".
- **Azure Artifacts:** Con este servicio, los equipos pueden integrar más fácilmente paquetes en un Azure Pipeline. Artifacts ofrece soporte para feeds de paquetes Apache Maven, npm y NuGet desde fuentes públicas y privadas, al igual que lo hacía la función "packages" en VSTS.
- **Azure Test Plans:** Este servicio es para pruebas planificadas y exploratorias de aplicaciones. Se integra con Azure Pipelines para habilitar pruebas automatizadas en los flujos de trabajo CI/CD. Los desarrolladores e ingenieros de operaciones que trabajaron con la función "test" en VSTS reconocerán la funcionalidad que ofrece Test Plans.
- **Dashboards:** Azure DevOps ofrece una visión general y personalizada del estado de un proyecto. Permiten a los usuarios visualizar información clave, métricas de rendimiento y gráficos de una manera clara y estructurada. [^7]

<br>
</details>

<details>
<summary> <strong> En el contexto de metodologias agiles </strong></summary>
Azure DevOps se integra estrechamente con las metodologías ágiles al ofrecer herramientas que permiten a los equipos trabajar de manera ágil y flexible. Con Azure Boards, se pueden gestionar tareas, priorizar historias de usuario y realizar seguimientos de los sprints o flujos de trabajo, lo cual es fundamental para prácticas ágiles como Scrum y Kanban. En general Azure Boards ofrece opciones para gestionar tableros basados en:

<br>

- **Scrum:** Utilizando los backlogs y los tableros Scrum de Azure Boards, los equipos pueden planificar sprints, gestionar tareas y hacer un seguimiento del progreso del trabajo de manera eficiente.

| ![Vista Jira Work Management](images/5_azure_sprint.png "Vista Jira Work Management") | 
|:--:| 
| *Fig 4. Configuración de Sprint en Scrum Azure DevOps* [^9] |

- **Kanban:** Los tableros Kanban de Azure Boards permiten gestionar el flujo de trabajo visualmente, ayudando a los equipos a optimizar los tiempos de entrega y evitar cuellos de botella ya que permite establecer límites de WIP. 

| ![Vista Jira Work Management](images/5_WIP.png "Vista Jira Work Management") | 
|:--:| 
| *Fig 5. WIP en Kanban Azure DevOps* [^8] |

- **Scrumban:** Una combinación de Scrum y Kanban, que también se apoya en los tableros de Azure Boards para gestionar flujos de trabajo ágiles con flexibilidad.
</details>

## 1.3. GitHub Project

<details>
<summary> <strong> Descripcion </strong> </summary>

Github Projects es una herramienta incorporada dentro de la plataforma de GitHub, que permite planificar y mantener un historial y registro detallado del trabajo, mediante funcionalidad flexibles y adaptables. En lugar de aplicar una metodología específica, un proyecto proporciona características flexibles que puedes personalizar en función de las necesidades y los procesos del equipo. Así, el proyecto se puede visualizar como una hoja de cálculo, un panel de tareas o un roadmap. Además, la herramienta permite visualizar el avance del proyecto en diferentes vistas y genera sus resultados en base a la herramienta de GitHub Issues incorporada igualmente a la plataforma, por lo que su uso es de muy fácil acceso. [^10][^11]

<br>
</details>

<details>
<summary> <strong> Funcionalidades </strong> </summary>

Las funcionalidades de GitHub Projects son muy sencillas, y entre ellas se encuentran: [^11]

-	**Actualizaciones del estado:** Los proyectos se construyen a partir de problemas y pull requests, creando referencias directas entre tu proyecto y el trabajo. La información se sincroniza automáticamente con tu proyecto y se actualizan vistas y gráficos. Los cambios en los problemas o pull requests también se reflejan en el proyecto.
-	**Adición de metadatos a los ítems:** Puedes utilizar campos personalizados para agregar metadatos a los problemas, pull requests y borradores. Ejemplos incluyen campos de fecha (para fechas de envío), número (para la complejidad de tareas), selección única (para prioridad) y texto (para notas rápidas).
-	**Automatización de los proyectos:** GitHub Projects ofrece flujos de trabajo automáticos para establecer campos cuando se añaden o cambian elementos, archivar elementos automáticamente según criterios y agregar elementos desde un repositorio que coincidan con ciertos criterios. También se puede usar la API de GraphQL y GitHub Actions para una mayor personalización.
-	**Visualización en diferentes perspectivas:** Los proyectos se pueden visualizar como una tabla de alta densidad, un tablero Kanban o una hoja de ruta estilo línea de tiempo. Las vistas personalizadas se pueden guardar y compartir con el equipo.


Adicionalmente, la creación de un proyecto se ofrece en los siguientes formatos: [^12]
1.	**Tableros de proyectos propiedad del usuario:** Pueden contener problemas (issues) y pull requests de cualquier repositorio personal.
2.	**Tableros de proyectos a nivel de organización:** Pueden contener problemas (issues) y pull requests de cualquier repositorio que pertenezca a una organización.
3.	**Tableros de proyectos de repositorio:** Están limitados a problemas (issues) y pull requests dentro de un solo repositorio.

<br>
</details>

<details>
<summary> <strong> En el contexto de metodologias agiles </strong></summary>

Como se mencionó anteriormente, GitHub Projects no impone una metodología específica, sino que ofrece una solución más flexible para adaptarse a las necesidades y a procesos del equipo. No obstante, con relación a las metodologías ágiles ofrece plantillas similares al marco de Kanban como: [^12]

1.	**Kanban básico:** Permite un seguimiento de las tareas mediante las columnas: To do, In progress y Done.
2.	**Kanban automatizado:** Las tarjetas (tareas con metadatos) se mueven automáticamente entre las columnas: To do, In progress y Done.
3.	**Kanban automatizado con revisión:** Las tarjetas se mueven automáticamente entre las columnas: To do, In progress y Done, con triggers adicionales ante estados de revisión de pull request-
4.	**Triage de errores:** Realiza el triage (evaluar y clasificar los errores o problemas reportados) y prioriza los errores con las columnas: To do, High priority, Low priority, and Closed.

| ![Vista Kanban básica en GitHub Project](images/6_githubprojects_kanban.png "Vista Kanban básica en GitHub Project") | 
|:--:| 
| *Fig 6. Vista Kanban básica en GitHub Projects* [^12] |

</details>

<br>

## 1.4. Resumen comparativo
| Característica           | Jira                          | Azure DevOps                   | GitHub Projects               |
|--------------------------|------------------------------|--------------------------------|--------------------------------|
| **Enfoque principal**   | Gestión de proyectos Agile   | Integración CI/CD y DevOps    | Gestión de proyectos para repositorios GitHub |
| **Metodologías soportadas** | Scrum, Kanban  | Scrum, Kanban                 | Kanban, listas personalizadas |
| **Integración con repositorios** | Bitbucket, GitHub, GitLab | Azure Repos, GitHub         | GitHub nativo |
| **Gestión de tareas**  | Issues, Epics, User Stories  | Work Items, Backlogs, Epics   | Issues, Milestones, Projects |
| **Automatización**    | Reglas de automatización avanzadas | Pipelines y automatización integrada | GitHub Actions y automatización |
| **Control de acceso y permisos** | Muy detallado y personalizable | Integrado con Azure Active Directory | Basado en permisos de GitHub |
| **Paneles y reportes** | Dashboards avanzados y personalizables | Reportes de rendimiento y DevOps | Visualizaciones básicas |
| **Integraciones**  | Amplia compatibilidad con plugins y API | Integración nativa con herramientas de Microsoft | Integraciones con GitHub Apps |
| **Uso ideal** | Equipos Agile, ITSM, grandes empresas | Equipos DevOps, desarrollo en entornos Microsoft | Equipos que trabajan en GitHub y buscan simplicidad |
| **Costo** | Pago por usuario, planes en la nube y on-premise | Pago por usuario en planes de Azure | Incluido en planes gratuitos y pagos de GitHub |

<br></br>

# 2. Marco teórico profundo de Scrum y Kanban
> Debe analizar detalladamente ambos frameworks. En cada caso, se debe incluir:
> - Historia y origen del enfoque.
> - Principios fundamentales.
> - Estructura del trabajo (roles, artefactos, ceremonias en Scrum; columnas, flujo, WIP en Kanban).
> - Ventajas y limitaciones de cada uno.
> - Cuándo es más adecuado utilizar uno u otro.
>
> Se espera un análisis comparativo entre ambos marcos y una reflexión sobre cómo podrían aplicarse
> en un proyecto estudiantil o real.

## 2.1. Scrum
### Historia y origen del enfoque
<details>

Scrum se ha convertido en uno de los marcos de trabajo ágiles más adoptados no solo en el desarrollo de software sino en diversas industrias. Esta metodología permite a equipos y organizaciones generar resultados de forma iterativa e incremental, adaptándose a requisitos cambiantes y fomentando la colaboración y la autoorganización. [^13]

Su origen inicia en 1986 cuando Takeuchi y Nonaka introducen el concepto de lo que hoy conocemos como Scrum en [*“The New New Product Development Game (1986)"*](https://www.thescrummaster.co.uk/wp-content/uploads/2016/09/The-New-New-Product-Development-Game.pdf)“, en donde equiparaban el proceso creativo con el rugby. El artículo describía un acercamiento basado en la escalabilidad y el trabajo en equipo que empresas como Honda, Canon y Fuji-Xerox habían utilizado para mejorar sus resultados, destacando la importancia los equipos autoorganizados y la gestión en el proceso de crecimiento. 

Posteriormente, a partir del artículo de Takeuchi y Nonaka, en 1993 el término Scrum fue introducido por primera vez introducido a equipos por los profesionales Jeff Sutherland, John Scumniotales, y Jeff McKenna. El término siguió creciendo hasta que en 1995 el término fue expuesto al público por primera vez mediante el artículo [*"The Scrum development process"*](https://www.thescrummaster.co.uk/wp-content/uploads/2016/09/SCRUM-Development-Process-K-Schwaber.pdf)  del expositor Ken Schwaber en la conferencia OOPSLA en Austin, Texas. Simultáneamente, Kent Beck inició a desarrollar el marco de Extreme Programming (XP) con la ayuda de Sutherland y Schwaber para que ambos marcos pudiesen trabajar complementándose.

La historia continúa cuando en 2001, se crea el Agile Manifesto propuesta por 17 colaboradores que observan la creciente demanda por una alternativa a los procesos de desarrollo de software complejos y basados en documentación. Este manifestó consta hasta la fecha de 4 valores y 12 principios, y sigue siendo la base de todo el desarrollo de software ágil hasta la actualidad, en donde Scrum se posiciona como un marco basado en una metodología ágil.

En el inicio de la década de los 2000, diferentes organizaciones de consultoría, entrenamiento y certificaciones del marco Scrum fueron creadas. Y finalmente, se puede decir que la historia de los fundamentos del marco Scrum finaliza en el 2010 cuando se publica la primera guía de Scrum gracias a los aportes de Ken Schwaber y Jeff Sutherland los cuales buscaban aclarar el concepto de Scrum. Dicha guía provee una serie de principios, roles, eventos y artefactos que conforman el marco, Desde eso, el acercamiento minimalista de Scrum fue muy bien recibido a globalmente, y hasta la fecha Schwaber y Sutherland mantienen actualizaciones constantes a la guía (Versión actual [2020](https://www.thescrummaster.co.uk/scrum/scrum-papers-archive/)). [^13]
</details>

### Principios fundamentales
<details>

Según la documentación oficial de Scrum [2020](https://www.thescrummaster.co.uk/scrum/scrum-papers-archive/), este marco cuenta con los siguientes principios fundamentales: [^14]

1.	**Transparencia**: Comunicación abierta, continua y sincrónica de parte de todo el equipo para evitar cuellos de botella en la información y mejorar la colaboración. 
2.	**Reflexión:** Revisiones frecuentes para evaluar avances, mejorar estimaciones y optimizar la planificación.
3.	**Adaptación:** Flexibilidad para ajustar prioridades según las necesidades del cliente y cambios en el proyecto.


Adicionalmente, Scrum plantea cinco valores fundamentales para los equipos de trabajo: [^14]

1.	Compromiso con tareas y objetivos en plazos de tiempo.
2.	Valentía al formular preguntas abiertas que pueden suponer retos pero que aumentan la honestidad y transparencia del proceso.
3.	Concentración durante un tiempo determinado únicamente en las tareas del Product Backlog.
4.	Actitud receptiva antes nuevas ideas, cambios y oportunidades.
5.	Respeto hacia los diferentes miembros del equipo, fomentando la colaboración y cooperación.

</details>


### Estructura de trabajo
<details>

| ![Scrum workflow](images/7_scrum.png "Scrum workflow") | 
|:--:| 
| *Fig 7. Scrum workflow* [^19] |

#### Roles [^14]
1.	Product Owner: Prioriza necesidades, guía al equipo en qué desarrollar y decide la frecuencia de lanzamientos. Actúa como enlace entre negocio y desarrollo.

2.	Scrum Master: Garantiza la correcta aplicación de Scrum, organiza recursos y eventos de cada Sprint, lidera la transformación digital y resuelve obstáculos externos.
3.	Developers: Compuesto por testers, diseñadores especialistas en la experiencia de usuario, ingenieros de operaciones y desarrolladores. Estos equipos colaboran para completar Sprints, fomentando prácticas sostenibles y auto-organización. 

#### Artefactos [^14]
1.	Product Backlog: Lista dinámica de tareas, mejoras y requisitos del proyecto, gestionada por el Product Owner. Se ajusta continuamente según prioridades y cambios del mercado.

2.	Sprint Backlog: Selección de tareas del Product Backlog que el equipo debe completar en el Sprint actual. Es flexible y evoluciona durante el Sprint.
3.	Incremento: Resultado tangible de cada Sprint que representa un avance del proyecto. Puede ser un producto listo para lanzamiento o una funcionalidad completa y probada.

#### Eventos [^14]
4.	Sprint planning: Se estima el trabajo a completar durante el siguiente sprint, definiendo objetivos específicos, medibles y viables.

5.	Sprint: Periodo durante el cual el equipo de Scrum trabaja conjuntamente para la consecución de un incremento. Usualmente dura dos semanas, pero puede variar según las necesidades del proyecto. Se aconseja que entre más complejo sea el trabajo y más factores desconocidos haya, el periodo del Sprint debe ser más corto.
6.	Daily Scrum: Reunión diaria y breve en la que los miembros del equipo se reportan y planifican el día. Su objetivo es informar sobre el trabajo concluido y expresar cualquier desafío para alcanzar los objetivos del Sprint.
7.	Sprint Review: Reunión informal al finalizar el sprint para revisar el trabajo concluido y exponerlo a los stakeholders. Puede generar que el Product Owner ajuste el producto backlog.
8.	Sprint Retrospective: Reunión del equipo para para documentar y hablar sobre qué funcionó y qué no durante el Sprint. Las ideas generadas se utilizan para mejorar los próximos Sprints.

</details>


### Ventajas y limitaciones
<details>


| **Ventajas de Scrum** [^15][^16] | **Limitaciones de Scrum** [^15][^16] |
|------------------------|---------------------------|
| Permite completar proyectos de manera rápida y efectiva, debido a la priorización de tareas en periodos cortos de tiempo. | Puede conducir al fenómeno de scope creep, es decir, al crecimiento incontrolado del alcance del proyecto debido a la incertidumbre de un cierre definido. |
| Proyectos grandes pueden ser divididos fácilmente en tareas más alcanzables. | El marco de trabajo puede ser desafiante en equipos grandes debido a que su implementación puede requerir de otros modelos más complejos como Scrum de Scrum. |
| El equipo tiene una clara visibilidad y comunicación del proyecto a partir de los diversos eventos, reduciendo la probabilidad de malentendidos. | Las reuniones consecutivas pueden frustrar a algunos miembros del equipo. |
| Acepta feedback constante de los clientes y stakeholders, lo cual mejora el resultado del proyecto. | Las probabilidades de que el proyecto fracase son altas si los miembros no están comprometidos. |
| Los sprints cortos permiten adaptarse a nuevos cambios de manera más sencilla. | Se requiere de una formación intensiva para implementar el modelo con éxito y obtener resultados de calidad. |
| El producto es desarrollado y testeado durante la revisión del sprint, lo cual ayuda a detectar riesgos tempranos. | Puede implicar un cambio en la estructura de la organización, lo cual puede tomar tiempo y esfuerzo para que los empleados se adecúen al nuevo paradigma. |
| Aumenta significativamente la satisfacción del cliente debido al feedback continuo y testing repetitivo. | No provee una estimación detallada del alcance del proyecto, así como del presupuesto y el tiempo. |
</details>


### ¿Cuándo es adecuado su uso?
<details>

Después de analizar las limitaciones de la metodología Scrum, podemos destacar que esta no siempre será factible, sino que esta sobresale sobre todo: [^17]

1.	Cuando los requisitos no son claros: Cuando el cliente tiene una idea general del producto, pero no especificaciones claras, lo que dificulta estimaciones precisas. En este caso Scrum es completamente ajustable y flexible durante todo el proceso.

2.	Cuando los cambios durante el desarrollo pueden ser muy probables: En proyectos donde los requisitos evolucionan constantemente debido a cambios en el negocio o la tecnología, Scrum facilita la adaptación continua.
3.	Cuando hay necesidad de probar la solución propuesta: Si se requiere un MVP para validar hipótesis del mercado y realizar ajustes tempranos, Scrum permite recopilar feedback y mejorar el producto antes de su lanzamiento final.
4.	Cuando existe alta disponibilidad del Product Owner (PO): El éxito de Scrum depende de la participación del PO para priorizar y definir correctamente las tareas del backlog.
5.	Cuando los equipos son capaces de auto-gestionarse: Scrum requiere un equipo con autonomía y experiencia suficiente para tomar decisiones sin depender de una supervisión constante. Se recomienda adicionalmente que los equipos consistan de 5 a 9 integrantes para maximizar el beneficio, de lo contrario, implementar celdas de trabajo puede ser una alternativa para equipos más grandes.
6.	Cuando el contrato es basado en tiempo y materiales: Aunque Scrum puede aplicarse en proyectos de precio fijo, funciona mejor en acuerdos de alcance abierto, donde se pueden hacer ajustes a medida que avanza el desarrollo.
7.	Cuando la cultura del cliente es receptiva y adaptable al cambio: Si el cliente es receptivo al cambio y la innovación, Scrum será más fácil de implementar y generará mejores resultados.
</details>

<br>

## 2.2. Kanban

### Historia y origen del enfoque
<details>

Kanban se originó a finales de la década de 1940 en Japón cuando Toyota buscaba una manera de mejorar sus procesos de ingeniería y producción. Uno de sus ingenieros, Taiichi Ohno, observó que los supermercados utilizaban un método de producción "pull", almacenando los artículos según la demanda prevista de los clientes para evitar tener demasiados productos en los estantes. Ohno se inspiró en esta técnica, que posteriormente desarrolló como producción "just-in-time" (JIT) e implementó en la fábrica de Toyota en 1953 como un enfoque temprano del Lean Manufacturing. El proceso Kanban fue el resultado de esta adaptación. [^18]

"Kanban" es una palabra japonesa que se puede traducir como "tarjeta visible". Toyota utilizaba tarjetas físicas para indicar los distintos pasos de su proceso de fabricación. Estas tarjetas permitían a los miembros del equipo ver fácilmente qué se había completado y qué quedaba por hacer. No fue hasta principios de la década de 2000 que Kanban comenzó a consolidarse en la gestión de proyectos. A David J. Anderson se le atribuye a menudo ser el primero en implementar Kanban en el desarrollo de software en 2005. Su libro sobre Kanban, publicado en 2010, sigue siendo uno de los recursos más completos disponibles para proyectos centrados en la tecnología. Desde entonces, la metodología ágil Kanban ha seguido evolucionando para adaptarse a proyectos de todos los sectores y mercados. [^18]
</details>

### Principios fundamentales
<details>
Inicialmente, Kanban propone una serie de principios fundamentales como: [^18]

1.	Empezar ahora: Indica que la concentración debe estar puesta en lo que se está haciendo actualmente y fomenta la comprensión completa de los procesos existentes, incluyendo qué funciona y qué no.

2.	Adoptar un enfoque incremental: Busca analizar cómo cambiar los procesos de forma gradual con el tiempo y evitar así, implementar cambios radicales.

3.	Mantener los roles: A diferencia de otros marcos que introducen roles específicos (como el Scrum Master), Kanban enfatiza el trabajo con los roles ya establecidos en tu equipo.

4.	Fomentar el liderazgo: Este marco busca que las mejoras provengan de todos los niveles, con el fin de motivar a cada empleado a actuar como líder, sin importar su rol o título.

Pero adicionalmente, se mencionan prácticas indispensables para que el marco sea implementado con éxito como: [^18]

1.	Visualizar el flujo de trabajo: Para mantener una imagen clara de como el flujo de trabajo se ve de una etapa a la otra, es necesario el uso de tableros físicos o virtuales.

2.	Work in Progress (WIP) limitado: Se define como la cantidad de tareas permitidas por etapa, y depende de la cantidad de miembros en el equipo.
3.	Manejo activo del flujo de trabajo: Los Project Managers deben comprometerse con monitorear el flujo para evitar cuellos de botella en el proceso y realizar así ajustes que mejoren la eficiencia.
4.	Crea pautas de proceso. Se define y comunica claramente las políticas sobre cómo se completan las tareas y qué significa que estén “terminadas”. Esto puede incluir listas de verificación en cada columna o tarjeta, indicando los requisitos para avanzar de etapa.
5.	Usar bucles de retroalimentación. Implementa herramientas y procesos que fomenten la retroalimentación temprana y continua. Esto puede incluir múltiples etapas de revisión o reportes y métricas que reflejen el rendimiento.
6.	Evolucionar: Como en otros marcos Ágiles, se fomenta la adaptación y mejora continua, por tanto, Kanban se enfoca en realizar pequeños cambios progresivos para optimizar tu flujo de trabajo y procesos.


</details>

### Estructura de trabajo
<details>

| ![kanban workflow](images/8_kanban.png "kanban workflow") | 
|:--:| 
| *Fig 8. Kanban workflow* [^20] |

A diferencia de muchas herramientas de gestión de proyectos que tienen una estructura rígida, los tableros Kanban están diseñados para ser flexibles. Estos fueron diseñados con el objetivo de personalizarse, modificarse e iterarse segun las necesidades del equipo o proyecto, con el fin único de reflejar el proceso y obtener puntos de mejora. Así, antes de comenzar a gestionar un proyecto bajo el marco de Kanban, es necesario es necesario tener en claro los siguientes conceptos: [^21]

-	Flujo: Es la secuencia completa de pasos por los que pasa una tarea desde su inicio hasta su finalización. Representa el proceso general de trabajo, desde la creación de una tarea hasta su entrega final.
-	Columna (carriles verticales): Es una representación visual de cada etapa del flujo en el tablero Kanban. Cada columna corresponde a un paso específico dentro del flujo de trabajo.
-	WIP limitado: Se refiere a la cantidad restringida de tareas que están en proceso (Work in Progress) dentro de cada etapa del flujo de trabajo en un momento dado. Se recomienda que cada columna tenga un WIP limitado para evitar la sobrecarga de trabajo y mejorar la eficiencia.

Ahora, si bien se considera un tablero Kanban a un tablero físico o virtual con notas en él, no todos aquellos que cumplan con la descripción anterior caben dentro de la categoría de Kanban correctamente. Para ello, es necesario considerar que el uso y objetivo de estos elementos, por lo que se puede decir entonces que en un tablero Kanban: [^21]
- Hay carriles verticales que representan los pasos de un proceso.
- Hay tarjetas (similares a notas adhesivas) que representan elementos de trabajo.
- Las tarjetas se mueven a través del proceso de izquierda a derecha.

Considerando solo estos tres elementos, depende de cada equipo o individuo decidir cómo utilizar el tablero, por ejemplo: [^21]

- Se pueden agregar carriles verticales para representar pasos específicos del proceso.
- Se pueden añadir carriles horizontales (swimlanes) para representar flujos de trabajo simultáneos y separar así los diferentes tipos de trabajos.
- Se pueden personalizar detalles en las tarjetas, como tipos de tarjetas e íconos, para comunicar el tipo de trabajo, su estado o información relevante para el equipo.
- Se pueden definir políticas de proceso para establecer claramente cómo deben moverse las tarjetas en el tablero.
- Se pueden implementar límites de trabajo en progreso (WIP) para restringir proactivamente la cantidad de trabajo en curso en cada columna, traduciéndose en un limite máximo de tareas que pueden desarrollarse en un momento específico.

Sin embargo, se puede decir que los pasos a seguir para estructurar correctamente un proyecto basado en Kanban son: [^22]

1. Visualizar el flujo de trabajo en un tablero Kanban, físico o virtual.
2. Estandarizar las etapas del flujo según las necesidades del equipo.
3. Identificar bloqueos y dependencias para resolución rápida.
4. Establecer límites WIP para optimizar el flujo.
5. Fomentar la colaboración entre los miembros del equipo.
6. Utilizar tarjetas Kanban con detalles clave sobre cada tarea.

</details>



### Ventajas y limitaciones

<details>

| **Ventajas de Kanban** [^23][^24] | **Limitaciones de Kanban** [^23][^24]|
|------------------------|---------------------------|
| Representa visualmente el flujo de trabajo, lo que permite identificar cuellos de botella y fomentar la colaboración. | A diferencia de Scrum, Kanban no define roles ni procesos fijos, lo que puede generar confusión sin una gestión adecuada. |
| Se ajusta fácilmente a cambios en prioridades y requisitos, facilitando la respuesta a interrupciones inesperadas. | Dificulta la estimación precisa del tiempo de finalización de tareas, lo que puede afectar la planificación del proyecto. |
| Al analizar el flujo de trabajo y realizar ajustes constantes, los equipos optimizan la eficiencia y reducen desperdicios. | La falta de una estructura rígida puede hacer que algunos equipos se desvíen de buenas prácticas sin la autodisciplina adecuada. |
| Un WIP limitado regula el número de tareas en curso, evita la sobrecarga y mejora la velocidad de entrega. | Sin límites efectivos de trabajo en progreso (WIP), existe el riesgo de ineficiencia y congestión en el flujo de trabajo. |
| Un tablero Kanban es ideal para un entorno de trabajo estable donde no hay cambios repentinos a un requisito existente. | Tiene un uso limitado en proyectos complejos, ya que no es ideal para proyectos con fases definidas y dependencias a largo plazo. |
</details>

### ¿Cuando es adecuado su uso?
<details>

Kanban es una opción bien adaptada para equipos que priorizan la entrega continua sobre plazos fijos. Es especialmente ventajoso para proyectos pequeños o la gestión de proyectos en curso con tareas frecuentes y de menor escala, como correcciones de errores o solicitudes de mejora. En resumen, Kanban es adecuado cuando: [^25]

- Tu equipo maneja un flujo continuo de tareas entrantes.
- No es necesario trabajar con plazos fijos para tareas o iteraciones.
- Tu equipo necesita una representación visual del trabajo en un tablero para facilitar el seguimiento del progreso e identificar cuellos de botella.
- Tu equipo es flexible para adaptarse a cambios en prioridades y requisitos.
</details>
<br>

## 2.3 Cuadro comparativo

A continuación se resumen las principales características de cada uno de los marcos: [^26]

| Característica           | Scrum                                  | Kanban                              |
|--------------------------|----------------------------------------|--------------------------------------|
| **Enfoque principal**   | Iteraciones fijas (Sprints) y entregas después de cada sprint          | Flujo y entregas continuas de trabajo           |
| **Roles definidos**      | Scrum Master, Product Owner, Equipo   | No tiene roles estrictos            |
| **Estructura del trabajo** | uede visualizarse en un tablero las taras del Sprint Backlog. | Tareas organizadas en un tablero con base en el WIP  |
| **Duración del ciclo**   | Sprints de 1 a 4 semanas              | No hay duración fija                |
| **Reuniones clave**      | Daily Stand-up, Sprint Planning, Review, Retrospective | Reuniones opcionales, enfocadas en la mejora continua |
| **Flexibilidad en cambios** | Cambios no permitidos durante un Sprint | Cambios pueden hacerse en cualquier momento |
| **Uso ideal**           | Equipos que trabajan en ciclos iterativos con planificación estructurada | Equipos con necesidades de entrega continua y flexibilidad |
| **Pull system**           | En cada sprint, del Product Backlog al Sprint Backlog y entre cada etapa durante el desarrollo del sprint. | Del Product Backlog o entre etapa sólo cuando el WIP lo permita. |



<br></br>

# 3. Casos reales de aplicación en la industria
> Investigue cómo se aplican las metodologías ágiles y estas herramientas en empresas tecnológicas
> reconocidas. Se deben analizar al menos dos casos de compañías reales.
> Por cada caso, incluya:
> - ¿Qué marco de trabajo utilizan? ¿Scrum, Kanban, una combinación, u otro?
> - ¿Qué herramientas tecnológicas usan para gestionarlo?
> - ¿Cómo adaptan las metodologías a su cultura organizacional?
> - ¿Qué beneficios o retos han reportado?
> - Reflexión crítica: ¿qué se puede aprender de este caso?

## 3.1 IBM
<details>

- **Marco de trabajo utilizado**

IBM utiliza principalmente Scrum como su marco de trabajo ágil para el desarrollo de software y otros proyectos tecnológicos. También implementan otras prácticas ágiles como Kanban en algunos equipos para mejorar la visualización de los flujos de trabajo. IBM se ha comprometido a ser una organización ágil, tanto en desarrollo de software como en otras áreas, como las operaciones internas y la gestión de proyectos. [^27] [^28]

- **Herramientas tecnológicas utilizadas**

IBM hace uso de varias herramientas para gestionar sus proyectos ágiles, destacándose Jira, Trello y Confluence (todas de Atlassian) para la gestión de tareas y la colaboración. Además, IBM Watson y herramientas internas de integración de procesos también son utilizados para mejorar la eficiencia del trabajo ágil dentro de sus equipos. [^29] [^30]

- **Adaptación a su cultura organizacional**

IBM tiene una cultura organizacional que favorece la innovación tecnológica, lo que facilita la implementación de metodologías ágiles. La compañía promueve la descentralización de decisiones, permitiendo que los equipos autónomos puedan tomar decisiones rápidamente. Esta mentalidad flexible es compatible con la implementación de prácticas ágiles, que permiten adaptarse rápidamente a los cambios en el mercado tecnológico. [^27] [^28]


- **Beneficios**

IBM ha visto mejoras en la colaboración entre equipos multidisciplinarios, la capacidad de entregar productos más rápido, y un enfoque más centrado en el cliente. Además, las metodologías ágiles han ayudado a mejorar la satisfacción del cliente debido a la mayor rapidez en la iteración y entrega de productos. [^28]

- **Retos**

A pesar de la adopción de prácticas ágiles, IBM ha enfrentado desafíos en la integración de equipos ágiles en una empresa tan grande, con procesos y estructuras jerárquicas arraigadas. La resistencia al cambio es uno de los mayores obstáculos, y la implementación a gran escala a veces ha creado disparidades en la forma de trabajar entre diferentes departamentos. [^27]

- **Reflexión**

El caso de IBM muestra cómo una empresa histórica puede adaptarse a metodologías ágiles, pero también resalta que la transición a la agilidad en grandes corporaciones no es sencilla. Es fundamental cultivar una mentalidad ágil en todos los niveles de la organización para garantizar que los equipos no solo sigan los métodos, sino que también se alineen con la cultura ágil.
</details>

<br>

## 3.2. Amazon
<details>
- **Marco de trabajo utilizado**

Amazon utiliza una combinación de metodologías ágiles, principalmente Scrum y Kanban. En cuanto a Scrum, emplean sprints estructurados para rastrear el progreso de los proyectos y mejorar la colaboración de los equipos de trabajo. Además, Amazon utiliza Kanban para visualizar flujos de trabajo y garantizar una ejecución continua desde la ideación hasta la entrega, asegurando que las tareas se realicen de manera eficiente sin cuellos de botella. También implementan prácticas de Lean Management y Six Sigma para optimizar los procesos y reducir el desperdicio, lo que refuerza el enfoque ágil. [^29]

- **Herramientas tecnológicas utilizadas**

Amazon utiliza una variedad de herramientas tecnológicas, incluidas algunas de sus propias soluciones. Algunas de las principales herramientas son: [^29]
    1. Jira y Asana: Para la gestión de proyectos, seguimiento de tareas, y documentación colaborativa.
    2. Slack: Para la comunicación en tiempo real entre los equipos distribuidos y para facilitar la colaboración.

- **Adaptación a su cultura organizacional**

Amazon adapta las metodologías ágiles a su cultura organizacional promoviendo una estructura descentralizada y equipos autónomos. La regla de las dos pizzas (Two-Pizza Rule) asegura que los equipos sean lo suficientemente pequeños como para ser eficientes y ágiles, permitiendo que cada miembro tenga un alto nivel de responsabilidad y contribución. Además, la cultura organizacional de Amazon pone un fuerte énfasis en la obsesión por el cliente, lo que impulsa a los equipos a trabajar hacia resultados que prioricen las necesidades del cliente. La integración de PRFAQ (Press Release & Frequently Asked Questions) asegura que todos los miembros del equipo tengan claridad sobre los objetivos y la visión desde el principio, alineándose con la estrategia global de Amazon. [^29]


- **Beneficios** [^29]

    1. Escalabilidad: Gracias a su infraestructura basada en la nube (AWS), Amazon puede gestionar proyectos a una escala global, lo que facilita la expansión continua sin sacrificar la eficiencia operativa.
    1. Agilidad y flexibilidad: El uso de metodologías ágiles les permite adaptarse rápidamente a las necesidades cambiantes del mercado y a la retroalimentación de los clientes, lo que les da una ventaja competitiva.
    1. Innovación constante: Los equipos pequeños y autónomos permiten la innovación constante, sin las barreras burocráticas típicas de grandes corporaciones.

- **Retos** [^29]

    1. Escalabilidad y complejidad: A medida que Amazon sigue creciendo, la gestión de proyectos a nivel global se hace cada vez más compleja, ya que implica coordinar a miles de empleados en diferentes ubicaciones.
    1. Altas expectativas de los clientes: Amazon debe cumplir con expectativas extremadamente altas de calidad y velocidad, lo que puede generar presión constante sobre los equipos.
    1. Coordinación entre equipos: Aunque la autonomía de los equipos es una ventaja, también puede generar dificultades en la coordinación efectiva entre equipos y departamentos, especialmente en proyectos de gran escala.
    1. Cumplimiento normativo: Amazon enfrenta desafíos regulatorios y de cumplimiento en diferentes países, lo que requiere un enfoque detallado para asegurar que todas las operaciones se alineen con las normativas locales e internacionales.


- **Reflexión**

El caso de Amazon resalta la importancia de combinar la flexibilidad de las metodologías ágiles con estrategias a gran escala. La empresa demuestra cómo optimizar procesos incluso a nivel global mediante la implementación de herramientas avanzadas y la toma de decisiones basada en datos. Un aspecto clave en su éxito es su enfoque centrado en el cliente, asegurándose de que cada proyecto esté alineado con las expectativas y necesidades del usuario, lo que refuerza la importancia de mantener este enfoque a lo largo de todo el ciclo de vida del proyecto.

Además, Amazon destaca el valor de los equipos autónomos y pequeños, como se refleja en su famosa regla de las dos pizzas. Al mantener equipos ágiles y bien enfocados, no solo mejora la eficiencia, sino que también fomenta la innovación. A pesar de los desafíos asociados con la coordinación y la complejidad, la clave del éxito de Amazon radica en su capacidad para adaptarse rápidamente a las circunstancias cambiantes y a las necesidades de los clientes.
</details>

<br> <br>

# Referencias

[^1]: "Agile Project Management Tools: A Brief Comparative View". Disponible en: [https://sciendo.com/pdf/10.2478/cait-2019-0033](https://sciendo.com/pdf/10.2478/cait-2019-0033)

[^2]: "Jira Work Management VS Jira Software". Disponible en: [https://tecnofor.es/en/jira-work-management-vs-jira-software/](https://tecnofor.es/en/jira-work-management-vs-jira-software/)

[^3]: "Jira for teams". Disponible en: [https://www.atlassian.com/software/jira/guides/getting-started/who-uses-jira#for-agile-teams](https://www.atlassian.com/software/jira/guides/getting-started/who-uses-jira#for-agile-teams)

[^4]: "Introducción a Visual Studio Team Services". Disponible en: [https://learn.microsoft.com/es-es/shows/level-up/introduction-to-visual-studio-team-services](https://learn.microsoft.com/es-es/shows/level-up/introduction-to-visual-studio-team-services)

[^5]: "Break down the main features of Azure DevOps Services". Disponible en: [https://www.techtarget.com/searchcloudcomputing/tip/Break-down-the-main-features-of-Azure-DevOps-Services](https://www.techtarget.com/searchcloudcomputing/tip/Break-down-the-main-features-of-Azure-DevOps-Services)

[^6]: "What is Azure DevOps?". Disponible en: [https://learn.microsoft.com/en-us/azure/devops/user-guide/what-is-azure-devops?view=azure-devops](https://learn.microsoft.com/en-us/azure/devops/user-guide/what-is-azure-devops?view=azure-devops)

[^7]: "Overview of services". Disponible en: [https://learn.microsoft.com/en-us/azure/devops/user-guide/services?view=azure-devops](https://learn.microsoft.com/en-us/azure/devops/user-guide/services?view=azure-devops)

[^8]: "Uso del panel". Disponible en: [https://learn.microsoft.com/es-es/azure/devops/boards/boards/kanban-quickstart?view=azure-devops](https://learn.microsoft.com/es-es/azure/devops/boards/boards/kanban-quickstart?view=azure-devops)

[^9]: "Implementación de procedimientos de Scrum para su equipo en Azure Boards
". Disponible en: [https://learn.microsoft.com/es-es/azure/devops/boards/sprints/scrum-overview?view=azure-devops](https://learn.microsoft.com/es-es/azure/devops/boards/sprints/scrum-overview?view=azure-devops)

[^10]: "Planning and tracking with Projects". Disponible en: [https://docs.github.com/en/issues/planning-and-tracking-with-projects](https://docs.github.com/en/issues/planning-and-tracking-with-projects)

[^11]: "About Projects". Disponible en: [https://docs.github.com/en/issues/planning-and-tracking-with-projects/learning-about-projects/about-projects](https://docs.github.com/en/issues/planning-and-tracking-with-projects/learning-about-projects/about-projects)

[^12]: "Introduction to GitHub Projects and Project boards". Disponible en: [https://learn.microsoft.com/en-us/training/modules/plan-agile-github-projects-azure-boards/2-introduction-to-project-boards](https://learn.microsoft.com/en-us/training/modules/plan-agile-github-projects-azure-boards/2-introduction-to-project-boards)

[^13]: "The History of Scrum". Disponible en: [https://www.agile42.com/en/blog/scrum-history#:~:text=Scrum%2C%20as%20it%20is%20known,%E2%80%9CScrum%E2%80%9D%20was%20fully%20developed.](https://www.agile42.com/en/blog/scrum-history#:~:text=Scrum%2C%20as%20it%20is%20known,%E2%80%9CScrum%E2%80%9D%20was%20fully%20developed.)

[^14]: "¿En qué consiste Scrum?". Disponible en: [https://aws.amazon.com/what-is/scrum/](https://aws.amazon.com/what-is/scrum/)

[^15]: "Scrum Project Management: Advantages and Disadvantages". Disponible en: [https://www.simplilearn.com/scrum-project-management-article](https://www.simplilearn.com/scrum-project-management-article)

[^16]: "Scrum Methodology: Advantages, Disadvantages, and Ways of Handling Possible Issues". Disponible en: [https://www.epicflow.com/blog/the-scrum-framework-advantages-disadvantages-and-ways-of-handling-possible-issues/](https://www.epicflow.com/blog/the-scrum-framework-advantages-disadvantages-and-ways-of-handling-possible-issues/)

[^17]: "When To Use Scrum?". Disponible en: [https://www.simpliaxis.com/resources/when-to-use-scrum](https://www.simpliaxis.com/resources/when-to-use-scrum)

[^18]: "What Is Kanban Methodology? The Ultimate Guide". Disponible en: [https://www.wrike.com/kanban-guide/what-is-kanban/](https://www.wrike.com/kanban-guide/what-is-kanban/)

[^19]: "What is Scrum?". Disponible en: [https://www.scrum.org/resources/what-scrum-module](https://www.scrum.org/resources/what-scrum-module)

[^20]: "What is a Kanban Board?". Disponible en: [https://tcard.leantransitionsolutions.com/tcard-kanban-boards](https://tcard.leantransitionsolutions.com/tcard-kanban-boards)

[^21]: "Why Use Kanban Boards?". Disponible en: [https://www.planview.com/resources/guide/introduction-to-kanban/use-kanban-boards/](https://www.planview.com/resources/guide/introduction-to-kanban/use-kanban-boards/)

[^22]: "Kanban". Disponible en: [https://www.atlassian.com/agile/kanban](https://www.atlassian.com/agile/kanban)

[^23]: "Pros & Cons of the Kanban Method in Project Management". Disponible en: [https://www.workamajig.com/blog/kanban-methodology-guide/pros-cons-kanban-method](https://www.workamajig.com/blog/kanban-methodology-guide/pros-cons-kanban-method)

[^24]: "Kanban Methodology: Advantages and Disadvantages in Project Management". Disponible en: [https://www.agilefever.com/blog/Kanban-Methodology-Advantages-and-Disadvantages-in-Project-Management/](https://www.agilefever.com/blog/Kanban-Methodology-Advantages-and-Disadvantages-in-Project-Management/)

[^25]: "Kanban vs Scrum: Which methodology is right for you?". Disponible en: [https://www.zoho.com/sprints/kanban-vs-scrum.html](https://www.zoho.com/sprints/kanban-vs-scrum.html)

[^26]: "Scrum VS Kanban". Disponible en: [https://resources.scrumalliance.org/Article/scrum-vs-kanban](https://resources.scrumalliance.org/Article/scrum-vs-kanban)

[^27]: "Agile Marketing Examples & Case Studies". Disponible en: [https://www.agilesherpas.com/blog/agile-marketing-examples-case-studies#:~:text=Teratada:%20Automated%20approvals%20and%20workflows,in%20a%20Swedish%20Success%20Story](https://www.agilesherpas.com/blog/agile-marketing-examples-case-studies#:~:text=Teratada:%20Automated%20approvals%20and%20workflows,in%20a%20Swedish%20Success%20Story)

[^28]: "How IBM leveraged Jira Data Center to build a foundation for the future". Disponible en: [https://www.atlassian.com/blog/jira/how-ibm-built-a-future-with-jira-data-center](https://www.atlassian.com/blog/jira/how-ibm-built-a-future-with-jira-data-center)

[^29]: "How to use IBM® App Connect with Confluence". Disponible en: [https://www.ibm.com/docs/en/app-connect/12.0?topic=apps-confluence](https://www.ibm.com/docs/en/app-connect/12.0?topic=apps-confluence)

[^31]: "How to use IBM App Connect with Trello". Disponible en: [https://www.ibm.com/docs/en/app-connect/12.0?topic=apps-trello](https://www.ibm.com/docs/en/app-connect/12.0?topic=apps-trello)

[^31]: "Amazon Project Management Best Practice". Disponible en: [https://www.projectmanagertemplate.com/post/amazon-project-management-best-practice#:~:text=Amazon%20incorporates%20Agile%20and%20Scrum,track%20progress%20and%20improve%20collaboration.](https://www.projectmanagertemplate.com/post/amazon-project-management-best-practice#:~:text=Amazon%20incorporates%20Agile%20and%20Scrum,track%20progress%20and%20improve%20collaboration.)
