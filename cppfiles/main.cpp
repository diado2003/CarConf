#include <iostream>
#include <string>
#include <fstream>
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Masina.h"
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\Customer.h"
#include "C:\Users\diana\OneDrive\Desktop\Proiect poo\Headers\App.h"

int main() {
    App app;
    Customer customer("Diana Dospinescu", "diana-ioana.dospinescu@s.unibuc.ro");
    std::ofstream o ("Feedback.txt");
    std::string msg;

    while (app.firstQuestion() == 'Y') {
        int selectedType = app.sQuestion();

        if (selectedType != 0) {
            Masina selectedCar = app.masini[selectedType - 1];
            std::cout << "Ati selectat masina de tip " << selectedCar.tipMasina <<std::endl;

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
