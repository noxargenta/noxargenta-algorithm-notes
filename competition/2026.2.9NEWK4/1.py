n = 3
sl = 1 << n
for i in range(sl):
    g = i ^ (i >> 1)
    print(g, end=" ")
print()