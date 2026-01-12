#ifndef POO_MASINA_ELECTRICA_H
#define POO_MASINA_ELECTRICA_H

#include "../Headers/Masina.h"

class MasinaElectrica : public Masina {
    int baterieKWh{};

public:
    MasinaElectrica(std::string brand, int hp, int basePrice, int baterieKWh);

    int getCustomHp() const override;
    int getCustomPrice() const override;
    void display() const override;

    Masina* clone() const override;
};

#endif
