# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = leaderboard.exe

# Source files in src/ folder
SOURCES = src/main.cpp src/user.cpp src/database_simulated.cpp

# Object files (change path for Windows)
OBJECTS = main.o user.o database_simulated.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile .cpp files to .o files (current directory)
main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

user.o: src/user.cpp
	$(CXX) $(CXXFLAGS) -c src/user.cpp -o user.o

database_simulated.o: src/database_simulated.cpp
	$(CXX) $(CXXFLAGS) -c src/database_simulated.cpp -o database_simulated.o

# Clean up (Windows compatible)
clean:
	del /Q *.o $(TARGET) 2>nul || exit 0

# Run the program
run: $(TARGET)
	$(TARGET)

# Phony targets
.PHONY: all clean run