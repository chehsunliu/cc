#ifndef __SNIPPET_MODULO_H__
#define __SNIPPET_MODULO_H__

#include <iostream>

namespace snippet {
namespace modulo {

template <class T, int Modulus = 1000000007>
class ModuloNumber {
   public:
    ModuloNumber() : value(0) {}
    ModuloNumber(const T &value) {
        this->value = value >= 0 ? value : value + Modulus * ((-value) / Modulus + 1);
        this->value %= Modulus;
    }

    bool operator==(const ModuloNumber &rhs) const { return this->value == rhs.value; }
    bool operator!=(const ModuloNumber &rhs) const { return !(*this == rhs); }
    bool operator<(const ModuloNumber &rhs) const { return this->value < rhs.value; }
    bool operator>(const ModuloNumber &rhs) const { return *this != rhs && !(*this < rhs); }
    bool operator<=(const ModuloNumber &rhs) const { return !(*this > rhs); }
    bool operator>=(const ModuloNumber &rhs) const { return !(*this < rhs); }

    ModuloNumber operator+(const ModuloNumber &rhs) const { return ModuloNumber(*this) += rhs; }
    ModuloNumber operator-(const ModuloNumber &rhs) const { return ModuloNumber(*this) -= rhs; }
    ModuloNumber operator*(const ModuloNumber &rhs) const { return ModuloNumber(*this) *= rhs; }

    ModuloNumber &operator++() { return *this += 1; }
    ModuloNumber operator++(int) {
        ModuloNumber tmp = *this;
        ++(*this);
        return tmp;
    }
    ModuloNumber &operator--() { return *this -= 1; }
    ModuloNumber operator--(int) {
        ModuloNumber tmp = *this;
        --(*this);
        return tmp;
    }

    ModuloNumber &operator=(const ModuloNumber &rhs) {
        this->value = rhs.value;
        return *this;
    }
    ModuloNumber &operator+=(const ModuloNumber &rhs) {
        this->value = (this->value + rhs.value) % Modulus;
        return *this;
    }
    ModuloNumber &operator-=(const ModuloNumber &rhs) {
        this->value = (this->value + Modulus - rhs.value) % Modulus;
        return *this;
    }
    ModuloNumber &operator*=(const ModuloNumber &rhs) {
        this->value = (this->value * rhs.value) % Modulus;
        return *this;
    }

    friend std::istream &operator>>(std::istream &is, ModuloNumber &number) {
        T tmp;
        is >> tmp;
        number.value = tmp % Modulus;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModuloNumber &number) {
        os << "ModuloNumber(" << number.value << " mod " << Modulus << ")";
        return os;
    }

   private:
    T value;
};

}  // namespace modulo
}  // namespace snippet

#endif
