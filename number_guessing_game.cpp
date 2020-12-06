// Copyright (c) 2020 Sean McLeod All rights reserved

// Created by Sean McLeod
// Created on November 2020
// This program is the number guessing game

#include <iostream>
#include <random>
#include <string>

int main()  {
    // this function can tell the user if the number they guessed is correct

    std::string guessedString;
    int guessedNumber;
    int randomNumber;

    // input
    std::cout << "Guess a number between 0 to 9: " << std::endl;
    std::cin >> guessedString;
    std::cout << "" << std::endl;

    // process
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // process and output
    try {
        guessedNumber = std::stoi(guessedString.c_str());

        if (guessedNumber == randomNumber) {
            std::cout << "You are correct!! " << randomNumber
                      << " is the correct number." << std::endl;
        } else {
            std::cout << "You are wrong! " << randomNumber
                      << " was the correct number. Try again." << std::endl;
        }
        }
    catch (std::invalid_argument) {
        std::cout << "This is not an integer" << std::endl;
    }
}
