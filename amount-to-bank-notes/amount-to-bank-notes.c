#include <stdio.h>
#include <math.h>

int main() {

    int amount, notes;

    printf("Amount: ");
    scanf("%d", &amount);

    printf("There are:\n");

    notes = (int) amount / 500;
    printf("%d notes of 500 $\n", notes);
    amount = amount - notes * 500;

    notes = (int) amount / 200;
    printf("%d notes of 200 $\n", notes);
    amount = amount - notes * 200;

    notes = (int) amount / 100;
    printf("%d notes of 100 $\n", notes);
    amount = amount - notes * 100;

    notes = (int) amount / 50;
    printf("%d notes of 50 $\n", notes);
    amount = amount - notes * 50;

    notes = (int) amount / 20;
    printf("%d notes of 20 $\n", notes);
    amount = amount - notes * 20;

    notes = (int) amount / 10;
    printf("%d notes of 10 $\n", notes);
    amount = amount - notes * 10;

    notes = (int) amount / 5;
    printf("%d notes of 5 $\n", notes);
    amount = amount - notes * 5;

    notes = (int) amount / 2;
    printf("%d notes of 2 $\n", notes);
    amount = amount - notes * 2;

    notes = (int) amount / 1;
    printf("%d notes of 1 $\n", notes);
    amount = amount - notes * 1 ;

    return 0;
}