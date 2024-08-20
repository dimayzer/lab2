TARGET = bin

CC = clang

CFLAGS_COMMON = -Wall -Wextra -Werror
LDFLAGS = -lreadline


SAN = -g -fsanitize=undefined





STACK_TYPE ?= LIST

ifeq ($(STACK_TYPE), LIST)
  SRCS = main.c lib/stack_list.c
else ifeq ($(STACK_TYPE), VECTOR)
  SRCS = main.c lib/stack_vector.c
else
    $(error Invalid STACK_TYPE. Available options: LIST, VECTOR)
endif


CFLAGS = $(CFLAGS_COMMON) $(SAN) -DVARIABLE=$(STACK_TYPE) 
OBJS = $(SRCS:.c = .o) 


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean: 
	rm -f $(TARGET)
