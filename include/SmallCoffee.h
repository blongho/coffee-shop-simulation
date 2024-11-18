//
// Created by Longho Bernard on 2024-11-18.
//

#ifndef COFFEESHOPPROGRAM_SMALLCOFFEE_H
#define COFFEESHOPPROGRAM_SMALLCOFFEE_H

#include "Coffee.h"

class SmallCoffee : public Coffee {
public:
    SmallCoffee();

    void display() const override;
};


#endif //COFFEESHOPPROGRAM_SMALLCOFFEE_H
