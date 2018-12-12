OBJ = $(OBJDIR)Hitbox.o
OBJDIR = ../../../../obj/Game/Object/Hitbox/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
