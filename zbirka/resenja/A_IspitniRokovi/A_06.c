/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

/* Funkcija ucitava brojeve sa standardnog ulaza i smesta ih u
   stablo. Funkcija vraca 1 u slucaju neuspesnog dodavanja elementa
   u stablo, a inace 0. */
int ucitaj_stablo(Cvor ** koren)
{
  *koren = NULL;
  int x;
  /* Sve dok ima brojeva na standardnom ulazu, ucitani brojevi se
     dodaju u stablo. Ukoliko funkcija dodaj_u_stablo vrati 1, onda
     je i povratna vrednost iz funkcije ucitaj_stablo 1. */
  while (scanf("%d", &x) == 1)
    if (dodaj_u_stablo(koren, x) == 1)
      return 1;
  return 0;
}

/* Funkcija prebrojava broj cvorova na n-tom nivou u stablu */
int prebroj_n(Cvor * koren, int n)
{
  /* Ukoliko je stablo prazno, rezultat je nula. Takodje, ako je n
     negativan broj, na tom nivou nema cvorova i rezultat je nula. */
  if (koren == NULL || n < 0)
    return 0;
  /* Ukoliko je n = 0, na tom nivou je samo koren. Ukoliko ima
     jednog potomka funkcija vraca 1, inace 0 */
  if (n == 0) {
    if (koren->levo == NULL && koren->desno != NULL)
      return 1;
    if (koren->levo != NULL && koren->desno == NULL)
      return 1;
    return 0;
  }
  /* Broj cvorova na n-tom nivou je jednak zbiru broja cvorova na
     (n-1)-om nivou levog podstabla i broja cvorova na (n-1)-om
     nivou levog podstabla */
  return prebroj_n(koren->levo, n - 1)
      + prebroj_n(koren->desno, n - 1);
}

int main()
{
  Cvor *koren;
  int n;
  scanf("%d", &n);

  /* Ucitavaju se elementi u stablo. U slucaju neuspesne alokacije
     oslobodja se alocirana memorija i izlazi se iz programa. */
  if (ucitaj_stablo(&koren) == 1) {
    fprintf(stderr, "-1\n");
    oslobodi_stablo(&koren);
    exit(EXIT_FAILURE);
  }

  /* Ispisuje se rezultat */
  printf("%d\n", prebroj_n(koren, n));

  /* Oslobadja se dinamicki alocirana memorija za stablo */
  oslobodi_stablo(&koren);

  exit(EXIT_SUCCESS);
}
