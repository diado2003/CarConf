#include "../Headers/App.h"
#include "../Headers/Exceptions.h"
#include "../Headers/MasinaElectrica.h"
#include "../Headers/MasinaSUV.h"
#include "../Headers/MasinaSport.h"

#include <iostream>
#include <limits>
#include <utility>

int App::contor = 0;

App::App(Customer customer_)
    : customer(std::move(customer_)) {
    ++contor;
}

App::App(const App& other)
    : customer(other.customer) {
    stock.reserve(other.stock.size());
    for (const auto& m : other.stock) {
        stock.emplace_back(m->clone());
    }
    ++contor;
}

void swap(App& a, App& b) noexcept {
    using std::swap;
    swap(a.stock, b.stock);
    swap(a.customer, b.customer);
    // contor rămâne global, nu îl schimbăm
}

App& App::operator=(App other) {
    swap(*this, other);
    return *this;
}

void App::seedStock() {
    stock.emplace_back(std::make_unique<MasinaSport>("BMW M4", 420, 50000, 80));
    stock.emplace_back(std::make_unique<MasinaSUV>("Volvo XC90", 300, 60000, 8));
    stock.emplace_back(std::make_unique<MasinaElectrica>("Tesla Model 3", 280, 45000, 75));
    stock.emplace_back(std::make_unique<MasinaSport>("Audi R8", 610, 150000, 120));
    stock.emplace_back(std::make_unique<MasinaSUV>("Toyota RAV4", 250, 35000, 7));
    stock.emplace_back(std::make_unique<MasinaElectrica>("Nissan Leaf", 150, 30000, 40));
    stock.emplace_back(std::make_unique<MasinaSport>("Audi TT", 230, 40000, 60));
}

void App::listCars() const {
    if (stock.empty()) {
        std::cout << "Nu exista masini in stoc.\n";
        return;
    }
    std::cout << "=== STOCK ===\n";
    for (std::size_t i = 0; i < stock.size(); ++i) {
        std::cout << i << ") ";
        stock[i]->display(); // apel virtual prin pointer de bază
    }
}

void App::buyCar(std::size_t index) {
    if (index >= stock.size()) {
        throw OutOfRange("Index invalid pentru masina.");
    }

    const auto& car = stock[index];
    const int price = car->getCustomPrice(); // virtual "specific temei"

    if (customer.getMoney() < price) {
        throw NotEnoughMoney("Nu ai destui bani pentru aceasta masina.");
    }

    // ok: avem bani
    customer.spendMoney(price);
    customer.addPurchase(car->getBrand() + " | paid " + std::to_string(price));

    // scoatem din stoc
    stock.erase(stock.begin() + static_cast<long>(index));

    std::cout << "Cumparare reusita! Bani ramasi: " << customer.getMoney() << "\n";
}

void App::run() {
    seedStock();

    while (true) {
        std::cout << "\nCustomer: " << customer.getName()
                  << " | Money: " << customer.getMoney()
                  << " | App instances: " << contor << "\n";

        std::cout << "1) List cars\n"
                  << "2) Buy car (by index)\n"
                  << "3) Show purchase history\n"
                  << "0) Exit\n"
                  << "Choose: ";

        int opt;
        if (!(std::cin >> opt)) {
            // input invalid -> curățăm și aruncăm
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw InvalidOption("Input invalid (nu e numar).");
        }

        if (opt == 0) return;

        if (opt == 1) {
            listCars();
        } else if (opt == 2) {
            std::cout << "Index: ";
            std::size_t idx;
            if (!(std::cin >> idx)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidOption("Index invalid.");
            }
            buyCar(idx);
        } else if (opt == 3) {
            customer.displayPurchaseHistory();
        } else {
            throw InvalidOption("Optiune inexistenta.");
        }
    }
}
