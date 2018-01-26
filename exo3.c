//Credit to Rodolphe for the idea;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct complexe_ {
    float real;
    float compl;
}complexe;

complexe addition(complexe a, complexe b) {
    complexe result;
    result.real = a.real + b.real;
    result.compl = a.compl + b.compl;
    return result;
}

complexe soustraction(complexe a, complexe b) {
    b.real = -b.real;
    b.compl = -b.compl;
    return addition(a,b);
}

complexe multiplication(complexe a, complexe b) {
   complexe result;
   result.real = a.real*b.real - a.compl*b.compl;
   result.compl = a.real*b.compl + a.compl*b.real;
   return result;
}

complexe division(complexe a, complexe b) {
    complexe result;
    float div = (b.real*b.real + b.compl*b.compl);
    result.real = (a.real*b.real + a.compl*b.compl)/div;
    result.compl = (a.compl*b.real -a.real*b.compl)/div;

    return result;
}

int main(int argc, char* argv[]){
    complexe number;
    complexe anotherNumber;
    complexe affichage;
    
    number.real = 1;
    number.compl = 1;
    anotherNumber.real = 2;
    anotherNumber.compl = 2;

    affichage = division(number, anotherNumber);
    printf("Reel : %f, Img: %f", affichage.real, affichage.compl);
    return 0;
}
