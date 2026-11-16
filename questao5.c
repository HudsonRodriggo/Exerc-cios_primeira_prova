#include <stdio.h>
#include <stdlib.h>

#define N 1000

void inserir(int *vetor, int *ocupado, int valor) {
    int indice, i, posicaoAtual;
    indice = ((valor % N) + N) % N;

    for (i = 0; i < N; i++) {
        posicaoAtual = (indice + i) % N;
        if (ocupado[posicaoAtual] == 0) {
            vetor[posicaoAtual] = valor;
            ocupado[posicaoAtual] = 1;
            printf("Valor inserido na posicao %d", posicaoAtual);
            return;
        }
    }
    printf("Vetor cheio!");
}

void buscar(int *vetor, int *ocupado, int valor) {
    int indice, i, posicaoAtual;
    indice = ((valor % N) + N) % N;

    for (i = 0; i < N; i++) {
        posicaoAtual = (indice + i) % N;
        if (ocupado[posicaoAtual] == 0) {
            printf("Valor nao encontrado.");
            return;
        }
        if (vetor[posicaoAtual] == valor) {
            printf("Valor encontrado na posicao %d", posicaoAtual);
            return;
        }
    }
    printf("Valor nao encontrado.");
}

int main() {
    int *vetor, *ocupado;
    int escolha, valor;

    vetor = malloc(N * sizeof(int));
    ocupado = calloc(N, sizeof(int));

    if (vetor == NULL || ocupado == NULL) {
        printf("Erro na alocacao de memoria.");
        free(vetor);
        free(ocupado);
        return 1;
    }

    do {
        printf("\n1 - Inserir valor");
        printf("\n2 - Buscar valor");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir(vetor, ocupado, valor);
        } else if (escolha == 2) {
            printf("Digite o valor que deseja buscar: ");
            scanf("%d", &valor);
            buscar(vetor, ocupado, valor);
        } else if (escolha != 0) {
            printf("Opcao invalida.");
        }
    } while (escolha != 0);

    free(vetor);
    free(ocupado);
    return 0;
}
