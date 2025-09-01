#pragma once

#include <raytracer/color.hpp>
#include <raytracer/hittable.hpp>
#include <raytracer/ray.hpp>

namespace raytracer {
class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const {
        return false;
    }
};
} // namespace raytracer
