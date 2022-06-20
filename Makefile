source := $(wildcard **/*.cpp)
headers := $(wildcard include/*.h)
objects := ${source:.cpp=.o}
run: $(objects)
	g++ -o run $(objects)
	clang-format -i $(source) $(headers)
%.o: %.cpp tests/%.cpp $(headers)
	g++ $@ -o $<
clean:
	del /f src\\*.o
	del /f run.exe
	del /f tests\\*.o
