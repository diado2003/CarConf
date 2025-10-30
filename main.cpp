#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

class Masina {
private:
    int tipMasina;
    std::string culoare;
    float motorizare;
    std::string marca;
    float pret;

public:
    Masina(int tip, const std::string &color, float engine, float price)
            : tipMasina(tip), culoare(color), motorizare(engine), pret(price) {}

    void setCuloare(const std::string &color) {
        culoare = color;
    }

    void setMotorizare(float engine) {
        motorizare = engine;
    }

    void setMarca(const std::string &brand) {
        marca = brand;
    }

    int getTipMasina() const {
        return tipMasina;
    }

    float getCustomPrice() const {
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
        } else if (culoare == "Galben"){
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

    friend std::ostream &operator<<(std::ostream &os, const Masina &masina) {
        os << "Tip_masina: " << masina.tipMasina
           << " culoare: " << masina.culoare
           << " capacitate: " << masina.motorizare
           << " marca " << masina.marca
           << " pret: " << masina.getCustomPrice() << '\n';
        return os;
    }
};

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Masina> purchasedCars;
    float totalCost = 0;

public:
    Customer(const std::string& customerName, const std::string& contact) : name(customerName), contactInfo(contact) {}

    void buyCar(const Masina& car) {
        purchasedCars.push_back(car);
        totalCost += car.getCustomPrice();
    }

    void displayPurchaseHistory() {
        std::cout << "Client: " << name << " mail: (" << contactInfo << ")\n";
        std::cout << "Masini cumparate: " << purchasedCars.size() << '\n';
        for (const auto& car : purchasedCars) {
            std::cout << car;
        }
        std::cout << "Cost total: " << totalCost << '\n';
    }
};

class App {
private:
    static int contor;
    int nrMasini = 0;
    std::vector<Masina> masiniCumparate;
    float totalCost = 0;

    std::vector<Masina> masini;
    const std::vector<std::string> availableColors = {"Galben", "Negru", "Rosu", "Albastru", "Verde", "Roz"};
    const std::vector<float> availableEngineCapacities = {1.4f, 1.6f, 2.0f, 2.5f, 3.0f};
    const std::vector<std::string> availableBrands = {"BMW", "Audi", "Mercedes", "Volkswagen", "Mazda", "Ford"};

public:
    App() {
        masini.emplace_back(1, "alb", 1.2f, 10000);
        masini.emplace_back(2, "alb", 1.2f, 20000);
        masini.emplace_back(3, "alb", 1.2f, 25000);
        masini.emplace_back(4, "alb", 1.2f, 30000);
        masini.emplace_back(5, "alb", 1.2f, 60000);
        nrMasini = contor++;
    }

    char firstQuestion() {
        char yn;
        std::cout << "Doriti sa cumparati o masina? [Y/N]: ";
        std::cin >> yn;
        if (yn == 'Y' || yn == 'y')
            std::cout << "Bine ati venit!\n\n\n";
        return yn;
    }

    int sQuestion() {
        int selectedType = 0;
        std::cout << "Avem disponibile urmatoarele masini: \n\n\n";
        for (const auto &masina : masini) {
            std::cout << masina;
        }
        std::cout << "\n\n\n";

        std::cout << "Introduceti tipul masinii dorite (1-" << masini.size() << "): ";
        std::cin >> selectedType;

        if (selectedType < 1 || selectedType > static_cast<int>(masini.size())) {
            std::cout << "Tipul masinii introdus nu este valid. Va rugam selectati un numar intre 1 si " << masini.size() << ".\n";
            selectedType = 0;
        }

        return selectedType;
    }

    Masina getCarCopy(size_t index) const {
        if (index < masini.size()) {
            return masini[index];
        }
        return Masina(0, "necunoscut", 0.0f, 0.0f);
    }

    void customizeCar(Masina &selectedCar) {
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

    void buyCar(Masina &selectedCar) {
        masiniCumparate.push_back(selectedCar);
        totalCost += selectedCar.getCustomPrice();
    }

    void displayPurchaseHistory() {
        std::cout << "Ati cumparat " << masiniCumparate.size() << " masini:\n";
        for (const auto &car : masiniCumparate) {
            std::cout << car;
        }
        std::cout << "Total de plata: " << totalCost << '\n';
    }

    size_t inventorySize() const { return masini.size(); }
    // const std::vector<std::string> availableColors = {"Galben", "Negru", "Rosu", "Albastru", "Verde", "Roz"};
    // const std::vector<float> availableEngineCapacities = {1.4f, 1.6f, 2.0f, 2.5f, 3.0f};
    // const std::vector<std::string> availableBrands = {"BMW", "Audi", "Mercedes", "Volkswagen", "Mazda", "Ford"};
    // std::vector<Masina> masini;
    //le-am pus in private
};

int App::contor = 0;

int main() {
    App app;
    Customer customer("Dospinescu Diana", "diana-ioana.dospinescu@s.unibuc.ro");
    std::ofstream o ("Feedback.txt");
    std::string msg;

    while (app.firstQuestion() == 'Y') {
        int selectedType = app.sQuestion();

        if (selectedType != 0) {
            Masina selectedCar = app.getCarCopy(static_cast<size_t>(selectedType - 1));
            std::cout << "Ati selectat masina de tip " << selectedCar.getTipMasina() <<std::endl;

            app.customizeCar(selectedCar);
            app.buyCar(selectedCar);
            customer.buyCar(selectedCar);
        } else {
            std::cout << "Selectia nu este valida. Aplicatia se va inchide.\n";
        }
    }

    std::cout<<"\n\n\n";

    app.displayPurchaseHistory();

    std::cout<<"\n\n\n";

    customer.displayPurchaseHistory();

    return 0;
}
