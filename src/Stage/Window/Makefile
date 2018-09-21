OBJ = $(OBJDIR)Window.o
OBJDIR = ../../../obj/Stage/Window/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
