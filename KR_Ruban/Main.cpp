#define _CRT_SECURE_NO_WARNINGS  // Developed by Ruban on 17.04.2024
#include <iostream>
#include "PowerOfTwo.h"
#include "Pyramide.h"
#include "ShortString.h"
#include "DoubleList.h"
#include "CyclicDoubleList.h"



int main() {

    try {
        ShortString<10> s2("dddddddddd");
        ShortString<10> s3 = s2;
        cout << s3;
       
       
    }
    catch (const ShortString<10>::BadShortString & ex) {
        ex.diagnose();
    }
    catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    
}