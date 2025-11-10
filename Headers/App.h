
#ifndef POO_APP_H
#define POO_APP_H

#include <vector>
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Masina.h"
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Customer.h"

class App {
private:
    static int contor;
    int nrMasini = 0;
    std::vector<Masina> masiniCumparate;
    float totalCost = 0;
    int totalHP = 0;
public:
    App();

    char firstQuestion();
    int sQuestion();
    void customizeCar(Masina &selectedCar);
    void buyCar(Masina &selectedCar);
    void displayPurchaseHistory();
    //void Hp-KwConv();



    const std::vector<std::string> availableColors = {"Galben", "Negru", "Rosu", "Albastru", "Verde", "Roz"};
    const std::vector<float> availableEngineCapacities = {1.4, 1.6, 2.0, 2.5, 3.0};
    const std::vector<std::string> availableBrands = {"BMW", "Audi", "Mercedes", "Volkswagen", "Mazda", "Ford"};
    std::vector<Masina> masini;
};

#endif