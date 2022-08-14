//
// Created by PiotrCiosmak on 09.08.2022.
//

#include "Tmen.hpp"
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

Tmen::Tmen()
{
    firstName = "Brak";
    lastName = "Brak";
    age = 0;
    height = 0;
    weight = 0;
    act = Tperson::sedentary;
}

Tmen::Tmen(string firstName, string lastName, int age, double height, double weight, activity act)
{
    //fistName
    firstName.at(0) = toupper(firstName.at(0));
    transform(firstName.begin() + 1, firstName.end(), firstName.begin() + 1, ::tolower);
    this->firstName = firstName;

    //lastName
    lastName.at(0) = toupper(lastName.at(0));
    transform(lastName.begin() + 1, lastName.end(), lastName.begin() + 1, ::tolower);
    this->lastName = lastName;

    //age
    if (age < 2 || age > 120)
    {
        cout << "---BLAD---\nWprowadzono niepoprawna liczbe jako wiek!!!" << endl;
        exit(-1);
    }
    this->age = age;

    //height
    if (height < 50 || height > 290)
    {
        cout << "---BLAD---\nWprowadzono niepoprawny wzrost !!!" << endl;
        exit(-1);
    }
    this->height = height;

    //weight
    if (weight < 10 || weight > 600)
    {
        cout << "---BLAD---\nWprowadzono niepoprawna wage !!!" << endl;
        exit(-1);
    }
    this->weight = weight;

    this->act = act;
}

void Tmen::calculateBMI()
{
    bmi = weight / ((height / 100) * (height / 100));
    cout << "Wynik\n"
            "BMI = " << setprecision(2) << bmi << " (";
    if (age <= 35)
    {
        if (bmi < 16.0)
            cout << "wyglodzenie";
        else if (bmi >= 16.0 && bmi <= 16.99)
            cout << "wychudzenie";
        else if (bmi >= 17.0 && bmi <= 18.49)
            cout << "niedowaga";
        else if (bmi >= 18.5 && bmi <= 24.99)
            cout << "prawidlowa masa ciala";
        else if (bmi >= 25.0 && bmi <= 29.99)
            cout << "nadwaga";
        else if (bmi >= 30.0 && bmi <= 34.99)
            cout << "otylosc I stopnia";
        else if (bmi >= 35.0 && bmi <= 39.99)
            cout << "otylosc II stopnia";
        else
            cout << "otylosc III stopnia";
    }
    else
    {
        if (bmi < 16.0)
            cout << "wyglodzenie";
        else if (bmi >= 16.0 && bmi <= 16.99)
            cout << "wychudzenie";
        else if (bmi >= 17.0 && bmi <= 18.49)
            cout << "niedowaga";
        else if (bmi >= 18.5 && bmi <= 26.99)
            cout << "prawidlowa masa ciala";
        else if (bmi >= 27.0 && bmi <= 29.99)
            cout << "nadwaga";
        else if (bmi >= 30.0 && bmi <= 34.99)
            cout << "otylosc I stopnia";
        else if (bmi >= 35.0 && bmi <= 39.99)
            cout << "otylosc II stopnia";
        else
            cout << "otylosc III stopnia";
    }
    cout << ")" << endl;
    saveToFileBMI();
}

void Tmen::calculateCalorie()
{
    double pal;
    switch (act)
    {
        case Tperson::sedentary:
            pal = 1.2;
            break;
        case Tperson::light:
            pal = 1.4;
            break;
        case Tperson::active:
            pal = 1.6;
            break;
        case Tperson::veryActive:
            pal = 1.8;
            break;
        case Tperson::extraActive:
            pal = 2.0;
            break;
    }
    calorie = static_cast<int>(66 + (13.7 * weight) + (5 * height) - (6.8 * age) * pal);
    cout << "Wynik\n" <<
         "Aby utrzymac wage musisz spozywac " << calorie << " kalori dziennie\n" <<
         "Aby tracic 0.25 kg tygodniowo musisz spozywac " << setprecision(0) << fixed << 0.90 * calorie << " dzienie\n" <<
         "Aby tracic 0.50 kg tygodniowo musisz spozywac " << fixed << 0.79 * calorie << " dzienie\n" <<
         "Aby tracic 1.00 kg tygodniowo musisz spozywac " << fixed << 0.59 * calorie << " dzienie\n" <<
         "Aby tyc 0.25 kg tygodniowo musisz spozywac " << fixed << 1.01 * calorie << " dzienie\n" <<
         "Aby tyc 0.50 kg tygodniowo musisz spozywac " << fixed << 1.23 * calorie << " dzienie\n" <<
         "Aby tyc 1.00 kg tygodniowo musisz spozywac " << fixed << 1.48 * calorie << " dzienie" << endl;
    saveToFileCalorie();
}

void Tmen::calculateAvgBMI()
{
    ifstream file("men_BMI_history.txt", ios::in);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }

    string line;
    double sum{};
    int counter{};
    while (getline(file, line), !line.empty())
    {
        sum += stod(line.substr(line.rfind(' ')));
        counter++;
    }
    cout << "Srednie BMI dla mezczyzn wynosi: " << fixed << setprecision(2) << sum / counter << endl;
    file.close();
}

void Tmen::calculateAvgCalorie()
{
    ifstream file("men_calorie_history.txt", ios::in);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }

    string line;
    double sum{};
    int counter{};
    while (getline(file, line), !line.empty())
    {
        sum += stod(line.substr(line.rfind(' ')));
        counter++;
    }
    cout << "Srednie zapotrzebowanie kaloryczne dla mezczyzn wynosi: " << fixed << setprecision(0) << sum / counter << endl;
    file.close();
}

void Tmen::saveToFileBMI()
{
    ofstream file("men_BMI_history.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }
    file << firstName << ' ' << lastName << ' ' << age << ' ' << height << ' ' << weight << ' ' << fixed << setprecision(2) << bmi << '\n';
    file.close();
}

void Tmen::saveToFileCalorie()
{
    ofstream file("men_calorie_history.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }
    file << firstName << ' ' << lastName << ' ' << age << ' ' << height << ' ' << weight << ' ' << act << ' ' << calorie << '\n';
    file.close();
}

void Tmen::calculateMacronutrients()
{
    switch (dietType)
    {
        case Tperson::sport:
            break;
        case Tperson::keto:
            break;
        case Tperson::reductive:
            break;
        case Tperson::standard:
            break;
        case Tperson::vegan:
            break;
        case Tperson::vegetarian:
            break;
    }
}


Tmen::~Tmen()
{
    cout << "Dziala destruktor klasy Tmen\n";
}
