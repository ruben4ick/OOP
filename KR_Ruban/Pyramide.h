#pragma once   // Developed by Ruban on 17.04.2024
#include "Triangle.h"
#include <iostream>

class Pyramide {
private:
    Point _a, _b, _c, _d;
    mutable Triangle* _abc, * _abd, * _acd, * _bcd;
public:
    Pyramide(const double x1 = 0, const double y1 = 0, const double z1 = 0, const double x2 = 1,
        const double y2 = 0, const double z2 = 0, const double x3 = 0, const double y3 = 1, const double z3 = 0,
        const double x4 = 0, const double y4 = 0, const double z4 = 1);
    Pyramide(const Point& a, const Point& b, const Point& c, const Point& d);
    Pyramide(const Pyramide&);
    ~Pyramide();
    Pyramide& operator=(const Pyramide&);

    const Point& vertexA() const;
    const Point& vertexB() const;
    const Point& vertexC() const;
    const Point& vertexD() const;

    Point& vertexA();
    Point& vertexB();
    Point& vertexC();
    Point& vertexD();

    //Creating faces
    const Triangle& face_ABC() const;
    const Triangle& face_ABD() const;
    const Triangle& face_ACD() const;
    const Triangle& face_BCD() const;

    Triangle& face_ABC();
    Triangle& face_ABD();
    Triangle& face_ACD();
    Triangle& face_BCD();

    ostream& show(ostream& os) const;
};
ostream& operator<<(ostream&, const Pyramide&);