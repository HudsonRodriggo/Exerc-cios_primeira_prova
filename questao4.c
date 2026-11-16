#include <stdio.h>

int main() {
    int quantidade, i, mulher;
    float valor, total1 = 0, total2 = 0, diferenca;

    printf("Quantidade de pagamentos: ");
    scanf("%d", &quantidade);

    for (i = 0; i < quantidade; i++) {
        printf("\nValor do pagamento: ");
        scanf("%f", &valor);
        printf("Quem pagou? (1 ou 2): ");
        scanf("%d", &mulher);

        if (mulher == 1) {
            total1 += valor;
        } else if (mulher == 2) {
            total2 += valor;
        } else {
            printf("Pessoa invalida!");
            i--;
        }
    }

    printf("Total pago pela mulher 1: R$ %.2f\n", total1);
    printf("Total pago pela mulher 2: R$ %.2f\n", total2);

    diferenca = total1 - total2;

    if (diferenca > 0) {
        printf("A mulher 2 deve devolver R$ %.2f para a mulher 1.", diferenca / 2);
    } else if (diferenca < 0) {
        printf("A mulher 1 deve devolver R$ %.2f para a mulher 2.", -diferenca / 2);
    } else {
        printf("As duas pagaram o mesmo valor. Nao ha necessidade de compensacao.");
    }

    return 0;
}

