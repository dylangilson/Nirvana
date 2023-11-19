NAME = nirvana

OBJDIR = ../objs
HEADERDIR = ../headers

CC = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -pedantic -lglfw -ldl -I $(HEADERDIR)

DEPS = glad.h display.hpp vao.hpp vbo.hpp raw_model.hpp loader.hpp renderer.hpp shader_program.hpp static_shader.hpp 
OBJS = glad.o main.o display.o vao.o vbo.o raw_model.o loader.o renderer.o shader_program.o static_shader.o

DEP = $(patsubst %, $(HEADERDIR)/%, $(DEPS))
OBJ = $(patsubst %, $(OBJDIR)/%, $(OBJS))

$(OBJDIR)/%.o: %.c $(DEP)
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/%.o: %.cpp $(DEP)
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean

clean:
	rm -f $(OBJDIR)/*.o $(NAME)