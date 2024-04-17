#pragma once //Developed by Ruban on 26.02.2024
#include "Point.h"

class Triangle {
public:
	class Segment;
	typedef Segment* Triangle::* SidePtr; 
	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1,
			const double y2 = 0, const double x3 = 0, const double y3 = 1); 
	Triangle(const Point& a, const Point& b, const Point& c); 
	Triangle(const Triangle&);
	~Triangle(); 
	
	Triangle& operator=(const Triangle&);

	const Point vertexA() const; 
	const Point vertexB() const;
	const Point vertexC() const;

	Point& vertexA();
	Point& vertexB();
	Point& vertexC();
	
	const Segment& side_a() const; 
	const Segment& side_b() const;
	const Segment& side_c() const;
	
	Segment& side_a(); 
	Segment& side_b();
	Segment& side_c();

	ostream& show(ostream& os) const; 

private:
	Point _a, _b, _c; 
	mutable Segment *_ab, *_bc, *_ca; 
};
ostream& operator<<(ostream&, const Triangle&); 
ostream& operator<<(ostream& os, const Triangle::Segment& segment);

class Triangle::Segment {
private:
	static unsigned int _freeID; 
	unsigned int _myId;
	const Point& _a;
	const Point& _b;
	Segment(const Segment&);
public:
	Segment(const Point& start, const Point& end);
	~Segment();
	const Point& start() const;
	const Point& end() const;
	const Point& start();
	const Point& end();
};