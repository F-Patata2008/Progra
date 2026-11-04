# promedios : str -> None
def promedios(nombre):
    lector = open(nombre, "r")
    escritor = open("promedios.txt", "w")
    for linea in lector:
        if linea[-1] == "\n":
            linea = linea[:-1]
        lista = linea.split(",")
        suma = 0
        for num in lista:
            suma += int(num)
        prom = suma / len(lista)
        escritor.write(str(prom) + "\n")
    escritor.close()
    lector.close()


# separar : str -> None
def separar(nombre):
    lector = open(nombre, "r")
    pos = open("positivos.txt", "w")
    neg = open("negativos.txt", "w")
    for linea in lector:
        if linea[-1] == "\n":
            linea = linea[:-1]
        lista = linea.split(",")
        lineaPos = ""
        lineaNeg = ""
        for num in lista:
            if int(num) < 0:
                lineaNeg += num + ","
            else:
                lineaPos += num + ","
        if len(lineaPos) > 0 and lineaPos[-1] == ",":
            lineaPos = lineaPos[:-1]
        if len(lineaNeg) > 0 and lineaNeg[-1] == ",":
            lineaNeg = lineaNeg[:-1]
        pos.write(lineaPos + "\n")
        neg.write(lineaNeg + "\n")
    lector.close()
    pos.close()
    neg.close()
