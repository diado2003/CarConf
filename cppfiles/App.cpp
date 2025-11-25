#include "../Headers/App.h"
#include <algorithm>
#include <iostream>

int App::contor = 0;

App::App() {
    masini.emplace_back(1, "alb", 1.2, 10000, 75, "Mazda");
    masini.emplace_back(2, "alb", 1.2, 20000, 100, "Audi");
    masini.emplace_back(3, "alb", 1.2, 25000, 125, "Volkswagen");
    masini.emplace_back(4, "alb", 1.2, 30000, 150, "BMW");
    masini.emplace_back(5, "alb", 1.2, 60000, 200, "Mercedes");

    nrMasini = contor++;
}

char App::firstQuestion() {
    char yn;
    std::cout << "Doriti sa cumparati o masina? [Y/N]: ";
    std::cin >> yn;
    if (yn == 'Y' || yn == 'y') // Added check for lowercase 'y' too
        std::cout << "Bine ati venit!\n\n\n";
    return yn;
}

int App::sQuestion() {
    int selectedType = 0;
    std::cout << "Avem disponibile urmatoarele masini: \n\n\n";
    for (const auto &masina : masini) {
        std::cout << masina;
    }
    std::cout << "\n\n\n";

    std::cout << "Introduceti tipul masinii dorite (1-" << masini.size() << "): ";
    std::cin >> selectedType;

    // Check bounds
    if (selectedType < 1 || selectedType > (int)masini.size()) {
        std::cout << "Tipul masinii introdus nu este valid. Va rugam selectati un numar intre 1 si " << masini.size() << ".\n";
        selectedType = 0;
    }

    return selectedType;
}
void App::customizeCar(Masina &selectedCar) {
    char customizationChoice;
        std::cout << "Doriti sa personalizati masina? [Y/N]: ";
        std::cin >> customizationChoice;

        if (customizationChoice == 'Y' || customizationChoice == 'y') {
            std::string customColor;
            float customEngineCapacity;
            std::string customBrand;

            std::cout << "Alegeti culoarea din " << availableColors.size() << " optiuni: ";
            for (const auto &color : availableColors) {
                std::cout << color << " ";
            }
            std::cout << "\nCuloare: ";
            std::cin >> customColor;

            if (std::find(availableColors.begin(), availableColors.end(), customColor) != availableColors.end()) {
                std::cout << "Alegeti capacitatea motorului din " << availableEngineCapacities.size()
                          << " optiuni: ";
                for (const auto &engine : availableEngineCapacities) {
                    std::cout << engine << " ";
                }
                std::cout << "\nCapacitate motor: ";
                std::cin >> customEngineCapacity;

                if (std::find(availableEngineCapacities.begin(), availableEngineCapacities.end(), customEngineCapacity) != availableEngineCapacities.end()) {
                    std::cout << "Alegeti marca masinii din " << availableBrands.size() << " optiuni: ";
                    for (const auto &brand : availableBrands) {
                        std::cout << brand << " ";
                    }
                    std::cout << "\nMarca: ";
                    std::cin >> customBrand;

                    if (std::find(availableBrands.begin(), availableBrands.end(), customBrand) != availableBrands.end()) {
                        selectedCar.setCuloare(customColor);
                        selectedCar.setMotorizare(customEngineCapacity);
                        selectedCar.setMarca(customBrand);
                        std::cout << "Masina a fost personalizata cu succes!\n";
                    } else {
                        std::cout << "Marca aleasa nu este valida. Masina va ramane neschimbata.\n";
                    }
                } else {
                    std::cout << "Capacitatea motorului aleasa nu este valida. Masina va ramane neschimbata.\n";
                }
            } else {
                std::cout << "Culoarea aleasa nu este valida. Masina va ramane neschimbata.\n";
            }
        } else {
            std::cout << "Ati ales o masina standard:\n";
        }
    }


void App::buyCar(Masina &selectedCar) {
    masiniCumparate.push_back(selectedCar);
    totalCost += selectedCar.getCustomPrice();
    totalHP += selectedCar.getCustomPrice();
}

void App::displayPurchaseHistory() {
    std::cout << "Ati cumparat " << masiniCumparate.size() << " masini:\n";
    for (const auto &car : masiniCumparate) {
        std::cout << car;
    }
    std::cout << "Total de plata: " << totalCost << '\n';
}