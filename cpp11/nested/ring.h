#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring {
private:
int _i;
int _max;
T *_values;
public:
    ring(int size): _i{0}, _max{size}, _values {NULL} {
        _values = new T[size];
    }
    ~ring() {
        delete [] _values;
    }
    void add(T item) {
        _values[_i] = item;
        if (++_i == _max) {
            _i = 0;
        }
    }
    int size() {
        return _max;
    }
    // more efficient to return reference, but could lead to memory issues
    T &get(int j) {
        return _values[j];
    }

    class iterator;

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(_max, *this);
    }

};

template<class T>
class ring<T>::iterator {
    private:
        int _pos;
        ring &_ring;
    public:
        iterator(int pos, ring &r): _pos{pos}, _ring{r} {

        }

        // without param is prefix operator
        iterator &operator++() {
            _pos++;
            return *this;
        }

        T &operator*() {
            return _ring.get(_pos);
        }

        bool operator!=(const iterator &other) const {
            return _pos != other._pos;
        }
};

#endif