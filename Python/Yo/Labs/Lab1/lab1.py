# Odio las recetas de diseño

# int -> int
# lit le suma uno, no se que mas decir
# (5) -> 6, (7)-> 8
def sumarUno (int):
    return int+1

algo = int (input("Ingresa un Número:\n"))
print(str(sumarUno(algo))+ " te gane!")

# int, int, int, int -> float
# recibe 4 nums, donde los 2 priemros compnen una fraciion y los otros 2 compene otra frac, y suma las frcaciones, y oara evitar problemas con el floating point precision, primeor sumamos los denominadores, y leugo dividimos por el denomnaodr combinado
# (1, 2, 2, 4) -> (1), (4, 5, 8,9) -> (76/45)

def sumarFrac(num1, dem1, num2, dem2):
    aux = (num1*dem2)+(num2*dem1)
    return aux/(dem2*dem1)




print("Suma de fraccciones: a/b + c/d")
a = int (input("a:\n"))
b = int (input("b:\n"))
c = int (input("c:\n"))
d = int (input("d:\n"))

print("suma =" + str(sumarFrac(a,b,c,d)))






import random # no es ramdom, es solamemt un numero pseaodlaetorio

# none -> int [1,6]
#devlve un num en el ranfgo [1,6]
# -> 5, -> 4
def dado():
    return random.randint(1,6)


def randint(a,b):
    maxi =max(a,b)
    mini = min(a,b)
    x = random.random()
    return (x*(maxi - mini)+1)

print(str(randint(60, 5)))





# me queiro pegar un tiro





def pendiente( x1, y1,x2,y2):
    aux1 = y2 - y1
    aux2 = x2 - x1
    return aux1/aux2

def ordenadaOrigen (x,y, m):
    return (y - m *x)


x1 = int(input("x1? "))
y1 = int(input("x2? "))

x2 = int(input("x2? "))
y2 = int(input("y2? "))
m = pendiente(x1,y1,x2,y2)
print("Ecuacion de la recta: y = " +str(m)+"x + " str(ordenadaOrigen(x1,y1,m)))
