#include <iostream>  // Developed by Ruban on 17.04.2024
using namespace std;

template<int N>
struct PowerOfTwo {
    static int poweOfTwo() {
        return 2 * PowerOfTwo<N - 1>::poweOfTwo();
    }

    PowerOfTwo() {
        PowerOfTwo<N - 1>(); 
        cout << "2^" << N << ": " << poweOfTwo() << endl;
    }
};

template<>
struct PowerOfTwo<0> {
    static int poweOfTwo() {
        return 1;
    }

    PowerOfTwo() {
        cout << "2^0: " << poweOfTwo() << endl;
    }
};

