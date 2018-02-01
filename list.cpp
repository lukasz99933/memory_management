#include <iostream>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
	previous(nullptr),
        value(v)
    {}

    Node* next;
    Node* previous;
    int value;
};

class List
{
public:
    List();
    void add(Node* node);        // dodaje element na koniec listy
    void addFirst(Node* node);   // dodaje element na początek listy
    Node* get(const int value);  // zwraca element o wskazanej wartości
    Node* getBackward(const int value); //szuka element od konca listy

private:
    Node* first;
};

List::List() :
    first(nullptr)
{}

void List::add(Node* node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        Node* current = first;
        while(current->next)
        {
            current = current->next;
        }
        current->next = node;
    }
}

void List::addFirst(Node* node)
{
	if(!first)
	{
		first=node;
	}
	else
	{


}
}

Node* List::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        Node* current = first;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main()
{
    List lista;
    Node* node4 = new Node(4);
    Node* node7 = new Node(7);

    lista.add(node4);
    lista.add(new Node(2));
    lista.add(node7);
    lista.add(new Node(9));
    auto node = lista.get(1);

    return 0;
}

