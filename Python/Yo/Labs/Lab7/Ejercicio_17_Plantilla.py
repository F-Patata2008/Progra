import estructura
from lista import *

# AB: valor(int) izq(AB) der(AB)
estructura.crear("AB", "valor izq der")

# ==============================================================================
# FUNCION CAMINO
# ==============================================================================

# camino : AB int -> lista(int)
# Devuelve una lista con los valores de los nodos recorridos desde la raiz hasta encontrar val en el ABB
# ejemplo: camino(unABB, 2) devuelve lista(4, lista(2, None))
def camino(ABB, val):
    if ABB == None:
        return None
    if ABB.valor == val:
        return lista(val, None)
    if val < ABB.valor:
        return lista(ABB.valor, camino(ABB.izq, val))
    else:
        return lista(ABB.valor, camino(ABB.der, val))


# ==============================================================================
# ABB DE EJEMPLO
# ==============================================================================

# tercer nivel
unABBizqizq = AB(1, None, None)
unABBizqder = AB(3, None, None)
unABBderizq = AB(5, None, None)
unABBderder = AB(7, None, None)

# segundo nivel
unABBizq = AB(2, unABBizqizq, unABBizqder)
unABBder = AB(6, unABBderizq, unABBderder)

# raiz del arbol
unABB = AB(4, unABBizq, unABBder)


# ==============================================================================
# TESTS
# ==============================================================================

assert camino(unABB, 5) == lista(4, lista(6, lista(5, None)))
assert camino(unABB, 7) == lista(4, lista(6, lista(7, None)))
assert camino(unABB, 1) == lista(4, lista(2, lista(1, None)))
assert camino(unABB, 3) == lista(4, lista(2, lista(3, None)))
assert camino(unABB, 2) == lista(4, lista(2, None))
assert camino(unABB, 6) == lista(4, lista(6, None))
assert camino(unABB, 4) == lista(4, None)
