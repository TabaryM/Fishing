OBJ = $(OBJDIR)Stage.o
OBJDIR = ../../obj/Stage/

RENDERER = Renderer
WINDOW = Window

all : before $(TARGET)

before :
	@(cd $(RENDERER) && $(MAKE))
	@(cd $(WINDOW) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
