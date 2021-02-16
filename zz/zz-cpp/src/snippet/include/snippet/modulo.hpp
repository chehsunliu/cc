#ifndef __SNIPPET_MODULO_H__
#define __SNIPPET_MODULO_H__

#include <iostream>

namespace snippet {
namespace modulo {

template <class T, int Modulus = 1000000007> class ModuloNumber {
  public:
    ModuloNumber() : value(0) {}
    ModuloNumber(const T &value) : value(value % Modulus) {}

    ModuloNumber &operator=(const ModuloNumber &rhs) {
        this->value = rhs.value;
        return *this;
    }

    bool operator==(const ModuloNumber &rhs) const { return this->value == rhs.value; }
    bool operator!=(const ModuloNumber &rhs) const { return !(*this == rhs); }

    ModuloNumber operator+(const ModuloNumber &rhs) const {
        T tmp = this->value + rhs.value;
        return ModuloNumber(tmp);
    }
    ModuloNumber operator-(const ModuloNumber &rhs) const {
        T tmp = (this->value < rhs.value ? this->value + Modulus: this->value) - rhs.value;
        return ModuloNumber(tmp);
    }
    ModuloNumber operator*(const ModuloNumber &rhs) const {
        T tmp = this->value * rhs.value;
        return ModuloNumber(tmp);
    }

    friend std::ostream &operator<<(std::ostream &os, const ModuloNumber &number) {
        os << "<ModuloNumber " << number.value << " % " << Modulus << ">";
        return os;
    }

  private:
    T value;
};

} // namespace modulo
} // namespace snippet

#endif
