OBJ = $(OBJDIR)InterfaceManager.o
OBJDIR = ../../../../obj/Game/Manager/InterfaceManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
