OBJ = $(OBJDIR)Fish.o
OBJDIR = ../../../../obj/Game/Object/Fish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
