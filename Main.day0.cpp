#include <iostream>
#include <assert.h>
class Vector {
    public:
        Vector (int size);
        double & operator[] (int index);
        int size ();
    private:
        double * _elements;
        int _size;
};
Vector::Vector (int size) :_elements { new double[size] }, _size { size } {}
double & Vector::operator[] (int index) {
    if (index > _size - 1 || index < 0) {
        throw std::out_of_range { "Vector::operator[]" };
    }
    return _elements[index];
}
int Vector::size () {
    return _size;
}
// enum class are strongly typed,
// they are NOT like enum's in C.
enum class TrafficLight { green, yellow, red };
TrafficLight & operator++ (TrafficLight & t) {
    switch (t) {
        case TrafficLight::green: return t=TrafficLight::yellow;
        case TrafficLight::red: return t=TrafficLight::green;
        case TrafficLight::yellow: return t=TrafficLight::red;
    }
}
int
main (int arcg, char ** argv) {
    for (auto i = 0; i < 10; ++i) {
        std::cout << "[" << i << "] ";
        std::cout << "Hello, world.";
        std::cout << std::endl;
    }
    std::cout << "[ ";
    for (auto value : { 42, 13, 45, 23 }) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;
    int v[] { 42, 13, 45, 23 };
    std::cout << "[ ";
    for (auto value : v) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "[ ";
    for (auto & reference : v) {
        // You can manipulate a reference
        // as you would do with the value
        // itself, i.e. no stars involed.
        std::cout << ++reference - 1 << " ";
    }
    std::cout << "]" << std::endl;
    int * ptr = nullptr;
    auto pptr = nullptr;
    Vector theVector(8);
    std::cout << "theVector.size() == " << theVector.size();
    std::cout << std::endl;
    TrafficLight t = TrafficLight::red;
    assert(++t == TrafficLight::green);
    try {
        std::cout << theVector[9] << std::endl;
    }
    catch (std::out_of_range) {
        // Do nothing, but catch the exception anyway ...
    }
    return 0;
}
