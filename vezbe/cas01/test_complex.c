/*
 Napisati program koji koristi kompleksne brojeve:
  - Definisati strukturu KompleksanBroj koja predstavlja kompleksan broj i sadrži realan i imaginaran deo kompleksnog broja.
 Napisati funkciju koja: 
  - ispisuje kompleksan broj na standardni izlaz, što lepše.
  - učitava kompleksan broj sa standardnog ulaza.
  - računa vrednosti realnog (imaginarnog) dela broja.
  - sabira (oduzima, množi) dva kompleksna broja.
  - računa konjugovano-kompleksni broj svog argumenta.
  - računa moduo kompleksnog broja.
  - računa argument kompleksnog broja.
  
  Paralelno dok pišemo funkcije, pišemo i main funkciju koja testira napisane funkcije.
 */


#include <stdio.h>
#include <math.h>

/* struktura kojom predstavljamo kompleksan broj, cuvajuci njegov realan i imaginaran deo */ 
typedef  struct {
    float real;
    float imag;
} KompleksanBroj;

/* Funkcija ucitava sa standardnog ulaza realan i imaginara deo kompleksnog broja i smesta ih u strukturu cija adresa je argument funkcije */ 
void ucitaj_kompleksan_broj(KompleksanBroj* z) {
    printf("Unesite realan i imaginaran deo kompleksnog broja: ");
    scanf("%f", &z->real);
    scanf("%f", &z->imag);
}

/* Funkcija ispisuje na standardan izlaz kompleksan broj z koji joj se salje kao argument u obliku (x + i y)  
   Ovoj funkciji se kompleksan broj prenosi po vrednosti, jer za ispis nam nije neophodno da imamo adresu
 */
void ispisi_kompleksan_broj(KompleksanBroj z) {
    printf("(");
   if( z.real != 0) {
        printf("%.2f",z.real);
        if(z.imag > 0 )
            printf(" +");

   }
   if(z.imag !=0 )
       printf(" %.2f i ",z.imag);
   
   if(z.imag ==0 && z.real ==0 )
       printf("0 ");
   
   printf(")");
}

/* Funkcija vraca vrednosti realnog dela kompleksnog broja */
float realan_deo(KompleksanBroj z) {
    return z.real;
}

/* Funkcija vraca vrednosti imaginarnog dela kompleksnog broja */
float imaginaran_deo(KompleksanBroj z) {
    return z.imag;
}

/* Funkcija vraca vrednost modula kompleksnog broja koji joj se salje kao argument */
float moduo(KompleksanBroj  z) {
    return sqrt( z.real* z.real + z.imag* z.imag);
}

/* Funkcija vraca vrednost konjugovano kompleksnog broja koji odgovara kompleksnom broju poslatom kao argument */
KompleksanBroj konjugovan(KompleksanBroj z) {
    KompleksanBroj z1 = z;
    
    z1.imag *= -1;
    
    return z1;
}

/* Funkcija vraca kompleksan broj cija vrednost je jednaka zbiru argumenata funkcije */
KompleksanBroj saberi(KompleksanBroj z1, KompleksanBroj  z2 ) {
    KompleksanBroj z = z1;
    
    z.real += z2.real;
    z.imag += z2.imag;
    
    return z;    
}

/* Funkcija vraca kompleksan broj cija vrednost je jednaka razlici argumenata funkcije */
KompleksanBroj oduzmi(KompleksanBroj z1, KompleksanBroj  z2 ) {
    KompleksanBroj z = z1;
    
    z.real -= z2.real;
    z.imag -= z2.imag;
    
    return z;    
}

/* Funkcija vraca kompleksan broj cija vrednost je jednaka proizvodu argumenata funkcije */
KompleksanBroj mnozi(KompleksanBroj z1, KompleksanBroj  z2 ) {
    KompleksanBroj z;
    
    z.real = z1.real *  z2.real - z1.imag * z2.imag;
    z.imag = z1.real *  z2.imag + z1.imag * z2.real;
    
    return z;    
}

/* Funkcija vraca argument kompleksnog broja koji je funkciji poslat kao argument */
float argument(KompleksanBroj z) {
    return atan2(z.imag, z.real);
}


/* U main() funckiji testiramo sve funckije koje smo definisali */
int main() {
    /* deklarisemo promenljive tipa KompleksanBroj */
    KompleksanBroj z1, z2;
    
    /* Ucitavamo prvi i ispisujemo ga potom na standardni izlaz  */
    ucitaj_kompleksan_broj(&z1);
    ispisi_kompleksan_broj(z1);
   
    /* Ispisujemo realan, imaginaran deo i moduo kompleksnog broja z1 */
    printf("\nrealan_deo: %.f\nimaginaran_deo: %f\nmoduo %f\n",realan_deo(z1), imaginaran_deo(z1), moduo(z1));
    printf("\n");
    
    /* Ucitavamo i drugi kompleksan broj i ispisujemo ga na standardni izlaz */
    ucitaj_kompleksan_broj(&z2);
    ispisi_kompleksan_broj(z2);
    
    /* Racunamo i ispisujemo konjugovano kompleksan broj od z2 */
    printf("\nNJegov konjugovano kompleksan broj: ");
    ispisi_kompleksan_broj( konjugovan(z2) );
    printf("\n");
   
    /* testiramo sabiranje kompleksnih brojeva */
    printf("\n");
    ispisi_kompleksan_broj(z1);
    printf(" + ");
    ispisi_kompleksan_broj(z2);
    printf("  =  ");
    ispisi_kompleksan_broj(saberi(z1, z2));
    printf("\n");
   
    /* testiramo oduzimanje kompleksnih brojeva */
    printf("\n");
    ispisi_kompleksan_broj(z1);
    printf(" - ");
    ispisi_kompleksan_broj(z2);
    printf("  =  ");
    ispisi_kompleksan_broj(oduzmi(z1, z2));
    printf("\n");
   
    /* testiramo mnozenje kompleksnih brojeva */
    printf("\n");
    ispisi_kompleksan_broj(z1);
    printf(" * ");
    ispisi_kompleksan_broj(z2);
    printf("  =  ");
    ispisi_kompleksan_broj(mnozi(z1, z2));
   
    /* testiramo funkciju koja racuna argument kompleksnih brojeva */
    printf("\n");
    ispisi_kompleksan_broj(z2);
    printf("\nArgument kompleksnog broja %f\n",argument(z2) );
   
    /* program se zavrsava uspesno, tj, bez greske*/
    return 0;
}

