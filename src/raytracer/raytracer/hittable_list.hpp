#pragma once

#include <raytracer/hittable.hpp>
#include <raytracer/interval.hpp>

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

namespace raytracer {
class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() : objects() {}
    hittable_list(shared_ptr<hittable> object) : objects() { add(object); }

    void clear() { objects.clear(); }

    void add(shared_ptr<hittable> object) { objects.push_back(object); }

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto &object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }

	vec3 acceleration(const point3& pos) const override {
		vec3 acc;
		
		for (const auto &object : objects) {
			acc += object->acceleration(pos);
		}

		return acc;
	}
};
} // namespace raytracer
