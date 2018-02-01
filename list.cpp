#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
	previous(nullptr),
        value(v)
    {}

    shared_ptr<Node> next;
    shared_ptr<Node> previous;
    int value;
};

class List
{
public:
    List();
    void add(shared_ptr<Node> node);        // dodaje element na koniec listy
    void addFirst(shared_ptr<Node> node);   // dodaje element na początek listy
    shared_ptr<Node> get(const int value);  // zwraca element o wskazanej wartości
    shared_ptr<Node> getBackward(const int value); //szuka element od konca listy

private:
    shared_ptr<Node> first;
    shared_ptr<Node> last;
};

List::List() :
    first(nullptr),
	last(nullptr)
{}

void List::add(shared_ptr<Node> node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        shared_ptr<Node> current = first;
        while(current->next)
        {
        	current = current->next;
        }
	last = node;
        current->next = node;
    }
}

void List::addFirst(shared_ptr<Node> node)
{
	if(!last)
	{
		last=node;
	}
	else
	{
		shared_ptr<Node> current =last;
		while(current->previous)
		{
			current=current->previous;
		}
		current->previous = node;
	}
}

shared_ptr<Node> List::getBackward(const int value)
{
	if(!first)
	{
		cout << "List is empty!" << endl;
		return nullptr;
	}
	else
    	{
        	shared_ptr<Node> current = last;
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

shared_ptr<Node> List::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        shared_ptr<Node> current = first;
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
    lista.add(make_shared<Node>(3));
    lista.addFirst(make_shared<Node>(2));
    auto node = lista.getBackward(2);

    return 0;
}

