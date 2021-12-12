#include <iostream>
#include "include/lab_3.h"
#include "include/deck.h"

int main () {
    Deck deck = Deck(10, Hearts);
    int com;
    bool exit = false;
    
    while (!exit) {
        try {
            std::cout << "\n{0} -> Exit\n{1} -> showCards\n{2} -> addCard\n{3} -> initRandomCards\n{4} -> deleteCard\n{5} -> showCard\n{6} -> addRandomCard\n{7} -> getNumOfCardInDeck\n{8} -> getSuitOfCardInDeck\n{9} -> getCardsWithSameSuit\n{10} -> sortBySuitAndDecreaseInRank\n\n\t=> ";
            getNumberS(com);
        
            std::cout << std::endl;
        
            switch (com) {
                case 0:
                    exit = true;
                    break;
                case 1:
                    deck.showCards();
                    break;
                case 2: {
                    size_t numberOfCardInDeck;
                    int num;
                    int suit;

                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);

                    std::cout << "num: ";
                    getNumberS(num);
                    
                    if (num < 2 || num > 14) {
                        throw num;
                    }

                    std::cout << "{0 - Diamonds\t1 - Hearts\t2 - Clubs\t3 - Spades}" << std::endl << "suit: ";
                    getNumberS(suit);

                    if (suit < 0 || suit > 3) {
                        throw suit;
                    }

                    Cards test = Cards(num, static_cast<suitCard>(suit));
                    deck.addCard(numberOfCardInDeck, test);

                    break;
                }
                case 3: {
                    int ans;
                    
                    std::cout << "Overwrite everything? (1/0): ";
                    getNumberS(ans);
                        
                    if (ans < 0 || ans > 1) {
                        throw ans;
                    }
                    
                    deck.initRandomCards(0, deck.getCountOfCardsInDeck(), static_cast<bool>(ans));
                    break;
                }
                case 4: {
                    size_t numberOfCardInDeck;

                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);
                    
                    deck.deleteCard(numberOfCardInDeck);
                    break;
                }
                case 5: {
                    size_t numberOfCardInDeck;
                    
                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);
                    
                    deck.showCard(numberOfCardInDeck);
                    break;
                }
                case 6: {
                    size_t numberOfCardInDeck;
                    
                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);
                    
                    deck.addRandomCard(numberOfCardInDeck);
                    break;
                }
                case 7: {
                    size_t numberOfCardInDeck;
                    int num;
                    
                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);
                    num = deck.getNumOfCardInDeck(numberOfCardInDeck);
                    
                    std::cout << "deck[" << numberOfCardInDeck << "].num -> " << num << std::endl;
                    break;
                }
                case 8: {
                    size_t numberOfCardInDeck;
                    std::string suit;
                    
                    std::cout << "number of card: ";
                    getNumberS(numberOfCardInDeck);
                    suit = suitCardToString(deck.getSuitOfCardInDeck(numberOfCardInDeck));
                    
                    std::cout << "deck[" << numberOfCardInDeck << "].suit -> " << suit << std::endl;
                    break;
                }
                case 9: {
                    int suit;
                    
                    std::cout << "{0 - Diamonds\t1 - Hearts\t2 - Clubs\t3 - Spades}" << std::endl << "suit: ";
                    getNumberS(suit);
                    
                    deck.getCardsWithSameSuit(static_cast<suitCard>(suit));
                    break;
                }
                case 10:
                    deck.sortBySuitAndDecreaseInRank();
                    break;
            }
        } catch(const std::exception & mess) {
            std::cerr << mess.what();
        } catch(const int mess) {
            std::cerr << "Error: " << mess << " <- incorrect number!" << std::endl;
        } catch(const size_t mess) {
            std::cerr << "Error: " << mess << " <- index out of range!" << std::endl;
        }
    }
    
    return 0;
}
