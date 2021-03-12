/* Program demonstrira upotrebu pokazivaca na prazan tip.
 * 
 * Pored pokazivaca na promenljive osnovnih tipovova, postoji i 
 * pokazivac na prazan tip (void). 
 * Pokazivac tipa (void*) se moze nazivati i genericki pokazivac. 
 * Takav pokazivac moze da pokazuje na objekat bilo kog drugog tipa, 
 * Da bismo koristili objekat na koji pokazuje takav pokazivac moramo 
 * svaki put eksplicitno da naglasimo kog je tipa podatak koji cemo
 * koristiti.
 */

#include <stdio.h>

int main()
{
    void *pp = NULL ; /* pp je pokazivac na prazan tip i trenutno ne pokazuje ni na sta. */
    int x = 2;
    char c = 'a';

    pp = &x;            /* pp sada ima vrednost adrese celobrojne promenljive x, tj pp pokazuje na x */
    *(int *)pp = 17;	/* x postaje 17.  
    Morali smo ekplicitno d kastujemo pp u tip (int*), da bi se primenom operatora dereferenciranja * na takvo pp, sa
    adrese koja se cuva u pp pristupilo 1 int-u.
    */
    printf("Adresa promenljive x je %p\n", &x);
    printf("%d i %p i %p\n\n", *(int*)pp, pp , (int *)pp);

    pp = &c;       /* Sada pp pokazuje na karaktersku promenljivu c*/ 
    printf("Adresa promenljive c je %p\n", &c);
    printf("%c i %p\n", *(char*)pp, (char *)pp);

    return 0;
}

