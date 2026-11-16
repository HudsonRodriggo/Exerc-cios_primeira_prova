#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float n1, n2, n3;
    float reposicao, NT;
    float media;
    char situacao[ 30 ];
} Aluno;

int main() {
    int n, i, j, menorIndice;
    float notas[ 4 ], soma, mediaTresMaiores;
    Aluno *alunos;

    scanf("%d", &n);
    if (n < 1 || n > 50) {
        return 1;
    }

    alunos = malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%f", &alunos[i].n1);
        scanf("%f", &alunos[i].n2);
        scanf("%f", &alunos[i].n3);
        scanf("%f", &alunos[i].reposicao);
        scanf("%f", &alunos[i].NT);

        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3;

        if (alunos[i].media >= 7) {
            strcpy(alunos[i].situacao, "Aprovado direto");
        } else {
            notas[ 0 ] = alunos[i].n1;
            notas[ 1 ] = alunos[i].n2;
            notas[ 2 ] = alunos[i].n3;

            menorIndice = 0;
            for (j = 1; j < 3; j++) {
                if (notas[j] < notas[menorIndice]) {
                    menorIndice = j;
                }
            }

            notas[menorIndice] = alunos[i].reposicao;
            alunos[i].media = (notas[ 0 ] + notas[ 1 ] + notas[ 2 ]) / 3;

            if (alunos[i].media >= 7) {
                strcpy(alunos[i].situacao, "Aprovado na reposicao");
            } else {
                notas[ 0 ] = alunos[i].n1;
                notas[ 1 ] = alunos[i].n2;
                notas[ 2 ] = alunos[i].n3;
                notas[ 3 ] = alunos[i].reposicao;

                soma = 0;
                menorIndice = 0;
                for (j = 0; j < 4; j++) {
                    soma += notas[j];
                    if (notas[j] < notas[menorIndice]) {
                        menorIndice = j;
                    }
                }

                mediaTresMaiores = (soma - notas[menorIndice]) / 3;
                alunos[i].media = (mediaTresMaiores + alunos[i].NT) / 2;

                if (alunos[i].media >= 6) {
                    strcpy(alunos[i].situacao, "Aprovado na final");
                } else {
                    strcpy(alunos[i].situacao, "Reprovado");
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Media: %.2f\n", alunos[i].media);
        printf("Situacao: %s\n", alunos[i].situacao);
    }

    free(alunos);
    return 0;
}
