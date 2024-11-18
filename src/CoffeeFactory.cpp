//
// Created by Longho Bernard on 2024-11-18.
//

#include "CoffeeFactory.h"

std::shared_ptr<Coffee> CoffeeFactory::create(const std::string &coffee) {
    if (coffee == "1") {
        return std::make_shared<SmallCoffee>();
    } else if (coffee == "2") {
        return std::make_shared<MediumCoffee>();
    } else if (coffee == "3") {
        return std::make_shared<LargeCoffee>();
    } else {
        return nullptr;
    }
}