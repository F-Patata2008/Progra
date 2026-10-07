import estructura

# cuenta: numero(str) saldo(int)
estructura.mutable("cuenta", "numero saldo")

cuenta1 = cuenta("100-1", 1000)
cuenta2 = cuenta("200-2", 2000)
cuenta3 = cuenta("300-3", 4000)
cuenta4 = cuenta("400-4", 8000)
cuenta5 = cuenta("500-5", 16000)


# saldo: lista(cuenta) str -> int
# devuelve el saldo de la cuenta numeroCuenta de la lista de cuentas unaLista
def saldo(unaLista, numeroCuenta):
    if vacia(unaLista):
        return -1
    else:
        if cabeza(unaLista).numero == numeroCuenta:
            return cabeza(unaLista).saldo
        else:
            return saldo(cola(unaLista), numeroCuenta)


# depositar: lista(cuenta) str int -> None
def depositar(unaLista, numeroCuenta, cantidad):
    if saldo(unaLista, numeroCuenta) == -1 or unaLista == listaVacia:
        return None
    if cabeza(unaLista).numero == numeroCuenta:
        cabeza(unaLista).saldo = cabeza(unaLista).saldo + cantidad
        return None
    return depositar(cola(unaLista), numeroCuenta, cantidad)


# girar: lista(cuenta) str int -> None
def girar(unaLista, numeroCuenta, cantidad):
    if saldo(unaLista, numeroCuenta) == -1:
        return None
    if cabeza(unaLista).numero == numeroCuenta:
        if cabeza(unaLista).saldo < cantidad:
            return None
        cabeza(unaLista).saldo = cabeza(unaLista).saldo - cantidad
        return None
    return girar(cola(unaLista), numeroCuenta, cantidad)


# Programa de test
from lista import *

listaCuentas = lista(cuenta1, lista(cuenta2, lista(cuenta3, lista(cuenta4, lista(cuenta5, listaVacia)))))

# Test de giro
# PRIMERO:
girar(listaCuentas, cuenta2.numero, 500)
assert cuenta2.saldo == 1500
# SEGUNDO:
girar(listaCuentas, cuenta1.numero, 500000000000)
assert cuenta1.saldo == 1000
# TERCERO:
girar(listaCuentas, cuenta5.numero, 16000)
assert cuenta5.saldo == 0

# Test de depositar
# PRIMERO:
depositar(listaCuentas, cuenta1.numero, 7980)
assert cuenta1.saldo == 8980
# SEGUNDO:
depositar(listaCuentas, cuenta4.numero, 980)
assert cuenta4.saldo == 8980
# TERCERO:
depositar(listaCuentas, cuenta5.numero, 6)
assert cuenta5.saldo == 6
