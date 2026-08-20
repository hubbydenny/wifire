CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
CFLAGS   := -Wall -O2

CXXFLAGS += -Ideps/imgui -Ideps/imgui/backends -Ideps
CFLAGS   += -Ideps/imgui -Ideps/imgui/backends -Ideps

LDFLAGS  := -lglfw -lGL -lm -ldl -lpthread

IMGUI_DIR := deps/imgui

IMGUI_SRC := \
	$(IMGUI_DIR)/imgui.cpp \
	$(IMGUI_DIR)/imgui_draw.cpp \
	$(IMGUI_DIR)/imgui_tables.cpp \
	$(IMGUI_DIR)/imgui_widgets.cpp \
	$(IMGUI_DIR)/imgui_demo.cpp \
	$(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
	$(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

IMGUI_OBJ := $(IMGUI_SRC:.cpp=.o)

SRCS := src/wifire.cpp
OBJS := $(SRCS:.cpp=.o)
TARGET := wifire

all: $(TARGET)

$(TARGET): $(OBJS) $(IMGUI_OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(IMGUI_DIR)/%.o: $(IMGUI_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(IMGUI_DIR)/backends/%.o: $(IMGUI_DIR)/backends/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(IMGUI_OBJ) $(TARGET)

.PHONY: all clean
