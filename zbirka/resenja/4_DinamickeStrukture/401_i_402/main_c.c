/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
  /* Lista je prazna na pocetku */
  Cvor *glava = NULL;
  Cvor *trazeni = NULL;
  int broj;

  /* Testira se funkcija za dodavanje vrednosti u listu tako da
     bude uredjena neopadajuce */
  printf("Unesite brojeve (CTRL+D za kraj unosa): ");
  while (scanf("%d", &broj) > 0) {
    /* Ako je funkcija vratila 1, onda je bilo greske pri alokaciji
       memorije za nov cvor. Memoriju alociranu za cvorove liste
       treba osloboditi pre napustanja programa. */
    if (dodaj_sortirano(&glava, broj) == 1) {
      fprintf(stderr,
              "Greska: Neuspesna alokacija memorije za cvor.\n");
      oslobodi_listu(&glava);
      exit(EXIT_FAILURE);
    }
    printf("\tLista: ");
    ispisi_listu(glava);
  }

  /* Testira se funkcija za pretragu liste */
  printf("\nUnesite broj koji se trazi: ");
  scanf("%d", &broj);

  trazeni = pretrazi_listu(glava, broj);
  if (trazeni == NULL)
    printf("Broj %d se ne nalazi u listi!\n", broj);
  else
    printf("Trazeni broj %d je u listi!\n", trazeni->vrednost);

  /* Testira se funkcija kojom se brise cvor liste */
  printf("\nUnesite broj koji se brise: ");
  scanf("%d", &broj);

  /* Brisu se cvorovi liste cija vrednost je jednaka unetom broju */
  obrisi_cvor_sortirane_liste(&glava, broj);

  printf("Lista nakon brisanja:  ");
  ispisi_listu(glava);

  /* Oslobadja se memorija zauzeta listom */
  oslobodi_listu(&glava);

  exit(EXIT_SUCCESS);
}
