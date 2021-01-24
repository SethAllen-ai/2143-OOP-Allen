#include <iostream>

using namespace std;

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    //Default constructor
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    //overloaded constructor
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    //adds an item to the que
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    //destructor
    int Pop() {
        int temp = Container[Front];
        // rolls front back to one when it hits end of the que
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    // access private class members
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};
// overloads the << operator to print the list each time the command cout<< c1 << endl;
ostream &operator<<(ostream &os, const CircularArrayQue &other) {
    //travels through the list and returns each number back to os
    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);
    
    //adds an item to the que
    C1.Push(1);
    //adds an item to the que
    C1.Push(2);
    //adds an item to the que
    C1.Push(3);
    
    // C1.Push(6);
    // C1.Push(7);
    //sends out all the numbers inputted into the array que
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
