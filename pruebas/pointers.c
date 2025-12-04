#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const int length = 100;
char cadena[100];

void UpperCase() {
    char *p1 = cadena;
    printf("-upr: ");
    while (*p1 != '\0') {
        if (*p1 >= 97 && *p1 <= 122) {
            *p1 -= 32;
        }
        printf("%c", *p1);
        p1++;
    }
    printf("\n");
}

void LowerCase() {
    char *p1 = cadena;
    printf("-lwr: ");
    while (*p1 != '\0') {
        if (*p1 >= 65 && *p1 <= 90) {
            *p1 += 32;
        }
        printf("%c", *p1);
        p1++;
    }
    printf("\n");
}

void TrimCase() {
    char *p1 = cadena;
    printf("-ctrim: ");
    while (*p1 != '\0') {
        if (*p1 == 32) {
            *p1 = *(p1 + 1);
            if (*(p1 + 1) == '\0') {
                break;
            } else {
                continue;
            }
        }
        printf("%c", *p1);
        p1++;
    }
    printf("\n");
}

void FUpperCase() {
    char *p1 = cadena;
    bool encounter = true;
    printf("-fupr: ");
    while (*p1 != '\0') {
        if (*p1 == 32) {
            encounter = true;
        } else if (encounter) {
            if (*p1 >= 97 && *p1 <= 122) {
                *p1 -= 32;
            }
            encounter = false;
        }
        printf("%c", *p1);
        p1++;
    }
    printf("\n");
}

void FLowerCase() {
    char *p1 = cadena;
    bool encounter = true;
    printf("-flwr: ");
    while (*p1 != '\0') {
        if (*p1 == 32) {
            encounter = true;
        } else if (encounter) {
            if (*p1 >= 65 && *p1 <= 90) {
                *p1 += 32;
            }
            encounter = false;
        }
        printf("%c", *p1);
        p1++;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Enter a text to edit: ");
        scanf("%[^\n]s", &*cadena);
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-upr") == 0) {
                UpperCase();
            } else if (strcmp(argv[i], "-lwr") == 0) {
                LowerCase();
            } else if (strcmp(argv[i], "-ctrim") == 0) {
                TrimCase();
            } else if (strcmp(argv[i], "-fupr") == 0) {
                FUpperCase();
            } else if (strcmp(argv[i], "-flwr") == 0) {
                FLowerCase();
            } else if (argc != 0) {
                printf("Argument %s is not valid!", argv[i]);
            }
        }
    } else {
        printf("Incorrect Usage: No arguments writen!\nWrite at least one of this arguments: \n -upr: Upper case\n -lwr: Lower case\n -ctrim: Delete spaces\n -fupr: First letter of all words to upper\n -flwr: First letter of all words to lower");
    }
    return 0;
}
