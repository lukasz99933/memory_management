0. Kompilacja projektu:
    > chmod +x install_packages.sh
    > su (hasło: nokia)
    > ./install_packages.sh
    > exit
    > mkdir build
    > cd build
    > cmake ..
    > make

Rada: Używaj gita. Rób commit co każdy punkt/podpunkt.

1. Uruchom valgrind1 i użyj valgrinda, aby sprawdzić wycieki pamięci
    > ./valgrind1
    > valgrind ./valgrind1
   Popraw kod tak, aby nie było wycieku pamięci, skompiluj i ponownie sprawdź program valgrindem

2. Uruchom valgrind2 i analogicznie użyj valgrinda aby sprawdzić wycieki pamięci. Popraw program.

3. Uruchom valgrind3 i sprawdź czy są w nim wycieki pamięci.
a) napisz własną klasę wyjatków dziedziczącą po logic_error i użyj jej w kodzie zamiast logic_error
b) popraw wyciek pamięci w programie
c) zmień kod w pliku valgrind3.cpp tak, aby używał unique_ptr.
d) użyj make_unique tam, gdzie to możliwe.

4. Zajrzyj do pliku list.cpp, gdzie zaimplementowana jest prosta lista jednokierunkowa.
Metoda add(Node* node) dodaje nowy węzeł zawsze na końcu listy.
Aby dostać konkretny węzeł, metoda get(const int value) iteruje po liście od pierwszego jej elementu w kierunku ostatniego,
przechodząc przez wszystkie elementy aż do napotkania tego, który chcemy zwrócić.
a) uruchom program list i sprawdź jak zachowuje się lista gdy dodajemy na nią więcej elementów
b) rozwiąż problem wycieków pamięci (bez stosowania inteligentnych wskaźników)
c) co się stanie jeśli na listę dodamy 2 razy ten sam węzeł? rozwiąż problem
d) zastosuj inteligentne wskaźniki w miejsce natywnych wskaźników
e) Stwórz własne wyjątki EmptyListError i NotFoundError, oba dziedziczące po std::runtime_error. Dodaj rzucanie i łapanie ich w odpowiednich miejsach.


Praca domowa - dla osób, które chcą poćwiczyć, przyda się do kolokwium :)
5. Przekształć listę jednokierunkową z pliku list.cpp w listę dwukierunkową. Ma ona umożliwiać:
  - wstawianie elementów na początek listy: void addFirst(shared_ptr<Node> node);
  - szukanie elementów od końca listy: shared_ptr<Node> getBackward(const int value)

6. Czy da się zmienić metody listy tak, aby przyjmowały/zwracały unique_ptr zamiast shared_ptr?
   Co będzie konsekwencją takiej zmiany? Podpowiedź: co się stanie z elementem listy, gdy metoda get zwróci go jako unique_ptr?

7. Przekształć klasy List i Node w klasy szablonowe, aby można było przechowywać dane takiego typu jak parametr szablonu.
   Przykład dla typu string:

    List<string> lista;
    auto nodeNapis = make_shared<Node<string>>("napis");
    auto nodeHello = make_shared<Node<string>>("hello");

    lista.add(nodeNapis);
    lista.add(nodeHello);
    auto node = lista.get("text");
