#include <algorithm>
#include <iostream>
#include <vector>

//#include "codebook/codebook.hpp"

#ifndef __CODEBOOK_MODULO_H__
#define __CODEBOOK_MODULO_H__

namespace codebook {
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
    ModuloInt operator/(const ModuloInt &rhs) const { return ModuloInt(*this) /= rhs; }

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
    ModuloInt &operator/=(const ModuloInt &rhs) {
        ModuloInt tmp = (*this) * rhs.inverse();
        this->value = tmp.value;
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
        os << number.value;
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
}  // namespace codebook

#endif

typedef codebook::modulo::ModuloInt<998244353> mint;

#define BUFFER_SIZE 200001
mint factorial[BUFFER_SIZE];

void computeFactorial() {
    factorial[0] = 1;
    factorial[1] = 1;

    for (int i = 2; i < BUFFER_SIZE; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

mint combination(int n, int x) {
    return factorial[n] / (factorial[n - x] * factorial[x]);
}

std::vector<mint> setup(int array[], const int &n) {
    std::vector<int> n0(32, 0);
    std::vector<int> n1(32, 0);

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if (array[j] % 2 == 1) {
                n1[i]++;
            } else {
                n0[i]++;
            }

            array[j] /= 2;
        }
    }

    std::vector<mint> ms(n, 0);
    for (int m = 1; m <= n; m++) {
        mint s = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 1; j <= n1[i]; j += 2) {
                if (j > m || m - j > n0[i]) {
                    continue;
                }

                s += combination(n1[i], j) * combination(n0[i], m - j) * mint(2).power(i);
            }
        }
        ms[m - 1] = s;
    }

    for (int i = 1; i < ms.size(); i++) {
        ms[i] += ms[i - 1];
    }

    return ms;
}

// 10^10 = (10^3)^3*10 = 2^30 * 10
// 10^18 = (10^3)^6 = 2^60
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    int array[BUFFER_SIZE];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    computeFactorial();
    auto ms = setup(array, n);

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int m;
        std::cin >> m;
        std::cout << ms[m - 1] << "\n";
    }

    return 0;
}