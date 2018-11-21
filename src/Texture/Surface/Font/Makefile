OBJ = $(OBJDIR)Font.o
OBJDIR = ../../../../obj/Texture/Surface/Font/


all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
