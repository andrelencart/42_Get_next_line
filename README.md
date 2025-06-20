# Get Next Line

## Introduction

Welcome to **get_next_line**!  
This project is part of the 42 school curriculum and aims to bring a handy feature to your C toolbox: reading a file line by line. If you've ever missed Python's `readline()` in C, this is for you. With `get_next_line`, you can process files or input streams one line at a time, without worrying about buffer sizes or manual parsing.

## Concept

The goal is simple: create a function that reads the next line from a file each time you call it. Here’s the function prototype:

```c
int get_next_line(int fd, char **line);
```

- **fd**: The file descriptor to read from (think: an open file or standard input).
- **line**: Where the function will store the next line (without the newline at the end).

Call `get_next_line` in a loop, and you’ll get each line from the file, one at a time. It handles the messy stuff: managing buffers, partial reads, and memory. Return values:
- `1` for a line read,
- `0` for end of file,
- `-1` for errors.

## Bonus Features

The bonus version takes it up a notch:
- **Multiple file descriptors:** Read from several files at once without mixing them up.
- **Solid memory management:** Handles big lines, empty files, and cleans up after itself.
- **Better error handling:** More robust, less likely to crash over edge cases.

## How to Compile & Use

Compiling is straightforward. Make sure to set the `BUFFER_SIZE` macro to control how much data is read at once (e.g., 42):

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Swap in your own `main.c` file for testing.