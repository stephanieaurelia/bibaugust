make:
	gcc -o bibaugust main.c sort.c load.c tools.c -O2 -Wall -Wshadow -pipe
debug:
	gcc -o bibaugust main.c sort.c load.c tools.c -O2 -Wall -Wshadow -pipe -g