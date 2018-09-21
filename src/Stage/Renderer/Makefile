OBJ = $(OBJDIR)Renderer.o
OBJDIR = ../../../obj/Stage/Renderer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
