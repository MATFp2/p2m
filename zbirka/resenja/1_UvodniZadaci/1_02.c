/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

/********************************************************************
Ovaj program koristi korektno definisanu biblioteku kompleksnih 
brojeva. U zaglavlju kompleksan_broj.h nalazi se definicija 
komplesnog broja i popis deklaracija podrzanih funkcija, a u 
kompleksan_broj.c se nalaze njihove definicije.

Kompilacija programa se najjednostavnije postize naredbom
gcc -Wall -lm -o kompleksan_broj kompleksan_broj.c main.c 
 
Kompilacija se moze uraditi i postupno, na sledeci nacin:
gcc -Wall -c -o kompleksan_broj.o kompleksan_broj.c
gcc -Wall -c -o main.o main.c
gcc -lm -o kompleksan_broj kompleksan_broj.o main.o

Napomena: Prethodne komande se koriste kada se sva tri navedena 
dokumenta nalaze u istom direktorijumu. Ukoliko se biblioteka (npr. 
kompleksan_broj.c kompleksan_broj.h) nalazi u direktorijumu sa imenom 
header_dir prevodjenje se vrsi dodavanjem opcije opcije -I header_dir
gcc -I header_dir -Wall -lm -o kompleksan_broj kompleksan_broj.c 
     main.c 
********************************************************************/

#include <stdio.h>
/* Ukljucuje se zaglavlje za rad sa kompleksnim brojevima */
#include "kompleksan_broj.h"

/* U glavnoj funkciji se za uneti kompleksan broj ispisuje njegov
   polarni oblik */
int main()
{
  KompleksanBroj z;

  /* Ucitava se kompleksan broj */
  ucitaj_kompleksan_broj(&z);

  /* Ispisuje se polarni oblik kompleksnog broja */
  printf("Polarni oblik kompleksnog broja je %.2f *  e^i * %.2f\n",
         moduo(z), argument(z));

  return 0;
}
