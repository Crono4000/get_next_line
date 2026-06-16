*This project has been created as part of the 42 curriculum by afranco-*

## Description

This project is a implementation of a c function called get_next_line.
A function that lets you extract line by line from a file.

## Instructions

### Requirements
- a c compiler

### Usage

1. You just need to compile the program with the get_next_line files and the BUFFER_SIZE you want:
	```bash
	cc program.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10
	```

### Example usage

1. Suppose you have a simple program `main.c`:
   ```c
	#include "get_next_line.h"
	#include <fcntl.h>

	int main(int argc, char **argv)
	{
		char	*line;
		int		fd;

		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		close(fd);
		return (0);
	}
   ```

2. Compile it with the function files:
   ```bash
   cc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10 -o program
   ```

3. Run it:
   ```bash
   ./program
   ```

## How it works

The algorithm uses a static buffer to preserve unread data between function calls. 
It first extracts any remaining characters from the previous read, then repeatedly reads chunks of size BUFFER_SIZE until a newline character or end-of-file is reached. 
The resulting line is dynamically constructed by concatenating the read chunks, while any excess data after the newline is kept in the static buffer for the next call.

## Resources

### References

- Peer discussions

### IA usage

Large Language Models were used for:
- Understand concepts from c like void static variables or the read command.

### Tests

This project was tested using francinette.
