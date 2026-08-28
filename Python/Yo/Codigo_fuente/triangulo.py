# Ejemplo Clase 3

# triangulo.py
import math

# perimetro: num num num -> num
# calcula el perimetro de un triangulo de lados a, b, y c
# ejemplo: perimetro(2, 3, 2) devuelve 7
def perimetro(a, b, c):
    return a + b + c

# Test
assert perimetro(2, 3, 2) == 7

# area: num num num -> float
# calcula el area de un triangulo de lados a, b, y c
# ejemplo: area(3, 4, 5) devuelve 6.0
def area(a, b, c):
    semi = perimetro(a, b, c) / 2.0
    area = math.sqrt(semi * (semi - a) * (semi - b) * (semi - c))
    return area

# Test
assert area(3, 4, 5) == 6.0
