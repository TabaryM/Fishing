OBJ = $(OBJDIR)Game.o
OBJDIR = ../../obj/Game/

OBJECT = Object
MANAGER = Manager

all : before $(TARGET)

debug : $(OBJ)

before :
	@(cd $(OBJECT) && $(MAKE))
	@(cd $(MANAGER) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
