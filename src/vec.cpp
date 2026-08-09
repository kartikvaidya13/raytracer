#include "vec.h"
#include <cmath>
#include <iostream>

vec::vec() : e{0,0,0,0} {}
vec::vec(double e0, double e1, double e2) : e{e0, e1, e2, 1.0} {}
vec::vec(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

vec vec::operator-() const { return vec(-e[0], -e[1], -e[2], e[3]); }
double vec::operator[](int i) const { return e[i]; }
double& vec::operator[](int i) { return e[i]; }

vec& vec::operator+=(const vec& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec& vec::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec& vec::operator/=(double t) {
    return *this *= 1/t;
}

double vec::length() const {
    return std::sqrt(length_squared());
}

double vec::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

// Vector Utility Functions

std::ostream& operator<<(std::ostream& out, const vec& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vec operator+(const vec& u, const vec& v) {
    return vec(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vec operator-(const vec& u, const vec& v) {
    return vec(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vec operator*(const vec& u, const vec& v) {
    return vec(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vec operator*(double t, const vec& v) {
    return vec(t*v.e[0], t*v.e[1], t*v.e[2]);
}

vec operator*(const vec& v, double t) {
    return t * v;
}

vec operator/(const vec& v, double t) {
    return (1/t) * v;
}

double dot(const vec& u, const vec& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

vec cross(const vec& u, const vec& v) {
    return vec(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vec unit_vector(const vec& v) {
    return v / v.length();
}