#pragma once

#include <raytracer/hittable.hpp>
#include <raytracer/interval.hpp>
#include <raytracer/vec3.hpp>

namespace raytracer {
class sphere : public hittable {
  public:
    sphere(const point3 &center, double radius, shared_ptr<material> mat, double mass=0.0)
        : center(center), radius(std::fmax(0, radius)), mat(mat), mass(mass) {}

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h * h - a * c;
        if (discriminant < 0) {
            return false;
        }

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }

	vec3 acceleration(const point3& pos) const override {
		vec3 r = pos - center;
		double dist = std::max(r.length_squared(), 1e-4);
		return -mass * unit_vector(r) / dist;
	}

  private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
	double mass;
};
} // namespace raytracer
