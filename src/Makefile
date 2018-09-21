OBJ = $(OBJDIR)main.o
OBJDIR = ../obj/

STAGE = Stage
GAME = Game
INIT = Initializer
TEXTURE = Texture
INPUT = Input

debug : before $(OBJ)

before:
	@(cd $(GAME) && $(MAKE))
	@(cd $(INIT) && $(MAKE))
	@(cd $(INPUT) && $(MAKE))
	@(cd $(STAGE) && $(MAKE))
	@(cd $(TEXTURE) && $(MAKE))

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
