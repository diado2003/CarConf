#ifndef POO_MASINA_H
#define POO_MASINA_H

#include <iostream>
#include <string>

class Masina {
public:
    int tipMasina;
    std::string culoare;
    float motorizare;
    std::string marca;
    float pret;
    int hp;

    Masina(int tip, std::string color, float engine, float price, int hp, std::string brand){

        void setCuloare(const std::string &color);
        void setMotorizare(float engine);
        void setMarca(std::string marca);
        [[nodiscard]] float getCustomPrice() const;
        int getCustomHp() const;

        friend std::ostream &operator<<(std::ostream &os, const Masina &masina);
    };
};

#endif