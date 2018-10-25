OBJ = $(OBJDIR)Input.o
OBJDIR = ../../obj/Input/

EVENT = Event
KEY = Key

all : before $(TARGET)

before :
	@(cd $(EVENT) && $(MAKE))
	@(cd $(KEY) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
