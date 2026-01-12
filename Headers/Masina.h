#ifndef POO_MASINA_H
#define POO_MASINA_H

#include <string>
#include <iostream> // Required for std::ostream

class Masina {
protected:
    std::string brand;
    int hp{};
    int basePrice{};

public:
    Masina(std::string brand, int hp, int basePrice);
    virtual ~Masina() = default;
    const std::string& getBrand() const;
    int getBaseHp() const;
    int getBasePrice() const;

    virtual int getCustomHp() const = 0;
    virtual int getCustomPrice() const = 0;
    virtual void display() const = 0;
    virtual Masina* clone() const = 0;
};

#endif