//
// Created by Longho Bernard on 2024-11-18.
//

#include "CoffeeOrder.h"
#include <algorithm>

std::size_t CoffeeOrder::getNumberOfCupsBySize(CoffeeSize coffeeSize) const {
    return std::count_if(coffees.begin(), coffees.end(),
                         [&](const CoffeePtr &coffee) { return coffee->getSize() == coffeeSize; });
}


void CoffeeOrder::add(const CoffeeOrder::CoffeePtr &coffee, std::size_t quantity) {
    for (std::size_t i = 0; i < quantity; ++i) {
        coffees.push_back(coffee);
    }
}


std::size_t CoffeeOrder::getNumberOfCupsSold() const {
    return coffees.size();
}

std::size_t CoffeeOrder::getNumberOfLargeCupsSold() const {
    return getNumberOfCupsBySize(CoffeeSize::LARGE);
}

std::size_t CoffeeOrder::getNumberOfMediumCupsSold() const {
    return getNumberOfCupsBySize(CoffeeSize::MEDIUM);
}

std::size_t CoffeeOrder::getNumberOfSmallCupsSold() const {
    return getNumberOfCupsBySize(CoffeeSize::SMALL);
}

double CoffeeOrder::getTotalRevenue() const {
    double revenue = 0.0;
    for (const auto &item: coffees) {
        revenue += item->getPrice();
    }
    return revenue;
}

double CoffeeOrder::getTotalVolumeSold() const {
    double volume = 0.0;
    for (const auto &item: coffees) {
        volume += item->getVolume();
    }
    return volume;
}

void CoffeeOrder::displayReceipt(std::ostream &os) const {
    if (coffees.empty()) {
        os << "No orders made. No receipt to print!\n";
    } else {
        os << "\n--- Receipt ---\n";
        const auto smallCupCoffee = std::find_if(coffees.begin(), coffees.end(),
                                                 [](const CoffeePtr &coffee) {
                                                     return coffee->getSize() == CoffeeSize::SMALL;
                                                 });
        if(smallCupCoffee != coffees.end()){
            const auto smallCupsSold = getNumberOfSmallCupsSold();
            os << std::setw(2) << std::right <<smallCupsSold << " ";
            smallCupCoffee->get()->display();
        }
        const auto mediumCupCoffee = std::find_if(coffees.begin(), coffees.end(),[](const CoffeePtr &coffee){return coffee->getSize() ==CoffeeSize::MEDIUM;} );

        if(mediumCupCoffee != coffees.end()){
            auto mediumCups = getNumberOfMediumCupsSold();
            os << std::setw(2) << std::right<< mediumCups << " ";
            mediumCupCoffee->get()->display();
        }

        const auto largeCupCoffee = std::find_if(coffees.begin(), coffees.end(),[](const CoffeePtr &coffee){return coffee->getSize() ==CoffeeSize::LARGE;} );

        if(largeCupCoffee != coffees.end()){
            auto largeCups = getNumberOfLargeCupsSold();
            os << std::setw(2) << std::right << largeCups << " ";
            largeCupCoffee->get()->display();
        }
        os << "Total Amount: $" << getTotalRevenue() << "\n";
        os << "------- END OF RECEIPT ------" << "\n";
    }

}
