#include "sphere.h"

sphere::sphere(const point& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

bool sphere::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const {
    vec oc = center - r.origin();
    auto a = r.direction().length_squared();
    // auto b = -2.0 * dot(r.direction(), oc);
    // b can be simplified such that b = -2h
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;
    // Since b has been simplified, we drop the 4
    auto discriminant = h*h - a*c;
    
    if ( discriminant < 0) 
        return false;
    
    auto sqrtd = std::sqrt(discriminant);

    // Find nearest root that lies in acceptable range.
    auto root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;

}