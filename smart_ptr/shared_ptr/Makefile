SOURCE:=$(wildcard *.cpp)
TARGET:=$(basename $(SOURCE))

$(TARGET): $(SOURCE)
	g++ --std=c++14 $< -o $@

.phony: clean
clean:
	rm -rf $(TARGET)

