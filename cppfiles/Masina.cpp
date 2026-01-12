#include "../Headers/Masina.h"
#include <string>
#include <utility>

Masina::Masina(std::string brand_, int hp_, int basePrice_)
    : brand(std::move(brand_)), hp(hp_), basePrice(basePrice_) {}

const std::string& Masina::getBrand() const { return brand; }
int Masina::getBaseHp() const { return hp; }
int Masina::getBasePrice() const { return basePrice; }

