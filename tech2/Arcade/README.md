# Arcade - Epitech Tek2 Project

_That ol' atari machine in the back of the store_

| Graphical Libraries | Games            |
| :------------------ | :--------------- |
| SDL                 | Snake (Nibbler)  |
| NCurses             | Pacman           |
| SFML                | DoodleJump (WIP) |

## How to run ?

Make sure you have all dependencies installed:
- Tools
    - [CMake](https://cmake.org/)
- Libs
    - [SDL](https://www.libsdl.org/)
    - [NCurses](https://invisible-island.net/ncurses/)
    - [SFML](https://www.sfml-dev.org/)

Then, you can run the game with the following command:

```sh
$> cmake -S . -B ./build
# CMake is used to build the entire project in ./build with all it's dependencies
# It then creates a Makefile that you can call using the following:
$> make -C ./build/
# The Makefile compiles all the files inside ./build/ and creates the final
# executable that you can call like so:
$> ./build/arcade <graphical_lib.so>
# The libs can be found in the "./lib/" folder
```

or you can use the `build.sh` script that you can find at root ! ;)
```sh
$> chmod +x ./build.sh
$> ./build.sh <graphical_lib.so>
# The libs can be found in the "./lib/" folder
```

### Credits

- Authored by:
    - Pierre PLASSIO  <pierre.plassio@epitech.eu>
    - Vitali DROUJKO  <vitali.droujko@epitech.eu>
    - Philippe CHEYPE <philippe.cheype@epitech.eu>
- With our parterns in crime:
    - Adrian LORENZI  <adrian.lorenzi@epitech.eu>
    - Anthony GHIZZO  <anthony.ghizzo@epitech.eu>
    - Quentin ROUVIER <quentin.rouvier@epitech.eu>
