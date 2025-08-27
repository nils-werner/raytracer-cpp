clean:
    - rm -rf builddir/ testdir/

run: build
    ./builddir/main

setup:
    meson setup builddir

build: setup
    meson compile -C builddir

test:
    meson setup testdir
    meson test -C testdir

fmt: setup
    ninja -C builddir clang-format

lint: setup
    ninja -C builddir clang-format-check
