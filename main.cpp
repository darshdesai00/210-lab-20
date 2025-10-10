#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2 == 0) ? 3 : 4;  // random 3 or 4 legs

        // random prices between 100.00 and 999.99
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++) {
            double price = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
            prices[i] = price;
        }
    }

    // new parameter constructor (legs + price array)
    Chair(int l, double arr[]) {
        legs = l;
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i];
    }

    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));  // seed random numbers
    cout << fixed << setprecision(2);

    Chair *chairPtr = new Chair;  // uses random constructor
    chairPtr->print();

    // now using the new parameter constructor
    double priceArr[3] = {199.99, 299.99, 399.99};
    Chair *livingChair = new Chair(3, priceArr);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}
