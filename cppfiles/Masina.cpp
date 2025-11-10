#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Masina.h"

#include <string>
#include <utility>

Masina::Masina(int tip, std::string color, float engine,std::string brand, float price, int hp)
        : tipMasina(tip), culoare(std::move(color)), motorizare(engine), pret(price), hp(hp) {}

void Masina::setCuloare(const std::string &color) {
    culoare = color;
}

void Masina::setMotorizare(float engine) {
    motorizare = engine;
}

float Masina::getCustomPrice() const {
    float customPrice = pret;

    if (culoare == "Negru") {
        customPrice += 10000.99;
    }
    else if (culoare == "Rosu") {
        customPrice += 800.99;
    }
    else if (culoare == "Albastru") {
        customPrice += 600.99;
    }
    else if (culoare == "Verde") {
        customPrice += 1250.99;
    }
    else if (culoare == "Galben"){
        customPrice += 500.99;
    }
    else if (culoare == "Roz"){
        customPrice += 750.99;
    }

    if (motorizare == 1.6f) {
        customPrice += 1500.99f;
    }
    else if (motorizare == 2.0f) {
        customPrice += 3000.0f;
    }
    else if (motorizare == 2.5f) {
        customPrice += 5750.99f;
    }
    else if (motorizare == 1.4f){
        customPrice += 999.99f;
    }
    else if (motorizare == 3.0f){
        customPrice += 8000.99f;
    }

    if (marca == "BMW") {
        customPrice += 10000.99;
    }
    else if (marca == "Audi") {
        customPrice += 8000.99;
    }
    else if (marca == "Mercedes") {
        customPrice += 12000.99;
    }
    else if (marca == "Volkswagen"){
        customPrice += 6000.99;
    }
    else if (marca == "Mazda") {
        customPrice += 5000.99;
    }
    else if (marca == "Ford") {
        customPrice += 4000.99;
    }
    return customPrice;
}

int Masina::getCustomHp() const {
    int customHp = hp;

    if (motorizare == 1.6) {
        customHp += 30;
    }
    else if (motorizare == 2.0) {
        customHp += 50;
    }
    else if (motorizare == 2.5) {
        customHp += 100;
    }
    else if (motorizare == 1.4){
        customHp+= 40;
    }

    return customHp;
}

std::ostream &operator<<(std::ostream &os, const Masina &masina) {
    os << "Tip_masina: " << masina.tipMasina
       << " culoare: " << masina.culoare
       << " capacitate: " << masina.motorizare
       << " marca " << masina.marca
       << " Putere: " << masina.getCustomHp()
       << " pret: " << masina.getCustomPrice() << '\n';
    return os;
}