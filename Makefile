source := $(wildcard **/*.cpp)
headers := $(wildcard include/*.h)
objects := ${source:.cpp=.o}

run: $(objects)
	g++ -o run $(objects)
	diff -u <(cat $(source)) <(clang-format $(source))
%.o: %.cpp tests/%.cpp $(headers)
	g++ $@ -o $<

fix:
	clang-format -i $(source) $(headers)

clean:
	del /f src\\*.o
	del /f run.exe
	del /f tests\\*.o
