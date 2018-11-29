OBJ = $(OBJDIR)Menu.o
OBJDIR = ../../../../../obj/Game/Manager/InterfaceManager/Menu/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
