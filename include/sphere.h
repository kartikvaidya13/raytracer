#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec.h"

class sphere : public hittable {
    public:
        sphere(const point& center, double radius);
        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;

        private:
        point center;
        double radius;
};

#endif