OBJ = $(OBJDIR)BombFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/BombFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
