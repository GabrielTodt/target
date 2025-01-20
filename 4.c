#include <stdio.h>

int main(int argc, char const *argv[])
{
    float sp = 67836.43;
    float rj = 36678.66;
    float mg = 29229.88;
    float es = 27165.48;
    float outros = 19849.53;
    
    float total = sp + rj + mg + es + outros;
    float porcentagem_sp = (sp / total) * 100;
    float porcentagem_rj = (rj / total) * 100;
    float porcentagem_mg = (mg / total) * 100;
    float porcentagem_es = (es / total) * 100;

    printf("Percentual de São Paulo: %f%%\n", porcentagem_sp);
    printf("Percentual do Rio de Janeiro: %f%%\n", porcentagem_rj);
    printf("Percentual de Minas Gerais: %f%%\n", porcentagem_mg);
    printf("Percentual do Espirito Santo: %f%%\n", porcentagem_es);
    return 0;
}
