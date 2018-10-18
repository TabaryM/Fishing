OBJ = $(OBJDIR)GameManager.o
OBJDIR = ../../../../obj/Game/Manager/GameManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
