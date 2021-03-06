1.Разработать класс "игральные карты" в соответствии со следующим заданием:
Состояние класса -
Колода игральных карт описывается состояниями (масть и ранг) определенного числа карт (например, от 1 до 52). Для описания карты целесообразно использовать структуру. Память под массив выделяется статически, во время компиляции, и задается массивом фиксированного размера. В группе карт не может быть одинаковых карт.
Протокол класса -
Определяет  возможности создания и инициализации экземпляров класса и правила их использования (методы класса).
Предусмотреть следующие возможности:
·          пустой конструктор для инициализации экземпляров и массивов экземпляров класса по умолчанию;
·          создание экземпляров класса с инициализацией количеством карт, значения которых определяются с помощью генератора случайных чисел;
·          создание экземпляров класса с инициализацией начальным состоянием одной карты;
·          ввод экземпляров класса из входного потока и вывод в выходной поток;
·          добавить карту к группе, значение которой получается с помощью генератора случайных чисел;
·          получить масть карты по её номеру в группе;
·          получить ранг карты по её номеру в группе;
·          упорядочить карты по масти и убыванию ранга;
·          выделить из группы карт подгруппу карт заданной масти.
2. Проектирование класса рекомендуется начать с представления состояния класса, учитывающего заданные операции, а затем реализации конструкторов и метода вывода. Для отладки и исчерпывающего тестирования других методов разработанного класса реализовать диалоговую программу, которая позволяет вводить параметры отлаживаемых методов. Для обработки ошибочных ситуаций использовать механизм исключительных ситуаций.
3. Повторить разработку класса, реализовав отдельные методы (там, где это оправданно), перегруженными операторами. Состав перегруженных операторов целесообразно согласовать с преподавателем.
4. Еще раз повторить разработку класса при условии, что память под массив необходимой длины выделяется динамически, во время выполнения программы (с помощью оператора new; память задается указателем на char в состоянии класса). Для хранения данных в экземпляре класса не должна использоваться лишняя память.
Дополнить интерфейс класса следующими возможностями:
·          создание экземпляра класса с его инициализацией другим экземпляром класса (копирующий конструктор);
·          переопределение экземпляра класса (с помощью перегруженного оператора присваивания).    
    
###################################################################################################################################################################
    
    Структура колоды (class Deck):
Хранит в себе количество карт в size_t countOfCardsInDeck(от 1 до 53)
Указатель на элемент структуры Crads * deck
    Структура карты(struct Cards):
Хранит в себе ранг карты int num(от 2 до 14 и 0 в случае, если масть Default) и масть карты в переменной типа suitCard suit
    Масти карты(enum suitCard):
Diamonds, // Буби       <0>
Hearts,   // Черви      <1>
Clubs,    // Крести     <2>
Spades,   // Пики       <3>
Default   // Без масти  <4>

###################################################################################################################################################################
    
    Создание архива(lib/mainLib.a):
g++ -c lib/deck.cpp -std=c++11
g++ -c lib/lab_3.cpp -std=c++11
ar rc mainLib.a deck.o lab_3.o
mv mainLib.a lib
    
    Запуск основной программы:
g++ main.cpp lib/mainLib.a -o main -std=c++11 -Wall

    Запуск теста:
g++ test.cpp lib/mainLib.a -lgtest -lgtest_main -pthread -o test -std=c++11 -Wall
