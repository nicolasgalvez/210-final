/**
 * Nick Galvez
 * 210 final
 * Using a struct, code a coffee booth queue simulation that uses a linked list as its core data structure.
 * The linked list's struct should be a node that contains the customer's name and drink order.
 * Create data arrays with names and drink orders from which to randomly create customer data.
 */
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <deque>
#include <vector>

using namespace std;

const int DATA_SIZE = 10, ROUNDS = 10;

string namesData[DATA_SIZE] = {"Phoebe", "Joey", "Monica", "Rachel", "Ross", "Chandler", "Gunther", "Janice", "Paul Rudd", "Susan"},
       drinkData[DATA_SIZE] = {"Espresso", "Latte", "Cappuccino", "Mocha", "Americano", "Macchiato", "Flat White", "Soy Latte", "Irish Coffee", "Turkish Coffee"},
       muffinData[DATA_SIZE] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Lemon Poppyseed", "Pumpkin Spice", "Cranberry Orange", "Apple Cinnamon", "Carrot", "Coffee Cake", "Double Chocolate"},
       friendShipBraceletData[DATA_SIZE] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet", "Black", "White", "Brown"},
       goatData[DATA_SIZE] = {"Billy", "Nanny", "Kid", "Doe", "Buck", "Wether", "Doeling", "Buckling", "Nanny", "Sniffy"};

struct Customer
{
    string name;
    string order;
    Customer *next;
};

class Queue
{
private:
    Customer *head;

public:
    void addCustomer()
    {
        Customer *temp = new Customer();
        temp->name = namesData[rand() % DATA_SIZE];
        temp->order = drinkData[rand() % DATA_SIZE];
        temp->next = head;
        head = temp;
        cout << temp->name << " has joined. They usually want a " << temp->order << endl;
    }
    void addToEnd()
    {
        Customer *temp = new Customer();
        temp->name = namesData[rand() % DATA_SIZE];
        temp->order = drinkData[rand() % DATA_SIZE];
        cout << temp->name << " has joined. They usually want a " << temp->order << endl;

        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Customer *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
    void removeCustomer()
    {
        if (head == NULL)
        {
            cout << "No customers in line" << endl;
            return;
        }
        if (!head->next)
        {
            cout << head->name << " gghas been served." << endl;
            delete head;
            head = NULL;
            return;
        }
        Customer *temp = head;
        // We have to get the last item, which is the first item...
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        cout << temp->next->name << " has ffbeen served." << endl;
        delete temp->next;
        temp->next = NULL;
    }
    void serve()
    {
        if (head == NULL)
        {
            cout << "No customers in line" << endl;
            return;
        }
        Customer *temp = head;
        cout << head->name << " has been served." << endl;
        head = head->next;
        delete temp;
    }

    void display()
    {
        Customer *temp = head;
        int cound = 1;
        while (temp != NULL)
        {
            cout << cound << ": " << temp->name << ": " << temp->order << endl;
            temp = temp->next;
            cound++;
        }
    }
    void process()
    {
        // remove a customer
        serve();
        // if 50% chance, add a customer
        if (rand() % 2 == 0)
        {
            addToEnd();
        }
        display();
    }
};

// deqeue
class MuffinQueue {
    private:
    deque<Customer> customers;
    void addToEnd() {

    }
    void serve() {

    }
    void display()
    {
    }
    void process()
    {
        // remove a customer
        serve();
        // if 50% chance, add a customer
        if (rand() % 2 == 0)
        {
            addToEnd();
        }
        display();
    }
};

// vector
class BraceletQueue {
    private:
    vector<Customer> customers;
    void addToEnd() {

    }
    void serve() {
        
    }
    void display()
    {
    }
    void process()
    {
        // remove a customer
        serve();
        // if 50% chance, add a customer
        if (rand() % 2 == 0)
        {
            addToEnd();
        }
        display();
    }
};

// vector
class BraceletQueue {
    private:
    vector<Customer> customers;
    void addToEnd() {

    }
    void serve() {
        
    }
    void display()
    {
    }
    void process()
    {
        // remove a customer
        serve();
        // if 50% chance, add a customer
        if (rand() % 2 == 0)
        {
            addToEnd();
        }
        display();
    }
};


int main()
{
    Queue coffeeShop = Queue();

    coffeeShop.addToEnd();
    coffeeShop.addToEnd();
    coffeeShop.addToEnd();

    coffeeShop.display();
    cout << endl;

    for (int i = 0; i < ROUNDS; i++)
    {
        cout << "Round " << i + 1 << endl;
        coffeeShop.process();
        cout << endl;
    }

    return 0;
}