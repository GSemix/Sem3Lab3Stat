#include <iostream>
#include "../include/lab_3.h"
#include "../include/deck.h"

Cards::Cards (int newNum, suitCard newSuit) {
    num = newNum;
    suit = newSuit;
}

Cards::Cards () {
    num = 0;
    suit = Default;
}

bool Cards::operator == (const Cards & card) const {
    return num == card.num && suit == card.suit;
}

bool Cards::operator == (suitCard newSuit) const {
    return suit == newSuit;
}

Cards & Cards::operator = (const Cards & card) { // Переопределение экземпляра класса (с помощью перегруженного оператора присваивания)
    if (this != &card) { // Проверка на самоприсваивание
        num = card.num;
        suit = card.suit;
    }
    
    return *this;
}

bool Cards::operator == (int newNum) const {
    return num == newNum;
}

Deck::Deck () {
    countOfCardsInDeck = 52;
}

Deck::Deck (int num, suitCard suit) {
    countOfCardsInDeck = 52;
    
    setNumOfCardInDeck(0, num);
    setSuitOfCardInDeck(0, suit);
}

size_t Deck::getCountOfCardsInDeck() const {
    return countOfCardsInDeck;
}

void Deck::setNumOfCardInDeck (size_t numberOfCardInDeck, int newNum) throw(size_t, int) {
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    if (newNum < 2 || newNum > 14) {
        throw newNum;
    }
    
    deck[numberOfCardInDeck].num = newNum;
}

void Deck::setSuitOfCardInDeck (size_t numberOfCardInDeck, suitCard newSuit) throw(size_t, const std::exception &) {
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    if (newSuit == Default) {
        throw std::logic_error("impossible to assign!");
    }
    
    deck[numberOfCardInDeck].suit = newSuit;
}

void Deck::showCards () const { // Выводит все карты из deck
    std::string suit;
    
    for (size_t i = 0; i < countOfCardsInDeck; i++) {
        suit = suitCardToString(getSuitOfCardInDeck(i));
        std::cout << i << " -> " << getNumOfCardInDeck(i) << " | " << suit << std::endl;
    }
}

bool Deck::isTwinCard (Cards card) const { // Определяет наличие card в deck
    for (size_t i = 0; i < countOfCardsInDeck; i++) {
        if (deck[i] == card) { // Выполнить перегрузку для стравнения объектов класса
            return true;
        }
    }
    
    return false;
}

void Deck::initRandomCards (size_t start, size_t end, bool clear) { // Заполняет колоду deck от start до end случайными картами
    srand(static_cast<unsigned int>(time(0)));
    
    if (clear) { // Перезаписывает все элементы
        deleteSeveralCards(start, end);
        
        for (size_t i = start; i < end; i++) {
            deck[i] = randomCard();
        }
    } else { // Заполняет только незаписанные элементы
        for (size_t i = start; i < end; i++) {
            if (deck[i] == 0 && deck[i] == Default) {
                deck[i] = randomCard();
            }
        }
    }
}

Cards Deck::randomCard () const { // Возвращает одну уникальную карту
    int num = getRandomNumber(2, 14);
    suitCard suit = static_cast<suitCard>(suitCard::Diamonds + (std::rand() % suitCard::Default));
    Cards test = Cards(num, suit);

    while (isTwinCard(test)) {
        num = getRandomNumber(2, 14);
        suit = static_cast<suitCard>(suitCard::Diamonds + (std::rand() % suitCard::Default));
        test = Cards(num, suit);
    }

    return test;
}

void Deck::addCard (size_t numberOfCardInDeck, Cards test) throw(size_t, const std::exception &) { // Создает или перезаписывает карту по индексу numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    if (!isTwinCard (test)) {
        deck[numberOfCardInDeck] = test;
    } else {
        throw std::logic_error("twin card!");
    }
}

void Deck::deleteCard (size_t numberOfCardInDeck) throw(size_t) { // Удаляет карту по индексу numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    Cards defaultCard;
    deck[numberOfCardInDeck] = defaultCard;
}

void Deck::deleteSeveralCards (size_t start, size_t end) { // Удаляет карты от start до end
    for (size_t i = start; i < end; i++) {
        deleteCard(i);
    }
}

void Deck::showCard (size_t numberOfCardInDeck) const throw(size_t) { // Выводит карту из deck по numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }


    std::string suit = suitCardToString(getSuitOfCardInDeck(numberOfCardInDeck));
    std::cout << numberOfCardInDeck << " -> " << getNumOfCardInDeck(numberOfCardInDeck) << " | " << suit << std::endl;
}

void Deck::addRandomCard (size_t numberOfCardInDeck) throw(size_t) { // Создает одну рандомную уникальную карту по индесу numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    deleteCard(numberOfCardInDeck);
    deck[numberOfCardInDeck] = randomCard();
}

int Deck::getNumOfCardInDeck (size_t numberOfCardInDeck) const throw(size_t) { // Показывает значение num карты по индексу numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    return deck[numberOfCardInDeck].num;
}

suitCard Deck::getSuitOfCardInDeck (size_t numberOfCardInDeck) const throw(size_t) { // Показывает значение suit карты по индексу numberOfCardInDeck
    if (numberOfCardInDeck < 0 || numberOfCardInDeck > (countOfCardsInDeck - 1)) {
        throw numberOfCardInDeck;
    }
    
    return deck[numberOfCardInDeck].suit;
}

void Deck::getCardsWithSameSuit (suitCard suit) const { // Показывает из deck карты одной масти
    for (size_t i = 0; i < countOfCardsInDeck; i++) {
        if (deck[i] == suit) {
            std::string _suit = suitCardToString(getSuitOfCardInDeck(i));
            std::cout << i << " -> " << getNumOfCardInDeck(i) << " | " << _suit << std::endl;
        }
    }
}

int Deck::findCard (int num, suitCard suit) const { // Находит карту в deck по num и suit
    for (size_t i = 0; i < countOfCardsInDeck; i++) {
        if (deck[i] == num && deck[i] == suit) {
            return i;
        }
    }
    
    return -1;
}

int Deck::getIndexMaxCardsNumInRange (suitCard suit, size_t start) const { // Возвращает индекс карты с мастью suit и максимальным num от элемента под индексом start
    int maxNum = 0;
    size_t j = -1;
    
    for (size_t i = start; i < countOfCardsInDeck; i++) {
        if (deck[i] == suit && getNumOfCardInDeck(i) > maxNum) {
            maxNum = getNumOfCardInDeck(i);
            j = i;
        }
    }
    
    return j;
}

void Deck::sortBySuitAndDecreaseInRank () { // Сортировка deck по масти и убыванию ранга
    suitCard suits[5] = {Clubs, Diamonds, Hearts, Spades};
    
    int start = 0;
    int count = 0;
    
    for (size_t i = 0; i < 5; i++) {
        for (size_t v = start; v < countOfCardsInDeck; v++) {
            int indexOfMaxNum = getIndexMaxCardsNumInRange(suits[i], v);
            
            if (indexOfMaxNum == -1) {
                break;
            } else {
                int num = getNumOfCardInDeck(v);
                suitCard suit = getSuitOfCardInDeck(v);
                
                deck[v] = Cards(getNumOfCardInDeck(indexOfMaxNum), getSuitOfCardInDeck(indexOfMaxNum));
                deck[indexOfMaxNum] = Cards(num, suit);
                
                count++;
            }
        }
        
        start += count;
        count = 0;
    }
}
