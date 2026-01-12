#include "../Headers/Customer.h"
#include <iostream>
#include <utility>

Customer::Customer(std::string name_, int money_)
    : name(std::move(name_)), money(money_) {}

const std::string& Customer::getName() const { return name; }
int Customer::getMoney() const { return money; }

void Customer::addMoney(int amount) {
    if (amount > 0) money += amount;
}

void Customer::spendMoney(int amount) {
    money -= amount;
}

void Customer::addPurchase(const std::string& item) {
    purchaseHistory.push_back(item);
}

void Customer::displayPurchaseHistory() const {
    std::cout << "Purchase history for " << name << ":\n";
    if (purchaseHistory.empty()) {
        std::cout << "  (empty)\n";
        return;
    }
    for (const auto& x : purchaseHistory) {
        std::cout << "  - " << x << "\n";
    }
}
