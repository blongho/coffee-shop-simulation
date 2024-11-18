//
// Created by Longho Bernard on 2024-11-18.
//

#ifndef COFFEESHOPPROGRAM_COFFEEFACTORY_H
#define COFFEESHOPPROGRAM_COFFEEFACTORY_H

#include <memory>
#include <string>

#include "SmallCoffee.h"
#include "MediumCoffee.h"
#include "LargeCoffee.h"

class CoffeeFactory {
private:
    CoffeeFactory() = default;

public:
    /**
     * Create a {@link Coffee} object on the fly
     * @param coffee a string denoting a coffee
     * @return a pointer to the coffee object
     */
    static std::shared_ptr<Coffee> create(const std::string &coffee);
};


#endif //COFFEESHOPPROGRAM_COFFEEFACTORY_H
