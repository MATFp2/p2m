/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAKS 50

/* Funkcija vrsi dinamicku alokaciju memorije potrebne za n niski
   od kojih nijedna nije duza od MAKS karaktera. */
char **alociranje_memorije(int n)
{
  char **linije = NULL;
  int i, j;
  /* Alocira se prostor za niz vrsti matrice */
  linije = (char **) malloc(n * sizeof(char *));
  /* U slucaju neuspesnog otvaranja ispisuje se -1 na standardni
     izlaz za greske i program zavrsava. */
  if (linije == NULL)
    return NULL;
  /* Alocira se prostor za svaku vrstu matrice. Niska nije duza od
     MAKS karaktera, a 1 se dodaje zbog terminirajuce nule. */
  for (i = 0; i < n; i++) {
    linije[i] = malloc((MAKS + 1) * sizeof(char));
    /* Ako alokacija nije prosla uspesno, oslobadjaju se svi
       prethodno alocirani resursi, i povratna vrednost je NULL */
    if (linije[i] == NULL) {
      for (j = 0; j < i; j++) {
        free(linije[j]);
      }
      free(linije);
      return NULL;
    }
  }
  return linije;
}

/* Funkcija oslobadja dinamicki alociranu memoriju */
char **oslobadjanje_memorije(char **linije, int n)
{
  int i;
  /* Oslobadja se prostor rezervisan za svaku vrstu */
  for (i = 0; i < n; i++) {
    free(linije[i]);
  }
  /* Oslobadja se memorija za niz pokazivaca na vrste */
  free(linije);

  /* Matrica postaje prazna, tj. nealocirana */
  return NULL;
}

int main(int argc, char *argv[])
{
  FILE *ulaz;
  char **linije;
  int i, n;

  /* Proverava argumenata komandne linije. */
  if (argc != 2) {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
  }

  /* Otvara se datoteka cije ime je navedeno kao argument komandne
     linije neposredno nakon imena programa koji se poziva. U
     slucaju neuspesnog otvaranja ispisuje se -1 na standardni
     izlaz za greske i program zavrsava izvrsavanje. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL) {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
  }
  /* Ucitava se broj linija. */
  fscanf(ulaz, "%d", &n);

  /* Alociranje memorije na osnovu ucitanog broja linija. */
  linije = alociranje_memorije(n);

  /* U slucaju neuspesne alokacije ispisuje se -1 na standardni
     izlaz za greske i program zavrsava. */
  if (linije == NULL) {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
  }

  /* Iz datoteke se ucita svih n linija. */
  for (i = 0; i < n; i++) {
    fscanf(ulaz, "%s", linije[i]);
  }

  /* Ispisu se u odgovarajucem poretku ucitane linije koje
     zadovoljavaju kriterijum. */
  for (i = n - 1; i >= 0; i--) {
    if (isupper(linije[i][0])) {
      printf("%s\n", linije[i]);
    }
  }
  /* Oslobadja se memorija koja je dinamicki alocirana. */
  linije = oslobadjanje_memorije(linije, n);

  /* Zatvara se datoteka. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
