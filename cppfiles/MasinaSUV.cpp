#include "../Headers/MasinaSUV.h"
#include <iostream>
#include <utility>

MasinaSUV::MasinaSUV(std::string brand_, int hp_, int basePrice_, int comfortLevel_)
    : Masina(std::move(brand_), hp_, basePrice_), comfortLevel(comfortLevel_) {}

int MasinaSUV::getCustomHp() const {
    return hp + comfortLevel * 2;
}

int MasinaSUV::getCustomPrice() const {
    return basePrice + comfortLevel * 300;
}

void MasinaSUV::display() const {
    std::cout << "[SUV] " << brand
              << " | HP: " << getCustomHp()
              << " | Price: " << getCustomPrice()
              << " | Comfort: " << comfortLevel << "\n";
}

Masina* MasinaSUV::clone() const {
    return new MasinaSUV(*this);
}
