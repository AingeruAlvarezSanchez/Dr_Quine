NAMES = Colleen \
        Grace   \
        Sully

CC = clang
CFLAGS = -Wall -Werror -Wextra -Os -fno-stack-protector

SRC = src/Colleen/Colleen.c   \
      src/Grace/Grace.c       \
      src/Sully/Sully.c

OBJ_DIR = obj/
OBJ = $(patsubst src/%.c, $(OBJ_DIR)%.o, $(SRC))

BIN_DIR = bin/
BIN = $(patsubst src/%.c, $(BIN_DIR)%, $(SRC))

.PHONY: all
all: $(BIN)

$(BIN_DIR)%: $(OBJ_DIR)%.o
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)%.o: src/%.c
	mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) -r $(BIN_DIR)

.PHONY: re
re: fclean all
