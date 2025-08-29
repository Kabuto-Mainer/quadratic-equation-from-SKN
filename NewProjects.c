
#include <stdio.h>
#include <ctype.h> 
#include <stdbool.h> 
#include <math.h>
#define Artichok 2.05
#define Svekla 1.15
#define Carrot 1.09
#define STOP 'q'
int main(void)
{ 
    char bufer, ch;
    float Ar = 0;
    float Sv = 0;
    float Ca = 0;
    float a;
    float Ar_Money = 0;
    float Ca_Money = 0;
    float Sv_Money = 0;
    float Bank = 0;
    float Veight = 0;

    printf("Type your order in format \"A - 4.5\"\n");
    printf("A - Artichok\nB - Svekla\nC - Carrot\n");
    printf("Print q for stop buying\n");
    while ((bufer = getchar()) != STOP){
        switch(bufer) {
            case 'A' : {
                scanf(" - %f", &a);
                Ar += a;
                break;
            }
            case 'B' : {
                scanf(" - %f", &a);
                Sv += a;
                break;
            }
            case 'C' : {
                scanf(" - %f", &a);
                Ca += a;
                break;
            }
        }
    }
    Ar_Money = Artichok * Ar;
    Sv_Money = Svekla * Sv;
    Ca_Money = Carrot * Ca;
    Bank = Ar_Money + Sv_Money + Ca_Money;
    Veight = Ar + Sv + Ca;
    if (Bank >= 100) {
        Bank *= 0,95;
    }
    if (Veight <= 5) {
        Bank += 6.5;
    }
    else if (Veight <= 20) {
        Bank += 14;
    }
    else {
        Bank += 14 + (floor(Veight) - 20) * 0.5;
    }
    printf("Inf about your order: \n");
    printf(" All cost is %.2f", Bank);
    printf("");
    return 0;
}