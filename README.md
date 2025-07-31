# John Conway's Game of Life

![[logo]((assets/logo+.png))](assets/logo.png)

![badge](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/potatmen/Life/blob/master/LICENSE.txt)
[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)
![workflow badge](https://github.com/potatmen/Life/actions/workflows/Life.yml/badge.svg)

This project demonstrates that
[John Conway's Game of Life][wiki]
written in C++ using OOP features (inheritance, encapsulation, polymorphism)
runs slower than the same implementation
using the [EO] programming language.
The broader goal is to show that the EO language
is more efficient for object-intensive projects in terms of execution time.
According to [previous research](https://github.com/yegor256/fibonacci),
measurements showed that the C++ implementation for counting Fibonacci numbers
using objects works slowly. Therefore, we decided to implement the Game of Life.
Fibonacci number counting is insufficient because using objects for its
implementation is artificial, as we can use a simple loop to calculate it.

First, you need to install the [Boost] library, along with `g++`,
`clang-format` and `clang-tidy` if not already installed.
On Ubuntu, install everything as follows:

```bash
sudo apt-get install --yes g++ libboost-all-dev clang-tidy clang-format
```

Additionally, install [eoc].

To build the project, run:

```bash
make
```

Choose between `fast_life` or `slow_life` to start the game.
For `fast_life`, run:

```bash
./fast_life --help
```

Otherwise:

```bash
./slow_life --help
```

It will show you all the available options.

Both implementations share the same options.
Examples below use `fast_life`.

For example, you can enter something like this:

```bash
./fast_life --batch 20 --size 40x40 --put 3x6 --put 6x8 --put 12x9
```

This runs an automated game with 20 generations on a 40x40 grid with
three initially alive cells.

To clean the environment:

```bash
make clean
```

To format all `.cpp` files using `clang-format`:

```bash
make fix
```

To run tests for the `fast` or `slow` version:

```bash
make fast_test
```

Or:

```bash
make slow_test
```

To see the [Gosper glider gun] pattern, run:

```bash
./fast_life --batch 1000 --sleep 170 --size 40x40 --put 10x26 --put 11x26 \
  --put 11x24 --put 12x14 --put 12x15 --put 12x23 --put 12x22 --put 12x36 \
  --put 12x37 --put 13x13 --put 13x17 --put 13x22 --put 13x23 --put 13x36 \
  --put 13x37 --put 14x2 --put 14x3 --put 14x12 --put 14x18 --put 14x22 \
  --put 14x23 --put 15x2 --put 15x3 --put 15x12 --put 15x16 --put 15x18 \
  --put 15x19 --put 15x24 --put 15x26 --put 16x12 --put 16x18 --put 16x26 \
  --put 17x13 --put 17x17 --put 18x14 --put 18x15
```

To see an infinite loop pattern:

```bash
./fast_life --batch 40 --sleep 500 --size 10x10 --put 5x4 --put 5x5 --put 5x6
```

To run the `EO` version:

```bash
eoc --alone dataize life size 3x3 put 2x1 put 2x2 put 2x3
```

You can use custom arguments. For the `size` option, use `NxM` where
`N` is height and `M` is width. Use `put AxB` to place an alive cell
at position `AxB`:

```bash
eoc --alone dataize life size NxM put AxB put CxD put ExF put ... and so on.
```

To recompile after changing the `EO` file, omit the `--alone` option:

```bash
eoc dataize life size NxM put AxB put CxD put ExF put ... and so on.
```

## Slow Version

There are some notable features of **Cell** and **Field** objects that
should be mentioned: all `for` statements are replaced with recursion,
objects are **immutable**, if we change something, we make a **copy**
of the object and make changes using the constructor, so to change
the current object we create a new one with changes.

**Field** stores the playing field and creates the next generation.

**Details:** `rec_line_print` and `rec_grid_print` print the field.
`rec_line_print` creates the initial field. `rec_live` creates the next generation.
`with` changes the `Cell` at position `(x,y)` by returning a new `Field`
object with the modified cell.
`count` counts alive neighbors for the cell at `(x,y)`. `live` calls
`rec_live` with specific arguments.

```cpp
class Field {
private:
  vector<vector<Cell>> grid;
  void rec_line_print(int depth);
  void rec_grid_print(int x, int y);
public:
  Field(int n, int m) : Field(make_grid(n, m)) {}
  Field(vector<vector<Cell>> g) : grid(g) {}
  vector<vector<Cell>> field();  // getters
  Field rec_add(Field cur, vector<pair<int, int>> s, int pos);
  Field rec_live(int x, int y, Field cur);
  static vector<vector<Cell>> make_grid(int n, int m);
  Field live();
  Field with(int x, int y, Cell a);
  void print();  // next_gen makers
  int count(int x, int y);
};
```

**Cell** stores the cell state (alive/dead). Method `live` takes an integer
to determine the next generation state and returns a `Cell` object.

```cpp
class Cell {
private:
  bool state;
public:
  Cell(bool st) : state(st) {}
  Cell() : Cell(false) {}
  bool status() const;
  Cell live(int cnt) const;
};
```

**Parse** parses command line arguments using the **BOOST** library
and validates input.

```cpp
class Parse {
private:
  int n = 100000;
  int m = 100000;
  vector<pair<int, int>> points;
  po::variables_map vm;
public:
  Parse() : Parse(nullptr) {}
  Parse(po::variables_map vmp) : vm(vmp) {}
  int length() const;
  int width() const;
  vector<pair<int, int>> grid();
  po::variables_map opts();
  vector<pair<int, int>> rec_cells(int pos, vector<pair<int, int>> p);
  static bool has(const string &s, char c);
  static bool valid(string const &s);
  pair<int, int> point(const string &s) const;
  static pair<int, int> size(const string &s);
  static pair<int, int> split(const string &s);
  void positive();
  void cells();
  void build();
};
```

## Fast Version

![Structure](https://user-images.githubusercontent.com/90863441/177322155-579f7f99-be1c-4e54-a9a4-c05e79cf7f11.png)

The main object is `Game(Grid(Size(), Field()), *optional* Repeats())`.

**Repeats** stores the number of iterations.

```cpp
class Repeats {
public:
  int rep;
  Repeats();
};
```

**Grid** stores the grid size and playing field.
It provides methods to print the current state and advance to the
next iteration.

```cpp
class Grid {
public:
  Size s;
  Field g;
  Grid(Size &st, Field &ff);
  void printGrid();
  void nextGen();
};
```

**Size** stores the playing field dimensions.

```cpp
class Size {
public:
  int n;
  int m;
  Size(){};
  Size(int x, int y);
};
```

**Field** stores a 2D array of `Cell` objects. It has methods to set initial
alive cells and count alive neighbors.

```cpp
class Field {
public:
  vector<vector<Cell>> f;
  Field(){};
  Field(Size sz);
  void read_and_set(Size sz);
  int count(int x, int y, int sz);
};
```

**Cell** stores the current state and next generation state.
It provides methods to modify these states.

**Details:** `changeNewState` stores the next generation state without
immediately applying it. This ensures neighbor cells can still read
the current state when calculating their next state. Once all new states
are determined, old values are updated.

`newState` stores the cell's state for the next generation during
calculation.

```cpp
class Cell {
private:
  bool curState = false;
  bool newState = false;
public:
  void changeNewState(bool val);
  void changeCurState();
  void setState(bool val);
  bool getCurState() const;
};

```

**Game** runs the game with a configurable interval between generations.

```cpp
class Game {
public:
  Game(Grid gr, Repeats rep, int time);
  Game(Grid gr);
};
```

**Parse** parses and validates console arguments.

```cpp
class Parse {
public:
  Parse(){};
  static pair get_size(string const &s);
  static vector> get_alive(vector const &a, int n, int m);
};
```

Additional helper objects for input validation and string-to-integer
conversion are not shown.

[Boost]: https://www.boost.org/
[wiki]: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
[EO]: https://github.com/objectionary/eo
[eoc]: https://github.com/objectionary/eoc
[Gosper glider gun]: https://conwaylife.com/wiki/Gosper_glider_gun
