OBJ = $(OBJDIR)Texture.o
OBJDIR = ../../obj/Texture/

SURFACE = Surface

all : before $(TARGET)

before :
	@(cd $(SURFACE) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
