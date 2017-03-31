#include <stdio.h>
#include <stdlib.h>


// Implementare l'esponente negativo

int main() {

    int a, b, i;
    long ris;
    char input_user[10];

    printf("Inserire la base\n");
    fgets(input_user, sizeof(input_user), stdin);
    a = atoi(input_user);

    printf("Inserire l\'esponente\n");
    fgets(input_user, sizeof(input_user), stdin);
    b = atoi(input_user);

    ris = 1;

    for(i=0; i<b; i++) {
        ris *= a;
    }

    printf("Il risultato: %ld\n", ris);

    return 0;

}
