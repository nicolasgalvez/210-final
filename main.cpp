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
};

class Queue {
    private:
    Customer data;
    Queue* next = nullptr;
public:
    Queue(Customer data) {
        this->data = data;
    }
};

int main()
{
    
    // test(hash_table);
    return 0;
}