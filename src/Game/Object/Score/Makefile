OBJ = $(OBJDIR)Score.o
OBJDIR = ../../../../obj/Game/Object/Score/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
