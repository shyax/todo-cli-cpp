# todo-cli

A minimal command-line todo manager written in C++. Tasks persist to a local `tasks.json` file.

## Requirements

- CMake 3.14+
- C++17 compiler (Clang / GCC)

## Build

```bash
cd todo-cli
cmake -B build -G "Unix Makefiles"
cd build && make
```

The `todo` binary is placed in the `build/` directory.

## Usage

```
todo <command> [args]
  add <title>      Add a new task
  ls               List tasks
  done <id>        Toggle complete
  rm <id>          Remove task
  edit <id> <txt>  Edit task title
```

### Examples

```bash
./todo add Buy groceries
./todo add "Fix the build"
./todo ls
./todo done 1
./todo edit 2 Buy groceries and cook dinner
./todo rm 2
```

## Data

Tasks are stored in `tasks.json` in the directory where the binary is run.
