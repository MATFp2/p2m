/* Program obrce elemente niza,  koriscenjem pokazivacke sintakse */
#include <stdio.h>

#define MAX 100

/* Funkcija obrce niz tako koriscenjem indekse sintakse */
void obrni_Niz_v1(int a[] , int n) {
    int i, j;
   /* Obrcemo niz */
    for(i = 0, j = n-1; i < j; i++, j--)
    {
          int t = a[i];
          a[i] = a[j];
          a[j] = t;
    }
}      


/* Funkcija obrce niz a koji joj se salje kao argument funkcije
 * Potpis bi mogao da izgleda i ovako 
 *     void obrni_Niz(int a[], int n)
 * sto je sto se C-a tice potpuno isto. Kako od mi napisali, argument a se tumaci kao 
 * pokazivac, tacnije, kao adresa prvog elementa niza i u odnosu na njega 
 * odredjuju se adrese ostalih elemenata.
*/
void obrni_Niz_v2(int *a, int n) {
    int *prvi, *poslednji;   /* Pokazivaci na elemente niza a */
    
    /* Obrcemo niz */
    for(prvi = a, poslednji = a + n - 1; prvi < poslednji; prvi++, poslednji--)
    {
          int t = *prvi;
          *prvi = *poslednji;
          *poslednji = t;
    }
}

/* Malo modifikovano koriscenje pokazivaca */
void obrni_Niz_v3(int *a, int n) {
    int *prvi, *poslednji;   /* Pokazivaci na elemente niza a */
    
    /* Obrcemo niz */
    for(prvi = a, poslednji = a + n - 1; prvi < poslednji;  )
    {
          int t = *prvi;
          /* inkrementiramo sada, jer poslednji put u iteraciji koristimo pokazivac prvi, 
           *i tako ga pripremimo za proveru uslova ostanka u petlji 
           * Operator ++ je veceg prioriteta od * ali kako se ovde koristi postinkrementiranje, 
           * na staru vrednost pokazivaca se primeni operator dereferenciranja i onda se na 
           * tu adresu stavi vrrednost koja je na adresi poslednji. Potom se inkrementira prvi,
           * sto za posledicu ima da prvi pokazuje na sledeci element u nizu
           */
          *prvi++ = *poslednji; 
          /* Iz istog razloga sada smanjujemo poslednji, a ne ranije 
           * Analogno kao za ++ , sada se prvo postavi vrednost t na staru adresu na koju je pokazivao poslednji,
           *  a potom se smanji, i pokazuje na element ispred prethodnog.
           */
          *poslednji-- = t;
    }
}

int main()
{
    int a[MAX];   /* Deklaracija niza a od najvise MAX elemenata */
    int n;        /* Broj elemenata niza a */
    int *p;   /* Pokazivac na elemente niza a */
    
    /* Unosimo broj elemenata */
    printf("Uneti broj elemenata niza (<= 100): ");
    scanf("%d", &n);
    
    /* Proveravamo da li je prekoraceno ogranicenje */
    /* n se postavlja na MAX u slucaju da je uneta veca vrednost */
    if( n > MAX )
        n = MAX;   
        
    /* Unosimo elemente niza */
    printf("Uneti elemente niza:\n");
    for(p = a; p - a < n; p++)
          scanf("%d", p);
          
    /* Prikaz niza */
    printf("Uneli ste niz:\n");
    for(p = a; p - a < n; p++)
          printf("%d ", *p);
    
    printf("\n");
    
    obrni_Niz_v1(a,n);
//    obrni_Niz_v2(a,n);
//    obrni_Niz_v3(a,n);
     
     
    /* Prikaz niza */
    printf("Niz nakon obrtanja:\n");
    for(p = a; p - a < n; p++)
          printf("%d ", *p);
    
    printf("\n");
    
    return 0;
}


