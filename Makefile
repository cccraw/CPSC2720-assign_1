CFLAGS = -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives
OBJECTS = Display.o main.o Simulator.o

show: $(OBJECTS)
	g++ -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	g++ $(CFLAGS) -c $^
