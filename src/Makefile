NAME = nirvana

CC = g++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++11 -pedantic -lglfw -ldl -I ../headers

INCLUDES = $(patsubst %, ../headers/, */%.hpp)
SRCS = $(wildcard */*.cpp)
OBJS = $(SRCS:.cpp=.o)

%.o: */%.cpp $(INCLUDES)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY : clean

clean:
	rm -f */*.o $(NAME)