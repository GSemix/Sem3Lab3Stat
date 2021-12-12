#include "gtest/gtest.h"
#include <iostream>
#include "include/deck.h"
#include "include/lab_3.h"

TEST(Deck, sampleTestAddCard)
{
    Deck deck;
    Cards card = Cards(10, Spades);
    deck.addCard(0, card);
    
    
    EXPECT_EQ(deck.findCard(10, Spades), 0);
}

TEST(Deck, sampleTestSetNumOfCardInDeck)
{
    Deck deck;
    deck.setNumOfCardInDeck(0, 10);
    deck.setSuitOfCardInDeck(0, Spades);
    
    EXPECT_EQ(deck.findCard(10, Spades), 0);
}

TEST(Deck, sampleTestIsTwinCard)
{
    Deck deck = Deck(10, Spades);
    Cards card = Cards(10, Spades);
    
    EXPECT_EQ(deck.isTwinCard(card), 1);
}

TEST(Deck, sampleTestRandomCard)
{
    Deck deck;
    deck.initRandomCards(1, deck.getCountOfCardsInDeck(), true);
    Cards card = deck.randomCard();
    
    EXPECT_EQ(deck.isTwinCard(card), 0);
}

TEST(Deck, sampleTestDeleteCard)
{
    Deck deck;
    
    Cards card = Cards(10, Spades);
    deck.addCard(0, card);
    
    deck.deleteCard(0);
    
    EXPECT_EQ(deck.isTwinCard(card), 0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
