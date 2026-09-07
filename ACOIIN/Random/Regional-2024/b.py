n = int(input())
m = int(input())

if (n * m) % 2 == 0:
    print(str(n * m / 2) + " " + str(n * m / 2))
else:
    print(str(1 + (n * m // 2)) + " " + str((n * m // 2)))
