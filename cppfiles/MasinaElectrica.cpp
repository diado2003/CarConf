#include "../Headers/MasinaElectrica.h"
#include <iostream>
#include <utility>

MasinaElectrica::MasinaElectrica(std::string brand_, int hp_, int basePrice_, int baterieKWh_)
    : Masina(std::move(brand_), hp_, basePrice_), baterieKWh(baterieKWh_) {}

int MasinaElectrica::getCustomHp() const {
    // electric: “spike” de putere
    return hp + baterieKWh / 2;
}

int MasinaElectrica::getCustomPrice() const {
    // bateria costă mult
    return basePrice + baterieKWh * 200;
}

void MasinaElectrica::display() const {
    std::cout << "[Electric] " << brand
              << " | HP: " << getCustomHp()
              << " | Price: " << getCustomPrice()
              << " | Battery: " << baterieKWh << "kWh\n";
}

Masina* MasinaElectrica::clone() const {
    return new MasinaElectrica(*this);
}
