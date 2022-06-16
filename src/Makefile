source := $(wildcard *.cpp)
objects := ${source:.cpp=.o}
run: $(objects)
    g++ -o run main.o
$(objects): $(source)
    g++ -c $(source)
clean:
    del /f *.o
    del /f run.exe