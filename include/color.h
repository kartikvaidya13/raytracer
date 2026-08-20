#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vec.h"

using color = vec;

inline void write_color(std::ostream& out, const color& pixel_color) {
    // Multiply RGB by alpha (w)
    auto a = pixel_color.w();
    auto r = pixel_color.x() * a;
    auto g = pixel_color.y() * a;
    auto b = pixel_color.z() * a;

    // Translate the compontent values to byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out pixel color components.
    out << rbyte << ' '<< gbyte << ' '<< bbyte << '\n';
}

#endif