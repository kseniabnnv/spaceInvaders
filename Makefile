exe_file=prog
SFML_INCLUDE_PATH = C:/SFML-2.6.1/include
LDFLAGS = -LC:/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32

SRCS = main.cpp \
       Application/application.cpp \
       Entities/player.cpp \
       Entities/alien.cpp \
       Entities/alienMatrix.cpp \
       Resources/textureContainer.cpp \
       States/stateStack.cpp \
       States/state.cpp \
       States/gameState/gameState.cpp \
       States/menuState/menuState.cpp \
       States/pauseState/pauseState.cpp \
       States/titleState/titleState.cpp \

OBJS = $(SRCS:.cpp=.o)
#OBJS = $(patsubst %.cpp,%.o,$(notdir $(SRCS)))

$(exe_file): $(OBJS)
	g++ $(OBJS) -o $(exe_file) $(LDFLAGS)

%.o: %.cpp
	g++ -c $< -o $@ -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
clean:
	del *.o $(exe_file).exe