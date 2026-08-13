def cont (bin,num ):
    if (bin == 1):
        return num+1 
    elif (bin == 0):
        return num
    else:
        num += bin %10
        return cont((bin//10),num)

assert cont (100, 0)== 1

def chequeo(bin, par):
    num = cont(bin, 0);
    if (num %2 == par):
        return True
    else:
        return False



binario = int(input("Ingrese un numero en bianrio:\n"))
paridad = int(input("Ingrese 0 o 1, indicando la paridad de unos:\n"))

if chequeo(binario, paridad):
    print ("La paridad de unos coincide con la paridad ingresada")
else:
    print("La paridad de unos no coincide con la paridad ingresada")

