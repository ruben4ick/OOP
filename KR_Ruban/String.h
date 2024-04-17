#include <iostream>  // Developed by Ruban on 17.04.2024
using namespace std;

class String {
private:
    char* _allocator;
public:
    String();
    String(const char*);
    ~String();

    String(const String&);
    String& operator=(const String&);

    String& operator+=(const String&);
    String operator+(const String&) const;

    const char* c_str() const;
    bool empty() const;

    friend ostream& operator<<(ostream&, const String&);
};

String::String() {
    _allocator = new char[1];
    _allocator[0] = '\0';
}

String::String(const char* ps) {
    if (ps == nullptr)
        ps = "";
    _allocator = new char[strlen(ps) + 1];
    strcpy(_allocator, ps);
}

String::~String() {
    delete[] _allocator;
}

String::String(const String& other) {
    _allocator = new char[strlen(other._allocator) + 1];
    strcpy(_allocator, other._allocator);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] _allocator;
        _allocator = new char[strlen(other._allocator) + 1];
        strcpy(_allocator, other._allocator);
    }
    return *this;
}

String& String::operator+=(const String& other) {
    char* temp = new char[strlen(_allocator) + strlen(other._allocator) + 1];
    strcpy(temp, _allocator);
    strcat(temp, other._allocator);
    delete[] _allocator;
    _allocator = temp;
    return *this;
}

String String::operator+(const String& other) const {
    String result(*this);
    result += other;
    return result;
}

const char* String::c_str() const {
    return _allocator;
}

bool String::empty() const {
    return _allocator[0] == '\0';
}

ostream& operator<<(ostream& os, const String& s) {
    os << s._allocator;
    return os;
}