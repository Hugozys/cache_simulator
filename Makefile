GXX = g++ -std=gnu++03 -ggdb3 -Wall -Werror -pedantic -c 
.PHONY: clean depend
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))


my_sim: $(OBJS)
	g++ -o $@  $(OBJS)

%.o: %.cpp
	$(GXX) $<

depend:
	makedepend $(SRCS)
clean:
	rm -f  *.o *# *~ my_sim
