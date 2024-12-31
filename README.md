# C-Crafting-Game
Customizable Crafting Game Written in C

## Customize
Customize this section of code here to change properties
```c
//Initializes important variables
char inventory[51] = {0};
strcat(inventory, "rock, wood");

//Every possible recipe
char recipes[120] = "rock:wood>axe;axe:rock>pickaxe;pickaxe:rock>metal;axe:wood>seed;wood:metal>shovel;shovel:rock>dirt;dirt:seed>fruit";

//Ending item
char needle[] = "fruit";
```
- Change inventory size to accomodate every item
- Change the starting string to change what items are started with (need to be separated by comma and space for formatting)
- Add or remove recipes using the format ITEM1:ITEM2>OUTPUT;
- Change the needle to alter the win condition

## Have fun
If you have fun, consider starring the project to support! :)
