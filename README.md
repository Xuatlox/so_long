*This project has been created as part of the 42 curriculum by ansimonn*

# Content

### 1. [Description](#description)

### 2. [Instructions](#instructions)

### 3. [Resources](#resources)

# Description

## Presentation

So Long is a project about creating a 2D game. The program must take a filename as an
argument in the .ber format. The corresponding file must be parsed by the program to
check it is a valid map. The map is represented following the next rules:

- "P" represents the starting player position


- "E" represents the exit position


- "C" represents a collectible position


- "1" represents a wall position


- "0" represents an empty position


A valid map contains only one "P" and one "E", and at least one "C".
It cannot contain another character than the ones above and must be fully surrounded by
walls. It must also have at least one valid path to collect every single collectibles
and get to the exit. It must finally be strictly rectangular. In any of the above cases
the program must exit cleanly and return Error followed on a second line by a description
of the error.

## Bonus features

In the bonus part I chose to add enemies to the game that will be represented as "X" on
the .ber map descriptor. They will try to chase the player to get him to be stuck somehow.

But the player can deal with them once he has collected every collectible on the map.
Once he gets all of them, he will unlock his final form, allowing him to beat enemies on
his way. The enemies will flee from the player once he gets to this point of the game
because, well, they don't want to face this and die.

# Instructions

To compile all the file needed you must use the `make` or `make bonus` command, whether you want
or not the bonus version. It will create object files directly into the `obj` or `bonus_obj` folder and
compile them to get your `so_long` binary at the root of the project.

From there you only need to execute it by executing the following command:

`$> ./so_long map.ber`

You can use the `make clean` command to delete all .o files in the obj folder, or the `make fclean` to also
delete the `so_long` binary.

The `make re` command will execute the `make fclean` command, and then recreate every object files and
the `so_long` binary.

# Resources

I chose not to use AI as I usually do, because I prefer to look for all the resources I need
by my own, so my references websites are here:

- The assets used in the game are all part of this pack: https://sethbb.itch.io/32rogues


- I used this guide to help me understand the functions from the MacroLibX:
  https://macrolibx.kbz8.me/

- This guide helped me understand the main guidelines of the project and how to get started:
  https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b
