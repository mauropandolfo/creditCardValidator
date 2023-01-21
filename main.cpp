#include <iostream>
#include "object/CreditCard.cpp"
#include <ncurses.h>

int main(){
    initscr();
    noecho();
    printw("Ingrese el numero de la tarjeta : ");
    char number[20];
    getnstr(number,19);
    printw("Ingrese su nombre : ");
    char name[50];
    getnstr(name,49);
    printw("Ingrese la fecha : ");
    char date[5];
    getnstr(date,4);
    printw("Ingrese el numero de la tarjeta : ");
    char code[4];
    getnstr(code,3);

    long realNumber = atol(number);
    int realCode = atoi(code);

    CreditCard card(realNumber,name,date,realCode);
    if(card.validate(card)){
        printw("TARJETA VALIDA");
    }else{
        printw("TARJETA INVALIDA");
    }
    getch();
    endwin();
    return 0;
}