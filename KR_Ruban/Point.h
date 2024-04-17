#pragma once  //Developed by Ruban on 26.02.2024
#include <iostream>
using namespace std;

class Point
{
private:
    static int _freeID;
    const int _pointID;
    double _x;
    double _y;
    double _z; 

public:
    Point(double x = 0, double y = 0, double z = 0); 
    Point(const Point&);
    ~Point();
    Point& operator=(const Point&);
    double& x();
    double& y();
    double& z(); 
    const double& x() const;
    const double& y() const;
    const double& z() const; 
};

ostream& operator<<(ostream&, const Point&);

