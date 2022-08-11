//
// Created by PiotrCiosmak on 09.08.2022.
//

#ifndef FITNESS_AND_HEALTH_CALCULATORS_TWOMEN_HPP
#define FITNESS_AND_HEALTH_CALCULATORS_TWOMEN_HPP

#include "Tperson.hpp"

class Twomen final : public Tperson
{
public:
    Twomen();

    Twomen(std::string firstName, std::string lastName, int age, double height, double weight, activity act);

    void create() override;

    void calculateBMI() override;

    void calculateCalorie() override;

    static void calculateAvgBMI();

    static void calculateAvgCalorie();

    std::string getFirstName() override;

    std::string getLastName() override;

    ~Twomen() override;

private:
    void saveToFileBMI() override;

    void saveToFileCalorie() override;
};


#endif //FITNESS_AND_HEALTH_CALCULATORS_TWOMEN_HPP
