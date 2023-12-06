NAME = nirvana

OBJ_DIR = ../objs
HEADER_DIR = ../headers

CC = g++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++11 -pedantic -lglfw -ldl -I $(HEADER_DIR)

INCLUDES = $(patsubst %, $(HEADER_DIR), /*/%.hpp)
SRCS = $(wildcard */*.cpp)
# SRCS = engine/main.cpp
OBJS = $(patsubst */%.cpp, */*.o, $(SRCS))

$(OBJ_DIR)/%.o: $(SRCS) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY : clean

clean:
	rm -f $(OBJ_DIR)/*.o $(NAME)