CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

STUDENT_SRC = ../../src/student
TARGET = test01

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) \
		$(STUDENT_SRC)/LinkedList.cpp \
		main.cpp \
		-o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
