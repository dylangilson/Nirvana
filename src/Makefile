NAME = nirvana

OBJ_DIR = ../objs
HEADER_DIR = ../headers

CC = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -pedantic -lglfw -ldl -I $(HEADER_DIR)

OBJ_FILES = glad.o main.o linear_algebra.o random_number_generator.o display.o vao.o vbo.o ebo.o raw_model.o loader.o renderer.o shader_program.o static_shader.o
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(OBJ_FILES))
INCLUDES = $(patsubst %, $(HEADER_DIR), /*/%.hpp)
SRC_FILE_PATH = */%.cpp
OBJ_FILE_PATH = %.o

$(OBJ_DIR)/$(OBJ_FILE_PATH): $(SRC_FILE_PATH) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean

clean:
	rm -f $(OBJ_DIR)/*.o $(NAME)