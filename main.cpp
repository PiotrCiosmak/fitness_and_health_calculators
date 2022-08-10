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

//srednia bmi
//srednia cal
//gdy mamy niedowage to pokazuje inne rzeczy po obliczeniu kalorii
//obliczanie makro składników



/*
void Tmen::calculateAvgBMI()
{
    ifstream file("men_BMI_history.txt", ios::in);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }
    string line;
    while (!file.eof())
    {
        getline(file, line);
        bmiArray.push_back(stod(line.substr(line.rfind(' '))));
    }
    double sum{};
    for (auto b: bmiArray)
    {
        sum += b;
    }
    cout << "Srednie BMI dla mezczyzn wynosi: " << sum / bmiArray.size() << endl;
    file.close();
}*/
