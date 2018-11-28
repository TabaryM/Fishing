OBJ = $(OBJDIR)Surface.o
OBJDIR = ../../../obj/Texture/Surface/

RECT = Rectangle
FONT = Font
TEXT = Text

all : before $(TARGET)

before :
	@(cd $(RECT) && $(MAKE))
	@(cd $(FONT) && $(MAKE))
	@(cd $(TEXT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
