*This project has been created as part of the 42 curriculum by bshbool.*

# fractol

## Description

**fractol** is a graphical project that explores the beauty of mathematical fractals through real-time rendering.
Using the MiniLibX graphics library, the program generates and displays famous fractals such as the **Mandelbrot**, **Julia**, and **Burning Ship** sets, allowing the user to navigate infinitely complex patterns through zooming, movement, and (optional) color variations.

The goal of this project is to deepen understanding of:
- Complex numbers and mathematical visualization
- Event handling (keyboard and mouse)
- Graphical programming and optimization in C

fractol is an invitation to observe mathematics as something living, fluid, and endlessly detailed.

---

## Instructions

### Requirements
- macOS or Linux
- `gcc`
- `make`
- MiniLibX (provided by 42)

### Compilation
To compile the program, run:
```
make
```
This will generate the executable:
```
./fractol
```
Usage:
```
./fractol <fractal_name> [parameters]
```
Available fractals:

- Mandelbrot
- Julia (./fractol Julia <re> <im>)
- Burning_Ship

Example:
```
./fractol Mandelbrot
./fractol Julia 0.285 0.01
./fractol Burning_Ship
```
---

Controls

- Mouse scroll: Zoom in / out
- Arrow keys: Move across the fractal
- Mouse movement (Julia): Modify parameters dynamically
- ESC: Exit the program

---

### Bonus: Burning Ship Fractal

The Burning Ship fractal is included as a bonus.

It is rendered similarly to Mandelbrot but with absolute values applied to the real and imaginary parts at each iteration.

Supports the same controls (zoom, move, exit).

Provides a visually distinct “ship-like” fractal pattern.

---

## Resources
- Wikipedia –  [Fractals](https://en.wikipedia.org/wiki/Fractal), [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set), and [Burning Ship fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)

- [MiniLibX man](https://harm-smits.github.io/42docs/libs/minilibx)

- [this guide on Medium](https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5)

- [yt guide](https://www.youtube.com/watch?v=ANLW1zYbLcs)

## AI Usage
AI tools were used as a learning assistant, not as an automatic code generator.

Specifically, AI was used for:

Clarifying mathematical concepts related to complex numbers and fractals

Helping structure the project and improve code readability

Assisting with documentation writing (README formatting and wording)

All implementation, logic, and debugging decisions were made and validated manually by me.