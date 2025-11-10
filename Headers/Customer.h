#ifndef POO_CUSTOMER_H
#define POO_CUSTOMER_H

#include <string>
#include <vector>
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Masina.h"

class Customer {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Masina> purchasedCars;
    float totalCost = 0;
    std::vector<Customer> Clients;

public:
    Customer(const std::string& customerName, const std::string& contact);

    void buyCar(const Masina& car);
    void displayPurchaseHistory();
};

#endif