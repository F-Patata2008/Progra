from lista import *

    # unionListas: lista(any) lista(any) -> lista(any)
    def unionListas(lista1, lista2):
        if vacia(lista1):
            return lista2
        else:
            return lista(cabeza(lista1), unionListas(cola(lista1), lista2))


    # menores: lista(int) int -> lista(int)
    def menores(unaLista, x):
        if vacia(unaLista):
            return listaVacia
        elif cabeza(unaLista) < x:
            return lista(cabeza(unaLista), menores(cola(unaLista), x))
        else:
            return menores(cola(unaLista), x)


    # enIntervalo: lista(int) int int -> lista(int)
    def enIntervalo(unaLista, x, y):
        if vacia(unaLista):
            return listaVacia
        elif cabeza(unaLista) >= x and cabeza(unaLista) <= y:
            return lista(cabeza(unaLista), enIntervalo(cola(unaLista), x, y))
        else:
            return enIntervalo(cola(unaLista), x, y)


    # mayores: lista(int) int -> lista(int)
    def mayores(unaLista, y):
        if vacia(unaLista):
            return listaVacia
        elif cabeza(unaLista) > y:
            return lista(cabeza(unaLista), mayores(cola(unaLista), y))
        else:
            return mayores(cola(unaLista), y)


    # reordenar: lista(int) int int -> lista(int)
    # Devuelve una lista con los valores de la lista original reordenados:
    # primero los valores menores que x, luego los que estan en el intervalo [x, y],
    # y luego los valores mayores que y, preservando el orden original en cada intervalo.
    # Ejemplo:
    # unaLista = lista(9, lista(8, lista(7, lista(6, lista(5, lista(4, lista(3, lista(2, lista(1, listaVacia)))))))))
    # reordenar(unaLista, 4, 6) devuelve lista(3, lista(2, lista(1, lista(6, lista(5, lista(4, lista(9, lista(8, lista(7, listaVacia)))))))))
    def reordenar(unaLista, x, y):
        # Test de pre-condicion
        assert x < y, "x debe ser menor que y"

        listaMenores = menores(unaLista, x)
        listaIntervalo = enIntervalo(unaLista, x, y)
        listaMayores = mayores(unaLista, y)

        return unionListas(listaMenores, unionListas(listaIntervalo, listaMayores))


    # Tests

    # Test del ejemplo del enunciado
    ejemploLista = lista(9, lista(8, lista(7, lista(6, lista(5, lista(4, lista(3, lista(2, lista(1, listaVacia)))))))))
    assert reordenar(ejemploLista, 4, 6) == lista(3, lista(2, lista(1, lista(6, lista(5, lista(4, lista(9, lista(8, lista(7, listaVacia)))))))))

    # Test 1 (distinto al ejemplo): Lista con numeros negativos y desordenados
    # Intervalos con x=0, y=5:
    # Menores que 0: -3, -1
    # Intervalo [0, 5]: 4, 0, 5
    # Mayores que 5: 8, 10
    L1 = lista(4, lista(-3, lista(8, lista(0, lista(5, lista(-1, lista(10, listaVacia)))))))
    esperado1 = lista(-3, lista(-1, lista(4, lista(0, lista(5, lista(8, lista(10, listaVacia)))))))
    assert reordenar(L1, 0, 5) == esperado1

    # Test 2 (distinto al ejemplo): Lista vacia
    assert reordenar(listaVacia, 2, 7) == listaVacia

    # Test 3 (distinto al ejemplo): Lista donde todos los elementos caen en una sola seccion (mayores que y)
    L3 = lista(10, lista(20, lista(30, listaVacia)))
    assert reordenar(L3, 2, 5) == lista(10, lista(20, lista(30, listaVacia)))
