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

using namespace std;

const int DATA_SIZE = 10, ROUNDS = 10;

string namesData[DATA_SIZE] = {
    "Phoebe", "Joey", "Monica", "Rachel", "Ross", "Chandler", "Gunther", "Janice", "Paul Rudd", "Susan"
}, drinkData[DATA_SIZE] = { "Espresso", "Latte", "Cappuccino", "Mocha", "Americano", "Macchiato", "Flat White", "Soy Latte", "Irish Coffee", "Turkish Coffee"
};

struct Customer
{
    string name;
    string order;
    Customer *next;
};

class Queue {
    private:
    Customer *head;
public:
    Queue() {
        Customer *data = new Customer();

        data->name = namesData[rand() % DATA_SIZE];
        data->order = drinkData[rand() % DATA_SIZE];
        data->next = head;
        // cout << data.order << data.name;
    }
    Queue(Customer data) {
        this->data = data;
    }
    void addCustomer() {
        Customer *newCustomer = new Customer(data);
        newCustomer->next = NULL;
        Customer *temp = newCustomer;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCustomer;
    }
};

int main()
{
    Queue coffeeShop = Queue();
    // test(hash_table);
    return 0;
}