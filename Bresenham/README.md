# Algoritmo de Bresenham para Reta

## Descrição
Este código implementa o algoritmo de Bresenham para desenhar uma reta em um espaço discreto, determinando quais pontos inteiros devem ser plotados para aproximar uma linha entre dois pontos.

Além disso, há um método auxiliar `not_bresenham`, que é utilizado para tratar o caso especial de retas verticais, onde o algoritmo de Bresenham não se aplica diretamente.

## Como Funciona
1. Se a reta for vertical (ou seja, `x1 == x2`), o método `not_bresenham` imprime diretamente os pontos da reta.
2. Caso contrário, o algoritmo de Bresenham é aplicado:
   - Calcula a inclinação `m` arredondada para duas casas decimais.
   - Inicia a variável `error` com 0.5.
   - Itera sobre os valores de `x` no intervalo definido, ajustando `y` com base no erro acumulado.
   - Quando o erro excede 1, `y` é incrementado e o erro é ajustado.

## Entrada
Os valores iniciais dos pontos da reta são definidos no bloco principal:
```python
x1 = 1
y1 = 1
x2 = 8
y2 = 5
```

## Saída
O programa imprime os pontos calculados da reta no formato:
```
( 1 , 1 ) error = 0.5
( 2 , 2 ) error = 0.07
( 3 , 2 ) error = 0.64
( 4 , 3 ) error = 0.21
( 5 , 3 ) error = 0.78
( 6 , 4 ) error = 0.35
( 7 , 4 ) error = 0.92
( 8 , 5 ) error = 0.49
```

![Plot do Bresenham](/Bresenham/Plot-Bresenham.png)

## Execução
Para executar o código, basta rodá-lo em um interpretador Python 3. Ele imprimirá os pontos da reta no console.

## Melhorias Possíveis
- Adicionar suporte para retas com declive negativo para o x com decrementação.

## Autor
Este script foi desenvolvido para demonstrar o funcionamento do algoritmo de Bresenham aplicado ao desenho de retas.