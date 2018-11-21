OBJ = $(OBJDIR)Texture.o
OBJDIR = ../../obj/Texture/

SURFACE = Surface
FONT = Font

all : before $(TARGET)

before :
	@(cd $(SURFACE) && $(MAKE))
	@(cd $(FONT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
