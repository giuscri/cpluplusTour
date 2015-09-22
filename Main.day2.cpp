#include <iostream>
#include <assert.h>
namespace NS {
    class Vector {
        private:
            int * _elements = nullptr;
            int _size = 0;
        public:
            Vector (int size) :_elements { new int[size] }, _size { size } {
                for (auto i = 0; i < _size; ++i) {
                    _elements[i] = 0;
                }
            }
            Vector (std::initializer_list<int> l) :_elements { new int[l.size()]}, _size { (int)(l.size()) } {
                std::copy(l.begin(), l.end(), _elements);
            }
            Vector (Vector & w) :_elements { new int[w.size()] }, _size { w.size() } {
                for (auto i = 0; i < _size; ++i) {
                    _elements[i] = w[i];
                }
            }
            Vector & operator= (Vector & w) {
                int * __elements = new int[w.size()];
                _size = w.size();
                for (auto i = 0; i < _size; ++i) {
                    __elements[i] = w[i];
                }
                delete []_elements;
                _elements = __elements;
                return *this;
            }
            ~Vector () {
                delete[] _elements;
            }
            void push_back (int value) {
                int * __elements = new int[_size + 1];
                for (auto i = 0; i < _size; ++i) {
                    __elements[i] = _elements[i];
                }
                __elements[_size] = value;
                delete[] _elements;
                _elements = __elements;
                _size = _size + 1;
            }
            int & operator[] (int index) const {
                return _elements[index];
            }
            bool operator== (const Vector & w) const {
                bool theyreequal = _size == w.size() ? true : false;
                for (auto i = 0; theyreequal && i < _size; ++i) {
                    if (_elements[i] != w[i]) {
                        theyreequal = false;
                    }
                }
                return theyreequal;
            }
            int size () const {
                return _size;
            }
    };
}

std::ostream & operator<< (std::ostream & os, NS::Vector & v) {
    for (auto i = 0; i < v.size(); ++i) {
        os << v[i] << " ";
    }
    return os;
}

int
main () {
    NS::Vector v(2);
    v.push_back(42);
    //NS::Vector w({ 0, 0, 42 });
    assert(v == NS::Vector({ 0, 0, 42 }));
    NS::Vector x = v;
    assert(x == v);
    NS::Vector y(x);
    assert(x == y);
    return 0;
}
