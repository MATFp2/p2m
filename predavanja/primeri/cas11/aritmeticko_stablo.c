#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1.1 definisemo koje operacije su dozvoljene

/* Definisemo novi tip operacija */
typedef enum operacija {pl = '+',min = '-', pod = '/', put = '*'} operacija;

// domaci: prosiriti skup operacija nekim binarnim operacijama
// nad celim brojevima, npr. mod, ^, min, max

// 1. definisemo strukturu koja opisuje jedan cvor stabla

/* Struktura koja predstavlja jedan cvor */
typedef struct _cvor
{
  int ind; /* indikator da li se u cvoru nalazi operator
	      (u tom slucaju ind ima vrednost 1)
	      ili broj (u tom slucaju ind ima vrednost 0) */
  int br; /* polje u kome cuvamo ceo broj, popunjeno samo ako
	     je polje ind postavljeno na 0 */
  operacija op; /* polje u kome cuvamo operator, popunjeno samo ako
		   je polje ind postavljeno na 1 */
  struct _cvor *l, *d;
} cvor;

// 2. fja koja kreira cvor stabla

/* Funkcija koja pravi jedan cvor pri cemu ostavlja neinicijalizovane
   vrednosti br i op */
cvor * napravi_cvor()
{
  cvor * novi = (cvor *)malloc(sizeof(cvor));
  if (novi == NULL)
    {
      fprintf(stderr, "greska prilikom alokacije memorije\n");
      exit(1);
    }
  novi->l = NULL;
  novi->d = NULL;
  return novi;
}

// 7. fja koja oslobadja stablo

/* Rekurzivna funkcija koja uklanja drvo, obilazak mora biti
   postorder */
void obrisi_drvo(cvor *drvo)
{
  if (drvo!=NULL)
    {
      obrisi_drvo(drvo->l);
      obrisi_drvo(drvo->d);
      free(drvo);
    }
}

// 3. kreiramo stablo od niske
// domaci: umesto sa pokazivacima, napisati fju koja radi sa indeksima

/* Rekurzivna funkcija koja parsira string. Predajemo joj adresu
   stringa da bi znali dokle smo stigli u toku parsiranja */

void pretvori_u_stablo(char ** s, cvor ** pdrvo)
{
  int c, br;
  cvor *novi;
  
  /* Uzimamo sledeci karakter iz stringa. */
  c = *(*s);
  
  /* Ako smo stigli do kraja stringa izlazimo */
  if (c == '\0')
    return;
  
  /* U suprotnom popunjavamo kreiramo novi cvor */
  novi = napravi_cvor();
  
  /* Ako nije u pitanju cifra znaci da smo ucitali operator... */
  if (!isdigit(c))
    {
      /* ...postavljamo indikator na 1 */
      novi->ind = 1;
      /* ...i operator na ucitan karakter */
      novi->op = c;
      /* Unosimo podatak u drvo */
      *pdrvo = novi;

      // domaci: unosenje dodatniih operatora koji se sastoje od
      // vise karaktera (min, max) bi zahtevalo dodatni kod na
      // ovom mestu
      
      /* Prelazimo na sledeci relevantan podatak, preskacemo blanko*/
      *s = *s+2;

      // domaci: za vezbu uraditi preskakanje praznina na pocetku poziva fje
      
      /* I rekurzivno parsiramo string da bismo formirali levo pa
	 zatim i desno podstablo */
      pretvori_u_stablo(s, &((*pdrvo)->l));
      pretvori_u_stablo(s, &((*pdrvo)->d));
    }
  
  /* A ako je u pitanju cifra... */
  else
    {
      /* ...ucitavamo i ostatak broja ako postoji*/
      br = 0;
      while(isdigit(c))
	{
	  br = br*10+c-'0'; /* uracunavamo tekuci karakter u broj */
	  (*s)++; /* pomeramo se za jedno mesto u stringu */
	  
	  c = *(*s); /* i citamo sledeci karakter */
	}
      
      /* postavljamo indikator na 0 */
      novi->ind = 0;
      /* i brojevnu vrednost na br */
      novi->br = br;
      /* Unosimo podatak u drvo */
      *pdrvo = novi;
      
      /* Prelazimo na sledeci relevantan podatak. Uzimamo u obzir da
	 pokazivac vec pokazuje na blanko (sem ako nismo stigli do
	 kraja stringa). */
      if (*(*s) != '\0')
	*s = *s+1;
    }
}

// 4. ispisi stablo prefiksno

void ispisi_drvo(cvor *drvo) {
  if (drvo!=NULL)
    {
      /* Prvo ispisujemo koren. Proveravamo vrednost indikatora */
      if (!drvo->ind)
	/* ako je indikator jednak 0 stampamo broj */
	printf("%d", drvo->br);
      else
	/* a inace stampamo karakter */
	printf("%c", drvo->op);
      
      /* ...a zatim i levo pa desno podstablo. */
      ispisi_drvo(drvo->l);
      ispisi_drvo(drvo->d);
    }
}

// 5. ispisi stablo infiksno

void ispisi_drvo_infiksno(cvor *drvo) {
  if (drvo == NULL)
    return;
  if (!drvo->ind)
    /* Ako smo naisli na brojevnu vrednost stampamo je. */
    printf("%d", drvo->br);
  else
    {
      /* U suprotnom imamo pravo stablo pa ispisujemo prvo levu
	 zagradu... */
      printf("(");
      /* pa levi izraz... */
      ispisi_drvo_infiksno(drvo->l);
      /* pa operator... sa razmacima okolo */
      printf(" %c ", drvo->op);
      /* pa desni izraz... */
      ispisi_drvo_infiksno(drvo->d);
      /* i na kraju ispisujemo desnu zagradu */
      printf(")");
    }
}

// 6. fja koja izracunava vrednost izraza

int izracunaj_drvo(cvor *drvo) {
  if (!drvo->ind)
    return drvo->br;
  else
    switch (drvo->op)
      {
      case '+': return izracunaj_drvo(drvo->l) + izracunaj_drvo(drvo->d);
      case '-': return izracunaj_drvo(drvo->l) - izracunaj_drvo(drvo->d);
      case '*': return izracunaj_drvo(drvo->l) * izracunaj_drvo(drvo->d);
      case '/': return izracunaj_drvo(drvo->l) / izracunaj_drvo(drvo->d);
      }
}
  


int main() {
  cvor * drvo = NULL;
  char s[20], *ps;
  int i=0;

  // 0. ucitavanje izraza sa standardnog ulaza
  
  printf("unesite aritmeticki izraz u prefiksnoj notaciji, novi red za kraj\n");
  /* Funkcija fgets cita sa standardnog ulaza (stdin) liniju (karaktere
     do unetog novog reda) ili dok se ne popuni 20 karaktera */
  if (fgets(s, 20, stdin) == NULL)
    {
      fprintf(stderr, "greska");
      
      exit(1);
    }
  
  /* Kako s sada sadrzi i oznaku za novi red na kraju brisemo je */
  while(s[i]!='\n')
    i++;
  
  /* i na kraju dodajemo '\0' da bi pripremili string za prenosenje
     u funkciju */  
  s[i] = s[i+1];
  
  /* Kako je s niz karaktera (a niz je konstantni pokazivac) on ne
     sme biti predat funkciji koja kreira stablo (posto funkcija
     menja pokazivac koji dobija kao prvi argument) pa uzimamo
     pomocni pokazivac da bismo mogli da menjamo njegovu vrednost */
  ps = s;

  // 3. poziv fje za kreiranje stabla
  
  /* Kreiramo stablo pozivom funkcije prevori_u_stablo */
  pretvori_u_stablo(&ps, &drvo);

  // 4. poziv fje za ispis stabla prefiksno
  
  /* Ispisujemo ga u prefiksnom poredku */
  ispisi_drvo(drvo);
  printf("\n");

  // 5. poziv fje za ispis stablo infiksno
  
  /* A zatim i u infiksnom. */
  ispisi_drvo_infiksno(drvo);

  // 6. poziv fje za izracunavanje vrednosti izraza
  
  /* Ispisujemo vrednost pocetnog izraza */
  printf(" = %d\n", izracunaj_drvo(drvo));

  // 7. poziv fje za oslobadjanje stabla
  
  // brisemo drvo
  obrisi_drvo(drvo);

  return 0;
}
