#include <stdio.h>
#include <string.h>

int main() {
    char frase1[101], frase2[101];
    char *palavras1[10], *palavras2[10];
    char *palavra;
    int qtd1 = 0, qtd2 = 0;
    int i, j, encontrou;
    int usadas[10] = {0};
    int iguais = 1;

    printf("Digite a primeira frase: ");
    fgets(frase1, 101, stdin);

    printf("Digite a segunda frase: ");
    fgets(frase2, 101, stdin);

    frase1[strcspn(frase1, "\n")] = '\0';
    frase2[strcspn(frase2, "\n")] = '\0';

    palavra = strtok(frase1, " ");
    while (palavra != NULL && qtd1 < 10) {
        palavras1[qtd1] = palavra;
        qtd1++;
        palavra = strtok(NULL, " ");
    }

    palavra = strtok(frase2, " ");
    while (palavra != NULL && qtd2 < 10) {
        palavras2[qtd2] = palavra;
        qtd2++;
        palavra = strtok(NULL, " ");
    }

    if (qtd1 != qtd2) {
        iguais = 0;
    } else {
        for (i = 0; i < qtd1; i++) {
            encontrou = 0;
            for (j = 0; j < qtd2; j++) {
                if (usadas[j] == 0 && strcmp(palavras1[i], palavras2[j]) == 0) {
                    usadas[j] = 1;
                    encontrou = 1;
                    break;
                }
            }
            if (encontrou == 0) {
                iguais = 0;
                break;
            }
        }
    }

    if (iguais == 1) {
        printf("Mesmas palavras");
    } else {
        printf("Palavras diferentes");
    }

    return 0;
}
