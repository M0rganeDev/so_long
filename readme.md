# so_long

![image](https://morgane.dev/uploads/qam6uuyur1.png)

so_long is a school42 project in which we have to create a small maze in which the player can move and have to collect a set amount of collectibles to win.

## Fair warnings : 

**THIS BRANCH CONTAINS A FOLLOW UP TO THE PROJECT, PLEASE GO TO THE [RESULT BRANCH](https://github.com/M0rganeDev/so_long/tree/result) FOR THE CODE I WROTE INITIALLY**

Also, minilibx is infamous for taking a very big amount of memory at runtime, I cannot guarantee your system can even handle it (My desktop with 16gb or ram froze more than once, and my 32gb one was left with MBs to spare).

Lastly, there is a few issues that went un-noticed during both developpement and defense : 

`>` Enemies that go on collectible permanently destroy them

`>` Step / collectible counters in bonus mode dont work as expected (although this is an easy fix)

`>` Floodfill visualiser (see [src/parser/floodfill_utils.c](https://github.com/M0rganeDev/so_long/blob/result/src/parser/floodfill_utils.c)) can cause freeze due to how minilibx work

## Compiling (x11 linux only !)

first make sure your system is ready for building the project, [check this repo to set everything up for minilibx](https://github.com/42Paris/minilibx-linux)

NixOS : a shell.nix and a default.nix will be added to the repository within the next few days

First git clone the project :

```bash
git clone -b result https://github.com/M0rganeDev/so_long # code for the initial project
git clone https://github.com/M0rganeDev/so_long # main branch used for fun (dont follow the norm)
```

Mandatory : 
```bash
make libs # clone the minilibx for linux, and compiles it with my libft
make all # build the program and link the libraries
```

Bonus : 
```bash
make libs # clone the minilibx for linux, and compiles it with my libft
make bonus # build the program and link the libraries
```

Note for MacOS users : in theory, you can build minilibx-linux under MacOS, but it is not supported at all.

Note for Windows users : dont bother, it wont work.
Execute :

`./so_long maps/[any map present in this directory]`

# Create a map :

## rules :

so_long maps have to follow a really simple yet important set of rules : 

`>` a map is defined as a rectangle (or square) where every lines are of the same size

`>` a map must be fully closed (the player cant exit it / the outer layer of the map must be a wall)

`>` a player, a collectible and an exit must be present

`>` the player must be able to reach every collectible and the exit

`>` the file containing the map must have the `.ber` file extension

`>` if a character not present in the props list (see bellow), the map is seen as invalid and wont launch

`>` if the map qualify as a map, it should be able to be launched no matter what (if the computer can handle it)

## props : 

| Prop name   | associated character |
|-------------|----------------------|
| Player      | 'P'                  |
| Wall        | '1'                  |
| Ground      | '0'                  |
| Collectible | 'C'                  |
| Enemy       | 'F'                  |

Note : an 'Enemy' prop can only exist in the bonus mode, and any map with an enemy opened in mandatory mode will not work.

Check [this map](https://github.com/M0rganeDev/so_long/blob/mommy/maps/b_lv1.ber) to see what qualify as a good (but hard) bonus map
and [this map](https://github.com/M0rganeDev/so_long/blob/mommy/maps/lv1.ber) to see what qualify as a valid mandatory mode map.
