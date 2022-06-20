source := $(wildcard **/*.cpp)
objects := ${source:.cpp=.o}
run: $(objects)
	g++ -o run tests/main.o src/cell.o
%.o: %.cpp tests/%.cpp
	g++ $@ -c $<
clean:
	del /f src\\*.o
	del /f run.exe
	del /f tests\\*.o
