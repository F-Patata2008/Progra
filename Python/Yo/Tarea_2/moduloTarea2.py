import estructura
from lista import *

# ==============================================================================
# DEFINICION DE ESTRUCTURAS
# ==============================================================================

# colaEspera: lista(str) lista(str) lista(str) int int str
estructura.crear(
    "colaEspera",
    "ultimos auxiliar primeros cantidadUltimos cantidadPrimeros valor",
)


# ==============================================================================
# FUNCIONES AUXILIARES (DESCOMPOSICION FUNCIONAL)
# ==============================================================================


# crearCola : -> colaEspera
# Crea y devuelve una nueva cola de espera vacia
# ejemplo: crearCola() devuelve colaEspera(listaVacia, listaVacia, listaVacia, 0, 0, '')
def crearCola():
    return colaEspera(listaVacia, listaVacia, listaVacia, 0, 0, "")


# Tests
assert crearCola() == colaEspera(listaVacia, listaVacia, listaVacia, 0, 0, "")
assert vacia(crearCola().ultimos)
assert vacia(crearCola().primeros)
assert crearCola().valor == ""


# lista2texto : lista(str) -> str
# Convierte una lista de strings en un texto con los elementos separados por ' -> '
# ejemplo: lista2texto(lista('b', lista('a', listaVacia))) devuelve 'b -> a'
def lista2texto(unaLista):
    if vacia(unaLista):
        return ""
    if vacia(cola(unaLista)):
        return str(cabeza(unaLista))
    return str(cabeza(unaLista)) + " -> " + lista2texto(cola(unaLista))


# Tests
assert lista2texto(listaVacia) == ""
assert lista2texto(lista("A", listaVacia)) == "A"
assert lista2texto(lista("B", lista("A", listaVacia))) == "B -> A"
assert (
    lista2texto(lista("h", lista("g", lista("f", lista("e", listaVacia)))))
    == "h -> g -> f -> e"
)


# formatearLinea : str str -> str
# Da formato a una linea con etiqueta y contenido, omitiendo el espacio si el contenido es vacio
# ejemplo: formatearLinea('Ultimos', 'A') devuelve 'Ultimos: A'
def formatearLinea(etiqueta, contenido):
    if contenido == "":
        return etiqueta + ":"
    return etiqueta + ": " + contenido


# Tests
assert formatearLinea("Ultimos", "A") == "Ultimos: A"
assert formatearLinea("Primeros", "") == "Primeros:"
assert formatearLinea("Valor", "B") == "Valor: B"
assert formatearLinea("Ultimos", "") == "Ultimos:"


# ultimosAAuxiliar : int colaEspera -> colaEspera
# Traspasa k elementos uno a uno desde la cabeza de ultimos hacia auxiliar
# ejemplo: ultimosAAuxiliar(1, colaEspera(lista('a', listaVacia), listaVacia, listaVacia, 1, 0, '')) devuelve colaEspera(listaVacia, lista('a', listaVacia), listaVacia, 1, 0, '')
def ultimosAAuxiliar(k, unaCola):
    if k == 0 or vacia(unaCola.ultimos):
        return unaCola
    nuevaCola = colaEspera(
        cola(unaCola.ultimos),
        lista(cabeza(unaCola.ultimos), unaCola.auxiliar),
        unaCola.primeros,
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return ultimosAAuxiliar(k - 1, nuevaCola)


# Tests
test_ua1 = colaEspera(
    lista("b", lista("a", listaVacia)), listaVacia, listaVacia, 2, 0, ""
)
assert ultimosAAuxiliar(0, test_ua1) == test_ua1
assert ultimosAAuxiliar(1, test_ua1).auxiliar == lista("b", listaVacia)
assert ultimosAAuxiliar(2, test_ua1).auxiliar == lista(
    "a", lista("b", listaVacia)
)
assert ultimosAAuxiliar(3, test_ua1).ultimos == listaVacia


# ultimosAPrimeros : colaEspera -> colaEspera
# Traspasa todos los elementos restantes desde ultimos hacia primeros uno a uno
# ejemplo: ultimosAPrimeros(colaEspera(lista('a', listaVacia), listaVacia, listaVacia, 1, 0, '')) devuelve colaEspera(listaVacia, listaVacia, lista('a', listaVacia), 1, 0, '')
def ultimosAPrimeros(unaCola):
    if vacia(unaCola.ultimos):
        return unaCola
    nuevaCola = colaEspera(
        cola(unaCola.ultimos),
        unaCola.auxiliar,
        lista(cabeza(unaCola.ultimos), unaCola.primeros),
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return ultimosAPrimeros(nuevaCola)


# Tests
assert ultimosAPrimeros(crearCola()) == crearCola()
test_up1 = colaEspera(lista("a", listaVacia), listaVacia, listaVacia, 1, 0, "")
assert ultimosAPrimeros(test_up1).primeros == lista("a", listaVacia)
test_up2 = colaEspera(
    lista("b", lista("a", listaVacia)), listaVacia, listaVacia, 2, 0, ""
)
assert ultimosAPrimeros(test_up2).primeros == lista("a", lista("b", listaVacia))
assert vacia(ultimosAPrimeros(test_up2).ultimos)


# auxiliarAUltimos : colaEspera -> colaEspera
# Traspasa todos los elementos desde auxiliar de vuelta hacia ultimos uno a uno
# ejemplo: auxiliarAUltimos(colaEspera(listaVacia, lista('a', listaVacia), listaVacia, 1, 0, '')) devuelve colaEspera(lista('a', listaVacia), listaVacia, listaVacia, 1, 0, '')
def auxiliarAUltimos(unaCola):
    if vacia(unaCola.auxiliar):
        return unaCola
    nuevaCola = colaEspera(
        lista(cabeza(unaCola.auxiliar), unaCola.ultimos),
        cola(unaCola.auxiliar),
        unaCola.primeros,
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return auxiliarAUltimos(nuevaCola)


# Tests
assert auxiliarAUltimos(crearCola()) == crearCola()
test_au1 = colaEspera(listaVacia, lista("x", listaVacia), listaVacia, 0, 0, "")
assert auxiliarAUltimos(test_au1).ultimos == lista("x", listaVacia)
test_au2 = colaEspera(
    listaVacia, lista("y", lista("x", listaVacia)), listaVacia, 0, 0, ""
)
assert auxiliarAUltimos(test_au2).ultimos == lista("x", lista("y", listaVacia))
assert vacia(auxiliarAUltimos(test_au2).auxiliar)


# balancearUltimos : colaEspera -> colaEspera
# Realiza el proceso de balance cuando la lista primeros esta vacia y ultimos es la lista original
# ejemplo: balancearUltimos(colaEspera(lista('b', lista('a', listaVacia)), listaVacia, listaVacia, 2, 0, '')) devuelve colaEspera(lista('b', listaVacia), listaVacia, lista('a', listaVacia), 1, 1, '')
def balancearUltimos(unaCola):
    n = unaCola.cantidadUltimos
    k = n // 2
    paso1 = ultimosAAuxiliar(k, unaCola)
    paso2 = ultimosAPrimeros(paso1)
    paso3 = auxiliarAUltimos(paso2)
    return colaEspera(
        paso3.ultimos,
        listaVacia,
        paso3.primeros,
        k,
        n - k,
        paso3.valor,
    )


# Tests
test_bu1 = colaEspera(lista("a", listaVacia), listaVacia, listaVacia, 1, 0, "")
assert (
    balancearUltimos(test_bu1).cantidadPrimeros == 1
    and balancearUltimos(test_bu1).cantidadUltimos == 0
)
test_bu2 = colaEspera(
    lista("b", lista("a", listaVacia)), listaVacia, listaVacia, 2, 0, ""
)
assert (
    balancearUltimos(test_bu2).cantidadPrimeros == 1
    and balancearUltimos(test_bu2).cantidadUltimos == 1
)
test_bu4 = colaEspera(
    lista("d", lista("c", lista("b", lista("a", listaVacia)))),
    listaVacia,
    listaVacia,
    4,
    0,
    "",
)
assert balancearUltimos(test_bu4).primeros == lista("a", lista("b", listaVacia))
assert balancearUltimos(test_bu4).ultimos == lista("d", lista("c", listaVacia))


# primerosAAuxiliar : int colaEspera -> colaEspera
# Traspasa k elementos uno a uno desde la cabeza de primeros hacia auxiliar
# ejemplo: primerosAAuxiliar(1, colaEspera(listaVacia, listaVacia, lista('a', listaVacia), 0, 1, '')) devuelve colaEspera(listaVacia, lista('a', listaVacia), listaVacia, 0, 1, '')
def primerosAAuxiliar(k, unaCola):
    if k == 0 or vacia(unaCola.primeros):
        return unaCola
    nuevaCola = colaEspera(
        unaCola.ultimos,
        lista(cabeza(unaCola.primeros), unaCola.auxiliar),
        cola(unaCola.primeros),
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return primerosAAuxiliar(k - 1, nuevaCola)


# Tests
test_pa1 = colaEspera(
    listaVacia, listaVacia, lista("a", lista("b", listaVacia)), 0, 2, ""
)
assert primerosAAuxiliar(0, test_pa1) == test_pa1
assert primerosAAuxiliar(1, test_pa1).auxiliar == lista("a", listaVacia)
assert primerosAAuxiliar(2, test_pa1).auxiliar == lista(
    "b", lista("a", listaVacia)
)
assert primerosAAuxiliar(3, test_pa1).primeros == listaVacia


# primerosAUltimos : colaEspera -> colaEspera
# Traspasa todos los elementos restantes desde primeros hacia ultimos uno a uno
# ejemplo: primerosAUltimos(colaEspera(listaVacia, listaVacia, lista('a', listaVacia), 0, 1, '')) devuelve colaEspera(lista('a', listaVacia), listaVacia, listaVacia, 0, 1, '')
def primerosAUltimos(unaCola):
    if vacia(unaCola.primeros):
        return unaCola
    nuevaCola = colaEspera(
        lista(cabeza(unaCola.primeros), unaCola.ultimos),
        unaCola.auxiliar,
        cola(unaCola.primeros),
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return primerosAUltimos(nuevaCola)


# Tests
assert primerosAUltimos(crearCola()) == crearCola()
test_pu1 = colaEspera(listaVacia, listaVacia, lista("a", listaVacia), 0, 1, "")
assert primerosAUltimos(test_pu1).ultimos == lista("a", listaVacia)
test_pu2 = colaEspera(
    listaVacia, listaVacia, lista("a", lista("b", listaVacia)), 0, 2, ""
)
assert primerosAUltimos(test_pu2).ultimos == lista("b", lista("a", listaVacia))
assert vacia(primerosAUltimos(test_pu2).primeros)


# auxiliarAPrimeros : colaEspera -> colaEspera
# Traspasa todos los elementos desde auxiliar de vuelta hacia primeros uno a uno
# ejemplo: auxiliarAPrimeros(colaEspera(listaVacia, lista('a', listaVacia), listaVacia, 0, 0, '')) devuelve colaEspera(listaVacia, listaVacia, lista('a', listaVacia), 0, 0, '')
def auxiliarAPrimeros(unaCola):
    if vacia(unaCola.auxiliar):
        return unaCola
    nuevaCola = colaEspera(
        unaCola.ultimos,
        cola(unaCola.auxiliar),
        lista(cabeza(unaCola.auxiliar), unaCola.primeros),
        unaCola.cantidadUltimos,
        unaCola.cantidadPrimeros,
        unaCola.valor,
    )
    return auxiliarAPrimeros(nuevaCola)


# Tests
assert auxiliarAPrimeros(crearCola()) == crearCola()
test_ap1 = colaEspera(listaVacia, lista("x", listaVacia), listaVacia, 0, 0, "")
assert auxiliarAPrimeros(test_ap1).primeros == lista("x", listaVacia)
test_ap2 = colaEspera(
    listaVacia, lista("x", lista("y", listaVacia)), listaVacia, 0, 0, ""
)
assert auxiliarAPrimeros(test_ap2).primeros == lista("y", lista("x", listaVacia))
assert vacia(auxiliarAPrimeros(test_ap2).auxiliar)


# balancearPrimeros : colaEspera -> colaEspera
# Realiza el proceso de balance cuando la lista ultimos esta vacia y primeros es la lista original
# ejemplo: balancearPrimeros(colaEspera(listaVacia, listaVacia, lista('a', lista('b', listaVacia)), 0, 2, '')) devuelve colaEspera(lista('b', listaVacia), listaVacia, lista('a', listaVacia), 1, 1, '')
def balancearPrimeros(unaCola):
    n = unaCola.cantidadPrimeros
    k = n // 2
    paso1 = primerosAAuxiliar(k, unaCola)
    paso2 = primerosAUltimos(paso1)
    paso3 = auxiliarAPrimeros(paso2)
    return colaEspera(
        paso3.ultimos,
        listaVacia,
        paso3.primeros,
        n - k,
        k,
        paso3.valor,
    )


# Tests
test_bp1 = colaEspera(listaVacia, listaVacia, lista("a", listaVacia), 0, 1, "")
assert (
    balancearPrimeros(test_bp1).cantidadUltimos == 1
    and balancearPrimeros(test_bp1).cantidadPrimeros == 0
)
test_bp2 = colaEspera(
    listaVacia, listaVacia, lista("a", lista("b", listaVacia)), 0, 2, ""
)
assert (
    balancearPrimeros(test_bp2).cantidadUltimos == 1
    and balancearPrimeros(test_bp2).cantidadPrimeros == 1
)
test_bp4 = colaEspera(
    listaVacia,
    listaVacia,
    lista("a", lista("b", lista("c", lista("d", listaVacia)))),
    0,
    4,
    "",
)
assert balancearPrimeros(test_bp4).primeros == lista("a", lista("b", listaVacia))
assert balancearPrimeros(test_bp4).ultimos == lista("d", lista("c", listaVacia))


# ==============================================================================
# FUNCIONES PRINCIPALES SOLICITADAS
# ==============================================================================


# balance : colaEspera -> colaEspera
# Balancea una cola de espera distribuyendo sus elementos entre ultimos y primeros
# ejemplo: balance(colaEspera(lista('b', lista('a', listaVacia)), listaVacia, listaVacia, 2, 0, '')) devuelve colaEspera(lista('b', listaVacia), listaVacia, lista('a', listaVacia), 1, 1, '')
def balance(unaCola):
    if vacia(unaCola.primeros):
        return balancearUltimos(unaCola)
    elif vacia(unaCola.ultimos):
        return balancearPrimeros(unaCola)
    return unaCola


# Tests
test_bal4 = colaEspera(
    lista("d", lista("c", lista("b", lista("a", listaVacia)))),
    listaVacia,
    listaVacia,
    4,
    0,
    "",
)
assert balance(test_bal4).primeros == lista("a", lista("b", listaVacia))
test_balp4 = colaEspera(
    listaVacia,
    listaVacia,
    lista("a", lista("b", lista("c", lista("d", listaVacia)))),
    0,
    4,
    "",
)
assert balance(test_balp4).ultimos == lista("d", lista("c", listaVacia))
test_bal_solo = colaEspera(lista("z", listaVacia), listaVacia, listaVacia, 1, 0, "")
assert balance(test_bal_solo).primeros == lista("z", listaVacia)
test_ya_bal = colaEspera(
    lista("b", listaVacia), listaVacia, lista("a", listaVacia), 1, 1, ""
)
assert balance(test_ya_bal) == test_ya_bal


# ingresar : str colaEspera -> colaEspera
# Ingresa un dato al final de la cola de espera, actualizando cantidadUltimos y valor
# ejemplo: ingresar('A', crearCola()) devuelve colaEspera(lista('A', listaVacia), listaVacia, listaVacia, 1, 0, 'A')
def ingresar(dato, unaCola):
    return colaEspera(
        lista(dato, unaCola.ultimos),
        unaCola.auxiliar,
        unaCola.primeros,
        unaCola.cantidadUltimos + 1,
        unaCola.cantidadPrimeros,
        dato,
    )


# Tests
i1 = ingresar("A", crearCola())
assert cabeza(i1.ultimos) == "A" and i1.cantidadUltimos == 1 and i1.valor == "A"
i2 = ingresar("B", i1)
assert cabeza(i2.ultimos) == "B" and i2.cantidadUltimos == 2 and i2.valor == "B"
i3 = ingresar("C", i2)
assert cabeza(cola(i3.ultimos)) == "B" and i3.cantidadUltimos == 3
assert vacia(i3.primeros) and vacia(i3.auxiliar)


# primero : colaEspera -> colaEspera
# Extrae el primer dato de la cola de espera, balanceando previamente si primeros esta vacia
# ejemplo: primero(ingresar('B', ingresar('A', crearCola()))).valor devuelve 'A'
def primero(unaCola):
    if vacia(unaCola.primeros):
        colaBalanceada = balance(unaCola)
    else:
        colaBalanceada = unaCola
    valorSacado = cabeza(colaBalanceada.primeros)
    return colaEspera(
        colaBalanceada.ultimos,
        colaBalanceada.auxiliar,
        cola(colaBalanceada.primeros),
        colaBalanceada.cantidadUltimos,
        colaBalanceada.cantidadPrimeros - 1,
        valorSacado,
    )


# Tests
p_base = ingresar("B", ingresar("A", crearCola()))
p_res1 = primero(p_base)
assert p_res1.valor == "A"
p_res2 = primero(p_res1)
assert p_res2.valor == "B"
assert p_res2.cantidadUltimos == 0 and p_res2.cantidadPrimeros == 0
p_odd = ingresar("C", ingresar("B", ingresar("A", crearCola())))
assert primero(p_odd).valor == "A"


# ultimo : colaEspera -> colaEspera
# Extrae el ultimo dato de la cola de espera, balanceando previamente si ultimos esta vacia
# ejemplo: ultimo(ingresar('B', ingresar('A', crearCola()))).valor devuelve 'B'
def ultimo(unaCola):
    if vacia(unaCola.ultimos):
        colaBalanceada = balance(unaCola)
    else:
        colaBalanceada = unaCola
    valorSacado = cabeza(colaBalanceada.ultimos)
    return colaEspera(
        cola(colaBalanceada.ultimos),
        colaBalanceada.auxiliar,
        colaBalanceada.primeros,
        colaBalanceada.cantidadUltimos - 1,
        colaBalanceada.cantidadPrimeros,
        valorSacado,
    )


# Tests
u_base = ingresar("B", ingresar("A", crearCola()))
u_res1 = ultimo(u_base)
assert u_res1.valor == "B"
u_res2 = ultimo(u_res1)
assert u_res2.valor == "A"
assert u_res2.cantidadUltimos == 0 and u_res2.cantidadPrimeros == 0
u_odd = ingresar("C", ingresar("B", ingresar("A", crearCola())))
assert ultimo(u_odd).valor == "C"


# colaEspera2texto : colaEspera -> str
# Devuelve un string con el estado de la cola mostrando listas ultimos y primeros y el atributo valor
# ejemplo: colaEspera2texto(crearCola()) devuelve 'Ultimos:\nPrimeros:\nValor:'
def colaEspera2texto(unaCola):
    lineaUltimos = formatearLinea("Ultimos", lista2texto(unaCola.ultimos))
    lineaPrimeros = formatearLinea("Primeros", lista2texto(unaCola.primeros))
    lineaValor = formatearLinea("Valor", str(unaCola.valor))
    return lineaUltimos + "\n" + lineaPrimeros + "\n" + lineaValor


# Tests
test_txt = crearCola()
test_txt = ingresar("h", ingresar("g", ingresar("f", ingresar("e", ingresar("d", ingresar("c", ingresar("b", ingresar("a", test_txt))))))))
test_txt = primero(test_txt)
assert (
    colaEspera2texto(test_txt)
    == "Ultimos: h -> g -> f -> e\nPrimeros: b -> c -> d\nValor: a"
)
assert colaEspera2texto(crearCola()) == "Ultimos:\nPrimeros:\nValor:"
test_solo_ult = ingresar("A", crearCola())
assert colaEspera2texto(test_solo_ult) == "Ultimos: A\nPrimeros:\nValor: A"
test_solo_pri = colaEspera(listaVacia, listaVacia, lista("Z", listaVacia), 0, 1, "Z")
assert colaEspera2texto(test_solo_pri) == "Ultimos:\nPrimeros: Z\nValor: Z"
