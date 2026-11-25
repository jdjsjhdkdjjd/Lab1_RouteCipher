CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11
TARGET=lab1_alpha

all: $(TARGET)

$(TARGET): main.cpp routeCipher.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp routeCipher.cpp -lm

clean:
	rm -f $(TARGET)