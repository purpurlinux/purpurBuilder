CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cc \
          $(SRC_DIR)/config.cc \
          $(SRC_DIR)/kernel_builder.cc \
          $(SRC_DIR)/rootfs_builder.cc \
          $(SRC_DIR)/bootloader_builder.cc \
          $(SRC_DIR)/build_orchestrator.cc

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cc=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/distro_builder

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)