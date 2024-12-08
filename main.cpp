#include <iostream>
#include <fstream>
#include <chrono>
#include "functions.h"

using namespace std;
using namespace chrono;

int main() {
    Queue q;

    cout << "Insert element '5' at the front\n";
    q.insert(5);

    cout << "Insert element '10' at the front\n";
    q.insert(10);

    cout << "Insert element '15' at the front\n";
    q.insert(15);

    cout << "Queue after inserting elements:\n";
    q.printAll();

    cout << "Removing an element from the front\n";
    q.remove();

    cout << "Queue after removal:\n";
    q.printAll();

    cout << "Clearing all elements in the Queue\n";
    q.erase();

    cout << "Queue after clearing:\n";
    q.printAll();

    //insertion time test
    measureInsertionTime();
    //deletion time test
    measureDeleteTime();

    return 0;
}
