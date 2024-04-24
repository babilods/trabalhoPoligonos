#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * fabs((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y)));
}

int main() {
    FILE *file;
    Ponto A, B, C;
    int numLados;

    // Abrindo o arquivo
    file = fopen("C:/faculdade01/TrabalhoPratico2/output/poligono.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lendo o número de lados do triângulo
    fscanf(file, "%d", &numLados);
    printf("Numero de lados do poligono: %d\n", numLados); // Imprimir o número de lados para depuração
    if (numLados != 3) {
        printf("O arquivo nao contem as coordenadas de um triangulo.\n");
        fclose(file);
        return 1;
    }

    // Lendo os vértices do arquivo
    fscanf(file, "%f %f", &A.X, &A.Y);
    fscanf(file, "%f %f", &B.X, &B.Y);
    fscanf(file, "%f %f", &C.X, &C.Y);

    // Fechando o arquivo
    fclose(file);

    // Calculando a área do triângulo
    float areaTriangulo = AreaTriangulo(A, B, C);

    // Exibindo a área do triângulo
    printf("A area do triangulo ABC e %.2f\n", areaTriangulo);

    return 0;
}
