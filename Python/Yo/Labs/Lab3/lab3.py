import turtle

turtle.hideturtle()
turtle.speed(0)


# h: num -> None
# Dibuja una letra H rotada en 90 grados (horizontal) centrada en la posicion actual
# ejemplo: h(128)
def h(largo):
    x = turtle.xcor()
    y = turtle.ycor()
    mitad = largo / 2

    # barra superior (horizontal)
    turtle.penup()
    turtle.goto(x - mitad, y + mitad)
    turtle.pendown()
    turtle.goto(x + mitad, y + mitad)

    # barra central (vertical conectora)
    turtle.penup()
    turtle.goto(x, y + mitad)
    turtle.pendown()
    turtle.goto(x, y - mitad)

    # barra inferior (horizontal)
    turtle.penup()
    turtle.goto(x - mitad, y - mitad)
    turtle.pendown()
    turtle.goto(x + mitad, y - mitad)

    # volver al centro
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()


# mover: num num -> None
# Mueve la tortuga una distancia relativa dx y dy sin trazar linea
# ejemplo: mover(10, -20)
def mover(dx, dy):
    turtle.penup()
    turtle.goto(turtle.xcor() + dx, turtle.ycor() + dy)
    turtle.pendown()


# dibujo: num -> None
# Genera recursivamente un fractal de arbol H con figuras rotadas en 90 grados
# ejemplo: dibujo(128)
def dibujo(largo):
    if largo > 4:
        # guardar centro actual
        x = turtle.xcor()
        y = turtle.ycor()
        mitad = largo / 2

        # dibujar H rotada en el centro
        h(largo)

        # esquina superior izquierda
        turtle.penup()
        turtle.goto(x - mitad, y + mitad)
        turtle.pendown()
        dibujo(largo // 2)

        # esquina superior derecha
        turtle.penup()
        turtle.goto(x + mitad, y + mitad)
        turtle.pendown()
        dibujo(largo // 2)

        # esquina inferior izquierda
        turtle.penup()
        turtle.goto(x - mitad, y - mitad)
        turtle.pendown()
        dibujo(largo // 2)

        # esquina inferior derecha
        turtle.penup()
        turtle.goto(x + mitad, y - mitad)
        turtle.pendown()
        dibujo(largo // 2)

        # volver al centro al terminar el nivel
        turtle.penup()
        turtle.goto(x, y)
        turtle.pendown()


# Ejecucion principal
dibujo(128)
turtle.done()
