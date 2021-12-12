#pragma once /* Защита от двойного подключения заголовочного файла */
#include "deck.h"

template <class S>
inline void getNumberS (S &num) throw(const std::exception &) {
    if (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::logic_error("incorrect input!");
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getRandomNumber(int min, int max);
std::string suitCardToString (suitCard suit);
