import estructura

#AB: valor(any) izq(AB) der(AB)
estructura.crear('AB', 'valor izq der')
ABVacio = None

# obtenerValor: AB -> int
# devuelve el numero en la raiz del arbol (que debe ser no vacio)
def obtenerValor(raiz):
    assert not vacio(raiz)
    return raiz.valor

# ramaIzq: AB -> AB
# devuelve subarbol izquierdo del arbol (que debe ser no vacio)
def ramaIzq(raiz):
    assert not vacio(raiz)
    return raiz.izq

# ramaDer: AB -> AB
# devuelve subarbol derecho del arbol (que debe ser no vacio)
def ramaDer(raiz):
    assert not vacio(raiz)
    return raiz.der

# vacio: AB -> AB
# devuelve True si el arbol esta vacio
def vacio(raiz):
    return raiz == ABVacio

