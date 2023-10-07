
all:
	gcc -std=c11 -Wall -Wextra fileRead.c -o fileRead

clean:
	rm -f fileRead