OBJ = $(OBJDIR)Surface.o
OBJDIR = ../../../obj/Texture/Surface/

RECT = Rectangle
FONT = Font

all : before $(TARGET)

before :
	@(cd $(RECT) && $(MAKE))
	@(cd $(FONT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
