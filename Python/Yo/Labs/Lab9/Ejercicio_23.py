# ==============================================================================
# CC1002 - Laboratorio 9 / Ejercicio 23
# ==============================================================================

# oscilacionTermica : list(int) list(int) -> list(int)
# Calcula la oscilacion termica diaria (temperatura maxima - minima) para cada dia
# a partir de las listas de temperaturas minimas y maximas del mismo largo.
# ejemplo: oscilacionTermica([5, 2, 5, 3, 4], [18, 21, 12, 8, 10]) devuelve [13, 19, 7, 5, 6]
def oscilacionTermica(minimas, maximas):
    # Test de precondicion: ambas listas deben tener el mismo largo
    assert len(minimas) == len(maximas), "Las listas deben tener el mismo largo"
    
    oscilaciones = []
    for i in range(len(minimas)):
        diferencia = maximas[i] - minimas[i]
        oscilaciones.append(diferencia)
    return oscilaciones


# Tests oscilacionTermica (al menos dos tests con al menos 5 valores)
# Test 1: 5 valores positivos
assert oscilacionTermica([5, 2, 5, 3, 4], [18, 21, 12, 8, 10]) == [13, 19, 7, 5, 6]

# Test 2: 6 valores con temperaturas negativas y cero
assert oscilacionTermica([-3, 0, 2, -1, 4, 1], [7, 10, 15, 9, 14, 11]) == [10, 10, 13, 10, 10, 10]

# Test 3: Datos de temperaturas.txt (7 valores)
assert oscilacionTermica([5, 2, 5, 3, 4, -1, 3], [18, 21, 12, 8, 10, 9, 9]) == [13, 19, 7, 5, 6, 10, 6]


# consecutivos : list(int) -> bool
# Determina si existen dos dias consecutivos cualesquiera con la misma oscilacion termica diaria
# ejemplo: consecutivos([13, 19, 7, 5, 5]) devuelve True
def consecutivos(lista):
    for i in range(len(lista) - 1):
        if lista[i] == lista[i + 1]:
            return True
    return False


# Tests consecutivos (al menos dos tests con al menos 5 valores)
# Test 1: Lista donde si hay dias consecutivos con igual oscilacion (True)
assert consecutivos([13, 19, 7, 5, 5]) == True

# Test 2: Lista donde no hay dias consecutivos con igual oscilacion (False)
assert consecutivos([13, 19, 7, 5, 6, 10, 6]) == False

# Test 3: Lista con consecutivos iguales al inicio (True)
assert consecutivos([10, 10, 13, 15, 8]) == True


# ==============================================================================
# PROGRAMA PRINCIPAL
# ==============================================================================

nombreArchivo = input("Ingrese el nombre del archivo de temperaturas: ")

archivo = open(nombreArchivo, "r")

minimas = []
maximas = []

for linea in archivo:
    lineaLimpia = linea.strip()
    if lineaLimpia != "":
        partes = lineaLimpia.split(",")
        minimas.append(int(partes[0]))
        maximas.append(int(partes[1]))

archivo.close()

# Calculo de oscilaciones termicas
oscilaciones = oscilacionTermica(minimas, maximas)

# Verificacion de dias consecutivos con igual oscilacion
if consecutivos(oscilaciones):
    print("Hubo dos dias consecutivos con la misma oscilacion termica diaria.")
else:
    print("No hubo dos dias consecutivos con la misma oscilacion termica diaria.")
