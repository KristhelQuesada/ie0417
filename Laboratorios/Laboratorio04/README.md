# Laboratorio 04: Patrones de diseño

### Tabla de contenidos

1. [Máquina expendedora](#1-máquina-expendedora)
2. [App de bebidas personalizadas (tipo Starbucks)](#2-app-de-bebidas-personalizadas-tipo-starbucks)
3. [Sistema tipo Pingdom con monitoreo de sitios web](#3-sistema-tipo-pingdom-con-monitoreo-de-sitios-web)

<br>

<br>

## 1. Máquina expendedora

### Problema
Diseñar una máquina expendedora que permita seleccionar productos, ver el precio, aceptar monedas o billetes, entregar el producto, devolver cambio, reembolsar, cancelar la transacción y manejar errores como producto agotado o falta de cambio. La pregunta puede verse en el siguiente enlace: [Design a vending machine](https://leetcode.com/discuss/post/125218/design-a-vending-machine-by-stefansfan-6m5j/)


### Patrones propuestos
- `State`
- `Strategy`
- `Command`

### Justificación
El problema de diseñar una máquina expendedora implica gestionar múltiples comportamientos que cambian en función del estado del sistema: aceptar dinero, permitir la selección del producto, dispensar, devolver cambio, y manejar errores como producto agotado o pago insuficiente. Por tanto, se considera posible aplicar una combinación de patrones de diseño para abordar las distintas responsabilidades del sistema de forma modular y extensible, aunque siempre se recomienda tener en cuenta el valor sobre la complejidad.

#### `State`

> El patrón State permite que un objeto modifique su comportamiento cuando cambia su estado interno, eliminando condicionales extensos y facilitando la transición entre estados. En el contexto de una máquina expendedora, cada fase del proceso —esperando pago, seleccionando producto, procesando compra, o error— puede modelarse como un estado independiente. Esto permite que el sistema delegue la lógica del comportamiento a clases específicas de estado, manteniendo el código limpio y abierto a nuevas extensiones sin modificar las clases existentes.
>
> Por ejemplo, si la máquina se encuentra en estado "Esperando dinero", solo aceptará monedas o billetes. Una vez alcanzado el monto, transita al estado "Esperando selección", donde se habilita la elección del producto. Cada estado encapsula sus propias reglas y responde solo a las operaciones válidas para ese momento.

#### `Strategy`

> El patrón Strategy es útil cuando se tienen múltiples algoritmos o procesos intercambiables que deben aplicarse en diferentes momentos. En este caso, los métodos de pago (monedas, billetes, tarjetas, apps) pueden encapsularse como estrategias concretas que comparten una misma interfaz. Esto permite cambiar dinámicamente el tipo de pago sin modificar el resto del sistema, cumpliendo con el principio de abierto/cerrado.
>
> Por ejemplo, si se quiere agregar soporte para pagos por código QR, se puede implementar una nueva estrategia de pago sin necesidad de alterar el código de lógica central de la máquina.

#### `Command`
> El patrón Command encapsula una solicitud como un objeto, permitiendo parametrizar acciones, almacenar un historial de operaciones o ejecutar comandos remotos. En el diseño de una máquina expendedora, cada acción del usuario (como seleccionar un producto, insertar dinero, solicitar reembolso o cancelar) puede representarse como un comando. Esto permite que el sistema sea desacoplado de las acciones concretas, y facilita la implementación de funcionalidades adicionales como deshacer operaciones, log de eventos, o incluso control por interfaz gráfica o remota.

### Implementación (Python)
<details>
<summary>Ver implementación en Python</summary>

<br> 

- A continuación, se plantea únicamente el pseudocodigo de algunas funcionalidades de la máquina expendedora bajo el patrón de **State** únicamente.

```python
class Estado:
    def insertar_dinero(self, monto): pass
    def seleccionar_producto(self): pass
    def dispensar(self): pass

class EsperandoPago(Estado):
    def insertar_dinero(self, monto):
        print("Dinero recibido:", monto)
        return EsperandoSeleccion()

class EsperandoSeleccion(Estado):
    def seleccionar_producto(self):
        print("Producto seleccionado.")
        return Entregando()

class Entregando(Estado):
    def dispensar(self):
        print("Producto dispensado.")
        return EsperandoPago()

class MaquinaExpendedora:
    def __init__(self):
        self.estado = EsperandoPago()

    def insertar_dinero(self, monto):
        self.estado = self.estado.insertar_dinero(monto)

    def seleccionar_producto(self):
        self.estado = self.estado.seleccionar_producto()

    def dispensar(self):
        self.estado = self.estado.dispensar()
```
</details>

<br> </br>

## 2. App de bebidas personalizadas (tipo Starbucks)

### Problema
Diseñar una aplicación backend que permita crear bebidas base (por ejemplo: café, té, matcha) con múltiples personalizaciones opcionales como leche, crema, jarabes, toppings, etc. Cada cliente puede construir su bebida de forma única, por lo que la estructura debe ser flexible, extensible y permitir la combinación dinámica de funcionalidades sin crear una explosión de subclases. Puede ver el enunciado del problema en el siguiente enlace: [How to create order for Starbucks coffee | System Design Question | Need Help?](https://leetcode.com/discuss/post/4258301/how-to-create-order-for-starbucks-coffee-8l0p/)

### Patrón propuesto
- `Decorator`

### Justificación
#### `Decorator`
> El patrón Decorator permite agregar funcionalidad a objetos individuales de manera dinámica sin alterar su clase. En este caso, una bebida básica (como un café americano o espresso) puede envolverse sucesivamente con nuevos comportamientos (leche, azúcar, caramelo, etc.). Cada decorador representa una característica adicional, y todos comparten una interfaz común que permite calcular el costo final y generar una descripción compuesta de la bebida.
> 
> Este patrón resulta adecuado cuando las combinaciones son impredecibles en tiempo de compilación, y se requiere mantener abiertas las extensiones sin modificar las clases base. Facilita la escalabilidad en sistemas donde nuevas opciones se introducen con frecuencia, ya que cada nueva personalización se modela como un decorador adicional.

### Implementación (Python)
<details>
<summary>Ver implementación en Python</summary>

```python
# Componente base
class Bebida:
    def descripcion(self):
        return "Bebida"

    def costo(self):
        return 0.0

# Componentes concretos
class Espresso(Bebida):
    def descripcion(self):
        return "Espresso"

    def costo(self):
        return 3.0

class TeVerde(Bebida):
    def descripcion(self):
        return "Té Verde"

    def costo(self):
        return 2.5

# Decoradores
class DecoradorBebida(Bebida):
    def __init__(self, bebida):
        self.bebida = bebida

class Leche(DecoradorBebida):
    def descripcion(self):
        return self.bebida.descripcion() + " + Leche"

    def costo(self):
        return self.bebida.costo() + 0.5

class Crema(DecoradorBebida):
    def descripcion(self):
        return self.bebida.descripcion() + " + Crema"

    def costo(self):
        return self.bebida.costo() + 0.7

class JarabeVainilla(DecoradorBebida):
    def descripcion(self):
        return self.bebida.descripcion() + " + Jarabe de Vainilla"

    def costo(self):
        return self.bebida.costo() + 0.6

# Uso del sistema
bebida = JarabeVainilla(Crema(Leche(Espresso())))
print(bebida.descripcion())  # Espresso + Leche + Crema + Jarabe de Vainilla
print("Precio:", bebida.costo())  # Precio: 4.8
```
</details>

<br> </br>


## Sistema tipo Pingdom con monitoreo de sitios web

### Problema
Pingdom es una herramienta de monitoreo de disponibilidad y rendimiento de sitios web. Su propósito principal es verificar periódicamente que los servicios web se encuentren en línea y funcionando correctamente, alertando a los responsables cuando se detecta una caída o lentitud significativa.

El objetivo es diseñar un sistema que replique las funcionalidades básicas de Pingdom: debe monitorear periódicamente el estado de múltiples sitios web registrados por distintos clientes, cuyos planes de suscripción determinan la frecuencia con la que se realizan los chequeos (por ejemplo, cada 1 minuto, 5 minutos o más). Además, el sistema debe detectar automáticamente cuándo un sitio deja de estar disponible (caída) o vuelve a estar activo, y generar notificaciones en tiempo real hacia los usuarios afectados. Finalmente, toda la información recolectada —como tiempos de respuesta, historial de actividad, frecuencia de caídas— debe poder visualizarse de forma estructurada, como dashboards o reportes detallados. Puede encontrar el enunciado en: [Design Pingdom | System design interview question](https://leetcode.com/discuss/post/5607927/design-pingdom-system-design-interview-q-9yd0/)

### Patrones propuestos
- `Observer` 
- `Strategy` 
- `Builder`

### Justificación
#### `Observer`

> El patrón Observer resulta esencial para desacoplar el sistema de monitoreo del sistema de notificación. Cada vez que se detecta un cambio de estado en un sitio (por ejemplo, al pasar de “activo” a “caído”), el sistema debe notificar a los observadores suscritos, que pueden ser módulos encargados de enviar emails, notificaciones push o registrar eventos para análisis posterior. De esta forma, este patrón es útil ya que:
> 1. Permite notificar a múltiples módulos (usuarios, logs, sistemas externos) sin acoplarse directamente a ellos.
> 2. Facilita la incorporación de nuevos canales de alerta sin modificar el núcleo del sistema de monitoreo.
> 3. Implementa una arquitectura reactiva ante cambios en el estado de los sitios web.

<br>

#### `Strategy`

> El patrón Strategy permite encapsular las diferentes políticas de chequeo que dependen del plan de suscripción del cliente (por ejemplo, chequeos cada 1, 5 o 10 minutos). Cada plan puede definir su propia lógica de temporización, y se puede seleccionar la estrategia adecuada en tiempo de ejecución, según el cliente.
> 1. Separa el qué hacer del cómo hacerlo, en este caso, separando el proceso de chequeo del intervalo con que se ejecuta.
> 1. Facilita extender o modificar los algoritmos de planificación sin alterar la lógica del monitor.
> 1. Mejora la mantenibilidad en sistemas con múltiples niveles de servicio.

<br>

#### `Builder`

> En escenarios donde se necesite crear reportes o dashboards personalizables por el usuario (por ejemplo, seleccionar qué sitios mostrar, rango de fechas, métricas a incluir), el patrón Builder puede emplearse para construir estos objetos complejos paso a paso. De esta forma es útil porque: 
> 1. Permite configurar reportes de forma flexible y con múltiples combinaciones válidas.
> 2. Mejora la separación entre la lógica de visualización y el modelo de datos subyacente.

### Implementación (Python)
<details>
<summary>Ver implementación en Python</summary>

```python
# Observer Pattern

class Observador:
    def actualizar(self, estado):
        pass

class Cliente(Observador):
    def __init__(self, nombre):
        self.nombre = nombre

    def actualizar(self, estado):
        print(f"[{self.nombre}] Notificación: Sitio {estado}")

# Sujeto (sitio monitoreado)
class SitioWeb:
    def __init__(self, url):
        self.url = url
        self.estado = "Desconocido"
        self.observadores = []

    def agregar_observador(self, obs):
        self.observadores.append(obs)

    def notificar(self):
        for obs in self.observadores:
            obs.actualizar(self.estado)

    def verificar_estado(self, nuevo_estado):
        if nuevo_estado != self.estado:
            self.estado = nuevo_estado
            self.notificar()

# Strategy Pattern

class EstrategiaChequeo:
    def ejecutar(self, sitio):
        pass

class FrecuenciaAlta(EstrategiaChequeo):
    def ejecutar(self, sitio):
        print(f"Chequeo frecuente a {sitio.url} cada 30s")

class FrecuenciaBaja(EstrategiaChequeo):
    def ejecutar(self, sitio):
        print(f"Chequeo a {sitio.url} cada 5min")

# Builder Pattern

class ConfiguracionMonitoreo:
    def __init__(self, cliente, sitio, estrategia):
        self.cliente = cliente
        self.sitio = sitio
        self.estrategia = estrategia

    def iniciar(self):
        self.sitio.agregar_observador(self.cliente)
        self.estrategia.ejecutar(self.sitio)

class MonitoreoBuilder:
    def __init__(self):
        self.cliente = None
        self.sitio = None
        self.estrategia = None

    def con_cliente(self, cliente):
        self.cliente = cliente
        return self

    def con_sitio(self, sitio):
        self.sitio = sitio
        return self

    def con_estrategia(self, estrategia):
        self.estrategia = estrategia
        return self

    def construir(self):
        return ConfiguracionMonitoreo(self.cliente, self.sitio, self.estrategia)

# Uso
cliente = Cliente("Empresa XYZ")
sitio = SitioWeb("https://xyz.com")
estrategia = FrecuenciaAlta()

monitoreo = MonitoreoBuilder().con_cliente(cliente).con_sitio(sitio).con_estrategia(estrategia).construir()
monitoreo.iniciar()

# Simulación de cambio de estado
sitio.verificar_estado("Caído")
```
</details>

<br> </br>
