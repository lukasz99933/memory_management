#include <iostream>
#include <memory>

using namespace std;

template<typename typ>
class Node
{
public:
    Node(const typ v) :
        next(nullptr),
	previous(nullptr),
        value(v)
    {}

    shared_ptr<Node> next;
    shared_ptr<Node> previous;
    typ value;
};

template<typename typ>
class List
{
public:
    List();
    void add(typ node);        // dodaje element na koniec listy
    void addFirst(typ node);   // dodaje element na początek listy
    typ get(const int value);  // zwraca element o wskazanej wartości
    typ getBackward(const int value); //szuka element od konca listy

private:
    typ first;
    typ last;
};

template<typename typ>
List<typ>::List() :
    first(nullptr),
	last(nullptr)
{}

template<typename typ>
void List<typ>::add(typ node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        typ current = first;
        while(current->next)
        {
        	current = current->next;
        }
	last = node;
        current->next = node;
    }
}

template<typename typ>
void List<typ>::addFirst(typ node)
{
	if(!last)
	{
		last=node;
	}
	else
	{
		typ current =last;
		while(current->previous)
		{
			current=current->previous;
		}
		current->previous = node;
	}
}

template<typename typ>
typ List<typ>::getBackward(const int value)
{
	if(!first)
	{
		cout << "List is empty!" << endl;
		return nullptr;
	}
	else
    	{
        	typ current = last;
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

template<typename typ>
typ List<typ>::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        typ current = first;
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
    List< shared_ptr<Node<int>> > lista;
    lista.add(make_shared<Node<int>>(3));
    lista.addFirst(make_shared<Node<int>>(2));
    auto node = lista.getBackward(2);

    return 0;
}

