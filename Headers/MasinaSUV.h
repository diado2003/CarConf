#ifndef POO_MASINA_SUV_H
#define POO_MASINA_SUV_H

#include "../Headers/Masina.h"

class MasinaSUV : public Masina {
    int comfortLevel{}; // 1..10

public:
    MasinaSUV(std::string brand, int hp, int basePrice, int comfortLevel);

    int getCustomHp() const override;
    int getCustomPrice() const override;
    void display() const override;

    Masina* clone() const override;
};

#endif
