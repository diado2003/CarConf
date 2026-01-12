#ifndef POO_CUSTOMER_H
#define POO_CUSTOMER_H

#include <string>
#include <vector>

class Customer {
    std::string name;
    int money{};
    std::vector<std::string> purchaseHistory;

public:
    Customer(std::string name, int money);

    const std::string& getName() const;
    int getMoney() const;

    void addMoney(int amount);
    void spendMoney(int amount);
    void addPurchase(const std::string& item);
    void displayPurchaseHistory() const;
};

#endif
