import moduloTarea1

# ==============================================================================
# PROCEDIMIENTO AUXILIAR
# ==============================================================================

# imprimir : int int -> None
# Imprime en pantalla los valores de una secuencia separados por segmentos de tamano n
# ejemplo: imprimir(1814, 1) imprime:
# 14
# 18
def imprimir(secuencia, n):
    if secuencia <= 0:
        return
    primer_seg = moduloTarea1.primerSegmento(secuencia, n)
    resto = moduloTarea1.restoSegmentos(secuencia, n)
    print(moduloTarea1.textoSegmento(primer_seg))
    imprimir(resto, n)


# ==============================================================================
# PROGRAMA INTERACTIVO PRINCIPAL
# ==============================================================================

secuencia = int(input("Secuencia? "))
n = int(input("n? "))

suavizada = moduloTarea1.proceso(secuencia, n)

if suavizada == -1:
    print("Datos ingresados no validos")
else:
    print("Valores originales:")
    imprimir(secuencia, n)
    print("Valores despues de proceso de suavizado:")
    imprimir(suavizada, n)
