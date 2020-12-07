# Computer Graphics

A collection of C programs to demonstrate the implementation of basic concepts used in computer graphics. We use OpenGL (Open Graphics Library) in these programs which is a  cross-language, cross-platform application programming interface (API) for rendering 2D and 3D vector graphics. 

Click [here](https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/) to learn about various OpenGL functions used in the programs.

## Setting up environment in Linux
    $ sudo apt-get upgrade && sudo apt-get update
    $ sudo apt-get install freeglut3
    $ sudo apt-get install freeglut3-dev

## Compiling a program
    > gcc filename.c -o filename -lGL -lglut -lGLU 
    > ./filename
            
## Contents:

### Basics
- Drawing Primitives
- Scenery using keyboard and mouse events 

### Line Drawing Algorithms
- Draw line using equation of line Y=m*X+C
- Draw line using DDA (Digital Differential Analyzer) Algorithm
- Draw line using Bresenham’s Line Algorithm 

### Circle and Ellipse
- Circle using Polar Equations
- Circle using Mid-Point Algorithm
- Ellipse using Mid-Point Algorithm 

### Clipping Algorithms
- Cohen Sutherland Line-Clipping Algorithm
- Sutherland Hodgeman Polygon-Clipping Algorithm

### Area Filling Algorithms
- Boundary Fill Algorithm
- Flood Fill Algorithm

### 2D Transformations
- Translation
- Rotation (with respect to arbitrary point also)
- Scaling (with respect to arbitrary point also)
- Reflection about x-axis, y-axis, y=x, y=-x and origin
- Reflection about a line Y=mX+c 
- Shearing about x-axis and y-axis

### 3D Transformations
- Translation
- Rotation about X, Y and Z axis
- Scaling 
- Reflection about XY, YZ and ZX plane
- Shearing about X, Y and Z axis

### Bezier Curves

### 3D Shapes with Animations
- Cube
- Sphere
- Cone
