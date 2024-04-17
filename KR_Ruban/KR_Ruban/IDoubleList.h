#pragma once   // Developed by Ruban on 17.04.2024
template<typename T>
class IDoubleList {
public:
    virtual void insert_front(const T& value) = 0;
    virtual void insert_back(const T& value) = 0;
    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual const T& front() const = 0;
    virtual const T& back() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual ~IDoubleList() {}
};


template <typename Iter, typename T>
bool find(Iter& it, const T& elem)
{
	while (!it.stop())
	{
		if (elem == *it)
			return true;
		++it;
	}
	return false;
}

template <typename T, class Itor>
ostream& operator<<(ostream& os, const Itor& itor)
{
	while (!itor.stop())
	{
		os << *itor << ' ';
		++itor;
	}
	return os << std::endl;
}



