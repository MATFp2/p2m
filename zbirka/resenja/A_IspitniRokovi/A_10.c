/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BITOVA_U_BAJTU 8

/* Funkcija u datom broju x menja mesta prvom i četvrtom bajtu */
unsigned int zamena(unsigned int x)
{
  /* Deklaracija promenljivih za odgovarajuce maske i pomocne
     promenljive */
  unsigned maska_prvi_bajt, maska_cetvrti_bajt;
  unsigned maska_prvi_bajt_komplement,
      maska_cetvrti_bajt_komplement;
  unsigned prvi_bajt, cetvrti_bajt;
  unsigned i;

  /* Maska_prvi_bajt odgovara broju cija je binarna reprezentacija
     00000....0000011111111 (8 bitova najmanje tezine su jedinice,
     a ostalo su nule). Moze se dobiti i tako sto se
     maska_prvi_bajt postavi na heksadekadnu vrednost FF. Drugi
     nacin za inicijalizaciju maske maska_prvi_bajt je dodavanjem
     jedinica sa desne strane: */
  maska_prvi_bajt = 1;
  for (i = 1; i < BITOVA_U_BAJTU; i++)
    maska_prvi_bajt = maska_prvi_bajt << 1 | 1;

  /* Maska_cetvrti_bajt odgovara broju cija je binarna
     reprezentacija 1111111100000....00000 (8 bitova najvece tezine
     su jedinice, a ostalo su nule) i moze se dobiti pomeranjem
     bitova prethodno kreirane maske maska_prvi_bajt tako da
     jedinice budu na poziciji bajta najvece tezine. */
  maska_cetvrti_bajt =
      maska_prvi_bajt << ((sizeof(unsigned) - 1) * BITOVA_U_BAJTU);

  /* Primenom operatora ~ na maska_prvi_bajt dobija se broj cija je
     binarna reprezentacija 11111....1111100000000 (8 bitova
     najmanje tezine su nule, a ostalo su jedinice) */
  maska_prvi_bajt_komplement = ~maska_prvi_bajt;
  /* Primenom operatora ~ na maska_prvi_bajt dobija se broj cija je
     binarna reprezentacija 0000000011111....11111 (8 bitova najvece
     tezine su nule, a ostalo su jedinice) */
  maska_cetvrti_bajt_komplement = ~maska_cetvrti_bajt;

  /* U promenljivu prvi_bajt se smesta broj koji se dobija kada se
     bitovi prvog bajta broja x pomere ulevo, tako da budu na
     poziciji cetvrtog bajta */
  prvi_bajt =
      (maska_prvi_bajt & x) << ((sizeof(unsigned) - 1) *
                                BITOVA_U_BAJTU);
  /* U promenljivu cetvrti_bajt se smesta broj koji se dobija kada
     se bitovi cetvrtog bajta broja x pomere udesno, tako da budu
     na poziciji prvog bajta */
  cetvrti_bajt =
      (maska_cetvrti_bajt & x) >> ((sizeof(unsigned) - 1) *
                                   BITOVA_U_BAJTU);

  /* Na nule se postavlja 8 bitova najmanje tezine, a ostali bitovi
     ostaju nepromenjeni */
  x = x & maska_prvi_bajt_komplement;

  /* Na nule se postavlja 8 bitova najvece tezine, a ostali bitovi
     ostaju nepromenjeni */
  x = x & maska_cetvrti_bajt_komplement;

  /* Na bitove na poziciji cetvrtog bajta se postavljaju bitovi iz
     prvog bajta */
  x = x | prvi_bajt;

  /* Na bitove na poziciji cetvrtog bajta se postavljaju bitovi iz
     prvog bajta */
  x = x | cetvrti_bajt;

  return x;
}

int main()
{
  int x;

  /* Sa standardnog ulaza se ucitava ceo broj */
  scanf("%d", &x);

  /* Provera da li je uneti broj negativan */
  if (x < 0) {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
  }

  /* Ispisuje se rezultat primene funkcije zamena na uneti broj x */
  printf("%u\n", zamena(x));

  exit(EXIT_SUCCESS);
}
