#include <stdio.h>

void declaration(char c, int length, char line1[], char line2[]) {
    for (int i = 0; i < length; i++) {
        line1[i] = c;
        line2[i] = c;
    }
}

void printhalf(char c, int length, char line1[], char line2[]) {
    for (int i = 0; i < length; i++) {
        line1[length - (i+1)] = c;
        line2[i] = c;
        printf("%s%s\n", line1,line2);
    }
}

int main() {
    int length;
    printf("Ingrese la longitud del polígono deseada: ");
    scanf("%d", &length);
    char line1[length];
    char line2[length];
    declaration(' ', length, line1, line2);
    printhalf('C', length, line1, line2);
    declaration('C', length, line1, line2);
    printhalf(' ', length, line1, line2);
    return 0;
}
