#include <stdio.h>

int length1;
int length2;

int main() {
    printf("Introduzca la longitud de la lista a l1: ");
    scanf("%d", &length1);
    int l1[length1];
    printf("Introduzca valor a valor la lista l1: ");
    for (int i = 0; i < length1; i++) {
        scanf("%d", &l1[i]);
    }
    printf("Introduzca la longitud de la lista a l2: ");
    scanf("%d", &length2);
    int l2[length2];
    printf("Introduzca valor a valor la lista l2: ");
    for (int i = 0; i < length2; i++) {
        scanf("%d", &l2[i]);
    }
    int selection;
    do {
        printf ("\n\nIndique que desea hacer con ella: \n 1- Length[l1]: Devuelve la longitud de la lista\n 2- Join[l1,l2]: Concatena dos listas\n 3- Union[l1,l2]: Devuelve una lista ordenada de los elementos que están en l1 o en l2\n 4- Intersection[l1,l2]: Devuelve una lista ordenada de los elementos comunes de ambas\n 5- Complement[l1,l2]: Devuelve una lista con los elementos de l1 que no estan en l2\n 6- Sort[l1]: Devuelve l1 ordenada de menor a mayor\n 7- SortReverse[l1]: Devuelve l1 ordenada de mayor a menor\n 8- Reverse[l1]: Devuelve el reverso de l1\n 9- RotateRight[l1]: Devuelve l1 con todos los elementos rotados a la derecha\n 10- RotateLeft[l1]: Devuelve l1 con todos los elementos rotados a la izquierda\n 11- First[l1]: Devuelve el primer elemento de l1\n 12- Rest[l1]: Devuelve la lista sin su primer elemento\n 13- Drop[l1, n]: Devuelve la lista sin sus n primeros elementos\n 14- Take[l1, n]: Devuelve los n primeros números de la lista\n 15- Append[l1,x]: Añade un elemento x al final\n 16- Prepend[l1, x]: Añade un elemento x al principio\n 17- Position[l1,x]: Devuelve una lista con las posiciones de x en l1\n 18- MemberQ[l1,x]: Devuelve True si x pertenece a l1 y False si no\n 19- Edit[l1]: Editar la lista\n 20- Salir\n\n");
        scanf("%d", &selection);
        switch (selection) {
            case 1: printf("De que lista desea obtener la longitud?\n 1- L1\n 2- L2\n");
                    int selection2;
                    scanf("%d", &selection2);
                    if (selection2 = 1) {
                        printf("[1] L1 tiene una longitud de %d valores\n", length1);
                    } else if (selection2 = 2) {
                        printf("[1] L2 tiene una longitud de %d valores\n", length2);
                    }
                    break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                printf("Función no implementada.");
                return 0;
            default: return 0;
        }
    } while (selection != 20);
    return 0;
}
