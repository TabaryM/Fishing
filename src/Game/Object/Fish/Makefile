OBJ = $(OBJDIR)Fish.o
OBJDIR = ../../../../obj/Game/Object/Fish/

NORMALFISH = NormalFish
FASTFISH = FastFish
GOLDFISH = GoldFish
RIPFISH = RipFish
BOMBFISH = BombFish
JEBAIFISH = JebaiFish

all : $(TARGET) after

debug : $(OBJ)

after :
	@(cd $(FASTFISH) && $(MAKE))
	@(cd $(NORMALFISH) && $(MAKE))
	@(cd $(GOLDFISH) && $(MAKE))
	@(cd $(RIPFISH) && $(MAKE))
	@(cd $(BOMBFISH) && $(MAKE))
	@(cd $(JEBAIFISH) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
