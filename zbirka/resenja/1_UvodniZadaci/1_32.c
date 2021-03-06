/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <string.h>

/* Niska moze imati najvise 31 karaktera + 1 za terminalnu nulu */
#define MAKS_DIM 32

/* Funkcija ispituje da li je zadata niska duzine n palindrom */
int palindrom(char s[], int n)
{
  /* Izlaz iz rekurzije - trivijalno, niska duzine 0 ili 1 je
     palindrom */
  if ((n == 1) || (n == 0))
    return 1;

  /* Da bi niska bila palindrom potrebno je da se poklapaju prvi i
     poslednji karakter i da je palindrom niska koja nastaje kada
     se polaznoj nisci otklone prvi i poslednji karakter */
  return (s[n - 1] == s[0]) && palindrom(s + 1, n - 2);
}

int main()
{
  char s[MAKS_DIM];
  int n;

  /* Ucitava se niska sa standardnog ulaza */
  scanf("%s", s);

  /* Odredjuje se duzina niske */
  n = strlen(s);

  /* Ispisuje se da li je niska palindrom ili nije */
  if (palindrom(s, n))
    printf("da\n");
  else
    printf("ne\n");

  return 0;
}
