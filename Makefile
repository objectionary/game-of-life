source := $(wildcard **/*.cpp)
headers := $(wildcard include/*.h)
objects := ${source:.cpp=.o}

run: $(objects)
	g++ -o run $(objects)
	bash -c "diff -u <(cat $(source)) <(clang-format $(source))"
%.o: %.cpp tests/%.cpp $(headers)
	g++ $@ -o $<

fix:
	clang-format -i $(source) $(headers)

clean:
	rm src/*.o
	rm run
	rm tests/*.o
