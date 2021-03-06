export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++11 -O3
export LDFLAGS =

export TARGET = debug

export INC =  -I"C:\MinGW\mingw64\x86_64-w64-mingw32\include" -I"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\include"
export LIBDIR = -L"C:\MinGW\mingw64\x86_64-w64-mingw32\lib" -L"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib"
export LIB = "C:\MinGW\mingw64\x86_64-w64-mingw32\lib\libmingw32.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2_image.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2_ttf.dll.a"

OBJDIR = obj/
BIN = bin/
SOURCE = src
OBJ = $(OBJDIR)main.o $(OBJDIR)Game/Game.o $(OBJDIR)Game/Manager/Manager.o $(OBJDIR)Game/Manager/InterfaceManager/InterfaceManager.o $(OBJDIR)Game/Manager/InterfaceManager/Bouton/Bouton.o $(OBJDIR)Game/Manager/SaveManager/SaveManager.o $(OBJDIR)Game/Manager/GameManager/GameManager.o $(OBJDIR)Game/Object/Object.o $(OBJDIR)Game/Object/Fish/Fish.o $(OBJDIR)Game/Object/Boat/Boat.o $(OBJDIR)Game/Object/Score/Score.o $(OBJDIR)Game/Object/Timer/Timer.o $(OBJDIR)Game/Object/Hook/Hook.o $(OBJDIR)Game/Object/Wave/Wave.o $(OBJDIR)Game/Object/Hitbox/Hitbox.o $(OBJDIR)Game/Object/GameOver/GameOver.o $(OBJDIR)Initializer/Initializer.o $(OBJDIR)Input/Input.o $(OBJDIR)Input/Event/Event.o $(OBJDIR)Input/Key/Key.o $(OBJDIR)Stage/Stage.o $(OBJDIR)Stage/Renderer/Renderer.o $(OBJDIR)Stage/Window/Window.o $(OBJDIR)Texture/Texture.o $(OBJDIR)Texture/Surface/Surface.o $(OBJDIR)Texture/Surface/Rectangle/Rectangle.o $(OBJDIR)Texture/Surface/Font/Font.o $(OBJDIR)Texture/Surface/Text/Text.o
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
	@mkdir obj/Game/Manager
	@mkdir obj/Game/Manager/SaveManager
	@mkdir obj/Game/Manager/GameManager
	@mkdir obj/Game/Manager/InterfaceManager
	@mkdir obj/Game/Manager/InterfaceManager/Bouton
	@mkdir obj/Game/Object
	@mkdir obj/Game/Object/Fish
	@mkdir obj/Game/Object/Boat
	@mkdir obj/Game/Object/Hook
	@mkdir obj/Game/Object/Hitbox
	@mkdir obj/Game/Object/Wave
	@mkdir obj/Game/Object/Score
	@mkdir obj/Game/Object/Timer
	@mkdir obj/Game/Object/GameOver
	@mkdir obj/Initializer
	@mkdir obj/Input
	@mkdir obj/Input/Event
	@mkdir obj/Input/Key
	@mkdir obj/Stage
	@mkdir obj/Stage/Renderer
	@mkdir obj/Stage/Window
	@mkdir obj/Texture
	@mkdir obj/Texture/Surface
	@mkdir obj/Texture/Surface/Font
	@mkdir obj/Texture/Surface/Text
	@mkdir obj/Texture/Surface/Rectangle
	@echo "Jobs done."
