clean:
    - rm -rf builddir/ testdir/

run: build
    ./builddir/main

build:
    meson setup builddir
    meson compile -C builddir

test:
    meson setup testdir
    meson test -C testdir

fmt:
    #!/usr/bin/env bash
    shopt -s globstar
    clang-format -i -- **/*.cpp **/*.hpp

lint:
    #!/usr/bin/env bash
    shopt -s globstar
    clang-format --dry-run -Werror -- **/*.cpp **/*.hpp
