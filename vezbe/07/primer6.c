/* Funkcije u C-u koje kao argument prihvataju niz, zapravo kao argument 
 * prihvataju adresu prvog elementa niza. Takvo ponasanje za posledice ima:
 *  - moramo da saljemo duzinu niza.(Osim za niske karaktera)
 *  - Bilo da u listi argumenata stoji double a[] ili double *a, kompajler sve
 *       tumaci kao double* a
 *  - Unutar tela funkcije a se koristi kao pokazivac na double. Posmatra se kao 
 * pokazivac na prvi element niza i sa a se moze raditi sve sto inace moze za 
 * pokazivackom promenljivom, ukljucujuci i promene vrednosti. Nebitno da li u 
 * potpisu funkcije stoji nizovska (double a[]) ili pokazivacka sintaksa (double *a)
 * 
 * - NIzovi se funkciji salju preko adrese prvog elementa.  Stoga se ne prave lokalne 
 * kopije citavog niza.
 * - Promene koje funkcija napravi na elementima niza odrazavaju se na originalni niz.
 * 
 * Funkcije u C-u nikada ne mogu da vrate niz preko povratne vrednosti. 
 * Mogu da vrate pokazivac, ali to nikako ne sme biti pokazivac na lokalnu promenljivu, 
 * pa ni ime lokalnog niza
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* Funkcija racuna zbir elemenata niza */
double zbir(double *a, int n) {
    double s = 0;
    int i;

    /* Sumiramo n elemenata niza */
    for(i = 0; i < n; s += a[i++]) ;

    return s;
}

/* Funkcija racuna najmanji element niza */
double min(double *a, int n) {
       double min = a[0];
       int i;
       
       /* Odredjujemo najmanji element */
       for(i = 1; i < n; i++)
                if ( a[i] < min )
                      min = a[i];
       
       return min;
}

/* Funkcija racuna proizvod elemenata niza */
double proizvod(double a[], int n) {
    double p = 1;
            
    /* Mnozimo n elemenata niza */
    for(; n; n--) 
        p *= *a++;

    return p;
}

/* Funkcija racuna najveci element niza */
double max(double *a, int n) {
    /* maximum je najpre prvi element */
    double max = *a;

    /* Odredjujemo najveci element
     * a se tretira kao pokazivac, pa moze da se izvrsi a++
     * da bi nam a pokazivalo na sledeci element     
     */
    for(a++, n--; n > 0; a++, n--)
        if ( *a > max )
                max = *a;

    return max;
}


int main() {
    double a[MAX];
    int n, i;
    
    /* Ucitavamo dimenziju niza */
    printf("Uneti broj elemenata niza (0 < n <= 100): ");
    scanf("%d", &n);
    /* Nephodno je da budemo sigurni da imamo bar neki element zbog funkcija min, max i proizvod*/
    if( n <= 0 ){ 
        fprintf(stderr, "Broj elemenata niza mora biti veci od 0!\n");
        exit(EXIT_FAILURE);
    }
    
    /* Proveravamo da li je dimenzija veca od MAX */
    if(n > MAX)
         n = MAX;
         
    /* Unosimo elemente niza */
    printf("Uneti elemente niza:\n");
    for(i = 0; i < n; i++)
          scanf("%lf", a + i);
          
    /* Pozivamo gornje funkcije i prikazujemo vrednosti */
    printf("Zbir elemenata niza je: %5.3f\n", zbir(a, n));
    printf("Proizvod elemenata niza je: %5.3f\n", proizvod(a, n));
    printf("Najveci element u nizu je: %5.3f\n", max(a, n));
    printf("Najmanji element u nizu je: %5.3f\n", min(a, n));      
    
    return 0;
}
 

             
