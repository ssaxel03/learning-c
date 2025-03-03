#include <stdio.h>
#include <math.h>

int main() {

    float Ax, Ay, Bx, By, distance;

    printf("x value of Point A: ");
    scanf("%f", &Ax);

    printf("y value of Point A: ");
    scanf("%f", &Ay);

    printf("x value of Point B: ");
    scanf("%f", &Bx);

    printf("y value of Point B: ");
    scanf("%f", &By);

    distance = sqrt( ((Bx-Ax)*(Bx-Ax))+((By-Ay)*(By-Ay)) );

    printf("The distance between A(%.3f,%.3f) and B(%.3f,%.3f) is %.3f.\n",
        Ax, Ay, Bx, By, distance);

    return 0;
}