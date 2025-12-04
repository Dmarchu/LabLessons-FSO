#include<stdio.h>

int main() {
    printf("Introduzca la longitud del array a ordenar: ");
    int length;
    while (length <= 0) {
        scanf("%d", &length);
    }
    printf("\nAhora, introduzca uno a uno cada valor del array a ordenar:\n");
    int array[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    printf("Su array ordenado es:\n {");
    int min;
    int temp;
    int pos;
    for (int i = 0; i < length; i++) {
        min = array[i];
        pos = i;
        for (int j = i; j < length; j++) {
            if (min > array[j]) {
                min = array[j];
                pos = j;
            }
        }
        temp = array[i];
        array[i] = min;
        array[pos] = temp;
        if (i == length - 1) {printf(" %d ", min);}
        else {printf(" %d,", min);}
    }
    printf("}\n");
    return 0;
}
