#include "naglowek.h"

/*****************************************************/
/* Funkcja dokłada liczbę calkowitą znajdującą się w */
/* zmiennej element na stos wskazywany przez         */
/* wskażnik pod wskażnikiem wstos                    */
/* PRE:                                              */
/*      wstos != NULL                                */
/* POST:                                             */
/*      funkcja dynamicznie alokuje pamięć wielkości */ 
/*      struktury ts_element i umieszcza w niej      */
/*      wyżej wspomnianą liczbę                      */
/*****************************************************/

void push (ts_element **wstos, int element) {
    if (*wstos == NULL) {
        *wstos = (ts_element *) malloc (sizeof(ts_element));
        (*wstos)->liczba = element;
        (*wstos)->poprzedni = NULL;
    } else {
        ts_element *pomocniczy = (ts_element *) malloc (sizeof(ts_element));
        pomocniczy->liczba = element;
        pomocniczy->poprzedni = *wstos;
        *wstos = pomocniczy;
    }
}

/*************************************************/
/* Funkcja zdejemuje liczbę calkowitą znajdującą */
/* się na szczycie stosu wskazywanego przez      */
/* wskażnik pod wskażnikiem wstos                */
/* PRE:                                          */
/*      wstos != NULL                            */
/* POST:                                         */
/*      funkcja zwraca wyżej wspomnianą liczbę   */
/*      (jeśli stos jest pusty to pojawia się    */
/*      stosowny komunikat)                      */
/*************************************************/

int pop (ts_element **wstos) {
    if (*wstos == NULL) {
        printf ("Stos jest pusty.");
    } else {
        int element = (*wstos)->liczba;
        if ((*wstos)->poprzedni == NULL) {
            free (*wstos);
            *wstos = NULL;
        } else {
        ts_element *pomocniczy = (*wstos)->poprzedni;
        (*wstos)->poprzedni = NULL;
        free (*wstos);
        *wstos = pomocniczy;
        pomocniczy = NULL;
        }
        return element;
    }
}  

/*********************************************/
/* Funkcja wyświetla na standardowym wyjściu */
/* zawartość stosu wskazywanego przez        */
/* wskażnik pod wskażnikiem wstos            */
/* PRE:                                      */
/*      wstos != NULL                        */
/* POST:                                     */
/*      zawartość stosu zostaje wyświetlona  */
/*      na standardowym wyjśiu               */
/*********************************************/

void full_print (ts_element **wstos) {
    ts_element *pomocniczy;
    if (*wstos == NULL) {
        printf("Stos jest pusty.\n");
    } else {
        pomocniczy = *wstos;
        do {
            printf("%d", pomocniczy->liczba);
            printf("\n");
            pomocniczy = pomocniczy->poprzedni;
        } while (pomocniczy != NULL);
    }
}

/***************************************************/
/* Funkcja usuwa wszystkie liczby znajdujące się   */
/* na stosie wskazywanym przez wskażnik pod        */
/* wskażnikiem wstos (oraz tworzące go struktury)  */
/* PRE:                                            */
/*      wstos != NULL                              */
/* POST:                                           */
/*      jeśli wcześniej została dynamicznie        */
/*      zaalokowana pamięć to zostaje ona          */
/*      zwolniona, a *wstos ustawiony na NULL      */
/***************************************************/

void clear (ts_element **wstos) {
    ts_element *pomocniczy;
    if (*wstos != NULL)
        if ((*wstos)->poprzedni == NULL) {
            free (*wstos);
            *wstos = NULL;
        } else {
            pomocniczy = *wstos;
            while (pomocniczy->poprzedni != NULL) {
            *wstos = (*wstos)->poprzedni;
            pomocniczy->poprzedni = NULL;
            free(pomocniczy);
            pomocniczy = *wstos;
            }
            free(pomocniczy);
            pomocniczy = NULL;
            *wstos = NULL;
    }
}

/****************************************************/
/* Funkcja sprawdza czy na stosie wskazywanym przez */
/* wskaźnik pod wskaźnikiem wstos znajdują się      */
/* conajmniej dwie liczby                           */
/* PRE:                                             */
/*      wstos != NULL                               */
/* POST:                                            */
/*      funkcja zwraca wartość 0 jeśli na stosie    */
/*      znajdują się mniej niż 2 liczby - w         */
/*      przeciwnym przypadku zwraca wartość 1       */
/****************************************************/

int czy_dwie_liczby (ts_element **wstos) {
    if (*wstos == NULL) {
        return 0;
    } else {
        if ((*wstos)->poprzedni == NULL) {
            return 0;
        } else {
            return 1;
        }
    }
}