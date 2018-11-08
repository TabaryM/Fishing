OBJ = $(OBJDIR)SaveManager.o
OBJDIR = ../../../../obj/Game/Manager/SaveManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
