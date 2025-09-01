#pragma once

#include <raytracer/color.hpp>
#include <raytracer/hittable.hpp>
#include <raytracer/ray.hpp>

namespace raytracer {
class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(
        [[maybe_unused]] const ray &r_in,
        [[maybe_unused]] const hit_record &rec,
        [[maybe_unused]] color &attenuation,
        [[maybe_unused]] ray &scattered) const {
        return false;
    }
};

class lambertian : public material {
  public:
    lambertian(const color &albedo) : albedo(albedo) {}

    bool scatter([[maybe_unused]] const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered)
        const override {
        auto scatter_direction = rec.normal + random_unit_vector();

        if (scatter_direction.near_zero()) {
            scatter_direction = rec.normal;
        }

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

  private:
    color albedo;
};

class metal : public material {
  public:
    metal(const color &albedo) : albedo(albedo) {}

    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return true;
    }

  private:
    color albedo;
};
} // namespace raytracer
