OBJ = $(OBJDIR)InterfaceManager.o
OBJDIR = ../../../../obj/Game/Manager/InterfaceManager/

MENU = Menu

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(MENU) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
