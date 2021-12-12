    Структура колоды (class Deck):
Хранит в себе количество карт в size_t countOfCardsInDeck(от 1 до 53)
Массив элементов структуры Crads deck
    Структура карты(struct Cards):
Хранит в себе ранг карты int num(от 2 до 14 и 0 в случае, если масть Default) и масть карты в переменной типа suitCard suit
    Масти карты(enum suitCard):
Diamonds, // Буби       <0>
Hearts,   // Черви      <1>
Clubs,    // Крести     <2>
Spades,   // Пики       <3>
Default   // Без масти  <4>

##############
    
    Создание архива(lib/mainLib.a):
g++ -c lib/deck.cpp -std=c++11
g++ -c lib/lab_3.cpp -std=c++11
ar rc mainLib.a deck.o lab_3.o
mv mainLib.a lib
    
    Запуск основной программы:
g++ main.cpp lib/mainLib.a -o main -std=c++11 -Wall

    Запуск теста:
g++ test.cpp lib/mainLib.a -lgtest -lgtest_main -pthread -o test -std=c++11 -Wall
