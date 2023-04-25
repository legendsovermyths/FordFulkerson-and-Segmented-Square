CC = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
INC_DIR = include
SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,obj/%.o,$(SRCS))
DEPS = $(wildcard $(INC_DIR)/*.hpp)
BINDIR = bin

TARGET = $(BINDIR)/main

all: obj $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

obj/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $< -o $@

obj:
	mkdir obj

clean:
	rm -rf obj/ $(TARGET)