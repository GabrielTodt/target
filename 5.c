#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "inverter string";

    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("String invertida: %s\n", str);

    return 0;
}
