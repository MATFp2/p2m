#include <stdio.h>

int main() {
    double x = 2.1, *px = &x;
    double y = 0.1, *py = &y;

    /* Prikazuju se vrednosti pokazivaca. Specifikator %p u printf()-u ispisuje vrednost
     * pokazivaca u heksadekadnoj notaciji 
     * Napomena: Pri svakom pokretanju dobijace se drugacije adrese
     */
    printf("Vrednost pokazivaca px je %p\n", px);
    printf("Vrednost pokazivaca py je %p\n\n", py);

    /* Ispisujemo vrednosti na koje pokazuju pokazivaci */
    printf("px pokazuje na vrednost: %f\n", *px);
    printf("py pokazuje na vrednost: %f\n\n", *py);

    /* Ispitujemo da li su pokazivaci jednaki, tj. da li pokazuju na isti objekat u memoriji */
    if(px == py)
        printf("Pokazivaci px i py pokazuju na isti objekat\n\n");
    else
        printf("Pokazivaci px i py ne pokazuju na isti objekat\n\n");

    py = px;

    /* Prikazuju se vrednosti pokazivaca. Specifikator %p u printf()-u ispisuje vrednost
        pokazivaca u heksadekadnoj notaciji */
    printf("Vrednost pokazivaca px je %p\n", px);
    printf("Vrednost pokazivaca py je %p\n\n", py);

    /* Ispisujemo vrednosti na koje pokazuju pokazivaci */
    printf("px pokazuje na vrednost: %f\n", *px);
    printf("py pokazuje na vrednost: %f\n\n", *py);

    /* Ispitujemo da li su pokazivaci jednaki, tj. da li pokazuju na isti objekat u memoriji */
    if(px == py)
        printf("Pokazivaci px i py pokazuju na isti objekat\n\n");
    else
        printf("Pokazivaci px i py ne pokazuju na isti objekat\n\n");

    /* Menjamo pokazivac, tako da sada pokazuje na y. */
    px = &y;

    /* Prikazuju se vrednosti pokazivaca. Specifikator %p u printf()-u ispisuje vrednost
        pokazivaca u heksadekadnoj notaciji */
    printf("Vrednost pokazivaca px je %p\n", px);
    printf("Vrednost pokazivaca py je %p\n\n", py);

    /* Ispisujemo vrednosti na koje pokazuju pokazivaci */
    printf("px pokazuje na vrednost: %f\n", *px);
    printf("py pokazuje na vrednost: %f\n\n", *py);

    /* Ispitujemo da li su pokazivaci jednaki, tj. da li pokazuju na isti objekat u memoriji */
    if(px == py)
        printf("Pokazivaci px i py pokazuju na isti objekat\n");
    else
        printf("Pokazivaci px i py ne pokazuju na isti objekat\n");

    return 0;
}
