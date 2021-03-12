/* 4. Napisati program koji ispisuje broj navedenih argumenata komandne linije,
 a zatim i same argumenate i njihove redne brojeve. */

#include <stdio.h>

/* int argc -- broj argumenta komandne linije
   char **argv --pokazivac na pokazivac na char koji sadrzi adresu
   prvog u nizu pokazivaca na karaktere. Svaki od tih pokazivaca na karaktere 
   sadrzi adresu odgovarajuce niske koja je argument komandne linije.*/

/* char *argv[]  <==>  char** argv   */
int main(int argc, char *argv[]){
    int i;

    printf("Broj argumenata je: %d\n",argc);
    
    /*ispisujemo argumente*/
    printf("\n");
    /* koristeci nizovsku strukturu*/
    for(i=0; i<argc; i++){
        printf("%d %s\n",i,argv[i]);
    }
    
    printf("\n");
    /*koristeci pokazivacku sintaksu*/
    i=argc;
    for (; argc>0; argc--)
        printf("%d %s\n",i-argc,*argv++);

    /* Nakon ove petlje argc =0 i argv je skroz pomeren na kraj, tj pokazuje na polje 
     * u memoriji koje dodje posle poslednjeg argumenta komandne linije.
     * Kako smo u i sacuvali vrednost broja argumenta mozemo da ponovo
     * postavimo argv da pokazuje na 0-ti argument komandne linije 
     */
    argv = argv - i;
    argc = i; 
    /* ispisacemo sa 0-ti karakter svako od argumenata */
    printf("\n");
    
    /* koristeci nizovsku sintaksu */
    for(i=0; i<argc; i++){
        printf("%c\n", argv[i][0]);
    }
    printf("\n");
    
    /* koristeci pokazivacku sintaksu */
    for (i=0 ; i<argc; i++ )
        printf("%c\n", **argv++);
    
    return 0;
}
