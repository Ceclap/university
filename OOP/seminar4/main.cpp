#include <iostream>
#include <cstring>

using namespace std;

class multime {
private:
    char* m;
    int k;

public:
    multime();
    multime(int cardinal);
    multime(const multime& other);
    ~multime();
    void operator=(const multime& other);
    multime operator+(const multime& other);
    multime operator-(const multime& other);
    multime operator*(const multime& other);
    bool operator<=(const multime& other);
    bool operator>=(const multime& other);
    friend istream& operator>>(istream& in, multime& m);
    friend ostream& operator<<(ostream& out, const multime& m);
    int cauta(const char element);
};

multime::multime() {
    m = new char[256];
    k = 0;
}

multime::multime(int cardinal) {
    m = new char[cardinal];
    k = 0;
}

multime::multime(const multime& other) {
    m = new char[256];
    k = other.k;
    strcpy(m, other.m);
}

multime::~multime() {
    delete[] m;
}

void multime::operator=(const multime& other) {
    if (this == &other) return;

    delete[] m;
    m = new char[256];
    k = other.k;
    strcpy(m, other.m);
}

multime multime::operator+(const multime& other) {
    multime result;
    result.k = k;

    strcpy(result.m, m);

    for (int i = 0; i < other.k; i++) {
        if (!result.cauta(other.m[i])) {
            result.m[result.k] = other.m[i];
            result.k++;
        }
    }

    return result;
}

multime multime::operator-(const multime& other) {
    multime result;
    result.k = 0;

    for (int i = 0; i < k; i++) {
        if (!other.cauta(m[i])) {
            result.m[result.k] = m[i];
            result.k++;
        }
    }

    return result;
}

multime multime::operator*(const multime& other) {
    multime result;
    result.k = 0;

    for (int i = 0; i < k; i++) {
        if (other.cauta(m[i])) {
            result.m[result.k] = m[i];
            result.k++;
        }
    }

    return result;
}

bool multime::operator<=(const multime& other) {
    for (int i = 0; i < k; i++) {
        if (!other.cauta(m[i])) {
            return false;
        }
    }
    return true;
}

bool multime::operator>=(const multime& other) {
    return other <= *this;
}

istream& operator>>(istream& in, multime& m) {
    cout << "Introduceți cardinalul mulțimii: ";
    in >> m.k;

    cout << "Introduceți elementele mulțimii: ";
    for (int i = 0; i < m.k; i++) {
        in >> m.m[i];
    }

    return in;
}

ostream& operator<<(ostream& out, const multime& m) {
    out << "{";
    for (int i = 0; i < m.k; i++) {
        out << m.m[i];
        if (i < m.k - 1) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}

int multime::cauta(const char element) {
    for (int i = 0; i < k; i++) {
        if (m[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    multime m1, m2;

    cin >> m1;
    cin >> m2;

    multime m3 = m1 + m2;
    cout << "Reuniunea m1 și m2: " << m3 << endl;

    multime m4 = m1 - m2;
    cout << "Diferența m1 și m2: " << m4 << endl;

    multime m5 = m1 * m2;
    cout << "Intersecția m1 și m2: " << m5 << endl;

    if (m1 <= m2) {
        cout << "m1 este inclusă în m2" << endl;
    } else {
        cout << "m1 nu este inclusă în m2" << endl;
    }

    if (m1 >= m2) {
        cout << "m2 este inclusă în m1" << endl;
    } else {
        cout << "m2 nu este inclusă în m1" << endl;
    }

    return 0;
}
