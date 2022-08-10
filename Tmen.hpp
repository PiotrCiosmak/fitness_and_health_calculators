//
// Created by PiotrCiosmak on 09.08.2022.
//

#ifndef FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP
#define FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP

#include "Tperson.hpp"

class Tmen final : public Tperson
{
public:
    Tmen();

    Tmen(std::string firstName, std::string lastName, int age, double height, double weight, activity act);

    virtual void create() override;

    void calculateBMI() override;

    void calculateCalorie() override;

    std::string getFirstName();

    std::string getLastName();

private:
    void saveToFileBMI() override;

    void saveToFileCalorie() override;
};


#endif //FITNESS_AND_HEALTH_CALCULATORS_TMEN_HPP
