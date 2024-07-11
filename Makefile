exe_file=prog
SFML_INCLUDE_PATH = C:/SFML-2.6.1/include
LDFLAGS = -LC:/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32

$(exe_file): main.o game.o textureContainer.o alienMatrix.o player.o alien.o
	g++ main.o game.o textureContainer.o alienMatrix.o player.o alien.o -o $(exe_file) $(LDFLAGS)
main.o: main.cpp
	g++ -c main.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
game.o: game.cpp game.h
	g++ -c game.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
player.o: player.cpp player.h
	g++ -c player.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
textureContainer.o: textureContainer.cpp textureContainer.h
	g++ -c textureContainer.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
alien.o: alien.h alien.cpp
	g++ -c alien.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
alienMatrix.o: alienMatrix.h alienMatrix.cpp
	g++ -c alienMatrix.cpp -I$(SFML_INCLUDE_PATH) -DSFML_STATIC
clean:
	del *.o $(exe_file).exe