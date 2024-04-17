#include "Triangle.h" //Developed by Ruban on 26.02.2024
using namespace std;

unsigned int Triangle::Segment::_freeID = 0;

Triangle::Segment::Segment(const Point& start, const Point& end) : _a(start), _b(end), _myId(_freeID++) {
#ifndef NDEBUG 
	cout << "SegmentID " << _myId << ": Segment created " << *this << endl;
#endif
}

Triangle::Segment::~Segment() {
#ifndef NDEBUG 
	cout << "SegmentID " << _myId << ": Segment removed " << *this << endl;
#endif
}

const Point& Triangle::Segment::start() const {
	return _a;
}

const Point& Triangle::Segment::end() const {
	return _b;
}

const Point& Triangle::Segment::start()
{
	return _a;
}

const Point& Triangle::Segment::end()
{
	return _b;
}


Triangle::Triangle(const double x1, const double y1, const double x2,
	const double y2, const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3), _ab(nullptr), _bc(nullptr), _ca(nullptr)
{
#ifndef NDEBUG 
	cout << "Triangle created by coordinates " << endl;
#endif
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
	_a(a), _b(b), _c(c), _ab(nullptr), _bc(nullptr), _ca(nullptr)
{
#ifndef NDEBUG 
	cout << "Triangle created by Points " << endl;
#endif
}

Triangle::Triangle(const Triangle& t) :
	_a(t._a), _b(t._b), _c(t._c),
	_ab(nullptr), _bc(nullptr), _ca(nullptr)
{
#ifndef NDEBUG 
	cout << "Triangle copied " <<endl;
#endif
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
#ifndef NDEBUG 
	cout << "Triangle deleted " <<  endl;
#endif
}

Triangle& Triangle::operator=(const Triangle& t) {
	_a = t._a; _b = t._b; _c = t._c;
	delete _ab;
	delete _bc;
	delete _ca;
	_ab = _bc = _ca = 0;
	return *this;
}

ostream& operator<<(ostream& os, const Triangle::Segment& segment) {
	os << segment.start() << " to "
		<< segment.end();
	return os;
}

const Point Triangle::vertexA() const {
	return _a;
}

const Point Triangle::vertexB() const {
	return _b;
}

const Point Triangle::vertexC() const {
	return _c;
}

Point& Triangle::vertexA() {
	return _a;
}

Point& Triangle::vertexB() {
	return _b;
}

Point& Triangle::vertexC() {
	return _c;
}

const Triangle::Segment& Triangle::side_a() const {
	if (_bc == 0)
		_bc = new Segment(_b, _c);
	return *_bc;
}

const Triangle::Segment& Triangle::side_b() const {
	if (_ca == 0)
		_ca = new Segment(_c, _a);
	return *_ca;
}

const Triangle::Segment& Triangle::side_c() const {
	if (_ab == 0)
		_ab = new Segment(_a, _b);
	return *_ab;
}


Triangle::Segment& Triangle::side_a() {
	if (_bc == 0)
		_bc = new Segment(_b, _c);
	return *_bc;
}

Triangle::Segment& Triangle::side_b() {
	if (_ca == 0)
		_ca = new Segment(_c, _a);
	return *_ca;
}

Triangle::Segment& Triangle::side_c() {
	if (_ab == 0)
		_ab = new Segment(_a, _b);
	return *_ab;
}


ostream& Triangle::show(ostream& os) const {
	os << "Triangle vertices: " << _a << ", " << _b << ", " << _c;
	return os;
}


ostream& operator<<(ostream& os, const Triangle& triangle) {
	return triangle.show(os);
}
