#include "sort.h"

/* Iterativna verzija funkcije koja sortira niz celih brojeva, primenom algoritma Selection Sort */
void selectionSort(int a[], int n) {
    int i, j;
    int min;
    int pom;

    /* U svakoj iteraciji ove petlje se pronalazi najmanji element medju
       elementima a[i], a[i+1],...,a[n-1], i postavlja se na poziciju i,
       dok se element na poziciji i premesta na poziciju min, na kojoj se
       nalazio najmanji od gore navedenih elemenata. */
    for (i = 0; i < n - 1; i++) {
        /* Unutrasnja petlja pronalazi poziciju min, na kojoj se nalazi
         *  najmanji od elemenata a[i],...,a[n-1]. */
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        /* Zamena elemenata na pozicijama (i) i min. Ovo se radi samo
         * ako  su (i) i min razliciti, inace je nepotrebno. */
        if (min != i) {
            pom = a[i];
            a[i] = a[min];
            a[min] = pom;
            }
    }
}


/* Rekurzivna implementacija Selection Sort algoritma kojim se sortira
 * u rastućem poretku niz celih brojeva  */
void selectionSort_rec(int a[], int n) {
    /* Izlaz iz rekurzije - Ako niz ima manje od 2 elementa */
    if ( n < 2 )
        return;
    
    /* Trazimo indeks minimalnog elementa niza a da bismo 
     *taj element smestili na 0-tu poziciju */ 
    int min, i;
    
    for( i= 0, min=0; i<n; i++)
        if( a[min] > a[i] )
            min = i;  
        
    /* ukoliko minimalni element vec nije na 0-toj poziciji smestamo ga. */
    if( min != 0)
        swap(a, min, 0);
    
    /*  Rekurzivni  poziv  - sortiramo preostalih  n-1 elemenata niza 
     * pocevsi od a[1]  */
    selectionSort_rec(a+1,n-1);
}





/* 	F-ja imlplementira algoritam sortiranja merge sort 
 * 	Algoritam ucesljava levu i desnu polovinu niza  */
void mergeSort(int  a[], int levi, int desni) {
    int i, j, k;              /* brojacke promenljive */
    static int b[MAX];     /* pomocni niz u koji smestamo ucesljane elemente */

    /* Izlaz iz rekurzije  */
    if( levi >= desni)
        return;
    
    /* odredjujemo indeks srednjeg elementa niza  */
    int srednji = ( levi + desni ) / 2;	

    /* Rekurzivni pozivi - za sortiranje prve i druge polovine niza */
    mergeSort(a, levi, srednji );
    mergeSort(a, srednji + 1, desni );

    /* Sada jos da ucesljamo sortirane polovine */
    /* Inicijalizujemo brojacke promenljive,  i je indeks elementa u levoj polovini.
     * j indeks elemenata u desnoj polovini. indeks k je indeks elementa  u  pomocnom nizu b   */
    i = levi; 
    j = srednji+1;
    k = 0;

    /* Dok ima elemenata u obe polovine */
    while( i <=srednji && j <= desni)
        if (a[i] < a[j])
            b[k++] = a[i++];
        else 
            b[k++] = a[j++];

    /* Ukoliko ima jos neki preostao iz prve polovine, prepisujemo */    
    while( i<= srednji)
        b[k++] = a[i++];
    
     /* Ukoliko je preostao neki element iz druge polovine, prepisujemo ga u niz b */    
    while(j<=desni)
        b[k++]=a[j++];
        
    /* prepisujemo ucesljani niz  b u niz a na pozicije od levog do desnog indeksa */
    for( i=levi, k=0; i<=desni ; i++, k++)
        a[i]=b[k];
}




/* Funkcija sortira deo niza celih brojeva  izmedju pozicija levi i desni */
void quickSort(int a[], int levi, int desni) {
    int pivotPozicija;
    int i, s, pivot;
    
    /* Izlaz iz rekurzije - prazan niz */
    if(levi >= desni)
        return;

    /* PARTICIONISANJE NIZA: 
     *    Svi elementi na pozicijama manjim ili jednakim od pivotPozicija
     *    (izuzev same pozicije levi) su strogo manji od pivota. Kada se  
     *    pronadje neki element manji od pivota, uvecava se pivotPozicija i 
     *    na tu poziciju se stavlja nadjeni element. Na kraju ce pivotPozicija 
     *    biti zaista pozicija na koju treba smestiti pivot, jer ce svi elementi 
     *    levo od te pozicije biti manji, a desno veci ili jednaki od pivota.
     */

    /* Biramo da pivot bude srednji element niza, a potom ga razmenjujemo 
    sa krajnim levi elementom niza. */
    s =  (levi+desni)/2;
    pivot= a[s];
    swap( a, levi,s);

    /* Pravu poziciju pivota trazimo pocev od krajnjeg levog.  */
    pivotPozicija=levi;
    for(i=levi+1; i<= desni; i++)
        if( a[i] < a[levi] )
            swap( a, ++pivotPozicija, i );	/* uveca*/

    /* Postavljamo pivot na njegovo mesto u sortiranom nizu */
    swap( a, levi, pivotPozicija);

    /* Rekurzivno sortiramo elemente manje od pivota*/
    quickSort(a, levi, pivotPozicija-1);
    
    /* Rekurzivno sortiramo elemente vece od  pivota */
    quickSort(a, pivotPozicija+1, desni );
}


/* Funkcija razmenjuje mesta elementima u nizu a na pozicijama i i j  */
void swap( int a[], int i, int j) {
    int tmp;

    tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}

