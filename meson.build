project(
  'raytracer',
  'cpp',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=everything', 'werror=true'],
)

dependencies = [
]

exe = executable(
  'book1',
  'book1.cpp',
  dependencies : dependencies,
  install : true,
)

test('basic', exe)
