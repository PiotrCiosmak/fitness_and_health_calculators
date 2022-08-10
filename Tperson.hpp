//
// Created by PiotrCiosmak on 08.08.2022.
//

#ifndef BMI_CALCULATOR_TPERSON_HPP
#define BMI_CALCULATOR_TPERSON_HPP

#include <iostream>

class Tperson
{
public:
    enum activity
    {
        sedentary, light, active, veryActive, extraActive
    };

    virtual void create() = 0;

    virtual void calculateBMI() = 0;

    virtual void calculateCalorie() = 0;

    virtual std::string getFirstName() = 0;

    virtual std::string getLastName() = 0;

    virtual ~Tperson()
    {
        std::cout << "Dziala destruktor klasy Tperson\n";
    }

protected:
    virtual void saveToFileBMI() = 0;

    virtual void saveToFileCalorie() = 0;

protected:
    std::string firstName;
    std::string lastName;
    int age;
    double height;
    double weight;
    activity act;
    double bmi;
    int calorie;
};


#endif //BMI_CALCULATOR_TPERSON_HPP
