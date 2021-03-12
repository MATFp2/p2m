/* Program modifikuje elemente niza,  koriscenjem pokazivacke sintakse */
#include <stdio.h>

#define MAX 100


/* Funkcija povecava za jedan sve elemente u prvoj polovini i smanjuje za 1 
 * elemente u desnoj polovini. Ukoliko niz ima neparan broj elemenata srednji 
 * ostaje netaknut. 
 */
void povecaj_smanji (int *a , int n) {
     int *prvi = a;
     int *poslednji = a+n-1;
    
     while( prvi < poslednji ){
         (*prvi)++;  /* povecava se vrednost elementa na koji prvi pokazuje */
         prvi++;        /* pomera se pokazivac na sledeci element */
         (*poslednji)--;   /* smanjuje se vrednost elementa na koji poslednji pokazuje */
         poslednji--;       /* pomera se pokazivac na element ispred */
    }
}


void povecaj_smanji_sazetije(int *a , int n) {
     int *prvi = a;
     int *poslednji = a+n-1;
    
     while( prvi < poslednji ){
         (*prvi++)++;
         (*poslednji--)--;
    }
}


/* glavna Funkcija*/
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
    
    povecaj_smanji(a,n);
//     povecaj_smanji_sazetije(a,n);
    
    /* Prikaz niza */
    printf("Niz nakon modifikacije:\n");
    for(p = a; p - a < n; p++)
        printf("%d ", *p);
    
    printf("\n");
    
    return 0;
}


