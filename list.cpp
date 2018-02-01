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
    Node* last;
};

List::List() :
    first(nullptr),
	last(nullptr)
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
	last = node;
        current->next = node;
    }
}

void List::addFirst(Node* node)
{
	if(!last)
	{
		last=node;
	}
	else
	{
		Node* current =last;
		while(current->previous)
		{
			current=current->previous;
		}
		current->previous = node;
	}
}

Node* List::getBackward(const int value)
{
	if(!first)
	{
		cout << "List is empty!" << endl;
		return nullptr;
	}
	else
    	{
        	Node* current = last;
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
                	current = current->previous;
            	}
        	} while(current);
        	cout << "Not found: value " << value << endl;
        	return nullptr;
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
    lista.add(new Node(3));
    lista.addFirst(new Node(1));
    lista.addFirst(new Node(2));
    auto node = lista.getBackward(2);

    return 0;
}

