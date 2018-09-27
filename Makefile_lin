export CXX = g++
export LD = g++

export CFLAGS = -Wall -std=c++11
export LDFLAGS =

export TARGET = debug

export INC =
export LIBDIR =
export LIB = -lSDL2 -lSDL2_image

OBJDIR = obj/
BIN = bin/
SOURCE = src
OBJ = $(OBJDIR)main.o $(OBJDIR)Game/Game.o $(OBJDIR)Game/Object/Object.o $(OBJDIR)Initializer/Initializer.o $(OBJDIR)Input/Input.o $(OBJDIR)Input/Event/Event.o $(OBJDIR)Stage/Stage.o $(OBJDIR)Stage/Renderer/Renderer.o $(OBJDIR)Stage/Window/Window.o $(OBJDIR)Texture/Texture.o $(OBJDIR)Texture/Surface/Surface.o $(OBJDIR)Texture/Surface/Rectangle/Rectangle.o
OUT = Fish

all : before out

before :
	@(cd $(SOURCE) && $(MAKE))

out : $(OBJ)
	@$(LD) $(LIBDIR) -o $(BIN)$(OUT) $^ $(LDFLAGS) $(LIB)
	@echo "Jobs done."

clean :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Game
	@mkdir obj/Game/Object
	@mkdir obj/Initializer
	@mkdir obj/Input
	@mkdir obj/Input/Event
	@mkdir obj/Stage
	@mkdir obj/Stage/Renderer
	@mkdir obj/Stage/Window
	@mkdir obj/Texture
	@mkdir obj/Texture/Surface
	@mkdir obj/Texture/Surface/Rectangle
	@echo "Jobs done."
