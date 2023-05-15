def median(x):
    """Calcula a mediana de uma lista de dados"""
    x = sorted(x)
    middle = int(len(x)/2)

    if len(x) % 2 == 0:
        m = x[middle-1]
    else:
        m = x[middle]

    return print(m)
