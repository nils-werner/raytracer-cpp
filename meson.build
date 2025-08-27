project(
  'raytracer',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=everything', 'werror=true'],
)

dependencies = [
]

main = executable(
  'main',
  'src/raytracer/main.cpp',
  dependencies : dependencies,
  install : true,
)

test('main', main)
