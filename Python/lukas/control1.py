# Mi codigo (colli)

correo = input("Ingrese el correo a crear:\n")

pA = correo.index('@')
pP = correo.index('.')

ussr = correo[:pA]
dom = correo[pA+1:pP]
subdm = correo[pP+1:]

if (ussr.isalpha() and dom == 'util') and (subdm == 'cl' or subdm == 'ar' or subdm == 'br' or subdm == 'co' or subdm == "uy"):
    print("Primer check valido")

else :
    if not ussr.isalpha():
        print("- Solo Leyras")
    if dom != 'util':
        print("- Dominio Malo")
    if subdm != "cl" or subdm != 'co' or subdm != 'ar' or subdm != 'uy' or subdm != 'br': #y siguw
        print("- Sub dom malo")
