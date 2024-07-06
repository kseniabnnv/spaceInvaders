exe_file=prog
$(exe_file): main.o game.o textureContainer.o
	g++ main.o game.o textureContainer.o -o $(exe_file) -LC:/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32
main.o: main.cpp
	g++ -c main.cpp -IC:/SFML-2.6.1/include -DSFML_STATIC
game.o: game.cpp game.h
	g++ -c game.cpp -IC:/SFML-2.6.1/include -DSFML_STATIC
textureContainer.o: textureContainer.cpp textureContainer.h
	g++ -c textureContainer.cpp -IC:/SFML-2.6.1/include -DSFML_STATIC
clean:
	rm –f *.o $(exe_file)