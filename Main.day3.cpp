#include <iostream>
#include <assert.h>

namespace NS {
    template<typename T>
    class Vector {
        private:
            T * _elements = nullptr;
            int _size = 0;
        public:
            Vector (int size);
            Vector (std::initializer_list<T> l);
            ~Vector ();
            T & operator[] (int index) const;
            int size () const;
            T * begin () const;
            T * end () const;
            bool operator== (Vector<T> & w);
            void pushback (T value);
    };
}

template<typename T>
NS::Vector<T>::Vector (int size) :_elements { new T[size] }, _size { size } {
    for (auto i = 0; i < _size; ++i) {
        _elements[i] = 0;
    }
}

template<typename T>
NS::Vector<T>::Vector (std::initializer_list<T> l) :_elements { new T[l.size()]}, _size { (int)(l.size()) } {
    std::copy(l.begin(), l.end(), _elements);
}

template<typename T>
NS::Vector<T>::~Vector () {
    delete []_elements;
    _size = 0;
}

template<typename T>
int NS::Vector<T>::size () const {
    return _size;
}

template<typename T>
T & NS::Vector<T>::operator[] (int index) const {
    return _elements[index];
}

template<typename T>
T * NS::Vector<T>::begin () const {
    return _elements;
}

template<typename T>
T * NS::Vector<T>::end () const {
    return _elements + _size;
}

template<typename T>
bool NS::Vector<T>::operator== (NS::Vector<T> & w) {
    bool equal = _size == w.size() ? true : false;
    for (auto i = 0; equal && i < _size; ++i) {
        if (_elements[i] != w[i]) {
            equal = false;
        }
    }
    return equal;
}

template<typename T>
void NS::Vector<T>::pushback (T pushee) {
    T * __elements = new T[_size + 1];
    if (_size > 0) { std::copy(_elements, _elements + _size, __elements); }
    delete []_elements;
    _elements = __elements;
    _size = _size + 1;
    __elements[_size - 1] = pushee;
}

template<typename T>
std::ostream & operator<< (std::ostream & os, NS::Vector<T> & v) {
    os << "[ ";
    for (auto & element : v) {
        os << element << " ";
    }
    return os << "]";
}

template<typename C, typename V>
V sum (C & c, V start) {
    V res = start;
    for (auto & element : c) {
        res = res + element;
    }
    return res;
}

int
main (int argc, char ** argv) {
    NS::Vector<int> v({ 42, 13, 85, 21 });
    NS::Vector<int> w(0);
    w.pushback(42);
    w.pushback(13);
    w.pushback(85);
    w.pushback(21);
    assert(v == w);
    assert(sum(v, 0) == (42+13+85+21));
    return 0;
}
