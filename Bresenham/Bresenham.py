def not_bresenham(x1, y1, x2, y2):
    if y2 > y1:
        for y in range(y1, y2 + 1):
            print("(", x1, ",", y, ")")
    else:
        y = y1
        while y >= y2:
            print("(", x1, ",", y, ")")
            y -= 1

def bresenham(x1, y1, x2, y2):

    m = round((y2 - y1) / (x2 - x1), 2)
    error = 0.5
    
    y = y1
    for x in range(x1, x2 + 1):
        print("(", x, ",", y, ") error =", round(error,2))
        error = error + m
        
        if error >= 1:
            y = y + 1
            error -= 1

if __name__ == '__main__':
    x1 = 1
    y1 = 1
    x2 = 8
    y2 = 5

    print ("\n")

    if x1 == x2:
        not_bresenham(x1, y1, x2, y2)
    else:
        if x1 > x2:
          x1 += x2
          x2 = x1 - x2
          x1 -= x2
        
        bresenham(x1, y1, x2, y2)
    print("\n")