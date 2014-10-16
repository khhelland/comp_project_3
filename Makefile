#Dette er makefilen for ODEsolver.cpp

COMPILEFLAGS = -O3
#LIBDIR = -L/usr/libs
LIBDIR = 
#INCLUDES = -I/usr/include
INCLUDES = 
LINKERFLAGS = -larmadillo 

PROJECT = main.x

obj = solarsystem.o main.o
COMPILER = g++

default: $(PROJECT)

$(PROJECT): $(obj)
	$(COMPILER) $(LIBDIR) $(INCLUDES) -o $(PROJECT) $(obj) $(LINKERFLAGS)  
%.o: %.cpp
	$(COMPILER) -c -o $@ $^ $(INCLUDES) $(COMPILEFLAGS) 
