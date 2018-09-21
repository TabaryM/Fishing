OBJ = $(OBJDIR)Event.o
OBJDIR = ../../../obj/Input/Event/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
