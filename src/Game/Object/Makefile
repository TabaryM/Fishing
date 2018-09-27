OBJ = $(OBJDIR)Object.o
OBJDIR = ../../../obj/Game/Object/

FISH = Fish
BOAT = Boat

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(FISH) && $(MAKE))
	@(cd $(BOAT) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
