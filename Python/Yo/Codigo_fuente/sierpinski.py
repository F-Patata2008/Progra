import turtle

turtle.hideturtle()
turtle.speed(0)

# triangulo: int -> None
# dibuja un triangulo equilatero
# de lado largo
def triangulo(largo):
    turtle.forward(largo)
    turtle.left(120)
    turtle.forward(largo)
    turtle.left(120)
    turtle.forward(largo)
    turtle.left(120)

# sierpinski: int -> None
# dibuja el triangulo de Sierpinski
# de longitud largo
def sierpinski(largo):
    if largo > 4:
        triangulo(largo)
        sierpinski(largo // 2)
        turtle.forward(largo // 2)
        sierpinski(largo // 2)
        turtle.backward(largo // 2)
        turtle.left(60)
        turtle.forward(largo // 2)
        turtle.right(60)
        sierpinski(largo // 2)
        turtle.left(60)
        turtle.backward(largo // 2)
        turtle.right(60)

# Triangulo de sierpinski
sierpinski(256)
turtle.done()
