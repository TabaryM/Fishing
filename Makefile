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
OBJ = $(OBJDIR)main.o $(OBJDIR)Game/Game.o $(OBJDIR)Game/Manager/Manager.o $(OBJDIR)Game/Manager/InterfaceManager/InterfaceManager.o $(OBJDIR)Game/Manager/GameManager/GameManager.o $(OBJDIR)Game/Object/Object.o $(OBJDIR)Game/Object/Fish/Fish.o $(OBJDIR)Game/Object/Fish/NormalFish/NormalFish.o $(OBJDIR)Game/Object/Fish/FastFish/FastFish.o $(OBJDIR)Game/Object/Fish/GoldFish/GoldFish.o $(OBJDIR)Game/Object/Fish/RipFish/RipFish.o $(OBJDIR)Game/Object/Fish/BombFish/BombFish.o $(OBJDIR)Game/Object/Fish/JebaiFish/JebaiFish.o $(OBJDIR)Game/Object/Boat/Boat.o $(OBJDIR)Game/Object/Hook/Hook.o $(OBJDIR)Initializer/Initializer.o $(OBJDIR)Input/Input.o $(OBJDIR)Input/Event/Event.o $(OBJDIR)Stage/Stage.o $(OBJDIR)Stage/Renderer/Renderer.o $(OBJDIR)Stage/Window/Window.o $(OBJDIR)Texture/Texture.o $(OBJDIR)Texture/Surface/Surface.o $(OBJDIR)Texture/Surface/Rectangle/Rectangle.o
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
	@mkdir obj/Game/Manager/InterfaceManager
	@mkdir obj/Game/Manager/GameManager
	@mkdir obj/Game/Object
	@mkdir obj/Game/Object/Fish
	@mkdir obj/Game/Object/Fish/NormalFish
	@mkdir obj/Game/Object/Fish/FastFish
	@mkdir obj/Game/Object/Fish/GoldFish
	@mkdir obj/Game/Object/Fish/RipFish
	@mkdir obj/Game/Object/Fish/BombFish
	@mkdir obj/Game/Object/Fish/JebaiFish
	@mkdir obj/Game/Object/Boat
	@mkdir obj/Game/Object/Hook
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
