# OBJS specifies which files to compile as part of the project
# When adding a new folder, add as <folder/*cpp>
OBJS = *.cpp graphics/*.cpp utilities/*.cpp math/*.cpp

# CC specifies which compiler we're using
CC = g++

# Flags
CFLAGS = -g -Wall

# INCLUDE_PATHS specifies the additional include paths we'll need
# X11 may not be needed in include and library. Test later. 
INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# COMPILER_FLAGS = -w

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -lGLEW -lglfw -lGLU -lGL

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = equinox


# This is the target that compiles our executable (make)
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# make run
run: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./equinox