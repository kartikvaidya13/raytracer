#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vec.h"

using color = vec;

void write_color(std::ostream& out, const color& pixel_color);

#endif