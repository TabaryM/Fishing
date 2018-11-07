OBJ = $(OBJDIR)RipFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/RipFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
