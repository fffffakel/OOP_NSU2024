#include <string>
#include <iostream>
#include <cstdint>
#include <cstring>
#include <algorithm>

class BitArray {
public:
    BitArray();
    ~BitArray();
    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray& b);
    void swap(BitArray& b);
    BitArray& operator=(const BitArray& b);
    void resize(int num_bits, bool value = false);
    void clear();
    void push_back(bool bit);
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);

    BitArray& operator<<=(int n);
    BitArray& operator>>=(int n);
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;
    BitArray& set(int n, bool val = true);
    BitArray& set();
    BitArray& reset(int n);
    BitArray& reset();
    bool any() const;
    bool none() const;
    BitArray operator~() const;
    int count() const;
    bool operator[](int i) const;
    int size() const;
    bool empty() const;
    std::string to_string() const;

private:
    bool* bits;
    int numBits;
};

BitArray::BitArray() : bits(nullptr), numBits(0) {}

BitArray::~BitArray() {
    if (bits != nullptr) {
        free(bits);
    }
}

BitArray::BitArray(int num_bits, unsigned long value) : numBits(num_bits) {
    bits = (bool*)calloc(numBits, sizeof(bool));
    for (int i = 0; i < numBits; i++) {
        bits[i] = (value >> i) & 1;
    }
}

BitArray::BitArray(const BitArray& b) : numBits(b.numBits) {
    bits = (bool*)calloc(numBits, sizeof(bool));
    for (int i = 0; i < numBits; i++) {
        bits[i] = b.bits[i];
    }
}

BitArray& BitArray::operator=(const BitArray& b) {
    if (this != &b) {
        if (bits != nullptr) {
            free(bits);
        }
        numBits = b.numBits;
        bits = (bool*)calloc(numBits, sizeof(bool));
        for (int i = 0; i < numBits; i++) {
            bits[i] = b.bits[i];
        }
    }
    return *this;
}

void BitArray::swap(BitArray& b) {
    std::swap(bits, b.bits);
    std::swap(numBits, b.numBits);
}

void BitArray::resize(int num_bits, bool value) {
    if (num_bits != numBits) {
        bool* newArray = (bool*)calloc(num_bits, sizeof(bool));
        for (int i = 0; i < std::min(numBits, num_bits); i++) {
            newArray[i] = bits[i];
        }
        for (int i = numBits; i < num_bits; i++) {
            newArray[i] = value;
        }
        if (bits != nullptr) {
            free(bits);
        }
        bits = newArray;
        numBits = num_bits;
    }
}

void BitArray::clear() {
    if (bits != nullptr) {
        free(bits);
    }
    bits = nullptr;
    numBits = 0;
}

void BitArray::push_back(bool bit) {
    numBits++;
    bits = (bool*)realloc(bits, numBits * sizeof(bool));
    bits[numBits - 1] = bit;
}

BitArray& BitArray::operator&=(const BitArray& b) {
    if (numBits == b.numBits) {
        for (int i = 0; i < numBits; i++) bits[i] &= b.bits[i];
        return *this;
    }
    else {
        std::cout << "size error" << std::endl;
        return *this;
    }
}

BitArray& BitArray::operator|=(const BitArray& b) {
    if (numBits == b.numBits) {
        for (int i = 0; i < numBits; i++) bits[i] |= b.bits[i];
        return *this;
    }
    else {
        std::cout << "size error" << std::endl;
        return *this;
    }
}

BitArray& BitArray::operator^=(const BitArray& b) {
    if (numBits == b.numBits) {
        for (int i = 0; i < numBits; i++) bits[i] ^= b.bits[i];
        return *this;
    }
    else {
        std::cout << "size error" << std::endl;
        return *this;
    }
}

BitArray& BitArray::operator<<=(int n) {
    if (n >= 0) {
        for (int i = numBits - 1; i >= n; i--) {
            bits[i] = bits[i - n];
        }
        for (int i = n - 1; i >= 0; i--) {
            bits[i] = 0;
        }
    }
    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n >= 0) {
        for (int i = 0; i < numBits - n; i++) {
            bits[i] = bits[i + n];
        }
        for (int i = numBits - n; i < numBits; i++) {
            bits[i] = 0;
        }
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    if (numBits + n > numBits) {
        BitArray result(*this);
        result <<= n;
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

BitArray BitArray::operator>>(int n) const {
    if (numBits - n >= 0) {
        BitArray result(*this);
        result >>= n;
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

BitArray& BitArray::set(int n, bool val) {
    if (n >= 0 && n < numBits) {
        bits[n] = val;
    }
    else {
        std::cout << "size error" << std::endl;
    }
    return *this;
}

BitArray& BitArray::set() {
    for (int i = 0; i < numBits; i++) bits[i] = true;
    return *this;
}

BitArray& BitArray::reset(int n) {
    if (n >= 0 && n < numBits) {
        bits[n] = false;
    }
    else {
        std::cout << "size error" << std::endl;
    }
    return *this;
}

BitArray& BitArray::reset() {
    for (int i = 0; i < numBits; i++) bits[i] = false;
    return *this;
}

bool BitArray::any() const {
    for (int i = 0; i < numBits; i++) {
        if (bits[i] == true) return true;
    }
    return false;
}

bool BitArray::none() const {
    for (int i = 0; i < numBits; i++) {
        if (bits[i] == true) return false;
    }
    return true;
}

BitArray BitArray::operator~() const {
    if (numBits > 0) {
        BitArray result(*this);
        for (int i = 0; i < numBits; i++) {
            result.bits[i] = !result.bits[i];
        }
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

int BitArray::count() const {
    int count = 0;
    for (int i = 0; i < numBits; i++) {
        if (bits[i] == true) count++;
    }
    return count;
}

bool BitArray::operator[](int i) const {
    if (i >= 0 && i < numBits) {
        return bits[i];
    }
    else {
        std::cout << "size error" << std::endl;
        return false;
    }
}

int BitArray::size() const {
    return numBits;
}

bool BitArray::empty() const {
    return numBits == 0;
}

std::string BitArray::to_string() const {
    std::string str;
    for (int i = numBits - 1; i >= 0; i--) {
        if (bits[i] == true) str += '1';
        else str += '0';
    }
    return str;
}

bool operator==(const BitArray& a, const BitArray& b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(const BitArray& a, const BitArray& b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return true;
        }
        return false;
    }
    else {
        return true;
    }
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1.size());
        for (int i = 0; i < b1.size(); i++) {
            result.set(i, b1[i] & b2[i]);
        }
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1.size());
        for (int i = 0; i < b1.size(); i++) {
            result.set(i, b1[i] | b2[i]);
        }
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    if (b1.size() == b2.size()) {
        BitArray result(b1.size());
        for (int i = 0; i < b1.size(); i++) {
            result.set(i, b1[i] ^ b2[i]);
        }
        return result;
    }
    else {
        std::cout << "size error" << std::endl;
        return BitArray();
    }
}

void print(const BitArray& ba) {
    std::cout << ba.to_string() << " (size=" << ba.size() << ")" << std::endl;
}