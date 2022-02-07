#include <stdio.h>

int main () {

        int dni, ure, minute, sekunde, n, x;
	
        printf("Vnesi število sekund: ");
	
        scanf("%d", &n); //vnos sekund preko spremenljivke n
        x = n; //shrani zacetno stevilo sekund za izpis na koncu

	//nov file pointer za delo z datotekami
	FILE * datoteka;
	//odpre rezultati1.txt in nadaljuje pisanje zaradi "a", na novo pa bi z "w"
	datoteka  = fopen("rezultati1.txt", "a");

        dni = n/(24*3600); //preveri število dni
        n = n % (24*3600); // v spremenljivko n shrani samo ostanek sekund brez dni
        ure = n/3600; //preveri število ur iz ostanka dni
        n %= 3600;  // v spremenljivko n shrani samo ostanek sekund od ur
        minute = n/60; // preveri stevilo minut iz ostanka ur
        n %=60; // preveri koliko sekund je se ostalo
        sekunde = n; // ostanek sekund ki niso bile razporejene v dni ure ali minute

        fprintf(datoteka, "Vneseno stevilo sekund %d se lahko zapise kot %d dni %d ur %d min %d sek \n", x, dni, ure, minute, sekunde); //izpis

	fclose(datoteka);
    return 0;



}


