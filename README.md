# Conway's Game of Life

This is a small project I made in one day just for fun (later improved a bit).

It implements the **[Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)** as imagined by **John Horton Conway** in the 70s.

It uses the console for display, but uses a special block character from the Unicode : `■`. If your terminal does not support it you can just replace the character with any one you want (the hashtag `#` for example) in [`gameoflife.c`](https://github.com/Biskweet/conways-game-of-life-c/blob/main/gameoflife.c).

Maybe I'll later add proper graphics one day.

It also includes a very brain-dead implementation of two patterns: one **oscillator** (a pulsar) and one **spaceship** (a glider) but they are disabled by default, because the random cells initializer breaks it & hence makes it pointless. You can still use it but I recommend disabling the initializer.

 

### Requirements

* Nothing lol



### How-to

* Just compile the code using `make all` or `make`
* Run `./main`



This code is inspired by the first, non working version I made using Python 3 and Pygame. Maybe I will come back on that project and fix it.

Obviously that means it probably isn't optimal as I am relatively new to programming (it's only been a few years), and it is *very* simple, but you can reuse the code freely. I'd even be happy to know you did, so do not hesitate to tell me!

 
