# Teoria de juegos

tenemso posicion ganadora, perdedora y empate

- Gnadora. Existe un movimiento que lleva a L para el rival
- Perdedora, Parar todo mivimientos, el rival gana, ya que quega d eforma optima
- Empate, caso borde cuando hay ciclos en el grafo

en un dag existe solo Ganar y perder. si tiene un ciclo, el juego no tine final

complejiidad O(V+E) con bfs

## Algoritmo para etiquetar

- Terminales L: No tinene arsitas salientes
- Existe un hijo L, si hay mov que lleva a l, esta pos es ganar
- Si todos los movs van a Gnara, esto es perder
- Si no es ni G ni p, bfs inverso, emepzar desde las terminales, propagar w/l, resto empate

(l = perder, ganar = W, D = empate)

## Juegos de Sustracion

sea un conjunto S = {1,2,4,8,16,... 2^k}

### Reglas :

S = {s1, s2,...} (finito o inf)
desde x, mover a x-s, si s pertenece a S, y z<=x]}
W/L se calcula hacia atras con DP

### Teroema de pericodiad:

si S es finito, El patron W/L es eventaulmente peridico, alos mas 2^(max(S)) estados psibles
