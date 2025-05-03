PRODUCT = Drivetrain

# Compiler and flags
CC = g++
CPPFLAGS = -Iinclude
CXXFLAGS = -Wall -Werror -Wextra -pedantic -Wno-unused-parameter -O0 $(CPPFLAGS)
LDFLAGS = -lpthread

# Directories
BUILD_DIR = build
INC_DIR = include
SRC_DIR = src

# Files
SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES = $(wildcard $(INC_DIR)/*.hpp)
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCE_FILES))
TARGET = $(BUILD_DIR)/$(PRODUCT)

.PHONY: all clean

all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJECT_FILES) | $(BUILD_DIR)
	$(CC) $(OBJECT_FILES) -o $@ $(LDFLAGS)

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*
