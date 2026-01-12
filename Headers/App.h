#ifndef POO_APP_H
#define POO_APP_H

#include "../Headers/Customer.h"
#include "../Headers/Masina.h"
#include <memory>
#include <vector>

class App {
    std::vector<std::unique_ptr<Masina>> stock;
    Customer customer;

    static int contor;

public:
    explicit App(Customer customer);

    App(const App& other);
    App& operator=(App other);
    App(App&&) noexcept = default;
    ~App() = default;

    friend void swap(App& a, App& b) noexcept;

    void seedStock();
    void listCars() const;
    void buyCar(std::size_t index);
    void run();
};

#endif
