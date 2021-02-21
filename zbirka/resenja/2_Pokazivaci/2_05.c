/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

/* Funkcija ispituje da li je niska palindrom, odnosno da li se
   isto cita spreda i odpozadi */
int palindrom(char *niska)
{
  int i, j;
  for (i = 0, j = strlen(niska) - 1; i < j; i++, j--)
    if (*(niska + i) != *(niska + j))
      return 0;
  return 1;
}

int main(int argc, char **argv)
{
  int i, n = 0;

  /* Nulti argument komandne linije je ime izvrsnog programa */
  for (i = 1; i < argc; i++)
    if (palindrom(*(argv + i)))
      n++;

  printf("Broj argumenata koji su palindromi je %d.\n", n);

  return 0;
}
