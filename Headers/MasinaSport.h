#ifndef POO_MASINA_SPORT_H
#define POO_MASINA_SPORT_H

#include "../Headers/Masina.h"

class MasinaSport : public Masina {
    int turboBoost{};

public:
    MasinaSport(std::string brand, int hp, int basePrice, int turboBoost);

    int getCustomHp() const override;
    int getCustomPrice() const override;
    void display() const override;

    Masina* clone() const override;
};

#endif
