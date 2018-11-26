OBJ = $(OBJDIR)Timer.o
OBJDIR = ../../../../obj/Game/Object/Timer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
