OBJ = $(OBJDIR)JebaiFish.o
OBJDIR = ../../../../../obj/Game/Object/Fish/JebaiFish/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
