# ==============================================================================
# CC1002 - Tarea 1: Modulo de funciones para suavizado de secuencias
# ==============================================================================

# ==============================================================================
# FUNCIONES PRINCIPALES SOLICITADAS (PARTE 1)
# ==============================================================================

# primerSegmento : int int -> int
# Recibe una secuencia y tamano de segmento validos, y devuelve el primer segmento
# ejemplo: primerSegmento(25191814, 2) devuelve 1814
def primerSegmento(secuencia, n):
    return secuencia % (100 ** n)

# Tests
assert primerSegmento(25191814, 2) == 1814
assert primerSegmento(3938363534313125191814, 4) == 25191814
assert primerSegmento(1210, 1) == 10
assert primerSegmento(30, 2) == 30


# restoSegmentos : int int -> int
# Recibe una secuencia y tamano de segmento validos, y devuelve la secuencia sin el primer segmento
# ejemplo: restoSegmentos(25191814, 2) devuelve 2519
def restoSegmentos(secuencia, n):
    return secuencia // (100 ** n)

# Tests
assert restoSegmentos(25191814, 2) == 2519
assert restoSegmentos(3938363534313125191814, 4) == 39383635343131
assert restoSegmentos(1210, 1) == 12
assert restoSegmentos(30, 2) == 0


# contar : int -> int
# Recibe una secuencia valida y devuelve la cantidad de numeros en la secuencia
# ejemplo: contar(25191814) devuelve 4
def contar(secuencia):
    if secuencia == 0:
        return 0
    return 1 + contar(secuencia // 100)

# Tests
assert contar(25191814) == 4
assert contar(1210) == 2
assert contar(30) == 1
assert contar(0) == 0


# estaOrdenada : int -> bool
# Recibe una secuencia valida e indica si esta ordenada en forma no decreciente
# ejemplo: estaOrdenada(25191814) devuelve True
def estaOrdenada(secuencia):
    if secuencia < 100:
        return True
    return (secuencia % 100 <= (secuencia // 100) % 100) and estaOrdenada(secuencia // 100)

# Tests
assert estaOrdenada(25191814) == True
assert estaOrdenada(1418) == False
assert estaOrdenada(1212) == True
assert estaOrdenada(10) == True


# textoSegmento : int -> str
# Recibe un segmento y devuelve un string con sus valores ordenados y separados por coma
# ejemplo: textoSegmento(1814) devuelve "14, 18"
def textoSegmento(segmento):
    if segmento == 0:
        return ""
    if segmento < 100:
        return str(segmento)
    return str(segmento % 100) + ", " + textoSegmento(segmento // 100)

# Tests
assert textoSegmento(1814) == "14, 18"
assert textoSegmento(363534) == "34, 35, 36"
assert textoSegmento(10) == "10"
assert textoSegmento(2222) == "22, 22"


# ==============================================================================
# FUNCIONES AUXILIARES (DESCOMPOSICION FUNCIONAL)
# ==============================================================================

# valoresValidos : int -> bool
# Verifica si todos los valores de una secuencia son enteros de 2 digitos en [10, 99]
# ejemplo: valoresValidos(2519) devuelve True
def valoresValidos(secuencia):
    if secuencia == 0:
        return True
    if secuencia % 100 < 10:
        return False
    return valoresValidos(secuencia // 100)

# Tests
assert valoresValidos(2519) == True
assert valoresValidos(10) == True
assert valoresValidos(501) == False
assert valoresValidos(0) == True


# secuenciaValida : int -> bool
# Determina si una secuencia es valida (positiva o cero, valores en [10, 99] y ordenada)
# ejemplo: secuenciaValida(25191814) devuelve True
def secuenciaValida(secuencia):
    if secuencia < 0:
        return False
    if secuencia == 0:
        return True
    return valoresValidos(secuencia) and estaOrdenada(secuencia)

# Tests
assert secuenciaValida(25191814) == True
assert secuenciaValida(0) == True
assert secuenciaValida(1418) == False
assert secuenciaValida(501) == False


# sumarSegmento : int -> int
# Calcula la suma de todos los valores de un segmento
# ejemplo: sumarSegmento(1814) devuelve 32
def sumarSegmento(segmento):
    if segmento == 0:
        return 0
    return (segmento % 100) + sumarSegmento(segmento // 100)

# Tests
assert sumarSegmento(1814) == 32
assert sumarSegmento(2519) == 44
assert sumarSegmento(10) == 10
assert sumarSegmento(0) == 0


# repetirValor : int int -> int
# Genera un numero repitiendo valor k veces en formato de secuencia
# ejemplo: repetirValor(19, 4) devuelve 19191919
def repetirValor(valor, k):
    if k == 0:
        return 0
    return valor + (repetirValor(valor, k - 1) * 100)

# Tests
assert repetirValor(19, 4) == 19191919
assert repetirValor(32, 2) == 3232
assert repetirValor(10, 1) == 10
assert repetirValor(15, 0) == 0


# suavizarSegmento : int -> int
# Devuelve el segmento suavizado reemplazando sus valores por la media entera
# ejemplo: suavizarSegmento(25191814) devuelve 19191919
def suavizarSegmento(segmento):
    if segmento == 0:
        return 0
    largo = contar(segmento)
    promedio = sumarSegmento(segmento) // largo
    return repetirValor(promedio, largo)

# Tests
assert suavizarSegmento(25191814) == 19191919
assert suavizarSegmento(35343131) == 32323232
assert suavizarSegmento(393836) == 373737
assert suavizarSegmento(39) == 39


# suavizarSecuencia : int int -> int
# Aplica recursivamente el proceso de suavizado sobre una secuencia en segmentos de tamano n
# ejemplo: suavizarSecuencia(25191814, 2) devuelve 22221616
def suavizarSecuencia(secuencia, n):
    if secuencia == 0:
        return 0
    primer_seg = primerSegmento(secuencia, n)
    resto = restoSegmentos(secuencia, n)
    seg_suavizado = suavizarSegmento(primer_seg)
    largo_seg = contar(primer_seg)
    return seg_suavizado + (suavizarSecuencia(resto, n) * (100 ** largo_seg))

# Tests
assert suavizarSecuencia(25191814, 2) == 22221616
assert suavizarSecuencia(3938363534313125191814, 4) == 3737373232323219191919
assert suavizarSecuencia(1210, 2) == 1111
assert suavizarSecuencia(0, 4) == 0


# ==============================================================================
# FUNCIONES PRINCIPALES SOLICITADAS (PARTE 2)
# ==============================================================================

# proceso : int int -> int
# Recibe secuencia y tamano de segmento. Devuelve -1 si hay datos invalidos, o la secuencia suavizada
# ejemplo: proceso(25191814, 2) devuelve 22221616
def proceso(secuencia, n):
    if n < 1 or not secuenciaValida(secuencia):
        return -1
    return suavizarSecuencia(secuencia, n)

# Tests
assert proceso(3938363534313125191814, 4) == 3737373232323219191919
assert proceso(25191814, 2) == 22221616
assert proceso(1418, 2) == -1
assert proceso(393836353431312519181, -2) == -1
