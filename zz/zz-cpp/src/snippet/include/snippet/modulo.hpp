#ifndef __SNIPPET_MODULO_H__
#define __SNIPPET_MODULO_H__

#include <iostream>

namespace snippet {
namespace modulo {

template <int64_t Modulus>
class ModuloInt {
    using u32 = uint32_t;
    using i64 = int64_t;

public:
    ModuloInt() : value(0) {}
    ModuloInt(const i64 &v) : value(v) {
        value = value >= 0 ? value : value + Modulus * ((-value) / Modulus + 1);
        value %= Modulus;
    }

    bool operator==(const ModuloInt &rhs) const { return this->value == rhs.value; }
    bool operator!=(const ModuloInt &rhs) const { return !(*this == rhs); }
    bool operator<(const ModuloInt &rhs) const { return this->value < rhs.value; }
    bool operator>(const ModuloInt &rhs) const { return *this != rhs && !(*this < rhs); }
    bool operator<=(const ModuloInt &rhs) const { return !(*this > rhs); }
    bool operator>=(const ModuloInt &rhs) const { return !(*this < rhs); }

    ModuloInt operator+(const ModuloInt &rhs) const { return ModuloInt(*this) += rhs; }
    ModuloInt operator-(const ModuloInt &rhs) const { return ModuloInt(*this) -= rhs; }
    ModuloInt operator*(const ModuloInt &rhs) const { return ModuloInt(*this) *= rhs; }

    ModuloInt &operator++() { return *this += 1; }
    ModuloInt operator++(int) {
        ModuloInt tmp = *this;
        ++(*this);
        return tmp;
    }
    ModuloInt &operator--() { return *this -= 1; }
    ModuloInt operator--(int) {
        ModuloInt tmp = *this;
        --(*this);
        return tmp;
    }

    ModuloInt &operator=(const ModuloInt &rhs) {
        this->value = rhs.value;
        return *this;
    }
    ModuloInt &operator+=(const ModuloInt &rhs) {
        this->value = (this->value + rhs.value) % Modulus;
        return *this;
    }
    ModuloInt &operator-=(const ModuloInt &rhs) {
        this->value = (this->value + Modulus - rhs.value) % Modulus;
        return *this;
    }
    ModuloInt &operator*=(const ModuloInt &rhs) {
        this->value = (this->value * rhs.value) % Modulus;
        return *this;
    }

    ModuloInt power(u32 n) const {
        if (n == 0) {
            return 1;
        }

        ModuloInt result = this->value;
        u32 currentExp = 1;

        while (currentExp * 2 <= n) {
            result *= result;
            currentExp *= 2;
        }

        return result * power(n - currentExp);
    }

    ModuloInt inverse() const { return this->power(Modulus - 2); }

    friend std::istream &operator>>(std::istream &is, ModuloInt &number) {
        i64 tmp;
        is >> tmp;
        number.value = tmp % Modulus;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModuloInt &number) {
        os << "ModuloNumber(" << number.value << " mod " << Modulus << ")";
        return os;
    }

private:
    i64 value;

    constexpr static bool modulusIsPrime() {
        for (i64 i = 2; i * i <= Modulus; i++) {
            if (Modulus % i == 0) {
                return false;
            }
        }
        return true;
    }

    static_assert(modulusIsPrime(), "Modulus must be a prime.");
};

}  // namespace modulo
}  // namespace snippet

#endif
