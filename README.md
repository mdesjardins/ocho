# 8️⃣ ocho 

Ocho is my [CHIP-8 emulator](http://devernay.free.fr/hacks/chip8/C8TECH10.HTM). There are tons of such emulators, this is mine.
I've barely started it - I just decided to check it into Github so I can easily access it on both of my computers.

## Why?

I love programming in C. It was my first language. As my career has progressed, I've worked in lots and lots of higher level 
languages, but sometimes I pine for the simplicity and rawness of C. For me, I think of programming in C as analogous to
"driving stick." It's hard. There are constraints. But it's fun.

## Future Plans

I actually want to learn Zig (another "low level" language!), but I thought it might be too difficult to dive right into a 
CHIP-8 emulator project with a new programming language, so I thought I'd try it in C first, then once I've figured that
out, maybe I'll try it again in Zig or some other language for fun. Kind of like my "write a Gopher server in multiple
languages" repository.

## Building and Running

I'm building this thing on macOS with gcc. You should be able to just run `make` and then run the `ocho` executable. Right 
now you need to pass it a ROM filename as the only argument.
