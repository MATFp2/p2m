/* 
 * Program ucitava imena i prezimena gradjana (najvise njih 1000) i kreira biracke spiskove.
 * Jedan biracki spisak je sortiran po imenu gradana, a drugi po prezimenu gradana. 
 * Program koji ucitava spisak gradana (najvise 1000) i ispisuje koliko gradana ima isti redni 
 * broj u oba biracka spiska. Pretpostaviti da je za ime, odnosno prezime gradjana dovoljno 14 karaktera.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define MAX_DUZINA 15

typedef struct gr{
       char ime[MAX_DUZINA];
       char  prezime[MAX_DUZINA];
} Gradjanin;

/* Fja sortira niz gradjana rastuce po imenima */
void sort_ime(Gradjanin a[], int n) {
    int i, j;
    int min;
    Gradjanin pom;

    for (i = 0; i < n - 1; i++) {
        /* Unutrasnja petlja pronalazi poziciju min, na kojoj se nalazi
            najmanji od elemenata a[i].ime,...,a[n-1].ime. */
        min = i;
        for (j = i + 1; j < n; j++)
        if (strcmp(a[j].ime, a[min].ime) < 0)
            min = j;

        /* Zamena elemenata na pozicijama (i) i min. Ovo se radi samo ako
            su (i) i min razliciti, inace je nepotrebno. */
        if (min != i) {
            pom = a[i];
            a[i] = a[min];
            a[min] = pom;
        }
    }
}

/* Fja sortira niz gradjana rastuce po prezimenima */
void sort_prezime(Gradjanin a[], int n)  {
    
    int i, j;
    int min;
    Gradjanin pom;

    for (i = 0; i < n - 1; i++)  {
        /* Unutrasnja petlja pronalazi poziciju min, na kojoj se nalazi
            najmanji od elemenata a[i].prezime,...,a[n-1].prezime. */
        min = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(a[j].prezime, a[min].prezime) < 0)
                min = j;

        /* Zamena elemenata na pozicijama (i) i min. Ovo se radi samo ako
            su (i) i min razliciti, inace je nepotrebno. */
        if (min != i) {
            pom = a[i];
            a[i] = a[min];
            a[min] = pom;
        }
    }
}

/* Pretraga niza Gradjana */
int linearna_pretraga(Gradjanin a[], int n, Gradjanin* x )  {
    int i;
    for (i = 0; i<n; i++)
        if (strcmp(a[i].ime, x->ime) == 0 && strcmp(a[i].prezime, x->prezime) == 0)
            return i;
    return -1;	
}        


int main() {   
    Gradjanin spisak1[MAX], spisak2[MAX];
    int isti_rbr=0;
    int i, n;
    
    FILE *fp = NULL;
    
     if(( fp = fopen("biracki_spisak.txt", "r"))== NULL)  {
        fprintf(stderr, "Neupesno otvaranje datoteke biracki_spisak.txt.\n" );	
        exit(EXIT_FAILURE); 
    }

    for(i=0; fscanf(fp,"%s %s", spisak1[i].ime, spisak1[i].prezime)!=EOF ;i++ )
             spisak2[i]=spisak1[i];
             
    n = i;    
    
    fclose(fp);
         
    sort_ime(spisak1, n);
    
	printf("\n\nBiracki spisak [uredjen prema imenima]:\n");
    for(i=0; i<n; i++)
             printf(" %d. %s %s\n",i,spisak1[i].ime, spisak1[i].prezime);         
   
   sort_prezime(spisak2, n);
    printf("\n\nBiracki spisak [uredjen prema prezimenima]:\n");
    for(i=0; i<n; i++)
             printf(" %d. %s %s\n",i,spisak2[i].ime, spisak2[i].prezime);         
   
   /* Linearno pretrazivanje nizova */
   for(i=0; i<n ;i++)
            if( i == linearna_pretraga(spisak2,n, &spisak1[i]))
                isti_rbr++;
                
    /* Alternativno resenje */
    /*	
    for(i=0; i<n ;i++)
            if( strcmp(spisak2[i].ime, spisak1[i].ime) == 0 && strcmp(spisak1[i].prezime, spisak2[i].prezime)==0)
                isti_rbr++;
    */

    printf("\n\nGradjana koji imaju isti redni broj na oba spiska ima : %d.\n",isti_rbr);    
    
    exit(EXIT_SUCCESS);
}
