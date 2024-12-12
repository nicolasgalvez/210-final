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
    void addCustomer() {
        Customer *temp = new Customer();
        temp->name = namesData[rand() % DATA_SIZE];
        temp->order = drinkData[rand() % DATA_SIZE];
        temp->next = head;
        head = temp;
        // cout << temp->order << temp->name;
    }
    void removeCustomer(){

    Customer *temp = head;
    head = head->next;
    delete temp;

    }
    void display(){
        Customer *temp = head;
        int cound = 1;
        while(temp != NULL){
            cout << cound << ": " << temp->name << ": " << temp->order << endl;
            temp = temp->next;
            cound++;
        }
    }
    void process () {
        
    }
};

int main()
{
    Queue coffeeShop = Queue();

    coffeeShop.addCustomer();
    coffeeShop.addCustomer();
    coffeeShop.addCustomer();
    
    coffeeShop.display();
    cout << endl;
    coffeeShop.removeCustomer();
    coffeeShop.display();
    // test(hash_table);
    return 0;
}