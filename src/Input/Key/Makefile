OBJ = $(OBJDIR)Key.o
OBJDIR = ../../../obj/Input/Key/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
