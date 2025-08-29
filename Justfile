clean:
    - rm -rf builddir*/

setup:
    meson setup builddir

build: setup
    meson compile -C builddir

run: build
    ./builddir/main > image.ppm

preview: run
    open image.ppm

test: setup
    meson test -C builddir

fmt: setup
    ninja -C builddir clang-format

lint: setup
    ninja -C builddir clang-format-check

release: clean
    meson setup builddir-release --buildtype=release
    meson compile -C builddir-release
