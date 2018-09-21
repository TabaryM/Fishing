OBJ = $(OBJDIR)Surface.o
OBJDIR = ../../../obj/Texture/Surface/

RECT = Rectangle

all : before $(TARGET)

before :
	@(cd $(RECT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
