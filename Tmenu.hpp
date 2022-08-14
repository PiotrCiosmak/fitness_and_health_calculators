//
// Created by PiotrCiosmak on 10.08.2022.
//

#ifndef FITNESS_AND_HEALTH_CALCULATORS_TMENU_HPP
#define FITNESS_AND_HEALTH_CALCULATORS_TMENU_HPP

#include "Tperson.hpp"

class Tmenu
{
public:
    //Tmenu();
    void drawStartMenu();

    void startMenuSelection();

    void drawMenu();

    void menuSelection();

    static void screenClear();

    ~Tmenu();
private:
    Tperson *p = nullptr;
};


#endif //FITNESS_AND_HEALTH_CALCULATORS_TMENU_HPP
