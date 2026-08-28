# cerca: num num num -> bool
# retorna True si x es igual a y con precision epsilon
def cerca(x, y, epsilon):
    diff = x - y
    return abs(diff) < epsilon

# Ejemplo de uso

# Test incorrecto (arroja AssertionError)
# assert 0.1 + 0.2 == 0.3

# Test correcto
tolerancia = 0.000001
assert cerca(0.1 + 0.2, 0.3, tolerancia)







