OBJ = $(OBJDIR)Text.o
OBJDIR = ../../../../obj/Texture/Surface/Text/


all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
