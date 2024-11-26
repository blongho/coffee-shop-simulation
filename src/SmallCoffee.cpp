//
// Created by Longho Bernard on 2024-11-18.
//

#include "SmallCoffee.h"


SmallCoffee::SmallCoffee()
: Coffee(CoffeeSize::SMALL, 1.75, 9){

}

void SmallCoffee::display() const {
    std::cout << "Small cup: $" << std::fixed << std::setprecision(2)
              << getPrice() << " (" << getVolume() << " oz)" << "\n";
}
