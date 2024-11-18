//
// Created by Longho Bernard on 2024-11-18.
//

#include "CoffeeShop.h"
#include "CoffeeFactory.h"
#include <string>

void CoffeeShop::run() const {
    while (true) {
        showMenu();
        os << "\nEnter your choice as a number: ";

        const auto choice = getMenuChoice();

        if (choice == "1") {
            buyCoffee();
        } else if (choice == "2") {
            showTotalCupsSold();
        } else if (choice == "3") {
            showTotalCoffeeOuncesSold();
        } else if (choice == "4") {
            showTotalRevenue();
        } else if (choice == "5") {
            printReceipt();
        } else if (choice == "0") {
            break;
        } else {
            os << "Invalid choice. Choose again!\n";
        }
    }

}

CoffeeShop::CoffeeShop()
        : order{std::make_unique<CoffeeOrder>()} {}

void CoffeeShop::showMenu() const {
    os << "\n====== MAVINS COFFEEE =====\n"
       << "Choose a number below for your choice \n"
       << "1. Buy coffee\n"
       << "2. Show total Cups sold\n"
       << "3. Total Coffee sold (in ounces)\n"
       << "4. Show Total Revenue\n"
       << "5. Show Receipt\n"
       << "0. Quit the program\n\n";
}

void CoffeeShop::buyCoffee() const {
    clearScreen();
    while (true) {
        os << "\nWhich kind of coffee? \n"
           << "1. Small Coffee Cup\n"
           << "2. Medium Coffee Cup\n"
           << "3. Large Coffee Cup\n";

        os << "\nEnter your choice: ";

        const auto coffeeChoice = getMenuChoice();

        if (coffeeChoice == "1" || coffeeChoice == "2" || coffeeChoice == "3") {
            os << "Enter the quantity of coffee: ";

            const auto quantity = getMenuChoice();

            if (quantity.empty()) {
                os << "Invalid value entered. Enter either 1,2 or 3\n";
            } else {
                try {
                    std::size_t coffeeAmount = std::stoull(quantity);

                    order->add(CoffeeFactory::create(coffeeChoice), coffeeAmount);

                    os << "\nMore coffee (Yes|No)? ";
                    const auto ans = getMenuChoice();
                    if (ans == "Yes" || ans == "yes" || ans == "Y" || ans == "y") {
                        continue;
                    } else {
                        break;
                        enterToContinue();
                    }
                } catch (const std::exception &exception) {
                    // os << exception.what() << "\n";
                    os << "Invalid value entered. Enter either 1,2 or 3\n";
                }
            }
        } else {
            os << "Invalid value entered. Enter either 1,2 or 3\n";
        }
    }

}

void CoffeeShop::showTotalCupsSold() const {
    clearScreen();
    os << "\nTotal Number of Cups sold " << order->getNumberOfCupsSold() << std::endl;
    enterToContinue();
}

void CoffeeShop::showTotalRevenue() const {
    clearScreen();
    os << "\nTotal revenue for " << order->getNumberOfCupsSold() << " of cups is $" << order->getTotalRevenue()
       << std::endl;
    enterToContinue();
}

void CoffeeShop::printReceipt() const {
    clearScreen();
    order->displayReceipt();
    enterToContinue();
}

void CoffeeShop::showTotalCoffeeOuncesSold() const {
    clearScreen();
    os << "\nTotal Coffee sold (in ounces) " << order->getTotalVolumeSold() << " oz" << std::endl;
    enterToContinue();
}

std::string CoffeeShop::getMenuChoice() const {
    std::string choice{};
    std::getline(std::cin, choice);
    return choice;
}

void CoffeeShop::clearScreen() const {
#ifdef __APPLE__
    std::system("clear");
    os << "Apple operating system\n";
#elif __unix__
    std::system("clear");
     os << "Linux operating system\n";
#elif _WIN32 || _WIN64
    std::system("cls");
     os << "Windows operating system\n";
#endif
}

void CoffeeShop::enterToContinue() const {
    os << "Press ENTER to continue";
    std::cin.get();
}