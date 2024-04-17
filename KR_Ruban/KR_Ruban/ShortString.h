#define _CRT_SECURE_NO_WARNINGS  // Developed by Ruban on 17.04.2024
#include <iostream>
#include "String.h"
using namespace std;

template <int n>
class ShortString {
private:
	char _allocator[n + 1];
public:
	class BadShortString; 
	ShortString(); 
	ShortString(const char);
	ShortString(const char*); 
	~ShortString(); 
	ShortString(const ShortString<n>&);
	ShortString& operator=(const ShortString&);

	ShortString& operator+=(const ShortString&);
	ShortString operator+(const ShortString&) const;
	operator String() const;

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
	if (ps == nullptr)
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
		throw BadShortString("String exceeds maximum length", *this, s);
	}
	strcat(_allocator, s._allocator);
	return *this;
}


template<int n>
ShortString<n> ShortString<n>::operator+(const ShortString<n>& s) const
{
	ShortString<n> result;
	if (strlen(_allocator) + strlen(s._allocator) > n) {
		throw BadShortString("String exceeds maximum length" , *this, s);
	}
	strcpy(result._allocator, _allocator);
	strcat(result._allocator, s._allocator);
	return result;
}

template<int n>
ShortString<n>::operator String() const
{
	return String(_allocator);
}

template<int n>
class ShortString<n>::BadShortString {
private:
	String _result;
	const string _reason; 
public:
	BadShortString(const string reason) : _reason(reason) {}
	BadShortString(const char* reason, const ShortString<n>& str1, const ShortString<n>& str2) : _reason(reason) {
		String first = String(str1);
		String second = String(str2);
		_result = first + second;
	}
	~BadShortString() {}

	
	void diagnose() const {
		cerr << _reason << endl;
		if (!_result.empty()) {
			cout << "Result of interrupted operation: " << _result << endl;
		}
	}
};


