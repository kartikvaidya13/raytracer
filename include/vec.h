#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>

class vec {
  public:
    double e[4];

    vec() : e{0,0,0,0} {}
    vec(double e0, double e1, double e2) : e{e0, e1, e2, 1.0} {}
    vec(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    // Geometic Coordinates
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Alpha Value
    double w() const { return e[3]; }

    vec operator-() const { return vec(-e[0], -e[1], -e[2], e[3]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec& operator+=(const vec& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

using point = vec;


// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec operator+(const vec& u, const vec& v) {
    return vec(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec operator-(const vec& u, const vec& v) {
    return vec(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec operator*(const vec& u, const vec& v) {
    return vec(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec operator*(double t, const vec& v) {
    return vec(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec operator*(const vec& v, double t) {
    return t * v;
}

inline vec operator/(const vec& v, double t) {
    return (1/t) * v;
}

inline double dot(const vec& u, const vec& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec cross(const vec& u, const vec& v) {
    return vec(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec unit_vector(const vec& v) {
    return v / v.length();
}

#endif