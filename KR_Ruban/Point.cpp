#include "Point.h" // Developed by Ruban on 26.02.2024

int Point::_freeID = 0;

Point::Point(double x, double y, double z) : _x(x), _y(y), _z(z), _pointID(++_freeID) {
#ifndef NDEBUG 
    cout << "PointID " << _pointID << ": Point created " << *this << endl;
#endif
    return;
}

Point::Point(const Point& u) : _x(u._x), _y(u._y), _z(u._z), _pointID(++_freeID) {
#ifndef NDEBUG 
    cout << "PointID " << _pointID << ": Point copied " << *this << endl;
#endif
    return;
}

Point::~Point() {
#ifndef NDEBUG 
    cout << "PointID " << _pointID << ": Point removed " << *this << endl;
#endif
    return;
}

Point& Point::operator=(const Point& u) {
    _x = u._x;
    _y = u._y;
    _z = u._z;
    return *this;
}

double& Point::x() { return _x; }

double& Point::y() { return _y; }

double& Point::z() { return _z; }

const double& Point::x() const { return _x; }

const double& Point::y() const { return _y; }

const double& Point::z() const { return _z; }

ostream& operator<<(ostream& os, const Point& point)
{
    os << "(" << point.x() << ", " << point.y() << ", " << point.z() << ")";
    return os;
}

