def getSublists(L, n):
    [L[i:i+n] for i  in range(0, len(L), n)]
    print L
    return L
L = [10, 4, 6, 8, 3, 4, 5, 7, 7, 2]
getSublists(L,2)
