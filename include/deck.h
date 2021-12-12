#pragma once /* Защита от двойного подключения заголовочного файла */

enum suitCard {
    Diamonds, // Буби       <0>
    Hearts,   // Черви      <1>
    Clubs,    // Крести     <2>
    Spades,   // Пики       <3>
    Default   // Без масти  <4>
};

struct Cards {
    int num;
    suitCard suit;
    
    Cards();
    Cards(int newNum, suitCard newSuit);
    
    bool operator == (const Cards & card) const;
    bool operator == (suitCard newSuit) const;
    bool operator == (int newNum) const;
    Cards & operator = (const Cards & card);
};

class Deck {
    private:
    
        size_t countOfCardsInDeck;
        Cards deck[52];
    
    public:
    
        Deck ();
        Deck (int num, suitCard suit);
    
        void showCards() const;
        size_t getCountOfCardsInDeck() const;
        bool isTwinCard(Cards card) const;
        void setNumOfCardInDeck(size_t numberOfCardInDeck, int newNum) throw(size_t, int);
        void setSuitOfCardInDeck(size_t numberOfCardInDeck, suitCard newSuit) throw(size_t, const std::exception &);
        void initRandomCards(size_t start, size_t end, bool clear);
        Cards randomCard() const;
        void addCard(size_t numberOfCardInDeck, Cards test) throw(size_t, const std::exception &);
        void deleteCard(size_t numberOfCardInDeck) throw(size_t);
        void showCard(size_t numberOfCardInDeck) const throw(size_t);
        void addRandomCard(size_t numberOfCardInDeck) throw(size_t);
        int getNumOfCardInDeck(size_t numberOfCardInDeck) const throw(size_t);
        suitCard getSuitOfCardInDeck(size_t numberOfCardInDeck) const throw(size_t);
        void getCardsWithSameSuit(suitCard suit) const;
        int findCard(int num, suitCard suit) const;
        int getIndexMaxCardsNumInRange(suitCard suit, size_t start) const;
        void sortBySuitAndDecreaseInRank();
        void deleteSeveralCards(size_t start, size_t end);
};





















//  & - унарный оператор взятия адреса
//  * - оператор разыменивания указателя (получение значения)

// нужно использовать передачю по ССЫЛКЕ большого объекта в функцию, потому что будет использоваться уже существующий объект, а не копироваться
// (при передачи по значению при компиляции выделяются отдельные участки памяти)

// указатели не могут принимать временные значения func (const int &a)
