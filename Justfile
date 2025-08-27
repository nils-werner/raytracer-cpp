clean:
    - rm -rf builddir/ testdir/

build:
    meson setup builddir
    meson compile -C builddir

test:
    meson setup testdir
    meson test -C testdir

fmt:
    clang-format -i -- **.cpp

lint:
    clang-format --dry-run -Werror -- **.cpp
