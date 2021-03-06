/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>

/* Rekurzivna funkcija za odredjivanje najvece heksadekadne cifre */
int maks_heksadekadna_cifra(unsigned x)
{
  /* Izlazak iz rekurzije: ako je vrednost broja 0, onda je i
     vrednost najvece heksadekadne cifre u broju 0 */
  if (x == 0)
    return 0;

  /* Odredjuje se poslednja heksadekadna cifra u broju */
  int poslednja_cifra = x & 15;

  /* Odredjuje se maksimalna heksadekadna cifra broja kada se iz
     njega izbrise poslednja heksadekadna cifra */
  int maks_bez_poslednje_cifre = maks_heksadekadna_cifra(x >> 4);

  return poslednja_cifra >
      maks_bez_poslednje_cifre ? poslednja_cifra :
      maks_bez_poslednje_cifre;
}

int main()
{
  unsigned x;

  /* Ucitava se neoznacen ceo broj */
  scanf("%u", &x);

  /* Ispisivanje vrednosti najvece heksadekadne cifre unetog broja */
  printf("%d\n", maks_heksadekadna_cifra(x));

  return 0;
}
