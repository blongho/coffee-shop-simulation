//
// Created by Longho Bernard on 2024-11-18.
//

#ifndef COFFEESHOPPROGRAM_COFFEEORDER_H
#define COFFEESHOPPROGRAM_COFFEEORDER_H

#include "SmallCoffee.h"
#include "MediumCoffee.h"
#include "LargeCoffee.h"

#include <vector>
#include <memory>

class CoffeeOrder {
private:

    using CoffeePtr = std::shared_ptr<Coffee>;

    using Coffees = std::vector<CoffeePtr>;

    Coffees coffees;

    std::size_t getNumberOfCupsBySize(CoffeeSize coffeeSize) const;

public:
    /**
     * Add a {@link Coffee} to the @link Coffees object
     * @param coffee  the coffee
     * @param quantity  the quantity of coffee
     */
    void add(const CoffeePtr &coffee, std::size_t quantity);

    std::size_t getNumberOfCupsSold() const;

    std::size_t getNumberOfLargeCupsSold() const;

    std::size_t getNumberOfMediumCupsSold() const;

    std::size_t getNumberOfSmallCupsSold() const;

    double getTotalRevenue() const;

    double getTotalVolumeSold() const;

    void displayReceipt(std::ostream &os = std::cout) const;

};


#endif //COFFEESHOPPROGRAM_COFFEEORDER_H
