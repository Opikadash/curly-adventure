#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

// SDLC Phase: Design - Planned BigInt class to handle large integers using a vector of digits for efficient storage.
class BigInt {
    vector<int> digits; // Store digits in a vector for better memory control
public:
    // Constructors
    BigInt(unsigned long long n = 0);
    BigInt(string &);
    BigInt(const char *);
    BigInt(BigInt &);

    // Helper Functions
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int) const;

    BigInt &operator=(const BigInt &);
    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);

    // Arithmetic Operations
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);
    friend BigInt &operator^=(BigInt &, const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    // Comparison Operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    // Other Functions
    friend BigInt sqrt(BigInt &a);
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
};

// SDLC Phase: Implementation - Constructor to handle string input
BigInt::BigInt(string & s) {
    digits.clear();
    digits.reserve(s.size()); // Pre-allocate memory for efficiency
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
    cout << "Log: Initialized BigInt from string: " << s << endl; // Basic OS-style logging
}

// SDLC Phase: Implementation - Constructor for unsigned long long
BigInt::BigInt(unsigned long long nr) {
    digits.clear();
    digits.reserve(20); // Pre-allocate for typical size of unsigned long long
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
    cout << "Log: Initialized BigInt from number: " << nr << endl;
}

// Other constructors (unchanged for brevity)
BigInt::BigInt(const char *s) {
    digits.clear();
    int len = strlen(s);
    digits.reserve(len);
    for (int i = len - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(BigInt & a) {
    digits = a.digits;
}

// Helper Functions (Adjusted for vector)
bool Null(const BigInt& a) {
    return a.digits.size() == 1 && a.digits[0] == 0;
}

int Length(const BigInt & a) {
    return a.digits.size();
}

int BigInt::operator[](const int index) const {
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

// Arithmetic Operations (Adjusted for vector, example for +=)
BigInt &operator+=(BigInt &a, const BigInt& b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.digits.resize(m, 0); // Explicit resizing
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    cout << "Log: Performed addition operation" << endl;
    return a;
}

// Output Operator (Adjusted for vector)
ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        out << (short)a.digits[i];
    return out;
}

// SDLC Phase: Testing - Main function with additional test cases
int main() {
    BigInt first("12345");
    cout << "The number of digits in first big integer = " << Length(first) << '\n';
    BigInt second(12345);
    if (first == second) {
        cout << "first and second are equal!\n";
    } else {
        cout << "Not equal!\n";
    }
    // Additional Test Cases
    BigInt zero("0");
    if (Null(zero)) {
        cout << "Zero test passed!\n";
    }
    BigInt large = Factorial(50);
    cout << "Factorial of 50 = " << large << '\n';
    return 0;
}
