#include <stdio.h>

void print_bits(int x)
{
    unsigned mask = 1 << (sizeof(int)*8-1);
    int i=0;
    
    while(mask)
    {
	mask & x ? printf("1") : printf("0");
	mask >>= 1;
    if (i%4 == 3) printf(" ");
    i++;
    }
    putchar('\n');
}

int main()
{
    /* Unos i ispis bitova broja. */
    int x;
    
    printf("Unesi broj\n");
    scanf("%d", &x);
    
    print_bits(x);
    printf("\n");

    /* Prednosti ako koristimo heksadekadni zapis. */
    printf("Unesi broj\n");
    scanf("%x", &x);
    
    print_bits(x);
    printf("\n");

    unsigned int y = 0xF0F0F0F0;
    printf("y: ");
    print_bits(y);
    printf("\n");

    /* Aritmeticko siftovanje, problem sa maskom. */
    int maska1 = 0xFF0000FF;
    unsigned int maska2 = 0xFF0000FF;

    printf("maska1: "); print_bits(maska1);
    printf("maska2: "); print_bits(maska2);

    maska1 = maska1 >> 10;
    printf("maska1: "); print_bits(maska1);

    maska2 = maska2 >> 10;
    printf("maska2: "); print_bits(maska2);  
    printf("\n");

    /* Eksluzivno ili moze da posluzi za sifrovanje podataka. */  
    maska2 = 0xFF0000FF;

    printf("x:            "); print_bits(x);
    x = x ^ maska2;
    printf("posiljalac x: "); print_bits(x);
    x = x ^ maska2;
    printf("primalac x:   "); print_bits(x);
    
    return 0;
}