# Falling Sand

This project is currently a simple prototype of a falling sand game, with plans to extend the simulation to include more features including a larger collection of element types.


Most of the present features are either work-in-progress or placeholder, and as such will be improved upon or replaced in the future.


You can compile and run the project for yourself using CMake as long as you have SDL2 installed where CMake can find it:

- Clone the project
- Make a 'build' directory inside the cloned repository
- run 'cmake ..' with any desired flags
- run 'cmake --build .'
- finally, run the generated executable.


### Controls:
Pressing a key will spawn the corresponding element at the mouse position:
- W for Water
- S for Sand
- L for Lava


Stone and steam aren't included in spawnable elmenents because they are by-products of elements reacting to one another.
