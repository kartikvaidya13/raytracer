#ifndef COMMON_H
#define COMMON_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ Std Usings
using std::make_shared;
using std::shared_ptr;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degs_to_rads(double degs) {
    return degs*pi / 180.0;
}

// Common Headers
#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec.h"

#endif