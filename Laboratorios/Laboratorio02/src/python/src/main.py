# -------------------------------------------------------------------------
# Examen Parcial II: Principios de informática
# Kristhel Daniela Quesada López, C06153
# Prof. Dany Vargas
# Algoritmo: Lector de archivos sismológicos
# -------------------------------------------------------------------------

class Sismo:
    """
    Clase que representa un sismo con sus características principales.

    :param identificacion: ID del sismo
    :type identificacion: str
    :param fecha: Fecha del sismo en formato YYYY-MM-DD
    :type fecha: str
    :param hora: Hora del sismo
    :type hora: str
    :param magnitud: Magnitud del sismo en la escala de Richter
    :type magnitud: float
    :param profundidad: Profundidad del sismo en kilómetros
    :type profundidad: float
    :param locacion: Ubicación del epicentro
    :type locacion: str
    """
    def __init__(self, identificacion, fecha, hora, magnitud, profundidad, locacion):
        self.identificacion = identificacion
        self.fecha = fecha
        self.hora = hora
        self.magnitud = float(magnitud)
        self.profundidad = float(profundidad)
        self.locacion = locacion
        self.intensidad = 0.0
        self.vector = []

    def fix_fechaError(self):
        """
        Corrige el formato de la fecha si el mes tiene un cero a la izquierda.
        """
        if self.fecha[5] == "0":
            posicion = 5
            if len(self.fecha) > posicion:
                self.fecha = self.fecha[0:posicion] + self.fecha[posicion + 1:]

    def calcular_intensidad(self):
        """
        Calcula la intensidad del sismo como magnitud/profundidad.
        """
        intensidad = float(self.magnitud / self.profundidad)
        self.intensidad += round(intensidad, 3)

    def buscar_por_fecha(self, anio, mes, dia):
        """
        Verifica si el sismo ocurrió en una fecha específica.

        :param anio: Año a buscar
        :type anio: int
        :param mes: Mes a buscar
        :type mes: int
        :param dia: Día a buscar
        :type dia: int
        :return: True si la fecha coincide, False en caso contrario
        :rtype: bool
        """
        self.fix_fechaError()
        fecha = "{0}-{1}-{2}".format(anio, mes, dia)
        return fecha == self.fecha

    def __repr__(self):
        """
        Devuelve una representación en cadena del sismo.

        :return: Representación legible del sismo
        :rtype: str
        """
        return "A las {0}, se registró un sismo de magnitud {1} en escala Richter y profundidad {2} km en {3}".format(
            self.hora, self.magnitud, self.profundidad, self.locacion)

    def hacer_vector(self):
        """
        Crea un vector con los datos principales del sismo.
        """
        self.fix_fechaError()
        self.vector.append(self.fecha)
        self.vector.append(self.hora)
        self.vector.append(self.magnitud)
        self.vector.append(self.profundidad)
        self.calcular_intensidad()
        self.vector.append(self.intensidad)
        self.vector.append(self.locacion)

    # Métodos GET con docstrings

    def get_fecha(self):
        """
        :return: Fecha del sismo
        :rtype: str
        """
        return self.fecha

    def get_hora(self):
        """
        :return: Hora del sismo
        :rtype: str
        """
        return self.hora

    def get_magnitud(self):
        """
        :return: Magnitud del sismo
        :rtype: float
        """
        return self.magnitud

    def get_profundidad(self):
        """
        :return: Profundidad del sismo
        :rtype: float
        """
        return self.profundidad

    def get_locacion(self):
        """
        :return: Locación del sismo
        :rtype: str
        """
        return self.locacion

    def get_intensidad(self):
        """
        :return: Intensidad calculada del sismo
        :rtype: float
        """
        self.calcular_intensidad()
        return self.intensidad

    def get_vector(self):
        """
        :return: Vector con la información del sismo
        :rtype: list
        """
        self.hacer_vector()
        return self.vector



#___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___


class Lector:
    """
    Clase encargada de leer archivos de sismos, procesar sus datos y brindar estadísticas.
    """

    def __init__(self):
        """
        Constructor que inicializa los vectores y el promedio de intensidades.
        """
        self.vector_sismos = []
        self.vector_intensidades = []
        self.promedio_intensidades = 0

    def solicitar_numero(self, mensaje):
        """
        Solicita al usuario un número entero válido mayor o igual a cero.

        :param mensaje: Texto que se mostrará al usuario como mensaje de entrada
        :type mensaje: str
        :return: Número ingresado por el usuario
        :rtype: int
        """
        numero_valido = False

        while not numero_valido:
            try:
                numero = int(input(mensaje))
                if numero < 0:
                    print("Ingrese un número correcto.")
                else:
                    return numero
            except:
                print("Por favor ingrese un número válido.")

    def abrir_archivo(self):
        """
        Solicita al usuario el nombre del archivo y lo abre.

        :return: Archivo abierto en modo lectura
        :rtype: _io.TextIOWrapper
        """
        datoValido = False

        while not datoValido:
            try:
                nombre = input("Ingrese el nombre del archivo: ")
                archivo = open(nombre + ".tsv", "r")
                datoValido = True
            except:
                print("Por favor ingrese un nombre de archivo válido.\n")

        return archivo

    def crear_vector(self, archivo):
        """
        Crea el vector de objetos Sismo a partir del archivo abierto.

        :param archivo: Archivo abierto que contiene los datos de los sismos
        :type archivo: _io.TextIOWrapper
        """
        vector_base = []

        for linea in archivo:
            if str.isdigit(linea[1]):
                vector_base.append(linea.split())

        locacion = ""
        for sismo in vector_base:
            elementos_xvector = len(sismo)
            for posicion in range(5, elementos_xvector):
                if posicion != (elementos_xvector - 1):
                    locacion += sismo[posicion] + " "
                else:
                    locacion += sismo[posicion]

            sismo_obj = Sismo(sismo[0], sismo[1], sismo[2], sismo[3], sismo[4], locacion)
            self.vector_sismos.append(sismo_obj)
            locacion = ""

    def retornar_max_sismo(self, archivo):
        """
        Busca el sismo de mayor intensidad para una fecha específica ingresada por el usuario.

        :param archivo: Archivo con los datos de los sismos
        :type archivo: _io.TextIOWrapper
        """
        vector_fecha = []
        vector_intensidades = []
        self.crear_vector(archivo)

        anio = self.solicitar_numero("\nIngrese año: ")
        mes = self.solicitar_numero("Ingrese mes: ")
        dia = self.solicitar_numero("Ingrese día: ")

        for sismo in self.vector_sismos:
            if sismo.buscar_por_fecha(anio, mes, dia):
                vector_fecha.append(sismo)

        if len(vector_fecha) != 0:
            posicion = 0
            for _ in range(len(vector_fecha)):
                for sismo in self.vector_sismos:
                    if sismo == vector_fecha[posicion]:
                        intensity = sismo.get_intensidad()
                        vector_intensidades.append(intensity)
                posicion += 1

            maxima = max(vector_intensidades)
            for contador, intensidad in enumerate(vector_intensidades):
                if intensidad == maxima:
                    vector_final = vector_fecha[contador]
                    print(vector_final)
        else:
            print("No hay sismos registrados para ese día")

    def calcular_promedio(self, archivo):
        """
        Calcula el promedio de la intensidad de todos los sismos registrados en el archivo.

        :param archivo: Archivo con los datos de los sismos
        :type archivo: _io.TextIOWrapper
        """
        self.crear_vector(archivo)

        for sismo in self.vector_sismos:
            intensity = sismo.get_intensidad()
            self.vector_intensidades.append(intensity)

        acumulado = sum(self.vector_intensidades)
        self.promedio_intensidades += acumulado / len(self.vector_intensidades)

    def menu(self):
        """
        Muestra el menú principal y solicita al usuario una opción válida.

        :return: Opción seleccionada por el usuario
        :rtype: int
        """
        numero_valido = False

        while not numero_valido:
            try:
                print("\nSeleccione la opción que desea realizar:\n"
                      "1. Más fuerte de un día.\n"
                      "2. Intensidad promedio.\n"
                      "0. Salir.")
                opcion = int(input("Opción: "))
                if 0 <= opcion <= 2:
                    return opcion
                else:
                    print("Por favor digite una opción válida.")
            except:
                print("Por favor ingrese una opción válida")

    def controlador(self):
        """
        Controlador principal del programa. Administra el flujo de interacción con el usuario.
        """
        detener = False
        archivo = self.abrir_archivo()
        self.calcular_promedio(archivo)

        while not detener:
            opcion = self.menu()

            if opcion == 1:
                self.retornar_max_sismo(archivo)
            elif opcion == 2:
                promedio = self.get_promedio()
                print(promedio)
            elif opcion == 0:
                detener = True
                print("¡Gracias por utilizar mi programa!")

    def get_vector_sismos(self):
        """
        :return: Vector con objetos de tipo Sismo leídos desde el archivo
        :rtype: list
        """
        archivo = self.abrir_archivo()
        self.crear_vector(archivo)
        return self.vector_sismos

    def get_promedio(self):
        """
        :return: Cadena con el promedio de intensidades de los sismos
        :rtype: str
        """
        return "La intensidad promedio de los sismos registrados es {} grados/km".format(
            round(self.promedio_intensidades, 3))


def main():
    """
    Función principal del programa.

    Se encarga de iniciar la ejecución del sistema sismológico,
    creando una instancia de la clase `Lector` y llamando al controlador
    principal para gestionar el flujo del programa.
    """
    print("BIENVENIDO A LA RED SISMOLÓGICA NACIONAL\n")
    lectura = Lector()
    lectura.controlador()


if __name__ == "__main__":
    main()
