CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = mini-shell

SRC = src/main.cpp src/shell.cpp src/mcp/mcp_server.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
