import turtle

turtle.hideturtle()
turtle.speed(0)

# h: int -> None
# dibuja una H horizontal centrada
# en la posicion actual, de tamaño largo
def h(largo):
    x = turtle.xcor()
    y = turtle.ycor()
    m = largo / 2

    turtle.penup()
    turtle.goto(x - m, y + m)
    turtle.pendown()
    turtle.goto(x + m, y + m)

    turtle.penup()
    turtle.goto(x - m, y)
    turtle.pendown()
    turtle.goto(x + m, y)

    turtle.penup()
    turtle.goto(x - m, y - m)
    turtle.pendown()
    turtle.goto(x + m, y - m)

    turtle.penup()
    turtle.goto(x - m, y + m)
    turtle.pendown()
    turtle.goto(x - m, y - m)

    turtle.penup()
    turtle.goto(x + m, y + m)
    turtle.pendown()
    turtle.goto(x + m, y - m)

# dibujo: int -> None
# dibuja la H fractal de tamaño largo
# en cada esquina dibuja otra H
# de la mitad del tamaño
def dibujo(largo):
    if largo > 4:
        x = turtle.xcor()
        y = turtle.ycor()
        m = largo / 2

        h(largo)

        turtle.penup()
        turtle.goto(x - m, y + m)
        turtle.pendown()
        dibujo(largo // 2)

        turtle.penup()
        turtle.goto(x + m, y + m)
        turtle.pendown()
        dibujo(largo // 2)

        turtle.penup()
        turtle.goto(x - m, y - m)
        turtle.pendown()
        dibujo(largo // 2)

        turtle.penup()
        turtle.goto(x + m, y - m)
        turtle.pendown()
        dibujo(largo // 2)

        turtle.penup()
        turtle.goto(x, y)
        turtle.pendown()

# H fractal
turtle.penup()
turtle.goto(0, 0)
turtle.setheading(45)   # rotacion global
turtle.pendown()

dibujo(128)
turtle.done()
