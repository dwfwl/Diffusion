# Diffusion

## Contents
* [Showcase](#showcase)
* [Physics](#Physics)
* [Building](#building)

## Showcase

## Physics
Diffusion simulates the [Fick's First Law of Diffusion](https://en.wikipedia.org/wiki/Fick%27s_laws_of_diffusion), 

$$
J = -D\frac{\partial C}{\partial x}
$$

Where:
- $J$ = diffusion flux (amount per unit area per unit time)
- $D$ = diffusion coefficient
- $C$ = concentration
- $x$ = distance
- The negative sign indicates diffusion occurs from **high** to **low** concentration.

## Building
First of all, this project requires [building GLFW](#building-glfw).
Recommended for building this project is using Visual Studio (preferably 2022).

## Building GLFW

This project requires `glfw3.lib`, so you must build GLFW from source.

1. Clone the GLFW repository:
   ```bash
   git clone https://github.com/glfw/glfw.git
   ```

2. Build it with CMake:
   ```bash
   cd glfw
   cmake -S . -B build
   cmake --build build --config Release
   ```

3. Copy `glfw3.lib` from `build/src/Release/` into the project's `lib/` folder (or update the linker path in Visual Studio).

Official GLFW repository: https://github.com/glfw/glfw
