#include <iostream>
#include "Tperson.hpp"
#include "Tmenu.hpp"
#include "Tmen.hpp"

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

//obliczanie makro składników