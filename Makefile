# make file for leetcode experiments

# the compiler is g++
CC = g++

# use C++11 standard
CFLAGS = -std=c++11

# define all the sources
SRCS = tree.cpp tree_ext.cpp leetcode.cpp sum_alg.cpp

# define all the headers
INCLUDES = tree.h tree_ext.h sum_alg.h

# define all the object files
OBJS = $(SRCS:.cpp=.o)

# define the target name
TARGET = leetcode

# remove
RM = rm

# build all
all: $(OBJS)
	$(CC) -o $(TARGET)  $(OBJS) 

leetcode.o: $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c leetcode.cpp

# tree basic module
tree.o: tree.cpp tree.h
	$(CC) $(CFLAGS) -c tree.cpp

# tree extend module
tree_ext.o: tree_ext.cpp tree.h
	$(CC) $(CFLAGS) -c tree_ext.cpp

# sum related algorithm problems
sum_alg.o: sum_alg.cpp sum_alg.h
	$(CC) $(CFLAGS) -c sum_alg.cpp

clean:
	$(RM) $(TARGET) *.o
