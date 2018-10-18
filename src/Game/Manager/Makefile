OBJ = $(OBJDIR)Manager.o
OBJDIR = ../../../obj/Game/Manager/

GMANAGER = GameManager
IMANAGER = InterfaceManager

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(GMANAGER) && $(MAKE))
	@(cd $(IMANAGER) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
