OBJ = $(OBJDIR)Initializer.o
OBJDIR = ../../obj/Initializer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
