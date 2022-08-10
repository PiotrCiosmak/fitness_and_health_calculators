//
// Created by PiotrCiosmak on 09.08.2022.
//

#ifndef FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP
#define FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP

#include "Tperson.hpp"
#include <vector>

class Tmen final : public Tperson
{
public:
    Tmen();

    Tmen(std::string firstName, std::string lastName, int age, double height, double weight, activity act);

    void create() override;

    void calculateBMI() override;

    void calculateCalorie() override;

    std::string getFirstName() override;

    std::string getLastName() override;

    ~Tmen() override;

private:
    void saveToFileBMI() override;

    void saveToFileCalorie() override;
};


#endif //FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP
