#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Vefificar se um número é um quadrado perfeito.
bool isPerfectSquare(int n) {
    int s = (int)sqrt(n);
    return s * s == n;
}

// Verificar se um número faz parte da sequência de fibonacci.
bool isFibonacci(int num) {
    // Um número é de Fibonacci se e somente se
    // (5 * n^2 + 4) ou (5 * n^2 - 4) é um quadrado perfeito
    return isPerfectSquare(5 * num * num + 4) || isPerfectSquare(5 * num * num - 4);
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    if (isFibonacci(num)) {
        printf("%d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("%d não pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}
