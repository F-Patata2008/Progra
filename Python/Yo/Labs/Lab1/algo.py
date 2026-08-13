#Ejercicio 2
#pendiente: num num num num -> float
#recibe dos pares de coordenadas y calcula la pendiente de la recta que pasa
#por ambos puntos.
def pendiente( x1, y1,x2,y2):
    aux1 = y2 - y1
    aux2 = x2 - x1
    return aux1/aux2
    

assert pendiente (1,1,4,5)==1.3333333333333333

#ordenadaOrigen: num num float -> float
#recibe las coordenadas de (x,y) de un punto por el cual pasa la recta y la
#pendiente m y devuelve el valor b.
def ordenadaOrigen (x,y, m):
    return (y - m *x)

x1 = int(input("x1? "))
y1 = int(input("y1? "))

x2 = int(input("x2? "))
y2 = int(input("y2? "))
pen = pendiente(x1,y1,x2,y2)

assert ordenadaOrigen(1,1,pendiente(1,1,4,5))==-0.33333333333333326

#ecuacionRecta: ->float
#recibe coordenadas (x1,y1) y (x2,y2) de parte del usuario y devuelve la pendiente
#mas la ordenada origen.
print("Ecuacion de la recta: y = " + str(pen) + "x + " + str(ordenadaOrigen(x1,y1,pen)) )

assert pendiente(2,5,4,1)==-2.0
assert ordenadaOrigen(2,5,pendiente(2,5,4,1))==9.0
