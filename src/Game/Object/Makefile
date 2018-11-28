OBJ = $(OBJDIR)Object.o
OBJDIR = ../../../obj/Game/Object/

FISH = Fish
BOAT = Boat
HOOK = Hook
WAVE = Wave
SCORE = Score
TIMER = Timer
GO = GameOver

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(FISH) && $(MAKE))
	@(cd $(BOAT) && $(MAKE))
	@(cd $(HOOK) && $(MAKE))
	@(cd $(WAVE) && $(MAKE))
	@(cd $(SCORE) && $(MAKE))
	@(cd $(TIMER) && $(MAKE))
	@(cd $(GO) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
