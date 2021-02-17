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

    bool operator==(const ModuloNumber &rhs) const;
    bool operator!=(const ModuloNumber &rhs) const;
    bool operator<(const ModuloNumber &rhs) const;
    bool operator>(const ModuloNumber &rhs) const;
    bool operator<=(const ModuloNumber &rhs) const;
    bool operator>=(const ModuloNumber &rhs) const;

    ModuloNumber operator+(const ModuloNumber &rhs) const;
    ModuloNumber operator-(const ModuloNumber &rhs) const;
    ModuloNumber operator*(const ModuloNumber &rhs) const;

    ModuloNumber &operator++();
    ModuloNumber operator++(int);
    ModuloNumber &operator--();
    ModuloNumber operator--(int);

    ModuloNumber &operator=(const ModuloNumber &rhs);
    ModuloNumber &operator+=(const ModuloNumber &rhs);
    ModuloNumber &operator-=(const ModuloNumber &rhs);
    ModuloNumber &operator*=(const ModuloNumber &rhs);

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

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator==(const ModuloNumber &rhs) const {
    return this->value == rhs.value;
}

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator!=(const ModuloNumber &rhs) const {
    return !(*this == rhs);
}

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator<(const ModuloNumber &rhs) const {
    return this->value < rhs.value;
}

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator>(const ModuloNumber &rhs) const {
    return this->value > rhs.value;
}

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator<=(const ModuloNumber &rhs) const {
    return !(*this > rhs);
}

template <class T, int Modulus>
bool ModuloNumber<T, Modulus>::operator>=(const ModuloNumber &rhs) const {
    return !(*this < rhs);
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> ModuloNumber<T, Modulus>::operator+(const ModuloNumber &rhs) const {
    T tmp = this->value + rhs.value;
    return ModuloNumber(tmp);
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> ModuloNumber<T, Modulus>::operator-(const ModuloNumber &rhs) const {
    T tmp = (this->value < rhs.value ? this->value + Modulus : this->value) - rhs.value;
    return ModuloNumber(tmp);
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> ModuloNumber<T, Modulus>::operator*(const ModuloNumber &rhs) const {
    T tmp = this->value * rhs.value;
    return ModuloNumber(tmp);
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator++() {
    this->value++;
    this->value %= Modulus;
    return *this;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> ModuloNumber<T, Modulus>::operator++(int) {
    ModuloNumber tmp = *this;
    ++(*this);
    return tmp;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator--() {
    this->value = this->value == 0 ? Modulus - 1 : this->value - 1;
    return *this;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> ModuloNumber<T, Modulus>::operator--(int) {
    ModuloNumber tmp = *this;
    --(*this);
    return tmp;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator=(const ModuloNumber &rhs) {
    this->value = rhs.value;
    return *this;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator+=(const ModuloNumber &rhs) {
    this->value = (this->value + rhs.value) % Modulus;
    return *this;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator-=(const ModuloNumber &rhs) {
    this->value = (this->value + Modulus - rhs.value) % Modulus;
    return *this;
}

template <class T, int Modulus>
ModuloNumber<T, Modulus> &ModuloNumber<T, Modulus>::operator*=(const ModuloNumber &rhs) {
    this->value = (this->value * rhs.value) % Modulus;
    return *this;
}

}  // namespace modulo
}  // namespace snippet

#endif
