OBJ = $(OBJDIR)InterfaceManager.o
OBJDIR = ../../../../obj/Game/Manager/InterfaceManager/

BOUTON = Bouton

all : before $(TARGET)

debug : $(OBJ)

before:
	@(cd $(BOUTON) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
