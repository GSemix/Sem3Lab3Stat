#include <iostream>
#include <ctime>
#include "../include/lab_3.h"

std::string suitCardToString (suitCard suit) {
    switch (suit) {
        case Diamonds:
            return "Diamonds";

        case Hearts:
            return "Hearts";

        case Clubs:
             return "Clubs";

        case Spades:
            return "Spades";

        case Default:
            return "Default";
    }
}

int getRandomNumber(int min, int max) { // Выбирает случайное число от min до max
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
