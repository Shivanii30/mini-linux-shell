CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = mini-shell

SRC = src/main.cpp src/shell.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
