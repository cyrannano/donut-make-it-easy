# DoNut make it easy
C++ based interface that lets you look at donuts and other bizzare 3D shapes in your friendly neighbourhood terminal

## Lets keep it UNIX just for now

The main idea/goal is to rasterize 3D shapes in the terminal using ASCII characters

Being able to rasterize and render in real time a torus with an ability to rotate it with a fixed light source will be considered as a success.

# Todo
- [x] Get/Update terminal size info
- [X] Draw ASCII character at given position
- [] Drawing 2D shapes
- [X] Rotating 2D shapes
- [ ] Figure out the details about math behind 3D shapes rendering
- [ ] Dot product between light ray and 3D object to figure out the light intensity
- [ ] Object rotation, probably some matrix equations


# Changelog
## 0.0.2
- Added Square class
- Implemented 2D rotation and movement
- For now program is drawing only vertices - not whole figures
- Rotation is a bit wanky and 'choppy' but I think that's because of the terminal row/col size which is kinda big
- When drawing shape the function is trying to compensate unevenness of row to col size. It does that simply by dividing height in half. But I feel like it's going to cause me trouble later. We will see.
- Right now, main.cpp, is displaying a Square and rotating it counterclockwise while moving down right with a ratio 2:1

## 0.0.1
- Implemented printing single character at given position in the terminal
- Created new virtual class Object, inherited from Interface (not sure wether thats good or not. It seems a bit evil, might change it later)
- Created new class Cube, inherited from Object
- Implemented screen clearing. Works kinda ok but looks kinda ugly. Probably will change it later
- At this point program just fills the terminal with # signs as a test. It should react to terminal resizing and behave accordingly.
## 0.0.0
- Initial commits
- Figuring out the environment/workspace
- Getting familiar with altering and gathering data from the terminal 
