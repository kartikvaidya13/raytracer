#ifndef RAY_H
#define RAY_H

#include "vec.h"

class ray {
    public:
        ray();
        ray(const point& origin, const vec& direction);

        const point& origin() const;
        const vec& direction() const;

        point at(double t) const;

        private:
            point orig;
            vec dir;
};

#endif