OBJ = $(OBJDIR)FastFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/FastFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
