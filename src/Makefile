CC=gcc
RM=rm -f

TARGET=../hora
CFLAGS = -Wall
SRCS=$(wildcard *.c)

OBJS=$(patsubst %.c,%.o,$(SRCS))


all: $(TARGET)
	@echo Made [ $? ] OK :\)

$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(DIR_OBJ)/%.o: %.c
	@$(CC) -c $(CFLAGS) $< -O $@

clean:
	@$(RM) $(OBJS)
	@$(RM) *~ core

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -f $(DIR_OBJ)
	
.PHONY: all clean distclean
