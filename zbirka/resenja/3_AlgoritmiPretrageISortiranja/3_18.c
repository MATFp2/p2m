/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jelena Graovac, Nina Radojicic,
*             Ana Spasic, Mirko Spasic, Andjelka Zecevic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *fin1 = NULL, *fin2 = NULL;
  FILE *fout = NULL;
  char ime1[11], ime2[11];
  char prezime1[16], prezime2[16];
  int kraj1 = 0, kraj2 = 0;

  /* Ako nema dovoljno arguemenata komandne linije */
  if (argc < 3) {
    fprintf(stderr,
            "Greska: Program se poziva sa %s datoteka1 datoteka2\n",
            argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Otvara se datoteka zadata prvim argumentom komandne linije */
  fin1 = fopen(argv[1], "r");
  if (fin1 == NULL) {
    fprintf(stderr, "Greska: Neuspesno otvaranje datoteke %s\n",
            argv[1]);
    exit(EXIT_FAILURE);
  }

  /* Otvara se datoteka zadata drugim argumentom komandne linije */
  fin2 = fopen(argv[2], "r");
  if (fin2 == NULL) {
    fprintf(stderr, "Greska: Neuspesno otvaranje datoteke %s\n",
            argv[2]);
    exit(EXIT_FAILURE);
  }

  /* Otvara se datoteka za upis rezultata */
  fout = fopen("ceo-tok.txt", "w");
  if (fout == NULL) {
    fprintf(stderr,
            "Greska: Neuspesno otvaranje datoteke ceo-tok.txt\n");
    exit(EXIT_FAILURE);
  }

  /* Cita se prvi student iz prve datoteke */
  if (fscanf(fin1, "%s%s", ime1, prezime1) == EOF)
    kraj1 = 1;

  /* Cita se prvi student iz druge datoteke */
  if (fscanf(fin2, "%s%s", ime2, prezime2) == EOF)
    kraj2 = 1;

  /* Sve dok nije dostignut kraj neke datoteke */
  while (!kraj1 && !kraj2) {
    int tmp = strcmp(ime1, ime2);
    if (tmp < 0 || (tmp == 0 && strcmp(prezime1, prezime2) < 0)) {
      /* Ime i prezime iz prve datoteke je leksikografski ranije, i
         biva upisano u izlaznu datoteku */
      fprintf(fout, "%s %s\n", ime1, prezime1);
      /* Cita se naredni student iz prve datoteke */
      if (fscanf(fin1, "%s%s", ime1, prezime1) == EOF)
        kraj1 = 1;
    } else {
      /* Ime i prezime iz druge datoteke je leksikografski ranije,
         i biva upisano u izlaznu datoteku */
      fprintf(fout, "%s %s\n", ime2, prezime2);
      /* Cita se naredni student iz druge datoteke */
      if (fscanf(fin2, "%s%s", ime2, prezime2) == EOF)
        kraj2 = 1;
    }
  }

  /* Ako se iz prethodne petlje izaslo zato sto je dostignut kraj
     druge datoteke, onda ima jos studenata u prvoj datoteci, koje
     treba prepisati u izlaznu, redom, jer su vec sortirani po
     imenu. */
  while (!kraj1) {
    fprintf(fout, "%s %s\n", ime1, prezime1);
    if (fscanf(fin1, "%s%s", ime1, prezime1) == EOF)
      kraj1 = 1;
  }

  /* Ako se iz prve petlje izaslo zato sto je dostignut kraj prve
     datoteke, onda ima jos studenata u drugoj datoteci, koje treba
     prepisati u izlaznu, redom, jer su vec sortirani po imenu. */
  while (!kraj2) {
    fprintf(fout, "%s %s\n", ime2, prezime2);
    if (fscanf(fin2, "%s%s", ime2, prezime2) == EOF)
      kraj2 = 1;
  }

  /* Zatvaraju se datoteke */
  fclose(fin1);
  fclose(fin2);
  fclose(fout);

  exit(EXIT_SUCCESS);
}
