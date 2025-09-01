#include <raytracer/main.hpp>

int main() {
    raytracer::hittable_list world;

    world.add(make_shared<raytracer::sphere>(raytracer::point3(0, 0, -1), 0.5));
    world.add(make_shared<raytracer::sphere>(raytracer::point3(0, -100.5, -1), 100));

    raytracer::camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world);
}
