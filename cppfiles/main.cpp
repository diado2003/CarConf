#include "../Headers/App.h"
#include "../Headers/Exceptions.h"
#include <iostream>

int main() {
    try {
        App app(Customer("Diana", 100000));
        app.run();
    } catch (const AppException& e) {
        std::cout << "Eroare (AppException): " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Eroare (std::exception): " << e.what() << "\n";
    }
    return 0;
}
