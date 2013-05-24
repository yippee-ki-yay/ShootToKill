#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.138                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC =  -I/home/nenad/Desktop/shoot_to_kill/Resource
CFLAGS =  -Wall `sdl-config --cflags`
RESINC = 
LIBDIR = 
LIB = -lSDL_image -lSDL_ttf
LDFLAGS =  `sdl-config --libs`

INC_DEBUG =  $(INC)
CFLAGS_DEBUG =  $(CFLAGS) -g
RESINC_DEBUG =  $(RESINC)
RCFLAGS_DEBUG =  $(RCFLAGS)
LIBDIR_DEBUG =  $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG =  $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/ShootStuff

INC_RELEASE =  $(INC)
CFLAGS_RELEASE =  $(CFLAGS) -O2
RESINC_RELEASE =  $(RESINC) -IResource
RCFLAGS_RELEASE =  $(RCFLAGS)
LIBDIR_RELEASE =  $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE =  $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/ShootStuff

OBJ_DEBUG = $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/Text.o $(OBJDIR_DEBUG)/Sprite.o $(OBJDIR_DEBUG)/Player.o $(OBJDIR_DEBUG)/PlayState.o $(OBJDIR_DEBUG)/Menu.o $(OBJDIR_DEBUG)/HighScore.o $(OBJDIR_DEBUG)/Animation.o $(OBJDIR_DEBUG)/Game.o $(OBJDIR_DEBUG)/Enemy.o $(OBJDIR_DEBUG)/EndScene.o $(OBJDIR_DEBUG)/Credits.o $(OBJDIR_DEBUG)/Collision.o $(OBJDIR_DEBUG)/Button.o $(OBJDIR_DEBUG)/Bullets.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/Text.o $(OBJDIR_RELEASE)/Sprite.o $(OBJDIR_RELEASE)/Player.o $(OBJDIR_RELEASE)/PlayState.o $(OBJDIR_RELEASE)/Menu.o $(OBJDIR_RELEASE)/HighScore.o $(OBJDIR_RELEASE)/Animation.o $(OBJDIR_RELEASE)/Game.o $(OBJDIR_RELEASE)/Enemy.o $(OBJDIR_RELEASE)/EndScene.o $(OBJDIR_RELEASE)/Credits.o $(OBJDIR_RELEASE)/Collision.o $(OBJDIR_RELEASE)/Button.o $(OBJDIR_RELEASE)/Bullets.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/main.o: main.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.c -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/Text.o: Text.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Text.c -o $(OBJDIR_DEBUG)/Text.o

$(OBJDIR_DEBUG)/Sprite.o: Sprite.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Sprite.c -o $(OBJDIR_DEBUG)/Sprite.o

$(OBJDIR_DEBUG)/Player.o: Player.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Player.c -o $(OBJDIR_DEBUG)/Player.o

$(OBJDIR_DEBUG)/PlayState.o: PlayState.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c PlayState.c -o $(OBJDIR_DEBUG)/PlayState.o

$(OBJDIR_DEBUG)/Menu.o: Menu.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Menu.c -o $(OBJDIR_DEBUG)/Menu.o

$(OBJDIR_DEBUG)/HighScore.o: HighScore.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c HighScore.c -o $(OBJDIR_DEBUG)/HighScore.o

$(OBJDIR_DEBUG)/Animation.o: Animation.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Animation.c -o $(OBJDIR_DEBUG)/Animation.o

$(OBJDIR_DEBUG)/Game.o: Game.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Game.c -o $(OBJDIR_DEBUG)/Game.o

$(OBJDIR_DEBUG)/Enemy.o: Enemy.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Enemy.c -o $(OBJDIR_DEBUG)/Enemy.o

$(OBJDIR_DEBUG)/EndScene.o: EndScene.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c EndScene.c -o $(OBJDIR_DEBUG)/EndScene.o

$(OBJDIR_DEBUG)/Credits.o: Credits.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Credits.c -o $(OBJDIR_DEBUG)/Credits.o

$(OBJDIR_DEBUG)/Collision.o: Collision.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Collision.c -o $(OBJDIR_DEBUG)/Collision.o

$(OBJDIR_DEBUG)/Button.o: Button.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Button.c -o $(OBJDIR_DEBUG)/Button.o

$(OBJDIR_DEBUG)/Bullets.o: Bullets.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c Bullets.c -o $(OBJDIR_DEBUG)/Bullets.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/main.o: main.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.c -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/Text.o: Text.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Text.c -o $(OBJDIR_RELEASE)/Text.o

$(OBJDIR_RELEASE)/Sprite.o: Sprite.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Sprite.c -o $(OBJDIR_RELEASE)/Sprite.o

$(OBJDIR_RELEASE)/Player.o: Player.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Player.c -o $(OBJDIR_RELEASE)/Player.o

$(OBJDIR_RELEASE)/PlayState.o: PlayState.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c PlayState.c -o $(OBJDIR_RELEASE)/PlayState.o

$(OBJDIR_RELEASE)/Menu.o: Menu.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Menu.c -o $(OBJDIR_RELEASE)/Menu.o

$(OBJDIR_RELEASE)/HighScore.o: HighScore.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c HighScore.c -o $(OBJDIR_RELEASE)/HighScore.o

$(OBJDIR_RELEASE)/Animation.o: Animation.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Animation.c -o $(OBJDIR_RELEASE)/Animation.o

$(OBJDIR_RELEASE)/Game.o: Game.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Game.c -o $(OBJDIR_RELEASE)/Game.o

$(OBJDIR_RELEASE)/Enemy.o: Enemy.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Enemy.c -o $(OBJDIR_RELEASE)/Enemy.o

$(OBJDIR_RELEASE)/EndScene.o: EndScene.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c EndScene.c -o $(OBJDIR_RELEASE)/EndScene.o

$(OBJDIR_RELEASE)/Credits.o: Credits.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Credits.c -o $(OBJDIR_RELEASE)/Credits.o

$(OBJDIR_RELEASE)/Collision.o: Collision.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Collision.c -o $(OBJDIR_RELEASE)/Collision.o

$(OBJDIR_RELEASE)/Button.o: Button.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Button.c -o $(OBJDIR_RELEASE)/Button.o

$(OBJDIR_RELEASE)/Bullets.o: Bullets.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c Bullets.c -o $(OBJDIR_RELEASE)/Bullets.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

