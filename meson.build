project(
  'raytracer',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3', 'werror=true'],
)

raytracer_dep = declare_dependency(
  include_directories : [
    'src/raytracer',
  ]
)

main = executable(
  'main',
  'src/raytracer/raytracer/main.cpp',
  dependencies : [
    raytracer_dep,
  ],
  install : true,
)

test(
  'main',
  main,
  timeout: 60,
)
