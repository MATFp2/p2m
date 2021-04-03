/*
Napraviti biblioteku "sort.h" i "sort.c" koja implementira algoritme sortiranja nizova celih brojeva. Biblioteka
treba da sadrzi  selection, quick i merge sort. 
Upotrebiti biblioteku kako bi se napravilo poredenje efikasnosti razlicitih algoritama sortiranja.  Efikasnost 
meriti na slucajno generisanim nizovima, na vec sortiranim nizovima i na opadajuce sortiranim nizovima. 
Zadavati velicinu i pocetni raspored elemenata u nizu kroz argumente komandne linije. 
Analizirati porast vremena sa porastom dimenzije n.
 */
/* pri prevodjenju program linkovati sa bibliotekom librt
   opciom -lrt zbog funkcije clock_gettime() */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

int main(int argc, char *argv[]) {
    /*
       tip_niza == 0 => slucajno generisani nizovi (default)
       tip_niza == 1 => sortirani nizovi (-r opcija komandne linije)
       tip_niza == 2 => obrnuto sortirani nizovi (-o opcija komandne linije)
     */
    int tip_niza = 0;
    int dimenzija = 0;    /* dimenzija niza koji se sortira */
    int i;
    int original[MAX], kopija[MAX];
    FILE *f = NULL ;   /* Pokazivac za datoteku u koju cemo pisati vremena izvrsavanja */
    
    char naziv_tipa_niza[20] = "slucajno generisan";
    /* strukture potrebne zbog preciznijeg merenja vremena izvrsavanja funkcija.
     * Sve vezano za merenje vremena izvrsavanja i generisanja nizova u ovom kodu 
     * je van gradiva Programiranja 2   */
    struct timespec time1, time2;
    

    if (argc < 2) {
        fprintf(stderr, "Program zahteva bar 2 argumenta komandne linije!\n");
        exit(EXIT_FAILURE);
    }

    /* Ocitavamo opcije i argumente prilikom poziva programa */
    for (i = 1; i < argc; i++) {
        /* Ako je u pitanju opcija... */
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'r':
                tip_niza = 1;
                strcpy(naziv_tipa_niza,"sortiran");
                break;
            case 'o':
                tip_niza = 2;
                strcpy(naziv_tipa_niza,"obrnuto sortiran");
                break;
            default:
                printf("Pogresna opcija -%c\n", argv[i][1]);
                return 1;
                break;
            }
        }
        /* Ako je u pitanju argument, onda je to duzina niza koji treba da se sortira */
        else {
            dimenzija = atoi(argv[i]);
            if (dimenzija <= 0 || dimenzija > MAX) {
                fprintf(stderr, "Dimenzija niza je neodgovarajuca!\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Elemente niza odredjujemo slucajno, ali vodeci racuna o tipu niza
     * dobijenom iz komandni linije.
     * srandom funkcija obezbedjuje novi seed za pozivanje 
     * random funkcije, i kako nas niz ne bi uvek isto izgledao 
     * seed smo postavili na tekuce vreme u sekundama od Nove godine 1970. 
     * random()%100 daje brojeve izmedju 0 i 99
     * Ovo je van gradiva Programiranja 2
     */
    srandom(time(NULL));
    if (tip_niza == 0)
        for (i = 0; i < dimenzija; i++)
                original[i] = random();
    else 
        if (tip_niza == 1)
            for (i = 0; i < dimenzija; i++)
                original[i] = i == 0 ? random() % 100 : original[i - 1] + random() % 100;
        else
            for (i = 0; i < dimenzija; i++)
                original[i] = i == 0 ? random() % 100 : original[i - 1] - random() % 100;

    /* Ispisujemo elemente niza 
        printf("Niz koji sortiramo je:\n");
        for (i = 0; i < dimenzija; i++)
        printf("%d\n", original[i]);
        */

    /* Upisujemo podatke o izvrsavanju programa u log fajl */
    if ((f = fopen("vremena_sortiranja.txt", "a")) == NULL) {
        fprintf(stderr, "Neuspesno otvaranje datoteke vremena_sortiranja.txt.\n");
        exit(EXIT_FAILURE);
    }

     printf("Selection Sort\n--------------------------------\n");
    /* Pravimo kopiju, tako da  funkcija za sortiranje moze da sortira svoju kopiju */   
    for( i = 0; i<dimenzija ; i++ ) 
        kopija[i] = original[i];
            
    /* Racunamo vreme proteklo od pocetka izvrsavanja programa */
    clock_gettime(CLOCK_REALTIME, &time1);

    /* Sortiramo niz selection sort algoritmom  */
    selectionSort(kopija , dimenzija);

    /* Racunamo novo vreme i razlika predstavlja vreme utroseno za sortiranje */
    clock_gettime(CLOCK_REALTIME, &time2);

    /*Upisujemo vreme za Selection sort u datoteku */
    fprintf(f,  "Selection sort niza od %d elemenata:\t %20ld ns. (niz je %s)\n", dimenzija,
        (time2.tv_sec - time1.tv_sec) * 1000000000 + time2.tv_nsec - time1.tv_nsec, naziv_tipa_niza);
     

    printf("Quick Sort\n--------------------------------\n");
    /* Pravimo kopiju, tako da  funkcija za sortiranje moze da sortira svoju kopiju */   
    for( i = 0; i<dimenzija ; i++ ) 
        kopija[i] = original[i];
            
    /* Racunamo vreme proteklo od pocetka izvrsavanja programa */
    clock_gettime(CLOCK_REALTIME, &time1);

    /* Sortiramo niz Quick sort algoritmom  */
    quickSort(kopija, 0, dimenzija-1);

    /* Racunamo novo vreme i razlika predstavlja vreme utroseno za sortiranje */
    clock_gettime(CLOCK_REALTIME, &time2);

    /*Upisujemo vreme za QuickSort u datoteku */
    fprintf(f,  "Quick sort niza od %d elemenata:\t %25ld ns. (niz je %s)\n", dimenzija,
            (time2.tv_sec - time1.tv_sec) * 1000000000 + time2.tv_nsec - time1.tv_nsec, naziv_tipa_niza);

    
    printf("Merge Sort\n--------------------------------\n");
    /* Pravimo kopiju, tako da  funkcija za sortiranje moze da sortira svoju kopiju */   
    for( i = 0; i<dimenzija ; i++ ) 
        kopija[i] = original[i];
            
    /* Racunamo vreme proteklo od pocetka izvrsavanja programa */
    clock_gettime(CLOCK_REALTIME, &time1);

    /* Sortiramo niz Merge sort algoritmom  */
    mergeSort(kopija, 0, dimenzija-1);

    /* Racunamo novo vreme i razlika predstavlja vreme utroseno za sortiranje */
    clock_gettime(CLOCK_REALTIME, &time2);

    /*Upisujemo vreme za Merge sort u datoteku */
    fprintf(f,  "Merge sort niza od %d elemenata:\t %25ld ns. (niz je %s)\n\n", dimenzija,
            (time2.tv_sec - time1.tv_sec) * 1000000000 + time2.tv_nsec - time1.tv_nsec, naziv_tipa_niza);

    /* Zatvaramo datoteku */
    fclose(f);
             
    /* Ispisujemo elemente niza 
       printf("Sortiran niz je:\n");
       for (i = 0; i < dimenzija; i++)
       printf("%d\n", kopija[i]);
     */

    return 0;
}
