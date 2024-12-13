/**
 * Nick Galvez
 * 210 final project
 */
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <string>

using namespace std;

const int DATA_SIZE = 10, ROUNDS = 100, INITIAL_CUSTOMERS = 3;

string namesData[DATA_SIZE] = {"Phoebe", "Joey", "Monica", "Rachel", "Ross", "Chandler", "Gunther", "Janice", "Susan", "Paul Rudd"},
       drinkData[DATA_SIZE] = {"Espresso", "Latte", "Cappuccino", "Mocha", "Americano", "Macchiato", "Flat White", "Soy Latte", "Irish Coffee", "Turkish Coffee"},
       muffinData[DATA_SIZE] = {"Blueberry", "Chocolate Chip", "Banana Nut", "Lemon Poppyseed", "Pumpkin Spice", "Cranberry Orange", "Apple Cinnamon", "Carrot", "Coffee Cake", "Double Chocolate"},
       friendShipBraceletData[DATA_SIZE] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet", "Black", "White", "Brown"},
       goatData[DATA_SIZE] = {"Billy", "Nanny", "Kid", "Doe", "Buck", "Wether", "Doeling", "Buckling", "Nanny", "Sniffy"}; // I guess these are types of goats?

struct CoffeeCustomer
{
    string name;
    string order;
    CoffeeCustomer *next;
};
struct Customer
{
    string name;
    string order;
};

class Queue
{
private:
    CoffeeCustomer *head;

public:
    Queue()
    {
        head = NULL;
        // add 3 customers to the list
        for (int i = 0; i < INITIAL_CUSTOMERS; i++)
        {
            addToEnd();
        }
    }
    void addCustomer()
    {
        CoffeeCustomer *temp = new CoffeeCustomer();
        temp->name = namesData[rand() % DATA_SIZE];
        temp->order = drinkData[rand() % DATA_SIZE];

        if (temp->name == "Paul Rudd")
        {
            temp->order = "career after 'Friends'";
        }

        temp->next = head;
        head = temp;
        cout << temp->name << " has joined the coffee line. They usually want a " << temp->order << endl;
    }
    void addToEnd()
    {
        CoffeeCustomer *temp = new CoffeeCustomer();
        temp->name = namesData[rand() % DATA_SIZE];
        temp->order = drinkData[rand() % DATA_SIZE];
        cout << temp->name << " has joined the coffee line. They usually want a " << temp->order << endl;

        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        CoffeeCustomer *last = head;
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
            cout << head->name << " has been served." << endl;
            delete head;
            head = NULL;
            return;
        }
        CoffeeCustomer *temp = head;
        // We have to get the last item, which is the first item...
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        cout << temp->next->name << " has been served." << endl;
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
        CoffeeCustomer *temp = head;
        cout << head->name << " has been served a " << head->order << endl;
        head = head->next;
        delete temp;
    }

    void display()
    {
        cout << "Coffee Queue" << endl;
        CoffeeCustomer *temp = head;
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
class MuffinQueue
{
private:
    deque<Customer> customers;

public:
    MuffinQueue()
    {
        // add 3 customers to the list
        for (int i = 0; i < INITIAL_CUSTOMERS; i++)
        {
            addToEnd();
        }
    }
    void addToEnd()
    {
        Customer temp;
        temp.name = namesData[rand() % DATA_SIZE];
        temp.order = muffinData[rand() % DATA_SIZE];

        if (temp.name == "Joey")
        {
            temp.order = "ALL OF THEM";
        }

        customers.push_back(temp);
        cout << temp.name << " has joined the Muffin line. They usually want a " << temp.order << " muffin." << endl;
    }
    void serve()
    {
        if (customers.size() == 0)
        {
            cout << "No customers in line" << endl;
            return;
        }
        cout << customers[0].name << " has been served a " << customers[0].order << endl;
        customers.erase(customers.begin());
    }
    void display()
    {
        int count = 1;
        cout << "Muffin Queue" << endl;
        for (auto it = customers.begin(); it != customers.end(); it++)
        {
            cout << count << ": " << it->name << ": " << it->order << endl;
            count++;
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

// vector
class BraceletQueue
{
private:
    vector<Customer> customers;

public:
    BraceletQueue()
    {
        // add 3 customers to the list
        for (int i = 0; i < INITIAL_CUSTOMERS; i++)
        {
            addToEnd();
        }
    }
    void addToEnd()
    {
        Customer temp;
        temp.name = namesData[rand() % DATA_SIZE];
        temp.order = friendShipBraceletData[rand() % DATA_SIZE];
        customers.push_back(temp);
        cout << temp.name << " has joined the bracelet line. They are trying on a " << temp.order << " bracelet." << endl;
    }
    void serve()
    {
        if (customers.size() == 0)
        {
            cout << "No customers in line" << endl;
            return;
        }
        cout << customers[0].name << " has been sold a " << customers[0].order << " bracelet." << endl;
        customers.erase(customers.begin());
    }
    void display()
    {
        int count = 1;
        cout << "Bracelet Queue" << endl;
        for (auto it = customers.begin(); it != customers.end(); it++)
        {
            cout << count << ": " << it->name << ": " << it->order << endl;
            count++;
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

// list
class GoatQueue
{
private:
    list<Customer> customers;

public:
    GoatQueue()
    {
        // add 3 customers to the list
        for (int i = 0; i < INITIAL_CUSTOMERS; i++)
        {
            addToEnd();
        }
    }
    void addToEnd()
    {
        // add a customer to the end of the list
        Customer temp;
        temp.name = namesData[rand() % DATA_SIZE];
        temp.order = goatData[rand() % DATA_SIZE];
        customers.push_back(temp);
        cout << temp.name << " has joined the goat line. They have their eye on a " << temp.order << endl;
    }
    void serve()
    {
        if (customers.size() == 0)
        {
            cout << "No customers in line" << endl;
            return;
        }
        cout << customers.front().name << " left with a " << customers.front().order << endl;
        customers.pop_front();
    }
    void display()
    {
        int count = 1;
        cout << "Goat Queue" << endl;
        for (auto it = customers.begin(); it != customers.end(); it++)
        {
            cout << count << ": " << it->name << ": " << it->order << endl;
            count++;
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

int main()
{
    Queue coffeeShop = Queue();
    MuffinQueue muffinShop = MuffinQueue();
    BraceletQueue braceletShop = BraceletQueue();
    GoatQueue goatShop = GoatQueue();

    for (int i = 0; i < ROUNDS; i++)
    {
        cout << endl
             << "====== Round " << i + 1 << endl;
        coffeeShop.process();
        muffinShop.process();
        braceletShop.process();
        goatShop.process();
        cout << endl;
    }

    return 0;
}