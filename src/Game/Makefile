OBJ = $(OBJDIR)Game.o
OBJDIR = ../../obj/Game/

BOAT = Boat

all : $(TARGET)

before :
	@(cd $(BOAT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
