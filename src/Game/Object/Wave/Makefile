OBJ = $(OBJDIR)Wave.o
OBJDIR = ../../../../obj/Game/Object/Wave/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
