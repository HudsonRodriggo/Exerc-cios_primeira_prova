#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int somaSequencia, maiorSoma;
    int *vetor;
    int inicio, fim, inicioAtual;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Quantidade invalida!");
        return 1;
    }

    vetor = (int *) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocacao");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", vetor + i);
    }

    somaSequencia = *(vetor);
    maiorSoma = *(vetor);
    inicio = 0;
    fim = 0;
    inicioAtual = 0;

    for (i = 1; i < n; i++) {
        if (somaSequencia + *(vetor + i) < *(vetor + i)) {
            somaSequencia = *(vetor + i);
            inicioAtual = i;
        } else {
            somaSequencia += *(vetor + i);
        }

        if (somaSequencia > maiorSoma) {
            maiorSoma = somaSequencia;
            inicio = inicioAtual;
            fim = i;
        }
    }

    printf("Maior soma: %d", maiorSoma);
    printf("\nSubsequencia: ");
    for (i = inicio; i <= fim; i++) {
        printf("%d ", *(vetor + i));
    }

    free(vetor);
    return 0;
}
