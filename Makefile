# make file for leetcode experiments

# the compiler is g++
CC = g++

# use C++11 standard
CFLAGS = -std=c++11

# define all the sources
SRCS = tree.cpp tree_ext.cpp leetcode.cpp sum_alg.cpp linkedlist.cpp linkedlist_ext.cpp \
       math_alg.cpp arr_alg.cpp

# define all the headers
INCLUDES = tree.h tree_ext.h sum_alg.h linkedlist.h linkedlist_ext.h math_alg.h arr_alg.h

# define all the object files
OBJS = $(SRCS:.cpp=.o)

# define the target name
TARGET = leetcode

# remove
RM = rm

# build all
all: $(OBJS)
	$(CC) -o $(TARGET)  $(OBJS) 

# temporarily the main entrace to test all the problem solutions
# expecting constant changes over the time. 
# TODO: Replace the main function with testing cases
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

# linked list basic module
linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

# linked list extended module
linkedlist_ext.o: linkedlist_ext.cpp linkedlist_ext.h
	$(CC) $(CFLAGS) -c linkedlist_ext.cpp

# math algorithm module
math_alg.o: math_alg.cpp math_alg.h
	$(CC) $(CFLAGS) -c math_alg.cpp

# array algorithm module
arr_alg.o: arr_alg.cpp arr_alg.h
	$(CC) $(CFLAGS) -c arr_alg.cpp
clean:
	$(RM) $(TARGET) *.o
