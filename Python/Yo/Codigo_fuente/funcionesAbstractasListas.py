from lista import *

# filtro: (X -> bool) lista(X) -> lista(X)
# devuelve una lista con todos los valores de unaLista
# donde la funcion operador devuelve True
def filtro(operador, unaLista):
    if vacia(unaLista):
        return listaVacia
    else:
        if operador(cabeza(unaLista)):
            return lista(cabeza(unaLista), filtro(operador, cola(unaLista)))
        else:
            return filtro(operador, cola(unaLista))

# mapa: (X -> Y) lista(X) -> lista(Y)
# devuelve una lista con funcion f aplicada a todos los valores de unaLista
def mapa(f, unaLista):
    if vacia(unaLista):
        return listaVacia
    else:
        return lista(f(cabeza(unaLista)), mapa(f, cola(unaLista)))

# fold: (X X -> X) X lista(X) -> X
# procesa los valores de unaLista con la funcion f y devuelve un unico valor
# el valor init se usa como valor inicial para procesar el primer valor
# de la lista y como acumulador para los resultados parciales.
# Si la lista esta vacia, devuelve el valor init
def fold(f, init, unaLista):
    if vacia(unaLista):
        return init
    else:
        return fold(f, f(init, cabeza(unaLista)), cola(unaLista))
