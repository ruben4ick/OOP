#include "Pyramide.h"  // Developed by Ruban on 17.04.2024
#include <iostream>
using namespace std;


Pyramide::Pyramide(const double x1, const double y1, const double z1, const double x2,
    const double y2, const double z2, const double x3, const double y3, const double z3,
    const double x4, const double y4, const double z4) :
    _a(x1, y1, z1), _b(x2, y2, z2), _c(x3, y3, z3), _d(x4, y4, z4),
    _abc(nullptr), _abd(nullptr), _acd(nullptr), _bcd(nullptr) {
#ifndef NDEBUG 
    cout << "Pyramide created " << endl;
#endif
}

Pyramide::Pyramide(const Point& a, const Point& b, const Point& c, const Point& d) :
    _a(a), _b(b), _c(c), _d(d),
    _abc(nullptr), _abd(nullptr), _acd(nullptr), _bcd(nullptr) {
#ifndef NDEBUG 
    cout << "Pyramide created " << endl;
#endif
}

Pyramide::Pyramide(const Pyramide& t) :
    _a(t._a), _b(t._b), _c(t._c), _d(t._d),
    _abc(nullptr), _abd(nullptr), _acd(nullptr), _bcd(nullptr) {
#ifndef NDEBUG 
    cout << "Pyramide copied " << endl;
#endif
}

Pyramide::~Pyramide()
{
    delete _abc;
    delete _abd;
    delete _acd;
    delete _bcd;
#ifndef NDEBUG 
    cout << "Pyramide deleted " << endl;
#endif
}

Pyramide& Pyramide::operator=(const Pyramide& t) {
    _a = t._a;
    _b = t._b;
    _c = t._c;
    _d = t._d;
    delete _abc;
    delete _abd;
    delete _acd;
    delete _bcd;
    _abc = _abd = _acd = _bcd = 0;
    return *this;
}

const Point& Pyramide::vertexA() const { return _a; }

const Point& Pyramide::vertexB() const { return _b; }

const Point& Pyramide::vertexC() const { return _c; }

const Point& Pyramide::vertexD() const { return _d; }

Point& Pyramide::vertexA() {
    updateFaces();
    return _a; 
}

Point& Pyramide::vertexB() {
    updateFaces();
    return _b; 
}

Point& Pyramide::vertexC() { 
    updateFaces();
    return _c; 
}

Point& Pyramide::vertexD() {
    updateFaces();
    return _d; 
}

const Triangle& Pyramide::face_ABC() const {
    if (_abc == 0)
        _abc = new Triangle(_a, _b, _c);
    return *_abc;
}

const Triangle& Pyramide::face_ABD() const {
    if (_abd == 0)
        _abd = new Triangle(_a, _b, _d);
    return *_abd;
}

const Triangle& Pyramide::face_ACD() const {
    if (_acd == 0)
        _acd = new Triangle(_a, _c, _d);
    return *_acd;
}

const Triangle& Pyramide::face_BCD() const {
    if (_bcd == 0)
        _bcd = new Triangle(_b, _c, _d);
    return *_bcd;
}

Triangle& Pyramide::face_ABC() {
    if (_abc == 0)
        _abc = new Triangle(_a, _b, _c);
    return *_abc;
}

Triangle& Pyramide::face_ABD() {
    if (_abd == 0)
        _abd = new Triangle(_a, _b, _d);
    return *_abd;
}

Triangle& Pyramide::face_ACD() {
    if (_acd == 0)
        _acd = new Triangle(_a, _c, _d);
    return *_acd;
}

Triangle& Pyramide::face_BCD() {
    if (_bcd == 0)
        _bcd = new Triangle(_b, _c, _d);
    return *_bcd;
}

void Pyramide::updateFaces() {
    delete _abc;
    delete _abd;
    delete _acd;
    delete _bcd;
    _abc = _abd = _acd = _bcd = nullptr;
}

ostream& Pyramide::show(ostream& os) const {
    os << "Pyramide vertices: A" << vertexA() << ", B" << vertexB() << ", C" << vertexC() << ", D" << vertexD() << endl;
    return os;
}

void Pyramide::createFaces()
{
    cout << "Faces: " << face_ABC() << ", " << endl << face_ABD() << ", " << endl << face_ACD() << ", " << endl << face_BCD() << endl;
}

ostream& operator<<(ostream& os, const Pyramide& pyramide) {
    return pyramide.show(os);
}