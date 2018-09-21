export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS =

export TARGET = debug

export INC =  -I"C:\MinGW\include" -I"C:\lib\SDL2-2.0.8\i686-w64-mingw32\include"
export LIBDIR = -L"C:\MinGW\lib" -L"C:\lib\SDL2-2.0.8\i686-w64-mingw32\lib"
export LIB = "C:\MinGW\lib\libmingw32.a" "C:\lib\SDL2-2.0.8\i686-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.8\i686-w64-mingw32\lib\libSDL2.dll.a"

OBJDIR = obj/
BIN = bin/
SOURCE = src
OBJ = $(OBJDIR)Stage/Window/Window.o $(OBJDIR)Texture/Surface/Rectangle/Rectangle.o $(OBJDIR)Texture/Surface/Surface.o $(OBJDIR)Texture/Texture.o $(OBJDIR)Initializer/Initializer.o $(OBJDIR)Game/Game.o $(OBJDIR)Stage/Renderer/Renderer.o $(OBJDIR)Stage/Stage.o $(OBJDIR)Input/Input.o $(OBJDIR)Input/Event/Event.o $(OBJDIR)main.o
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
	@mkdir obj/Input
	@mkdir obj/Input/Event
	@mkdir obj/Stage
	@mkdir obj/Stage/Renderer
	@mkdir obj/Stage/Window
	@mkdir obj/Initializer
	@mkdir obj/Game
	@mkdir obj/Texture
	@mkdir obj/Texture/Surface
	@mkdir obj/Texture/Surface/Rectangle
	@echo "Jobs done."
