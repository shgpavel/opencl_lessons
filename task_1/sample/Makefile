CFLAGS := -Wall -Wextra -O3 -std=c2x ${CFLAGS}

CC = clang
LD = clang

solution: sol.c
	$(CC) sol.c -lOpenCL $(CFLAGS)

clean:
	rm -rf a.out
