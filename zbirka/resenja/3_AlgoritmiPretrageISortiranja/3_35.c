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
#include <search.h>

#define MAX 500

/* Struktura sa svim informacijama o pojedinacnom studentu */
typedef struct {
  char ime[21];
  char prezime[21];
  int bodovi;
} Student;

/* Funkcija poredjenja za sortiranje po broju bodova. Studenti sa
   istim brojem bodova se dodatno sortiraju leksikografski po
   prezimenu */
int poredi1(const void *a, const void *b)
{
  Student *prvi = (Student *) a;
  Student *drugi = (Student *) b;

  if (prvi->bodovi > drugi->bodovi)
    return -1;
  else if (prvi->bodovi < drugi->bodovi)
    return 1;
  else
    /* Ako su jednaki po broju bodova, treba ih uporediti po
       prezimenu */
    return strcmp(prvi->prezime, drugi->prezime);
}

/* Funkcija za poredjenje koja se koristi u pretrazi po broju
   bodova. Prvi parametar je ono sto se trazi u nizu (broj bodova),
   a drugi parametar je element niza ciji se bodovi porede. */
int poredi2(const void *a, const void *b)
{
  int bodovi = *(int *) a;
  Student *s = (Student *) b;
  return s->bodovi - bodovi;
}

/* Funkcija za poredjenje koja se koristi u pretrazi po prezimenu.
   Prvi parametar je ono sto se trazi u nizu (prezime), a drugi
   parametar je element niza cije se prezime poredi. */
int poredi3(const void *a, const void *b)
{
  char *prezime = (char *) a;
  Student *s = (Student *) b;
  return strcmp(prezime, s->prezime);
}

int main(int argc, char *argv[])
{
  Student kolokvijum[MAX];
  int i;
  size_t br_studenata = 0;
  Student *nadjen = NULL;
  FILE *fp = NULL;
  int bodovi;
  char prezime[21];

  /* Ako je program pozvan sa nedovoljnim brojem argumenata daje se
     informacija korisniku kako se program koristi i prekida se
     izvrsavanje. */
  if (argc < 2) {
    fprintf(stderr, "Greska: Program se poziva sa %s datoteka\n",
            argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Otvara se datoteka */
  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Greska: Neupesno otvaranje datoteke %s\n",
            argv[1]);
    exit(EXIT_FAILURE);
  }

  /* Ucitava se sadrzaj */
  for (i = 0;
       fscanf(fp, "%s%s%d", kolokvijum[i].ime,
              kolokvijum[i].prezime,
              &kolokvijum[i].bodovi) != EOF; i++);

  /* Zatvara se datoteka */
  fclose(fp);
  br_studenata = i;

  /* Sortira se niz studenata po broju bodova, gde se unutar grupe
     studenata sa istim brojem bodova sortiranje vrsi po prezimenu */
  qsort(kolokvijum, br_studenata, sizeof(Student), &poredi1);

  printf("Studenti sortirani po broju poena opadajuce, ");
  printf("pa po prezimenu rastuce:\n");
  for (i = 0; i < br_studenata; i++)
    printf("%s %s  %d\n", kolokvijum[i].ime,
           kolokvijum[i].prezime, kolokvijum[i].bodovi);

  /* Pretrazuju se studenati po broju bodova binarnom pretragom jer
     je niz sortiran po broju bodova. */
  printf("Unesite broj bodova: ");
  scanf("%d", &bodovi);

  nadjen =
      bsearch(&bodovi, kolokvijum, br_studenata, sizeof(Student),
              &poredi2);

  if (nadjen != NULL)
    printf
        ("Pronadjen je student sa unetim brojem bodova: %s %s %d\n",
         nadjen->ime, nadjen->prezime, nadjen->bodovi);
  else
    printf("Nema studenta sa unetim brojem bodova\n");

  /* Pretraga po prezimenu se mora vrsiti linearno jer je niz
     sortiran po bodovima. */
  printf("Unesite prezime: ");
  scanf("%s", prezime);

  nadjen =
      lfind(prezime, kolokvijum, &br_studenata, sizeof(Student),
            &poredi3);

  if (nadjen != NULL)
    printf
        ("Pronadjen je student sa unetim prezimenom: %s %s %d\n",
         nadjen->ime, nadjen->prezime, nadjen->bodovi);
  else
    printf("Nema studenta sa unetim prezimenom\n");

  exit(EXIT_SUCCESS);
}
