import estructura

estructura.crear("AB", "valor izq der")


# mapaAB: (X->Y) AB(X) -> AB(Y)
# Recibe una funcion (anonima o definida) y devuelve el AB con todos los valores modificados por la funcion recibida
def mapaAB(fucn, ABact):
    if ABact == None:
        return None
    return AB(fucn(ABact.valor), mapaAB(fucn, ABact.izq), mapaAB(fucn, ABact.der))


# Arbol binario de ejemplo
# tercel nivel
unABizqizq = AB(10, None, None)
unABizqder = AB(8, None, None)
unABderizq = None
unABderder = AB(4, None, None)
# segundo nivel
unABizq = AB(7, unABizqizq, unABizqder)
unABder = AB(4, unABderizq, unABderder)
# raiz del arbol
unAB = AB(1, unABizq, unABder)

assert mapaAB(lambda x: x + 1, unAB) == AB(
    2, AB(8, AB(11, None, None), AB(9, None, None)), AB(5, None, AB(5, None, None))
)
