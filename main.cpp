#include <iostream>
#include "Tperson.hpp"
#include "Tmenu.hpp"

int main()
{
    Tmenu menu;
    menu.drawStartMenu();
    menu.startMenuSelection();
    while (true)
    {
        menu.drawMenu();
        menu.menuSelection();
    }
}

//srednia bmi
//srednia cal
//gdy mamy niedowage to pokazuje inne rzeczy po obliczeniu kalorii
//obliczanie makro składników