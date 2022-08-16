//
// Created by PiotrCiosmak on 09.08.2022.
//

#include "TWomen.hpp"
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

TWomen::TWomen()
{
    firstName = "Brak";
    lastName = "Brak";
    age = 0;
    height = 0;
    weight = 0;
    act = TPerson::sedentary;
}

TWomen::TWomen(std::string firstName, std::string lastName, int age, double height, double weight, activity act)
{
    //fistName
    this->firstName = toupper(firstName.at(0));
    transform(firstName.begin() + 1, firstName.end(), this->firstName.begin() + 1, ::tolower);

    //lastName
    this->lastName = toupper(lastName.at(0));
    transform(lastName.begin() + 1, lastName.end(), this->lastName.begin() + 1, ::tolower);

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

void TWomen::calculateBMI()
{
    bmi = weight / ((height / 100) * (height / 100));
    cout << "Wynik\n"
            "BMI = " << setprecision(2) << bmi << "(";
    if (age <= 35)
    {
        if (bmi < 16.0)
            cout << "wyglodzenie";
        else if (bmi >= 16.0 && bmi <= 16.99)
            cout << "wychudzenie";
        else if (bmi >= 17.0 && bmi <= 18.49)
            cout << "niedowaga";
        else if (bmi >= 18.5 && bmi <= 23.99)
            cout << "prawidlowa masa ciala";
        else if (bmi >= 24.0 && bmi <= 29.99)
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
        else if (bmi >= 18.5 && bmi <= 25.99)
            cout << "prawidlowa masa ciala";
        else if (bmi >= 26.0 && bmi <= 29.99)
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

void TWomen::calculateCalorie()
{
    double pal;
    switch (act)
    {
        case TPerson::sedentary:
            pal = 1.2;
            break;
        case TPerson::light:
            pal = 1.4;
            break;
        case TPerson::active:
            pal = 1.6;
            break;
        case TPerson::veryActive:
            pal = 1.8;
            break;
        case TPerson::extraActive:
            pal = 2.0;
            break;
    }
    calorie = static_cast<int>(655 + (9.6 * weight) + (1.8 * height) - (4.7 * age) * pal);
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

void TWomen::calculateAvgBMI()
{
    ifstream file("women_BMI_history.txt", ios::in);
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
    cout << "Srednie BMI dla kobiet wynosi: " << fixed << setprecision(2) << sum / counter << endl;
    file.close();
}

void TWomen::calculateAvgCalorie()
{
    ifstream file("women_calorie_history.txt", ios::in);
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
    cout << "Srednie zapotrzebowanie kaloryczne dla kobiet wynosi: " << fixed << setprecision(0) << sum / counter << endl;
    file.close();
}

void TWomen::saveToFileBMI()
{
    ofstream file("women_BMI_history.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }
    file << firstName << ' ' << lastName << ' ' << age << ' ' << height << ' ' << weight << ' ' << fixed << setprecision(2) << bmi << '\n';
    file.close();
}

void TWomen::saveToFileCalorie()
{
    ofstream file("women_calorie_history.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Blad otwarcia pliku!!!";
        exit(-1);
    }
    file << firstName << ' ' << lastName << ' ' << age << ' ' << height << ' ' << weight << ' ' << act << ' ' << calorie << '\n';
    file.close();
}

void TWomen::calculateMacronutrients()
{
    if (getCalorie() == 0)
    {
        return;
    }
    switch (objective)
    {
        case TPerson::weightLoss:
            protein = static_cast<int>(calorie * 0.35 / 4);
            fat = static_cast<int>(calorie * 0.15 / 9);
            carbo = static_cast<int>(calorie * 0.50 / 9);
            break;
        case TPerson::conditionImprovment:
            protein = static_cast<int>(calorie * 0.40 / 4);
            fat = static_cast<int>(calorie * 0.20 / 9);
            carbo = static_cast<int>(calorie * 0.40 / 9);
            break;
        case TPerson::massBulid:
            protein = static_cast<int>(calorie * 0.50 / 4);
            fat = static_cast<int>(calorie * 0.10 / 9);
            carbo = static_cast<int>(calorie * 0.40 / 9);
            break;
    }
    cout << calorie << " kcal / dzien\n"
         << "Bialka: " << protein << " g\n"
         << "Tluszcze: " << fat << " g\n"
         << "Weglowodany: " << carbo << " g" << endl;
}

TWomen::~TWomen()
{
    cout << "Dziala destruktor klasy TWomen\n";
}