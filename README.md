# Raytracer

A toy raytracer in C++, based on [Ray Tracing in One Weekend](https://raytracing.github.io/)

## Building

Build and run:

```
just build
./builddir/main > image.ppm
```

## Development

Fix code style using `clang-format`

```
just fmt
```

Check code style using `clang-format` and `clang-tidy`

```
just lint
```

Run unit-tests

```
just test
```

Or all in one go

```
just fmt lint test
```
