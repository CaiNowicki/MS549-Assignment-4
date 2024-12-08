#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    Queue q;
    cout << "Insert element '5' at the front\n";
    q.insert(5);

    cout << "Insert element '10' at the front\n";
    q.insert(10);

    cout << "Insert element '15' at the front\n";
    q.insert(15);

    cout << "Number of elements in the Queue: " << q.size() << endl;

    cout << "Removing an element from the front\n";
    q.remove();

    cout << "Number of elements in the Queue after removal: " << q.size() << endl;

    cout << "Clearing all elements in the Queue\n";
    q.erase();

    cout << "Is the Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
