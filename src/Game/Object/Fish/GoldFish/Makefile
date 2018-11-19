OBJ = $(OBJDIR)GoldFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/GoldFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
