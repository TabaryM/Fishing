OBJ = $(OBJDIR)Object.o
OBJDIR = ../../../obj/Game/Object/

FISH = Fish

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(FISH) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
