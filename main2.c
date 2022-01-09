#include "naglowek.h"

int main () {
    ts_element *stos = NULL;    //Wskaźnik jest ustawiony na NULL, bo będzie pod niego dynamicznie alokowana pamięć
    ts_element **wstos = &stos;
    char znak;                  //Zmienna do przechowywania znaku działania lub opcji
    int liczba;                 //Zmienna do przechowywania liczby
    int a, b, wynik;            //Zmienne pomocnicze

    //Instrukcja obsługi programu wyświtlająca się kiedy zostaje rozpoczęte jego działanie

    printf ("Ten program pełni role czterodziałaniowego kalkulatora operującego w tzw. odwrotnej notacji polskiej.\n");
    printf ("Dostępne opcje:\n");
    printf ("P - usuń ostatnią wprowadzoną liczbę ze stosu,\nc - usuń wszystkie wprowadzone liczby ze stosu,\n");
    printf ("r - zamień ze sobą dwie ostatnie wprowdzone na stos liczby,\nd - zduplikuj ostatnią wprowadzoną na stos liczbę,\n");
    printf ("p - wypisz ostatnią wprowadzoną na stos liczbę,\nf - wypisz wszystkie liczby będące na stosie,\nq - zakończ działanie programu.\n");
    printf ("'=' - wypisz wynik obliczeń\n");
    printf ("UWAGA! W celu podania ujemnej liczby użyj znaku '_' zamiast '-'.\n");
    printf ("Podaj liczby oraz operatory działań ('+', '-', '*', '/') i/lub opcje:\n\n");

    while (znak != 'q') {       //Jeśli znak == q zwraca wartość 1 to koniec działania programu
        scanf ("%c", &znak);    //Pobranie znaku ze standardowego wejścia   
        if (operator_lub_opcja (znak) == 1) {   //Sprawdzenie czy jest znak dzialania lub opcji
            switch (znak) {     //Jeśli jest, to zostaje wykonane odpowiednie działanie lub opcja
                case '+':       //Dodawanie
                    if (czy_dwie_liczby (wstos) == 1) {
                        a = pop (wstos) + pop (wstos); 
                        push (wstos, a);
                    } else {
                        printf ("\nBłąd: na stosie są mniej niż dwie liczby\n\n");
                    }
                    break;
                case '-':       //Odejmowanie
                    if (czy_dwie_liczby (wstos) == 1) {
                        a = pop (wstos);
                        b = pop (wstos) - a;
                        push (wstos, b);
                    } else {
                        printf ("\nBłąd: na stosie są mniej niż dwie liczby\n\n");
                    }
                    break;
                case '*':       //Mnożenie
                    if (czy_dwie_liczby (wstos) == 1) {
                        a = pop (wstos) * pop (wstos);
                        push (wstos, a);
                    } else {
                        printf ("\nBłąd: na stosie są mniej niż dwie liczby\n\n");
                    }
                    break;
                case '/':       //Dzielenie
                    if (czy_dwie_liczby (wstos) == 1) {
                        a = pop (wstos);
                        if (a != 0) {
                            b = pop (wstos) / a;
                            push (wstos, b);
                        } else {
                            printf ("\nBłąd: dzielenie przez zero\n\n");
                        }
                    } else {
                        printf ("\nBłąd: na stosie są mniej niż dwie liczby\n\n");
                    }    
                    break;
                case 'P':       //Usunięcie ostatniej wprowadzonej liczby ze stosu
                    pop (wstos);
                    break;
                case 'c':       //Usunięcie wszystkich wprowadzonych liczb ze stosu
                    clear (wstos);
                    break;
                case 'r':       //Zamienienie ze sobą dwóch ostatnich wprowdzonych na stos liczb
                    if (czy_dwie_liczby (wstos) == 1) {
                        a = pop (wstos);
                        b = pop (wstos);
                        push (wstos, a);
                        push (wstos, b);
                    } else {
                        printf ("\nBłąd: na stosie są mniej niż dwie liczby\n\n");
                    }
                    break;
                case 'd':       //Zduplikowanie ostatniej wprowadzonej na stos liczby
                    a = pop (wstos);
                    push (wstos, a);
                    push (wstos, a);
                    break;
                case 'p':       //Wypisanie ostatniej wprowadzonej na stos liczby
                    printf ("\n");
                    if (*wstos != NULL) {
                        a = (*wstos)->liczba;
                        printf ("%d\n\n", a);
                    } else {
                        printf ("Stos jest pusty.\n\n");
                    }
                    break;
                case 'f':       //Wypisanie wszystkich liczb będących na stosie
                    printf ("\n");
                    full_print (wstos);
                    printf ("\n");
                    break;
                case '=':       //Wypisanie wyniku obliczeń
                    wynik = (*wstos)->liczba;
                    printf ("\nWynik wynosi %d\n\n", wynik);
                    break;
                case '_':       //Ujemna liczba
                    scanf ("%d", &liczba);
                    a = -1 * liczba;
                    push (wstos, a);
                    break;
            }
        } else {        
            ungetc (znak, stdin);   //Jeśli nie jest, to znak zostaje oddany na standardowe wejście
            scanf ("%d", &liczba);  //oraz wczytany jako liczba
            push (wstos, liczba);   //i dołożony na stos
        }
    }   
        free (stos);
        stos = NULL;
        wstos = NULL;
        return 0;
}