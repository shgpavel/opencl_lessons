CFLAGS := -Wall -Wextra -O3 -std=c23 ${CFLAGS}
LDFLAGS := -lOpenCL ${LDFLAGS}
# -fsanitize=address -fsanitize=undefined

CC = clang
LD = clang

SRC := solution.c

.PHONY: all clean
all: $(SRC)
	$(CC) $(SRC) $(LDFLAGS) $(CFLAGS)
clean:
	rm -rf a.out
