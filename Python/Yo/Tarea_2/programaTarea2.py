import moduloTarea2


# interactivo : colaEspera -> None
# Ejecuta el ciclo interactivo de operaciones sobre la cola de espera
# ejemplo: interactivo(moduloTarea2.crearCola())
def interactivo(unaCola):
    op = input("Op (1:ingresar, 2:sacar primero, 3:sacar ultimo)? ")
    if op == "1":
        valor = input("Valor? ")
        nuevaCola = moduloTarea2.ingresar(valor, unaCola)
        print(moduloTarea2.colaEspera2texto(nuevaCola))
        interactivo(nuevaCola)
    elif op == "2":
        nuevaCola = moduloTarea2.primero(unaCola)
        print(moduloTarea2.colaEspera2texto(nuevaCola))
        interactivo(nuevaCola)
    elif op == "3":
        nuevaCola = moduloTarea2.ultimo(unaCola)
        print(moduloTarea2.colaEspera2texto(nuevaCola))
        interactivo(nuevaCola)
    else:
        # Se ignora cualquier operacion distinta a 1, 2 o 3 y se vuelve a preguntar
        interactivo(unaCola)


# ==============================================================================
# EJECUCION PRINCIPAL
# ==============================================================================

colaInicial = moduloTarea2.crearCola()
interactivo(colaInicial)
