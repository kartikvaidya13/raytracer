#ifndef HITTABLE_H
#define HITTABLE_H

#include "common.h"

class hit_record{
    public:
        point p;
        vec normal;
        double t;
        bool front_face;

        /// @brief Sets the hit record normal vector.
        /// @param r ray vector
        /// @param outward_normal outward normal, assumed unit length
        void set_face_normal(const ray& r, const vec& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable{
    public:
        virtual ~hittable() = default;
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

};
#endif