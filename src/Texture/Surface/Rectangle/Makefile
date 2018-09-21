OBJ = $(OBJDIR)Rectangle.o
OBJDIR = ../../../../obj/Texture/Surface/Rectangle/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
