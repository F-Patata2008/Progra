Descuento = 10
Iva = 0.19
Pan = int(150)
Leche = int(1299)
Mantequilla = int(1699)
Cantidad_de_pan = int(input('Cuanto pan compras?\n'))
Cantidad_de_leche = int(input('cuantas leches compras?:\n'))
Cantidad_de_mantequilla = int(input('cuantas mantequillas compras:\n'))



Precio_cantidad_de_pan = (Pan * Cantidad_de_pan)
Precio_cantidad_de_leche = (Leche * Cantidad_de_leche)
Precio_cantidad_de_mantequilla = (Mantequilla * Cantidad_de_mantequilla)
Subtotal = (Precio_cantidad_de_pan + Precio_cantidad_de_leche + Precio_cantidad_de_mantequilla)
Porcentaje_iva = (Subtotal * Iva)
Porcentaje_descuento = (Subtotal * 1.19)* 0.1
Precio_final = (Subtotal * 1.19)*0.9
print('$'+str(Pan),str(Cantidad_de_pan),'$'+str(Precio_cantidad_de_pan))
print('$'+str(Leche),str(Cantidad_de_leche),'$'+str(Precio_cantidad_de_leche))
print('$'+str(Mantequilla),str(Cantidad_de_mantequilla),'$'+str(Precio_cantidad_de_mantequilla))
print()
print('....................................')
print('SUBTOTAL:','$'+str(Subtotal))
print('DESC ('+str(Descuento)+'%)','$'+str(Porcentaje_descuento))
