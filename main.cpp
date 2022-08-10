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