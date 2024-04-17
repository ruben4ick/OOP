#define _CRT_SECURE_NO_WARNINGS  // Developed by Ruban on 17.04.2024
#include <iostream>
using namespace std;

template <int n>
class ShortString {
private:
	char _allocator[n + 1];
public:
	class BadShortString; // Клас для обробки аварійних ситуацій
	ShortString(); // Конструктор порожнього рядка
	ShortString(const char); // Конструктор за одним символом
	ShortString(const char*); // Конструктор С++-рядка за С-рядком
	~ShortString(); // Деструктор
	ShortString(const ShortString<n>&);
	ShortString& operator=(const ShortString&);

	ShortString& operator+=(const ShortString&);
	ShortString operator+(const ShortString&) const;


	friend ostream& operator<<(ostream& os, const ShortString& s) {
		os << s._allocator;
		return os;
	}
};


template<int n>
ShortString<n>::ShortString()
{
	_allocator[0] = '\0';
	return;
}

template<int n>
ShortString<n>::ShortString(const char c)
{
	_allocator[0] = c;
	_allocator[1] = '\0'; 
}

template<int n>
ShortString<n>::ShortString(const char* ps)
{
	if (ps == 0)
		throw BadShortString("Attempt to use not defined pointer");
	if (strlen(ps) > n) {
		throw BadShortString("String exceeds maximum length");
	}
	strncpy(_allocator, ps, n); 
	_allocator[n] = '\0'; 
}

template<int n>
ShortString<n>::~ShortString()
{
}


template<int n>
ShortString<n>::ShortString(const ShortString<n>& s)
{
	strncpy(_allocator, s._allocator, n);
	_allocator[n] = '\0'; 
}

template <int n>
ShortString<n>& ShortString<n>::operator=(const ShortString& s) {
	if (this != &s) { 
		strncpy(_allocator, s._allocator, n);
		_allocator[n] = '\0';
	}
	return *this;
}

template<int n>
ShortString<n>& ShortString<n>::operator+=(const ShortString<n>& s)
{
	if (strlen(_allocator) + strlen(s._allocator) > n) {
		throw BadShortString("String exceeds maximum length");
	}
	strcat(_allocator, s._allocator);
	return *this;
}


template<int n>
ShortString<n> ShortString<n>::operator+(const ShortString<n>& s) const
{
	ShortString<n> result;
	if (strlen(_allocator) + strlen(s._allocator) > n) {
		throw BadShortString("String exceeds maximum length");
	}
	strcpy(result._allocator, _allocator);
	strcat(result._allocator, s._allocator);
	return result;
}


template<int n>
class ShortString<n>::BadShortString {
private:
	const string _reason; 
	const size_t _index; 
public:
	BadShortString(string reason = "", const size_t index = 0) :
		_reason(reason), _index(index) {
		return;
	}
	~BadShortString() {}

	
	void diagnose() const {
		cerr << _reason << endl;
		if (_index != 0)
			cerr << ' ' << _index << endl;
	}
};


