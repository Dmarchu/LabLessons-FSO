#include<stdio.h>

int main() {
    printf("Please enter a number to receive its factorial: ");
    int num;
    do { scanf("%d", &num);
        if (num < -12 || num > 12) {printf("\nWrong integer input.\n");}
    } while (num <= 0);
    int num2 = num;
    int temp = num - 1;
    for (temp; temp > 0; temp--) {
        num *= temp;
    }
    printf("The factorial of %d it's %d \n", num2, num);
    return 0;
}
