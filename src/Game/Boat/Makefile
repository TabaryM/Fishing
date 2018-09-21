OBJ = $(OBJDIR)Boat.o
OBJDIR = ../../../obj/Game/Boat/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
