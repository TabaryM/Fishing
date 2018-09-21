OBJ = $(OBJDIR)Input.o
OBJDIR = ../../obj/Input/

EVENT = Event

all : before $(TARGET)

before :
	@(cd $(EVENT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
