#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c, somma;
    float media;
    char input_user[10];
    
    c = 0;
    somma = 0;
    media = 0;
    
    do{
        printf("Inserisci un numero\n");
        fgets(input_user, sizeof(input_user), stdin);
        n = atoi(input_user);
        
        if(n==0) {
            if(media) {
                printf("Somma: %d\n", somma);
                printf("Numeri: %d\n", c);
                printf("Media: %f\n", media);
            }else{
                printf("Non hai inserito numeri\n");
            }
            
            return 0;            
        }
        
        c++;
        somma += n;
        media = (float)somma / c;
    
    }while(1);

}
