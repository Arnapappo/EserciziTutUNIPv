#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, max;
    int primo = 1; //Boolean
    char input_user[10];
    
    printf("(Il numero 0 termina il programma)\n");

    do{
        printf("Inserisci un numero\n");
        fgets(input_user, sizeof(input_user), stdin);
        n = atoi(input_user);

        if(n==0){
            if(!primo){
                printf("Massimo: %d\n", max);
            }else{
                printf("Non hai inserito numeri\n");
            }
            
            return 0;
        }
        
        if(primo) {
            max = n;
            primo = 0;
        }else if(n>max) {
            max = n;
        }

    }while(1);

}
