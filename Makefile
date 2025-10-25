EXE_NAME = rush-02

SRC_DIR = src
CFILES = helpers.c \
	 errors.c \
	 linkedlist.c \
	 parse_dict.c \
	  main.c

OBJECTS = $(CFILES:%.c=$(SRC_DIR)/%.o)

H_DIR = includes

CFLAGS += -Wall -Wextra -Werror -I$(H_DIR)
CC = cc

#rules
$(EXE_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE_NAME) 

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(EXE_NAME)

clean:
	rm -f $(OBJECTS)


