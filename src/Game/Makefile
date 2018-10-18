OBJ = $(OBJDIR)Game.o
OBJDIR = ../../obj/Game/

OBJECT = Object
MANAGER = Manager

all : before $(TARGET)

before :
	@(cd $(OBJECT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
