# Soccer Players Management System

A comprehensive C programming project that implements a complete soccer player management system with advanced data structures, memory management, and utility functions.

## 🚀 Features

- **Player Management**: Create, clone, and manage soccer player profiles
- **Data Structures**: Custom implementations for integers and doubles arrays
- **Memory Management**: Advanced memory allocation with leak detection
- **File I/O**: Read player data from files and standard input
- **Search & Filter**: Multiple search algorithms for players by various criteria
- **Position System**: Support for all soccer positions (Goalkeeper, Defense, Midfield, Forward)

## 🏗️ Project Structure

```
players/
├── jogador.h          # Player data structure and function declarations
├── jogador.c          # Player management implementation
├── our_ints.h         # Custom integer array utilities
├── our_ints.c         # Integer array implementation
├── our_doubles.h      # Custom double array utilities
├── our_doubles.c      # Double array implementation
├── leaks_checker.h.c  # Memory leak detection system
├── jogadores.txt      # Sample player data file
└── README.md          # This file
```

## 🎯 Core Components

### Player Management (`jogador.h/c`)
- **Player Structure**: Stores player information (name, birth year, position, caps, goals, club)
- **Constructor/Destructor**: Memory-safe player creation and cleanup
- **Player Operations**: Clone players, add international caps, update statistics
- **I/O Functions**: Read players from files and standard input
- **Search Functions**: Find players by name, club, or statistics

### Utility Libraries
- **`our_ints`**: Comprehensive integer array manipulation library
- **`our_doubles`**: Advanced double array operations and statistics
- **`leaks_checker`**: Memory leak detection and reporting system

## 📊 Data Format

Players are stored with the following structure:
```
FirstName   LastName   BirthYear   Position   Caps   Goals   Club
```

Example:
```
Cristiano  Ronaldo    1985        Avancado   196    118     Al Nassr
Bruno      Fernandes  1994        Medio      53     13      Manchester United
```

## 🛠️ Building and Running

### Prerequisites
- GCC compiler
- Make (optional)

### Compilation
```bash
# Compile the main player system
gcc -c jogador.c -o jogador.o

# Compile utility libraries
gcc -c our_ints.c -o our_ints.o
gcc -c our_doubles.c -o our_doubles.o

# Link all objects
gcc jogador.o our_ints.o our_doubles.o -o players_system
```

### Running
```bash
# Run with sample data
./players_system < jogadores.txt

# Interactive mode
./players_system
```

## 🔍 Available Functions

### Player Management
- `jogador()` - Create new player
- `free_jogador()` - Free player memory
- `jogador_dup()` - Clone player
- `adiciona_internacionalizacao()` - Add international cap

### Search & Filter
- `pesquisa_jogador()` - Find player by name
- `pesquisa_melhor_marcador()` - Find top scorer
- `pesquisa_jogadores_clube()` - Filter by club
- `pesquisa_jogadores_inter()` - Filter by international caps range

### I/O Operations
- `get_jogadores()` - Read from standard input
- `get_jogadores_from_file()` - Read from file
- `println_jogador()` - Display player information
- `println_jogadores()` - Display multiple players

## 🧪 Testing

The project includes comprehensive testing functions:
- `test_Jogador_File_Loading()` - Test file loading functionality
- `test_Jogador_Sorting()` - Test sorting algorithms
- `test_Jogador_Pesquisa()` - Test search functions

## 💾 Memory Management

- **Automatic Memory Allocation**: Safe memory management for strings
- **Leak Detection**: Built-in memory leak checker
- **Deep Copying**: Proper cloning of complex data structures
- **Resource Cleanup**: Automatic cleanup of allocated resources

## 🎨 Code Quality

- **Clean Architecture**: Well-structured header and implementation files
- **Comprehensive Documentation**: Detailed function documentation in Portuguese
- **Error Handling**: Robust error checking and validation
- **Modular Design**: Separated concerns for maintainability

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 👨‍💻 Author

**Brandon Mejia** - [GitHub Profile](https://github.com/kanekitakitos)

## 🙏 Acknowledgments

- Pedro Guerreiro for the utility library foundations
- C programming community for best practices and examples

---

⭐ **Star this repository if you find it helpful!**
