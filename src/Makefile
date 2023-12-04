NAME = nirvana

OBJ_DIR = ../objs
HEADER_DIR = ../headers

CC = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -pedantic -lglfw -ldl -I $(HEADER_DIR)

OBJ_FILES = glad.o stb_image.o main.o linear_algebra.o random_number_generator.o display.o vao.o vbo.o ebo.o raw_model.o loader.o renderer.o shader_program.o static_shader.o
OBJ_FILES += uniform.o uniform_bool.o uniform_float.o uniform_int.o uniform_matrix4f.o uniform_matrix4f_vector.o uniform_sampler.o 
OBJ_FILES += uniform_vector2f.o uniform_vector3f.o uniform_vector4f.o texture.o model_texture.o textured_model.o
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