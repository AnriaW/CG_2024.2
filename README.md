# Cheat Sheet para OpenGL

## Como Compilar:

```sh
gcc -c -o [arquivo].o [arquivo].c -I"C:\MinGW\include"
gcc -o [arquivo].exe [arquivo].o -L"C:\MinGW\lib" -lfreeglut -lopengl32 -lglu32
```

ou

```sh
gcc -c -o [arquivo].o [arquivo].c -I"C:\Caminho\para\o\MinGW\include"
gcc -o [arquivo].exe [arquivo].o -L"C:\Caminho\para\o\MinGW\lib" -lfreeglut -lopengl32 -lglu32
```