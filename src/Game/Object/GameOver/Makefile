OBJ = $(OBJDIR)GameOver.o
OBJDIR = ../../../../obj/Game/Object/GameOver/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
