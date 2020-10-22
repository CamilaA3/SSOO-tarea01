CC=cc
SRC=hora.c
CFLAGS=-Wall -std=c17

TARGET=../hora
BIN=hora

OBJ=$(SRC:.c=.o)

INCLUDES=-I./include -I/opt/local/include
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread

CXXFLAGS=-std=c++17 -Wall -O2

DIR_OBJ=objs

SRCS=$(wildcard *.cc)

OBJS=$(patsubst %.cc,$(DIR_OBJ)/%.o,$(SRCS))

all:  $(BIN)
	 $(TARGET)
	@echo Made [ $? ] OK :\)


$(BIN): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(@)
	@rm -f $(OBJ)
	@rm -f *~
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 
	
$(DIR_OBJ)/%.o: %.cc
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)
	

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f $(BIN)
	
	@$(RM) $(OBJS)
	@$(RM) *~ core
	
distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -f $(DIR_OBJ)

.PHONY: all clean distclean
