#include <raytracer/main.hpp>

using std::make_shared;

int main() {
    raytracer::hittable_list world;

    auto material_ground = make_shared<raytracer::lambertian>(raytracer::color(0.8, 0.8, 0.0));
    auto material_center = make_shared<raytracer::lambertian>(raytracer::color(0.1, 0.2, 0.5));
    auto material_left = make_shared<raytracer::metal>(raytracer::color(0.8, 0.8, 0.8));
    auto material_right = make_shared<raytracer::metal>(raytracer::color(0.8, 0.6, 0.2));

    world.add(make_shared<raytracer::sphere>(raytracer::point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<raytracer::sphere>(raytracer::point3(0.0, 0.0, -1.2), 0.5, material_center));
    world.add(make_shared<raytracer::sphere>(raytracer::point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<raytracer::sphere>(raytracer::point3(1.0, 0.0, -1.0), 0.5, material_right));

    raytracer::camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 10;
    cam.max_depth = 10;

    cam.render(world);
}
