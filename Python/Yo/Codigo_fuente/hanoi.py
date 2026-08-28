# hanoiRec: int str str str -> str
# Devuelve un string con la lista de movimientos para
# resolver el problema de las Torres de Hanoi con n discos,
# moviendolos desde la torre de partida a la torre final
# y quedando la torre del medio como torre auxiliar

def hanoiRec(n, partida, medio, final):
    if n == 0: # Caso base
        return '' 
    else: # Caso recursivo
        # Se mueven n - 1 discos de torre de partida a torre del medio
        texto1 = hanoiRec(n - 1, partida, final, medio)
        # Se mueve el disco mas grande de torre de partida a torre final
        texto2 = str(partida) + ' --> ' + str(final) + '\n'
        # Se mueven n - 1 discos de torre del medio a torre final
        texto3 = hanoiRec(n - 1, medio, partida, final)
        return texto1 + texto2 + texto3

# hanoi: int -> str
# Invoca el primer llamado recursivo de hanoiRec
# ejemplo: hanoi(4) devuelve el texto con los movimientos para 4 discos
def hanoi(n):
    return hanoiRec(n, 'primera', 'segunda', 'tercera')




