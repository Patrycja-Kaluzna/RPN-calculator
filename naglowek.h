#include <stdio.h>
#include <stdlib.h>

//Struktura wykorzystana w implementacji stosu na dynamicznej liście jednokierunkowej

typedef struct element {
    int liczba;
    struct element *poprzedni;
} ts_element;

void push (ts_element **, int);
int pop (ts_element **);
void full_print (ts_element **);
void clear (ts_element **);
int operator_lub_opcja (char);
int czy_dwie_liczby (ts_element **);