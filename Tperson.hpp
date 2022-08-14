//
// Created by PiotrCiosmak on 08.08.2022.
//

#ifndef BMI_CALCULATOR_TPERSON_HPP
#define BMI_CALCULATOR_TPERSON_HPP

#include <iostream>
#include <vector>

class Tperson
{
public:
    enum activity
    {
        sedentary, light, active, veryActive, extraActive
    };

    enum objective
    {
        weightLoss, conditionImprovment, massBulid
    };

    void create();

    std::string getFirstName();

    std::string getLastName();

    int getCalorie();

    virtual void calculateBMI() = 0;

    virtual void calculateCalorie() = 0;

    virtual void calculateMacronutrients() = 0;

    virtual ~Tperson()
    {
        std::cout << "Dziala destruktor klasy Tperson\n";
    }

protected:
    virtual void saveToFileBMI() = 0;

    virtual void saveToFileCalorie() = 0;

    std::string firstName;
    std::string lastName;
    int age;
    double height;
    double weight;
    activity act;
    double bmi;
    int calorie;
    objective objective;
    int estimatedAmountOfFat;
    int protein;
    int carbo;
    int fat;
};


#endif //BMI_CALCULATOR_TPERSON_HPP