OBJ = $(OBJDIR)Object.o
OBJDIR = ../../../obj/Game/Object/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
