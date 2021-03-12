/* Program demonstrira jednostavnu upotrebu pokazivaca. 
 * 
 * Pokazivac je promenljiva koja sadrzi adresu nekog objekta u memoriji.
 * Ako je T proizvoljan tip, a x je promenljiva tipa T, tada je &x izraz cija vrednost 
 * je tipa T*, tj pokazivac na tip T
 * T x;
 * 
 * Ako je p definisan pokazivac na tip T i inicijalizovan na adresu od  x.
 * T *p;
 * p = &x; 
 * kazemo da p pokazuje na x
 * Onda izraz *p je tipa int i ima vrednost koju ima x.
 * 
 * *p = 2;  
 * Sada smo promenili vrednost na 2 objektu na koji p pokazuje.
 * 
 * Operator referenciranja & primenjen na neki objekat odredjuje adresu tog
 * objekta u memoriji
 * Operator & se ne moze primenljivati na izraze i konstante.
 */

#include <stdio.h>

 /* main funkcija */
int main()   {
    int x =1, y=3;
    
    /* p je pokazivac na tip int, odnosno *p je tipa int.*/
    int *p;
    /* Operator referenciranja & primenjen na neki objekat odredjuje adresu tog
     * objekta u memoriji. Ne moze primenljivati na izraze i konstante.
     *
     *  Nakon sledece naredbe dodele, kazemo da p pokazuje na x. 
     *  Onda izraz *p je tipa int i ima vrednost koju ima x.
     */
    p = &x; 

    /* Prikaz vrednosti x preko pokazivacke promenljive p  */
    printf("Vrednost promenljive x: %d\t y: %d\n", *p, y);

    /* menjamo vrednost promenljivoj y sada na istu vrednost koju ima promenljiva
     na koju pokazuje p, tj na vrednost promenljive x, u nasem slucaju. */
    y = *p;
    *p =  0;   /* sada smo promenljivoj na koju p pokazuje, u nasem slucaju x,  vrednost postavili na 0, */
    
   /* Prikaz vrednosti x i y nakon promena */
    printf("Vrednost promenljive x: %d\t y: %d\n",x, y);
    
    /* Promena vrednosti promenljive x preko pokazivaca p koji na nju pokazuje */
    p = &x;
    *p = *p + 10;
    printf("Vrednost promenljive x: %d\t y: %d\n",x, y);

    ++*p ; /*uvecava se vrednost x za 1 */ 
    printf("Vrednost promenljive x: %d\t y: %d\n",x, y);

    (*p)++ ; /*uvecava se vrednost x za 1 */ 
    printf("Vrednost promenljive x: %d\t y: %d\n",x, y);

    return 0;
}

