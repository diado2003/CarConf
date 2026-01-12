#include "../Headers/MasinaSport.h"
#include <iostream>
#include <utility>

MasinaSport::MasinaSport(std::string brand_, int hp_, int basePrice_, int turboBoost_)
    : Masina(std::move(brand_), hp_, basePrice_), turboBoost(turboBoost_) {}

int MasinaSport::getCustomHp() const {
    return hp + turboBoost;
}

int MasinaSport::getCustomPrice() const {
    return basePrice + turboBoost * 50;
}

void MasinaSport::display() const {
    std::cout << "[Sport] " << brand
              << " | HP: " << getCustomHp()
              << " | Price: " << getCustomPrice()
              << " | TurboBoost: " << turboBoost << "\n";
}

Masina* MasinaSport::clone() const {
    return new MasinaSport(*this);
}
