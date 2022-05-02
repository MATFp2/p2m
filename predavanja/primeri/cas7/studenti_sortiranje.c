typedef struct _student
{
  char ime[MAX_IME];
  char prezime[MAX_IME];
  int ocena;
} student;


// Sortiranje studenata po oceni:
void sort_po_oceni(student a[], int n)
{
  int i, j;
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if(a[i].ocena < a[j].ocena)
	{
	  student pom=a[i];
	  a[i]=a[j];
	  a[j]=pom;
	}
}

//Sortiranje studentata po imenu:
void sort_po_imenu(student a[], int n)
{
  int i, j;
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if(strcmp(a[i].ime, a[j].ime)<0)
	{
	  student pom=a[i];
	  a[i]=a[j];
	  a[j]=pom;
	}
}

// Sortiranje studenata po prezimenu:
void sort_po_prezimenu(student a[], int n)
{
  int i, j;
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if(strcmp(a[i].prezime, a[j].prezime)<0)
	{
	  student pom=a[i];
	  a[i]=a[j];
	  a[j]=pom;
	}
}

// Izdvojimo funkcije poredjenja:
int poredi_po_oceni(student st1, student st2)
{
  return st1.ocena - st2.ocena;
}

int poredi_po_imenu(student st1, student st2)
{
  return strcmp(st1.ime, st2.ime);
}

int poredi_po_prezimenu(student st1, student st2)
{
  return strcmp(st1.prezime, s2.prezime);
}

/*
  Vidimo da sve tri funkcije imaju isti potpis i jos jedno bitno svojstvo, 
  a to je da sve tri vracaju vrednost:
  - manju od nule ukoliko je prvi element manji od drugog, 
  - nula ukoliko su elementi jednaki i 
  - vrednost vecu od nule ukoliko je drugi element veci od prvog.

Sada funkcija koja sortira niz izgleda ovako:
 */

void sortiraj_studente_po_imenu(student a[], int n)
{
  int i, j;
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      /*if(poredi_po_prezimenu(a[i], a[j])<0)*/
      /*if(poredi_po_oceni(a[i], a[j])<0)*/
      if(poredi_po_imenu(a[i], a[j])<0)
	{
	  student pom=a[i];
	  a[i]=a[j];
	  a[j]=pom;
	}
}

// vidimo da mozemo da dodamo funkciju poredjenja kao argument funkciji
// sortiranja i da na taj nacin dobijemo jednu funkciju umesto tri:

/*
- tip niza
- tip pomocne promenljive
- operacija poredjenja --- pomerili u argumente fje

 */
void sort_studente(student a[], int n, int (*f)(student, student))
{
  int i, j;
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if((*f)(a[i], a[j])<0)
	{
	  student pom;
	  pom =a[i];
	  a[i]=a[j];
	  a[j]=pom;
	}
}


/* zamene dve vrednosti na pozicijama i i j
-- prelazimo na pokazivace, menjamo dve vrednosti u memoriji cije adrese imamo
- adresa_itog elementa
- adresa_jtog elementa
- size - velicina prostora u memoriji koju zauzima jedan element

void *tmp = malloc(size);
memcpy(tmp, adresa_itog, size);
memcpy(adresa_itog, adresa_jtog, size);
memcpy(adresa_jtog, tmp, size);
free(tmp);

 */


/* uopstenje fje poredjenja, da radi sa proizvoljnim tipom*/
// prvi korak, prelazimo na pokazivace student *
int poredi_po_oceni(student* st1, student* st2)
{
  return (*st1).ocena - (*st2).ocena;
}

// drugi korak, prelazimo na pokazivace void*
int poredi_po_oceni(void* pst1, void* pst2)
{
  student st1, st2;

  st1 = *((student*)pst1);
  st2 = *((student*)pst2);
  
  return st1.ocena - st2.ocena;
}

// rezultat
int poredi_int(void *x, void *y){
  int a, b;
  a = *(int*)x;
  b = *(int*)y;
  return a-b;
}

// fja sortiranja koristi tu funkciju:
void sort(void* a, int n, int size, int (*f)(void*, void*)){
  int i, j;

  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++){

      void *adresa_itog = a + i * size;
      void *adresa_jtog = a + j * size;
      
      if((*f)(adresa_itog, adresa_jtog)<0)
	{
	  void *tmp = malloc(size);
	  
	  memcpy(tmp, adresa_itog, size);
	  memcpy(adresa_itog, adresa_jtog, size);
	  memcpy(adresa_jtog, tmp, size);
	  
	  free(tmp);
	}
    }

}

int main(){
  int *a;
  int n;
  int i;

  scanf("%d", &n);
  a = (int *) malloc(n*sizeof(int));

  for(i=0; i<n; i++)
    scanf("%d", &a[i]);

  sort((void*)a, n, sizeof(int), poredi_int);

  for(i=0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}


void pretraga(void*, void* a, int n, int size, int (*f)(void*, void*));

/*
fja poredjenja u generickoj fji: poredi element koji trazimo sa elementom niza

vrednost tipa int, u nizu celih brojeva

niz struktura studenata, sortiran po broju indeksa
pretrazujete sortiran niz studenata po broju indeksa --- 

 */
