/* Napisati program koji cita sadrzaj dve datoteke od kojih svaka sadrzi
   spisak imena i prezimena studenata iz jedne od dve grupe rastuce sortiran 
   po imenima i kreira jedinstven spisak studenata sortiranih po imenu rastuce.
   Program dobija nazive datoteka iz komandne linije, i jedinstven spisak
   upisuje u datoteku ceo_tok.txt
   Pretpostaviti da je ime studenta nije duze od 10, a prezime nije duze od 15 karaktera.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Programu su neophodni argumenti komandne linije */
int main(int argc, char * argv[]) {
    FILE *fin1=NULL, *fin2 =NULL;
    FILE *fout =NULL;
    char ime1[11], ime2[11];
    char prezime1[16], prezime2[16];
    int kraj1 = 0, kraj2 = 0;
    
    if(argc <3) {
        fprintf(stderr, "Nedovoljno argumenata komandne linije!\nProgram se poziva sa: %s grupa_1.txt grupa_2.txt\n\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    fin1 = fopen(argv[1],"r");
    if(fin1==NULL) {
        fprintf(stderr, "Neuspesno otvaranje datoteke %s\n\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    fin2 = fopen(argv[2],"r");
    if(fin2==NULL) {
        fprintf(stderr, "Neuspesno otvaranje datoteke %s\n\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    fout = fopen("ceo_tok.txt","w");
    if(fout==NULL) {
        fprintf(stderr, "Neuspesno otvaranje datoteke ceo_tok.txt za pisanje\n\n");
        exit(EXIT_FAILURE);
    }

     /* citamo narednog studenta iz prve datoteke */
    if( fscanf(fin1, "%s%s",ime1, prezime1) == EOF) 
        kraj1 = 1;
    
    /* citamo narednog studenta iz druge datoteke */
    if( fscanf(fin2, "%s%s",ime2, prezime2)  == EOF) 
        kraj2 = 1;
    
    /* sve dok nismo dosli do kraja neke datoteke */
    while( !kraj1 && !kraj2 ) {
        if( strcmp(ime1, ime2) <0 ){
            /* ime i prezime iz prve datoteke je leksikografski ranije,
            upisujemo ga u izlaznu datoteku */
            fprintf(fout, "%s %s\n",ime1, prezime1);
              /* citamo narednog studenta iz prve datoteke */
            if( fscanf(fin1, "%s%s",ime1, prezime1) == EOF) 
                kraj1 = 1;
        }
        else {
            /* ime i prezime iz druge datoteke je leksikografski ranije,
            upisujemo ga u izlaznu datoteku*/
            fprintf(fout, "%s %s\n",ime2, prezime2);
            /* citamo narednog studenta iz druge datoteke */
            if( fscanf(fin2, "%s%s",ime2, prezime2)  == EOF) 
                kraj2 = 1;
        }
    }

    /* Ako  smo iz prethodne petlje izasli zato sto se doslo do kraja druge datoteke,
    onda ima jos imena u prvoj datoteci, i prepisujemo ih, redom, jer su vec sortirani po imenu.*/
    while( !kraj1) {
        fprintf(fout, "%s %s\n",ime1, prezime1);
        if( fscanf(fin1, "%s%s",ime1, prezime1)  == EOF)
            kraj1 =1;
    }

    /* Ako  smo iz prve petlje izasli zato sto se doslo do kraja prve datoteke,
    onda ima jos imena u drugoj datoteci, i prepisujemo ih, redom, jer su vec sortirani po imenu.*/
    while( !kraj2  ) {
        fprintf(fout, "%s %s\n",ime2, prezime2);
        if( fscanf(fin2, "%s%s",ime2, prezime2)  == EOF)
            kraj2 = 1;
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout);
        
    return 0;
}