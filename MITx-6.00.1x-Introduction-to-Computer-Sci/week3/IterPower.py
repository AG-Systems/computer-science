def iterPower(base, exp):
    r = 1
    while exp > 0:
        x = (x * base)
        exp -= 1
    return x
