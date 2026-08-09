#ifndef COLOR_H
#define COLOR_H

#include "vec.h"

#include <iostream>

using color = vec;

void write_color(std::ostream& out, const color& pixel_color);

#endif