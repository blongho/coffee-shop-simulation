//
// Created by Longho Bernard on 2024-11-18.
//

#ifndef COFFEESHOPPROGRAM_COFFEE_H
#define COFFEESHOPPROGRAM_COFFEE_H

#include <iostream>
#include <iomanip>

enum class CoffeeSize {
    SMALL,
    MEDIUM,
    LARGE
};

class Coffee {
private:
    const CoffeeSize size;
    const double price;
    const double volume;
public:
    /**
     * Constructor
     * @param size the size
     * @param price the price
     * @param volume  the volume in ounces
     */
    Coffee(CoffeeSize size, double price, double volume);

    virtual ~Coffee();

    [[nodiscard]] CoffeeSize getSize() const;

    [[nodiscard]] double getPrice() const;

    [[nodiscard]] double getVolume() const;

    virtual void display() const = 0;
};


#endif //COFFEESHOPPROGRAM_COFFEE_H
