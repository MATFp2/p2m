/* Program demonstrira jaku vezu koja postoji u programskom jeziku C 
 * izmedju nizova i pokazivaca.
 * Sve sto se moze postici indeksiranjem elemenata niza, moze se postici
 * i pomocu pokazivaca.
 */

#include <stdio.h>

int main() {
    /* Niza a ce u memoriji biti smesten u 10 susednih jedinica/ */
    int a[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    
    /* Kako je po definiciji, ime niza sinonim za adresu pocetnog elementa niza, tj a[0], 
     * sledeca naredba dodele je ekvivalentna dodeli:        
     * p = &a[0] */
    int *p = a;
    
    /* Slicno i zapis a[i] ima isto znacenje kao i *(a+i), pri cemu je ovo drugo blize kompajlerovom mehanizmu 
     * citanja i-tog elementa niza.  
     * Ako je           a[i]  <==> *(a+i)
     * onda je        &a[i]  <==> a+i    
     * 
     * Slicno vazi i za pokazivac p. Ako p pokazuje na neki element niza a, tada p+1 je pokazuje na naredni element, 
     * dok p+i pokazuje na element koji se nalazi u memoriji i pozicija desno od elementa na koji pokazuje p, 
     * a p-i pokazuje na element koji  se u nizu a nalazi i pozicija pre elementa nakoji pokazuje p.
     * 
     * BITNO: Postoji razlika izmedju imena niza a i pokazivacke promenljive p = a. 
     * Najpre, p je promenljiva i moze da promeni vrednost, dok a nije promenljiva vec ime niza i ne moze da menja svoju vrednost.
     * Ukratko: p = a i p++ su dozvoljene operacije
     *  Dok a= p i a++ nisu dozvoljene, jer a nije promenljiva vec niz celih brojeva, samo je automatski konvertovana u pokazivac na prvi element.
     */
    
    int i;
    
    printf("Vrednost izraza a (tipa int *): %p\n", a);
    printf("Vrednost izraza p (tipa int *): %p\n", p);
    /* Ispisuje se zapravo vrednost pocetnog elementa niza */
    printf("Vrednost izraza *a (tipa int): %d\n", *a);
    printf("Vrednost izraza *p (tipa int): %d\n\n", *p);
    
    for(i = 0; i < 10; i++)
    {   /* adresa i-tog elementa izracunata na vise nacina */
          printf("Vrednost izraza &a[%d] (tipa int *): %p\n",  i, &a[i]);
          printf("Vrednost izraza &p[%d] (tipa int *): %p\n",  i, &p[i]);
          printf("Vrednost izraza (a + %d) (tipa int *): %p\n", i, a + i);
          printf("Vrednost izraza (p + %d) (tipa int *): %p\n", i, p + i);
          
          /* pristupamo i-tom elementu pomocu indeksa primenjenog na niz ili na pokazivac*/
          printf("Vrednost izraza a[%d] (tipa int): %d\n",  i, a[i]);     
          printf("Vrednost izraza p[%d] (tipa int): %d\n",  i, p[i]);
          
          /* pristupamo i-tom elementu pomocu pokazivacke sintakse*/
          printf("Vrednost izraza *(a + %d) (tipa int): %d\n", i, *(a + i));
          printf("Vrednost izraza *(p + %d) (tipa int): %d\n\n", i, *(p + i));
    }
          
    return 0;
}

          
    
