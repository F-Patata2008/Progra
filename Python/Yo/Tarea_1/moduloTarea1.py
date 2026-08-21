# ==========================================
# FUNCIONES AUXILIARES
# ==========================================

# segmento: int int int int -> int
# Extrae los primeros n numeros (2 digitos cada uno) de una secuencia, acumulandolos en num
# ejemplo: segmento(25191814, 0, 2, 0) devuelve 1814
def segmento(secuencia, num, n, cont):
    if cont == n or secuencia == 0:
        return num
    # Se extraen los últimos 2 dígitos y se posicionan
    num += (secuencia % 100) * (100 ** cont)
    return segmento(secuencia // 100, num, n, cont + 1)


# restos: int int int -> int
# Elimina los primeros n numeros (2 digitos cada uno) de una secuencia y devuelve el resto
# ejemplo: restos(25191814, 2, 0) devuelve 2519
def restos(secuencia, n, cont):
    if cont == n or secuencia == 0:
        return secuencia
    return restos(secuencia // 100, n, cont + 1)


# conti: int int -> int
# Cuenta la cantidad de numeros (pares de digitos) en la secuencia a partir de un acumulador
# ejemplo: conti(2519, 0) devuelve 2
def conti(secuencia, cont):
    if secuencia == 0:
        return cont
    return conti(secuencia // 100, cont + 1)


# recorrer: int int -> bool
# Verifica si los numeros de la secuencia estan ordenados de forma no decreciente recursivamente
# ejemplo: recorrer(2519, 14) devuelve True
def recorrer(secuencia, ant):
    if secuencia == 0:
        return True
    if secuencia % 100 < ant:
        return False
    return recorrer(secuencia // 100, secuencia % 100)


# suma_segmento: int int -> int
# Suma todos los numeros (pares de digitos) de una secuencia, acumulandolos en suma_act
# ejemplo: suma_segmento(1914, 0) devuelve 33
def suma_segmento(secuencia, suma_act):
    if secuencia == 0:
        return suma_act
    return suma_segmento(secuencia // 100, suma_act + (secuencia % 100))


# suavizada: int int int int -> int
# Crea un segmento de tamano n donde todos los valores son iguales a prom
# ejemplo: suavizada(16, 0, 2, 0) devuelve 1616
def suavizada(prom, num, n, cont):
    if cont == n:
        return num
    num += prom * (100 ** cont)
    return suavizada(prom, num, n, cont + 1)


# procesar_recursivo: int int int -> int
# Aplica el proceso de suavizado a toda la secuencia recursivamente por segmentos de tamano n
# ejemplo: procesar_recursivo(25191814, 2, 0) devuelve 22221616
def procesar_recursivo(secuencia, n, cont):
    if secuencia == 0:
        return 0
        
    primer_seg = primerSegmento(secuencia, n)
    resto = restoSegmentos(secuencia, n)
    
    # Calculamos cuántos elementos tiene realmente este segmento (por si es el último y es más chico)
    largo_real = contar(primer_seg)
    
    # Calculamos la parte entera del promedio
    prom = suma_segmento(primer_seg, 0) // largo_real
    
    # Creamos el segmento suavizado con el largo REAL
    seg_suavizado = suavizada(prom, 0, largo_real, 0)
    
    # Llamamos a la recursión para el resto de la secuencia
    resto_suavizado = procesar_recursivo(resto, n, cont + 1)
    
    # Unimos el segmento actual suavizado con el resto ya procesado
    return seg_suavizado + (resto_suavizado * (100 ** largo_real))


# ==========================================
# FUNCIONES PRINCIPALES
# ==========================================

# primerSegmento: int int -> int
# Recibe una secuencia y tamano de segmento validos, devuelve el primer segmento
# ejemplo: primerSegmento(25191814, 2) devuelve 1814
def primerSegmento(secuencia, n):
    return segmento(secuencia, 0, n, 0)


# restoSegmentos: int int -> int
# Recibe una secuencia y tamano de segmento validos, devuelve la secuencia sin el primer segmento
# ejemplo: restoSegmentos(25191814, 2) devuelve 2519
def restoSegmentos(secuencia, n):
    return restos(secuencia, n, 0)


# contar: int -> int
# Recibe una secuencia valida y devuelve la cantidad de numeros en la secuencia
# ejemplo: contar(25191814) devuelve 4
def contar(secuencia):
    if secuencia == 0:
        return 0
    return conti(secuencia, 0)


# estaOrdenada: int -> bool
# Recibe una secuencia valida e indica si esta ordenada en forma no decreciente
# ejemplo: estaOrdenada(25191814) devuelve True
def estaOrdenada(secuencia):
    if secuencia == 0:
        return True
    return recorrer(secuencia // 100, secuencia % 100)


# textoSegmento: int -> str
# Recibe un segmento y devuelve un string con los valores ordenados y separados por coma
# ejemplo: textoSegmento(1814) devuelve "14, 18"
def textoSegmento(segmento):
    # Si es un número menor a 100, es el último de la cadena (no lleva coma)
    if segmento < 100:
        return str(segmento)
    # Recursión: "numero actual, " + llamada recursiva
    return str(segmento % 100) + ", " + textoSegmento(segmento // 100)


# proceso: int int -> int
# Recibe secuencia y tamano de segmento. Devuelve -1 si hay error, sino devuelve la secuencia suavizada
# ejemplo: proceso(25191814, 2) devuelve 22221616
def proceso(secuencia, n):
    if n <= 0 or secuencia <= 0 or not estaOrdenada(secuencia):
        return -1
    if secuencia == 0:
        return 0
    return procesar_recursivo(secuencia, n, 0)



# ==========================================
# TESTING (4 asserts por cada función)
# ==========================================

# Tests de funciones auxiliares
assert segmento(25191814, 0, 2, 0) == 1814
assert segmento(3938363534313125191814, 0, 4, 0) == 25191814
assert segmento(1210, 0, 1, 0) == 10
assert segmento(0, 0, 3, 0) == 0

assert restos(25191814, 2, 0) == 2519
assert restos(3938363534313125191814, 4, 0) == 39383635343131
assert restos(1210, 1, 0) == 12
assert restos(10, 2, 0) == 0

assert conti(25191814, 0) == 4
assert conti(0, 0) == 0
assert conti(10, 0) == 1
assert conti(9999, 0) == 2

assert recorrer(2519, 18) == True
assert recorrer(14, 18) == False
assert recorrer(0, 99) == True
assert recorrer(1925, 30) == False

assert suma_segmento(1814, 0) == 32
assert suma_segmento(2519, 0) == 44
assert suma_segmento(0, 0) == 0
assert suma_segmento(10, 5) == 15

assert suavizada(16, 0, 2, 0) == 1616
assert suavizada(22, 0, 2, 0) == 2222
assert suavizada(50, 0, 3, 0) == 505050
assert suavizada(0, 0, 0, 0) == 0

assert procesar_recursivo(25191814, 2, 0) == 22221616
assert procesar_recursivo(1210, 2, 0) == 1111
assert procesar_recursivo(30, 2, 0) == 30
assert procesar_recursivo(0, 2, 0) == 0

# Tests de funciones principales solicitadas
assert primerSegmento(25191814, 2) == 1814
assert primerSegmento(1210, 1) == 10
assert primerSegmento(30, 2) == 30
assert primerSegmento(0, 2) == 0

assert restoSegmentos(25191814, 2) == 2519
assert restoSegmentos(1210, 1) == 12
assert restoSegmentos(30, 2) == 0
assert restoSegmentos(0, 2) == 0

assert contar(25191814) == 4
assert contar(1210) == 2
assert contar(30) == 1
assert contar(0) == 0

assert estaOrdenada(25191814) == True
assert estaOrdenada(1418) == False
assert estaOrdenada(1212) == True
assert estaOrdenada(10) == True

assert textoSegmento(1814) == "14, 18"
assert textoSegmento(363534) == "34, 35, 36"
assert textoSegmento(10) == "10"
assert textoSegmento(2222) == "22, 22"

assert proceso(3938363534313125191814, 4) == 3737373232323219191919
assert proceso(25191814, 2) == 22221616
assert proceso(1418, 2) == -1  # Falla porque está desordenada
assert proceso(25191814, -1) == -1  # Falla porque n <= 0
