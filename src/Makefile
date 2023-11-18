NAME = nirvana

OBJDIR = ../objs
HEADERDIR = ../headers

CC = g++
CFLAGS = -g -Wall -Wextra -std=c++11 -pedantic -lGL -lGLU -lGLEW -lglfw -lX11 -lpthread -ldl -I $(HEADERDIR)

DEPS = display.hpp vao.hpp vbo.hpp raw_model.hpp loader.hpp renderer.hpp shader_program.hpp static_shader.hpp 
OBJS = main.o display.o vao.o vbo.o raw_model.o loader.o renderer.o shader_program.o static_shader.o

DEP = $(patsubst %, $(HEADERDIR)/%, $(DEPS))
OBJ = $(patsubst %, $(OBJDIR)/%, $(OBJS))

$(OBJDIR)/%.o: %.cpp $(DEP)
	@mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean

clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d *~ core output output.* $(NAME)