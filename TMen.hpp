//
// Created by PiotrCiosmak on 09.08.2022.
//

#ifndef FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP
#define FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP

#include "TPerson.hpp"
#include <vector>

class TMen final : public TPerson
{
public:
    TMen();

    TMen(std::string firstName, std::string lastName, int age, double height, double weight, activity act);

    void calculateBMI() override;

    void calculateCalorie() override;

    static void calculateAvgBMI();

    static void calculateAvgCalorie();

    void calculateMacronutrients() override;

    ~TMen() override;

private:
    void saveToFileBMI() override;

    void saveToFileCalorie() override;
};


#endif //FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP