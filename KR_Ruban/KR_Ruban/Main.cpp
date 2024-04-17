#define _CRT_SECURE_NO_WARNINGS  // Developed by Ruban on 17.04.2024
#include <iostream>
#include "PowerOfTwo.h"
#include "Pyramide.h"
#include "Point.h"
#include "ShortString.h"
#include "IDoubleList.h"
#include "DoubleList.h"
#include "CyclicDoubleList.h"



int main() {
    cout << endl << "=============================" << endl << endl;
    cout << "Task 1" << endl << endl;
    PowerOfTwo<10>();

    cout << endl << "=============================" << endl << endl;

    cout << "Task 2-3: DoubleList + Iterator(Task5)" << endl << endl;

     DoubleList<int> doubleList;

    cout << "Inserting elements" << endl;
    doubleList.insert_back(1);
    doubleList.print();
    doubleList.insert_back(2);
    doubleList.print();
    doubleList.insert_front(3);
    doubleList.print();

    cout << endl << "Front element of the list: " << doubleList.front() << endl;
    cout << "Back elementof the list: " << doubleList.back() << endl;
    cout << "Size of the list: " << doubleList.size() << endl;
    cout << "Is the list empty? " << (doubleList.empty() ? "Yes" : "No") << endl;

    cout << endl << "Popping elements" << endl;
    doubleList.print();
    doubleList.pop_back();
    doubleList.print();
    doubleList.pop_front();
    doubleList.print();
    doubleList.pop_back();
    cout << "Size of the list: " << doubleList.size() << endl;
    cout << "Is the list empty? " << (doubleList.empty() ? "Yes" : "No") << endl;


    cout << endl << "Double List Iterator" << endl;
    DoubleList<int> doubleListIter;
    doubleListIter.insert_back(3);
    doubleListIter.insert_back(4);
    doubleListIter.insert_back(3);
    doubleListIter.insert_front(2);
    doubleListIter.insert_front(1);
    DoubleList<int>::Iterator itor = doubleListIter.attach();

    cout << "Iterator: ";
    operator<<<int>(cout, itor);
    itor.start();
    find(itor, 3);
    cout << "Iterator(after find 3): ";
    operator<<<int>(cout, itor);
    itor.start();
    find(itor, 2);
    cout << "Iterator(after find 2): ";
    operator<<<int>(cout, itor);


    cout << endl << "=============================" << endl << endl;


    cout << "Task 4: CyclicDoubleList + Iterator(Task5)" << endl << endl;

    CyclicDoubleList<double> cyclicDoubleList;

    cout << "Inserting elements" << endl;
    cyclicDoubleList.insert_back(1.1);
    cyclicDoubleList.print();
    cyclicDoubleList.insert_back(2.2);
    cyclicDoubleList.print();
    cyclicDoubleList.insert_front(3.3);
    cyclicDoubleList.print();

    cout << endl << "Front element of the list: " << cyclicDoubleList.front() << endl;
    cout << "Back elementof the list: " << cyclicDoubleList.back() << endl;
    cout << "Size of the list: " << cyclicDoubleList.size() << endl;
    cout << "Is the list empty? " << (cyclicDoubleList.empty() ? "Yes" : "No") << endl;

    cout << endl << "Popping elements" << endl;
    cyclicDoubleList.print();
    cyclicDoubleList.pop_back();
    cyclicDoubleList.print();
    cyclicDoubleList.pop_front();
    cyclicDoubleList.print();
    cout << "Size of the list: " << cyclicDoubleList.size() << endl;
    cout << "Is the list empty? " << (cyclicDoubleList.empty() ? "Yes" : "No") << endl;


    cout << endl << "Cyclic Double List Iterator" << endl;
    CyclicDoubleList<double> cyclicDoubleListIter;
    cyclicDoubleListIter.insert_back(3.3);
    cyclicDoubleListIter.insert_back(4.4);
    cyclicDoubleListIter.insert_back(3.3);
    cyclicDoubleListIter.insert_front(2.2);
    cyclicDoubleListIter.insert_front(1.1);
    CyclicDoubleList<double>::Iterator itor—yclic = cyclicDoubleListIter.attach();

    itor—yclic.start();
    cout << "Iterator: ";
    operator<<<double>(cout, itor—yclic);
    itor—yclic.start();
    find(itor—yclic, 3.3);
    cout << "Iterator(after find 3): ";
    operator<<<double>(cout, itor—yclic);

    cout << "Showing cyclicality of Cyclic Double List:" << endl;
    for (int i = 0; i < 2 * cyclicDoubleListIter.size(); ++i) {
        cout << *itor—yclic << " ";
        ++itor—yclic;
    }
    cout << endl;

    cout << endl << "=============================" << endl << endl;

    
    cout << "Task 6-7" << endl << endl;

    Point A(0, 0, 0);
    Point B(1, 0, 0);
    Point C(0, 1, 0);
    Point D(0, 0, 1);

    Pyramide pyramide1(0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2);
    cout << "Pyramide by coordinates of Points: " << pyramide1 << endl;

    Pyramide pyramide2(A, B, C, D);
    cout <<"Pyramide by Points: "  << pyramide2;
    pyramide2.createFaces(); //Creates faces and shows them

    Pyramide copyPyramide(pyramide2);
    cout << endl << "copy(pyramide2): " << copyPyramide << endl;
    copyPyramide = pyramide1;
    cout << "copy = pyramide1(operator=): " << copyPyramide << endl;

    cout << "Vertices modificators " << endl;
    pyramide2.vertexC().y() = 2;
    pyramide2.vertexB().x() = 2;
    pyramide2.vertexD().z() = 3;
    cout << "Pyramide2 after modificators: " << pyramide2;
    pyramide2.createFaces();
   


    cout << endl << "=============================" << endl << endl;

    cout << "Task 8-10" << endl << endl;
    try {
        ShortString<10> s1("Hello");
        ShortString<10> s2("World");

        cout << "s1<10>: " << s1 << endl;
        cout << "s2<10>: " << s2 << endl;

        ShortString<10> copy(s1); 
        cout << "copy(s1): " << copy << endl;
        copy = s2;
        cout << "copy = s2(operator=): " << copy << endl;
        
        ShortString<10> s3 = s1 + s2;
        cout << "s3<10> (s1 + s2): " << s3 << endl;

        s1 += s2;
        cout << "s1 += s2: " << s1 << endl << endl;

        s3 += s1; //This triggers BadShortString
    }
    catch (const ShortString<10>::BadShortString & ex) {
        ex.diagnose();
    }

    try {
        ShortString<5> s1("Hello");
        ShortString<5> s2("World");
        ShortString<5> s4 = s1 + s2; //This triggers BadShortString
    }
    catch (const ShortString<5>::BadShortString & ex) {
        ex.diagnose();
    }

    cout << endl << "============================="  << endl;
}