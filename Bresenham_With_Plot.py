import matplotlib.pyplot as plt

def not_bresenham(x1, y1, x2, y2, points):
    if y2 > y1:
        for y in range(y1, y2 + 1):
            points.append((x1, y))
    else:
        y = y1
        while y >= y2:
            points.append((x1, y))
            y -= 1

def bresenham(x1, y1, x2, y2, points):
    m = round((y2 - y1) / (x2 - x1), 2)
    error = 0.5
    
    y = y1
    for x in range(x1, x2 + 1):
        points.append((x, y))
        error = error + m
        
        if error >= 1:
            y = y + 1
            error -= 1

def plot_line(x1, y1, x2, y2):
    points = []
    
    if x1 == x2:
        not_bresenham(x1, y1, x2, y2, points)
    else:
        if x1 > x2:
            x1, x2 = x2, x1
            y1, y2 = y2, y1
        
        bresenham(x1, y1, x2, y2, points)
    
    # Separando coordenadas para plotagem
    x_vals, y_vals = zip(*points)
    
    plt.plot(x_vals, y_vals, 'ro-', label='Bresenham')  # Plota os pontos
    plt.plot([x1, x2], [y1, y2], 'b--', label='Linha Ideal')  # Linha teórica
    
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Algoritmo de Bresenham')
    plt.grid(True)
    plt.legend()
    plt.show()

if __name__ == '__main__':
    x1, y1 = 1, 1
    x2, y2 = 8, 5
    plot_line(x1, y1, x2, y2)
