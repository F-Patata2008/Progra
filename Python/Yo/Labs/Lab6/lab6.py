import estructura

# ==============================================================================
# DEFINICION DE ESTRUCTURAS
# ==============================================================================

# AB: valor(int) izq(AB) der(AB)
estructura.crear("AB", "valor izq der")


# ==============================================================================
# FUNCIONES
# ==============================================================================


# sumarUno : int -> int
# Devuelve el numero entero sumado en 1
# ejemplo: sumarUno(3) devuelve 4
def sumarUno(n):
    return n + 1


# Tests
assert sumarUno(0) == 1
assert sumarUno(10) == 11
assert sumarUno(-5) == -4


# mapaAB : (any -> any) AB -> AB
# Aplica una funcion f a todos los valores de los nodos de un arbol binario unAB,
# devolviendo un nuevo arbol binario con la misma estructura y los valores transformados.
# ejemplo: mapaAB(sumarUno, AB(1, None, None)) devuelve AB(2, None, None)
def mapaAB(f, unAB):
    if unAB == None:
        return None
    return AB(f(unAB.valor), mapaAB(f, unAB.izq), mapaAB(f, unAB.der))


# ==============================================================================
# TESTS
# ==============================================================================

# Arbol binario de ejemplo dado en el enunciado
# tercer nivel
unABizqizq = AB(10, None, None)
unABizqder = AB(8, None, None)
unABderizq = None
unABderder = AB(4, None, None)

# segundo nivel
unABizq = AB(7, unABizqizq, unABizqder)
unABder = AB(4, unABderizq, unABderder)

# raiz del arbol
unAB = AB(1, unABizq, unABder)


# Arbol binario resultante (calculado a mano sumandole 1 a cada nodo)
# tercer nivel
resABizqizq = AB(11, None, None)
resABizqder = AB(9, None, None)
resABderizq = None
resABderder = AB(5, None, None)

# segundo nivel
resABizq = AB(8, resABizqizq, resABizqder)
resABder = AB(5, resABderizq, resABderder)

# raiz del arbol resultante
arbolEsperado = AB(2, resABizq, resABder)


# Test principal del enunciado (usando la funcion definida)
assert mapaAB(sumarUno, unAB) == arbolEsperado

# Test usando funcion anonima (lambda)
assert mapaAB(lambda x: x + 1, unAB) == arbolEsperado

# Test con arbol vacio
assert mapaAB(sumarUno, None) == None

# Test con un solo nodo y multiplicacion por 2
assert mapaAB(lambda x: x * 2, AB(5, None, None)) == AB(10, None, None)
