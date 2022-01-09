#include "naglowek.h"

/**************************************************/
/* Funkcja sprawdza czy w zmiennej znakowej znak  */
/* znajduje się znak działania lub opcji          */
/* PRE:                                           */
/*      brak                                      */
/* POST:                                          */
/*      funkcja zwraca wartość 1 jeśli w zmiennej */
/*      znajduje się znak inny niż cyfra - w      */
/*      przeciwnym przypadku zwraca wartość 0     */
/**************************************************/

int operator_lub_opcja (char znak) {
    int i;
    char tab[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    for (i = 0; i < 10; i++) {
    if (znak == tab[i]) {
        return 0;
        }
    } 
    return 1;
}