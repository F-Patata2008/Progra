import estructura
import lista


def unionListas(lista1, lista2):
    if lista.vacia(lista1):
        return lista2
    else:
        return lista(cabeza(lista1), unionListas(cola(lista1), lista2))


def buscar(listaRevsiar, num):
    if lista.vacia(listaRevsiar):
        return listaRevsiar
    if lista.cabeza(listaRevsiar) < num:
        return lista(lista.cabeza(listaRevsiar), buscar(lista.cola(listaRevsiar)))
    return buscar(lista.cola(listaRevsiar), num)


def buscar2(listaRevsiar, num1, num2):
    if lista.vacia(listaRevsiar):
        return listaRevsiar
    if lista.cabeza(listaRevsiar >= num1) and lista.cabeza(listaRevsiar) <= num2:
        return lista(
            lista.cabeza(listaRevsiar), buscar2(lista.cola(listaRevsiar), num1, num2)
        )
    return buscar2(lista.cola(listaRevsiar), num1, num2)


def buscar3(listaRevsiar, num):
    if lista.vacia(listaRevsiar):
        return listaRevsiar
    if lista.cabeza(listaRevsiar) > num:
        return lista(lista.cabeza(listaRevsiar), buscar3(lista.cola(listaRevsiar), num))
    return buscar3(lista.cola(listaRevsiar), num)


def reordenar(listaActual, x, y):
    if x >= y:
        return listaActual
    unionListas(
        buscar(listaActual, x),
        unionListas(buscar2(listaActual, x, y), buscar3(listaActual, y)),
    )
