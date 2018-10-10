OBJ = $(OBJDIR)Hook.o
OBJDIR = ../../../../obj/Game/Object/Hook/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
