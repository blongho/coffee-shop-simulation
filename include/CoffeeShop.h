//
// Created by Longho Bernard on 2024-11-18.
//

#ifndef COFFEESHOPPROGRAM_COFFEESHOP_H
#define COFFEESHOPPROGRAM_COFFEESHOP_H

#include "CoffeeOrder.h"

class CoffeeShop final {
private:
    std::unique_ptr<CoffeeOrder> order = nullptr;

    std::ostream &os = std::cout;

    void showMenu() const;

    void buyCoffee() const;

    void showTotalCupsSold() const;

    void showTotalRevenue() const;

    void showTotalCoffeeOuncesSold() const;

    void printReceipt() const;

    [[nodiscard]] std::string getMenuChoice() const;

    void clearScreen() const;

    void enterToContinue() const;

public:
    CoffeeShop();

    ~ CoffeeShop() = default;

    void run() const;
};


#endif //COFFEESHOPPROGRAM_COFFEESHOP_H
