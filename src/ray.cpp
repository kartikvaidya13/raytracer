#include "ray.h"

ray::ray() {}

ray::ray(const point& origin, const vec& direction) : orig(origin), dir(direction) {}

const point& ray::origin() const { return orig; }
const vec& ray::direction() const { return dir; }

point ray::at(double t) const {
    return orig + t*dir;
}