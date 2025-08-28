#pragma once

#include <raytracer/color.hpp>
#include <raytracer/vec3.hpp>

namespace raytracer {
class ray {
  public:
    ray() : orig(point3(0, 0, 0)), dir(point3(0, 0, 1)) {}

    ray(const point3 &origin, const vec3 &direction)
        : orig(origin), dir(direction) {}

    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    point3 at(double t) const { return orig + t * dir; }

  private:
    point3 orig;
    vec3 dir;
};

color ray_color(const ray &r);
bool hit_sphere(const point3 &center, double radius, const ray &r);

bool hit_sphere(const point3 &center, double radius, const ray &r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

color ray_color(const ray &r) {
    if (hit_sphere(point3(0, 0, -1), 0.5, r)) {
        return color(1, 0, 0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}
} // namespace raytracer
