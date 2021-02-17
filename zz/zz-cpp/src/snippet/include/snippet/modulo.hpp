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
        T tmp = (this->value < rhs.value ? this->value + Modulus : this->value) - rhs.value;
        return ModuloNumber(tmp);
    }

    ModuloNumber operator*(const ModuloNumber &rhs) const {
        T tmp = this->value * rhs.value;
        return ModuloNumber(tmp);
    }

    ModuloNumber &operator++() {
        this->value++;
        this->value %= Modulus;
        return *this;
    }

    ModuloNumber operator++(int) {
        ModuloNumber tmp = *this;
        this->value++;
        this->value %= Modulus;
        return tmp;
    }

    friend std::istream &operator>>(std::istream &is, ModuloNumber &number) {
        T tmp;
        is >> tmp;
        number.value = tmp % Modulus;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModuloNumber &number) {
        os << "<" << number.value << " (mod " << Modulus << ")>";
        return os;
    }

  private:
    T value;
};

} // namespace modulo
} // namespace snippet

#endif
