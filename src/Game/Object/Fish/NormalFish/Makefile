OBJ = $(OBJDIR)NormalFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/NormalFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
