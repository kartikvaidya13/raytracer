#ifndef VEC_H
#define VEC_H

#include <cmath>
#include <iostream>

class vec {
  public:
    double e[4];

    vec();
    vec(double e0, double e1, double e2);
    vec(double e0, double e1, double e2, double e3);

    // Geometic Coordinates
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Alpha Value
    double w() const { return e[3]; }

    vec operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    vec& operator+=(const vec& v);
    vec& operator*=(double t);
    vec& operator/=(double t);

    double length() const;
    double length_squared() const;
};

using point = vec;


// Vector Utility Functions
std::ostream& operator<<(std::ostream& out, const vec& v);
vec operator+(const vec& u, const vec& v);
vec operator-(const vec& u, const vec& v);
vec operator*(const vec& u, const vec& v);
vec operator*(double t, const vec& v);
vec operator*(const vec& v, double t);
vec operator/(const vec& v, double t);
double dot(const vec& u, const vec& v);
vec cross(const vec& u, const vec& v);
vec unit_vector(const vec& v);

#endif