import moduloTarea1

# int int -> void
# recibe una secuencia, la separa en segmentos de tmaño n, y los imprime
# ejemplo (3938363534313125191814) devuelve: 
# 14, 18, 19, 25, 31
# 31, 34, 35, 36, 38
# 39

def imprimir(secuencia, n):
    # Caso base: si ya no queda secuencia, salimos de la recursión
    if secuencia <= 0:
        return
        
    primer_seg = moduloTarea1.primerSegmento(secuencia, n)
    resto = moduloTarea1.restoSegmentos(secuencia, n)
    
    # Imprimimos el string del segmento actual
    print(moduloTarea1.textoSegmento(primer_seg)) 
    
    # Llamada recursiva para el resto (sin return porque es un procedimiento)
    imprimir(resto, n)


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
