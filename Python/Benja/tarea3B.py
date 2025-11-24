# ----------------------------------------------------------------------------
# Clase Especie
# Representa una especie en la reserva.
# Atributos:
#   - nombre (str): Nombre de la especie.
#   - ids (list): Lista de IDs (str) asociados a esta especie.
#   - avistamientos (list): Lista de avistamientos (str) "Puesto,Fecha,Hora".
class Especie:
    
    # __init__ : str -> Especie
    # Propósito: Inicializa un objeto Especie con nombre y listas vacías.
    def __init__(self, nombre):
        self.nombre = nombre
        self.ids = []
        self.avistamientos = []

    # obtenerNombre : None -> str
    # Propósito: Retorna el nombre de la especie.
    # Ejemplo: esp.obtenerNombre() -> "ciervo"
    def obtenerNombre(self):
        return self.nombre

    # obtenerIDs : None -> list
    # Propósito: Retorna la lista de IDs asociados.
    # Ejemplo: esp.obtenerIDs() -> ["1", "4"]
    def obtenerIDs(self):
        return self.ids

    # agregarID : str -> None
    # Propósito: Agrega un ID a la lista si no existe previamente.
    # Ejemplo: esp.agregarID("10")
    def agregarID(self, ident):
        if ident not in self.ids:
            self.ids.append(ident)

    # agregarAvistamiento : str -> None
    # Propósito: Agrega un string de avistamiento a la lista.
    # Ejemplo: esp.agregarAvistamiento("Puesto1,2025-10-15,10:00")
    def agregarAvistamiento(self, avist):
        self.avistamientos.append(avist)

    # zonaMasProbable : int -> str
    # Propósito: Retorna el puesto (moda) donde más se ha avistado esta especie
    #            a la hora dada.
    # Ejemplo: ciervo_obj.zonaMasProbable(14) -> "Puesto7"
    def zonaMasProbable(self, hora):
        puestos = []
        for av in self.avistamientos:
            partes = av.split(",")
            puesto = partes[0]
            hora_str = partes[2]
            h = int(hora_str.split(":")[0])
            
            if h == hora:
                puestos.append(puesto)

        if len(puestos) == 0:
            return "No hay datos suficientes"

        mas_comun = puestos[0]
        max_rep = 0
        
        unicos = []
        for p in puestos:
            if p not in unicos: unicos.append(p)

        for p in unicos:
            rep = puestos.count(p)
            if rep > max_rep:
                max_rep = rep
                mas_comun = p

        return mas_comun


# Variable de estado global
lista_especies = []


# ----------------------------------------------------------------------------
# cargarEspecies : str -> None
# Propósito: Lee el archivo "ID,especie", crea objetos Especie únicos en
#            lista_especies y asigna los IDs correspondientes.
# Ejemplo: cargarEspecies("animales.txt")
def cargarEspecies(nombreArchivo):
    global lista_especies
    lista_especies = []
    
    archivo = open(nombreArchivo, "r", encoding="utf-8")
    for linea in archivo:
        linea = linea.strip()
        if linea != "":
            partes = linea.split(",")
            ident = partes[0]
            nombre_esp = partes[1]

            objeto_encontrado = None
            for e in lista_especies:
                if e.obtenerNombre() == nombre_esp:
                    objeto_encontrado = e
                    break
            
            if objeto_encontrado is None:
                objeto_encontrado = Especie(nombre_esp)
                lista_especies.append(objeto_encontrado)
            
            objeto_encontrado.agregarID(ident)
    archivo.close()


# ----------------------------------------------------------------------------
# agregarAvistamientos : str -> None
# Propósito: Lee archivo de avistamientos y los agrega al objeto Especie
#            que contenga el ID del animal avistado.
# Ejemplo: agregarAvistamientos("avistamientos.txt")
def agregarAvistamientos(nombreArchivo):
    archivo = open(nombreArchivo, "r", encoding="utf-8")
    for linea in archivo:
        linea = linea.strip()
        if linea != "":
            partes = linea.split(",")
            puesto = partes[0]
            ident  = partes[1]
            fecha  = partes[2]
            hora   = partes[3]

            avist = puesto + "," + fecha + "," + hora

            for esp in lista_especies:
                if ident in esp.obtenerIDs():
                    esp.agregarAvistamiento(avist)
                    break
    archivo.close()


# ----------------------------------------------------------------------------
# corregirHora : None -> None
# Propósito: Recorre todos los objetos Especie y corrige sus avistamientos
#            posteriores al 19-Oct, restando una hora.
# Ejemplo: corregirHora() modifica los objetos en lista_especies.
def corregirHora():
    fecha_limite = "2025-10-19"
    for esp in lista_especies:
        for i in range(len(esp.avistamientos)):
            av = esp.avistamientos[i]
            partes = av.split(",")
            
            puesto = partes[0]
            fecha  = partes[1]
            hora   = partes[2]

            if fecha > fecha_limite:
                hh, mm_str = hora.split(":")
                hh = int(hh)
                hh = hh - 1
                
                nueva_fecha = fecha
                if hh < 0:
                    hh = 23
                    f_split = fecha.split("-")
                    anio = int(f_split[0])
                    mes  = int(f_split[1])
                    dia  = int(f_split[2])
                    dia = dia - 1
                    
                    if dia == 0:
                        mes = mes - 1
                        if mes == 0:
                            mes = 12
                            anio = anio - 1
                        dias_mes = [0,31,28,31,30,31,30,31,31,30,31,30,31]
                        dia = dias_mes[mes]
                    
                    s_mes = str(mes)
                    if mes < 10: s_mes = "0" + s_mes
                    s_dia = str(dia)
                    if dia < 10: s_dia = "0" + s_dia
                    nueva_fecha = str(anio) + "-" + s_mes + "-" + s_dia
                
                s_hh = str(hh)
                if hh < 10: s_hh = "0" + s_hh
                
                nueva_hora = s_hh + ":" + mm_str
                esp.avistamientos[i] = puesto + "," + nueva_fecha + "," + nueva_hora


# ----------------------------------------------------------------------------
# Test
def test():
    cargarEspecies("animales.txt")
    print("Test cargarEspecies: OK (" + str(len(lista_especies)) + " especies creadas)")
    
    agregarAvistamientos("avistamientos.txt")
    print("Test agregarAvistamientos: OK")
    
    # Buscar un objeto para probar el método
    obj_prueba = None
    for e in lista_especies:
        if e.nombre == "puma":
            obj_prueba = e
            break
            
    if obj_prueba:
        res = obj_prueba.zonaMasProbable(10)
        print("Test metodo zonaMasProbable('puma', 10): " + res)
        
    corregirHora()
    print("Test corregirHora: Ejecutado.")

if __name__ == "__main__":
    test()
