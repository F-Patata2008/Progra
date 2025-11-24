import estructura

# Definición de la estructura
estructura.mutable("animal", "identificador especie listaAvistamientos")

# Variable de estado global
lista_animales = []

# ----------------------------------------------------------------------------
# cargarAnimales : str -> None
# Propósito: Lee un archivo con formato "ID,especie" y llena la variable de
#            estado 'lista_animales' con estructuras 'animal' que tienen
#            una lista de avistamientos vacía inicialmente.
# Ejemplo:
#   Suponga un archivo "test_animales.txt" con:
#       1,ciervo
#   Al llamar cargarAnimales("test_animales.txt"), lista_animales contendrá:
#       [animal(identificador='1', especie='ciervo', listaAvistamientos=[])]
def cargarAnimales(nombreArchivo):
    global lista_animales
    lista_animales = [] # Reiniciar para evitar duplicados en tests
    
    archivo = open(nombreArchivo, "r", encoding="utf-8")
    for linea in archivo:
        linea = linea.strip()
        if linea != "":
            partes = linea.split(",")
            ident = partes[0]
            esp = partes[1]
            nuevo = animal(ident, esp, [])
            lista_animales.append(nuevo)
    archivo.close()


# ----------------------------------------------------------------------------
# agregarAvistamientos : str -> None
# Propósito: Lee un archivo con avistamientos "Puesto,ID,Fecha,Hora" y agrega
#            esta información a la lista de avistamientos del animal
#            correspondiente en la variable de estado global.
# Ejemplo:
#   Si lista_animales tiene un animal con ID '1'.
#   Y el archivo "test_avis.txt" tiene: Puesto1,1,2025-10-15,10:00
#   Al ejecutar agregarAvistamientos("test_avis.txt"), el animal ID '1' tendrá:
#       listaAvistamientos=['Puesto1,2025-10-15,10:00']
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
            
            for a in lista_animales:
                if a.identificador == ident:
                    a.listaAvistamientos.append(avist)
                    break
    archivo.close()


# ----------------------------------------------------------------------------
# zonaMasProbable : str int -> str
# Propósito: Dada una especie y una hora (entero HH), retorna el puesto de
#            observación (moda) donde más se ha avistado esa especie a esa hora.
#            Retorna "No hay datos suficientes" si no hay registros.
# Ejemplos:
#   zonaMasProbable("ciervo", 14) -> "Puesto7"
#   zonaMasProbable("unicornio", 10) -> "No hay datos suficientes"
def zonaMasProbable(especieAnimal, hora):
    puestos = []
    
    for a in lista_animales:
        if a.especie == especieAnimal:
            for av in a.listaAvistamientos:
                partes = av.split(",") 
                puesto = partes[0]
                hora_str = partes[2] # HH:MM
                
                h = int(hora_str.split(":")[0])
                
                if h == hora:
                    puestos.append(puesto)
    
    if len(puestos) == 0:
        return "No hay datos suficientes"
    
    # Calcular moda manualmente
    mas_comun = puestos[0]
    max_rep = 0
    
    # Obtener unicos para iterar menos
    unicos = []
    for p in puestos:
        if p not in unicos:
            unicos.append(p)
            
    for p in unicos:
        c = puestos.count(p)
        if c > max_rep:
            max_rep = c
            mas_comun = p
            
    return mas_comun


# ----------------------------------------------------------------------------
# corregirHora : None -> None
# Propósito: Modifica la variable de estado corrigiendo los avistamientos
#            posteriores al 19 de Octubre de 2025, restando 1 hora.
#            Maneja el cambio de día (00:00 -> 23:00 del día anterior).
# Ejemplo:
#   Si existe un avistamiento "...,2025-10-20,13:00" -> cambia a "...,2025-10-20,12:00"
#   Si existe un avistamiento "...,2025-10-20,00:30" -> cambia a "...,2025-10-19,23:30"
def corregirHora():
    global lista_animales
    fecha_limite = "2025-10-19"
    
    for a in lista_animales:
        for i in range(len(a.listaAvistamientos)):
            av = a.listaAvistamientos[i]
            partes = av.split(",")
            
            puesto = partes[0]
            fecha  = partes[1]
            hora   = partes[2]
            
            if fecha > fecha_limite:
                hh, mm_str = hora.split(":")
                hh = int(hh)
                
                hh = hh - 1
                
                nueva_fecha = fecha
                
                # Caso borde: cambio de día
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
                    
                    # Formateo manual
                    s_mes = str(mes)
                    if mes < 10: s_mes = "0" + s_mes
                    s_dia = str(dia)
                    if dia < 10: s_dia = "0" + s_dia
                    nueva_fecha = str(anio) + "-" + s_mes + "-" + s_dia
                
                s_hh = str(hh)
                if hh < 10: s_hh = "0" + s_hh
                
                nueva_hora = s_hh + ":" + mm_str
                
                a.listaAvistamientos[i] = puesto + "," + nueva_fecha + "," + nueva_hora


# ----------------------------------------------------------------------------
# Test
def test():
    # 1. Cargar datos
    cargarAnimales("animales.txt")
    print("Test cargarAnimales: OK (Total cargados: " + str(len(lista_animales)) + ")")
    
    # 2. Cargar avistamientos
    agregarAvistamientos("avistamientos.txt")
    print("Test agregarAvistamientos: OK")
    
    # 3. Test Zona
    z = zonaMasProbable("condor", 10)
    print("Test zonaMasProbable('condor', 10): " + z)
    
    # 4. Corregir Hora
    corregirHora()
    print("Test corregirHora: Ejecutado sin errores.")

if __name__ == "__main__":
    test()
