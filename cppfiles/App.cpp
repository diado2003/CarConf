#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\App.h"

#include <algorithm>

int App::contor = 0;

App::App() {
    masini.emplace_back(1, "alb", 1.2, 10000,75);
    masini.emplace_back(2, "alb", 1.2, 20000,100);
    masini.emplace_back(3, "alb", 1.2, 25000,125);
    masini.emplace_back(4, "alb", 1.2, 30000,150);
    masini.emplace_back(5, "alb", 1.2, 60000,200);
    nrMasini = contor++;
}

char App::firstQuestion() {
    char yn;
    std::cout << "Doriti sa cumparati o masina? [Y/N]: ";
    std::cin >> yn;
    if (yn == 'Y')
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

    if (selectedType < 1 || selectedType > masini.size()) {
        std::cout << "Tipul masinii introdus nu este valid. Va rugam selectati un numar intre 1 si " << masini.size() << ".\n";
        selectedType = 0;
    }

    return selectedType;
}