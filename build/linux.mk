# Mingw Makefile for RDBootUI2 LINUX

# C++ compiler
CXX = g++

# Targets name
TARGET = RDBootUI2_linux

# Source files
SRC = main.cpp

# Standard flags for C++
CXXFLAGS = -O3 -pipe

# Standard preprocessor flags (common for CC and CXX)
CPPFLAGS =

# Standard linker flags
LDFLAGS =

# Location and arguments of wx-config script
WX_CONFIG = wx-config

# C++ flags to use with wxWidgets code
WX_CXXFLAGS_1 = `$(WX_CONFIG) --static=yes --cxxflags`
WX_CXXFLAGS_2 = `$(WX_CONFIG) --static=yes --libs`

################################################################################

################################################################################

all:
	$(CXX) -c -o $(TARGET).o $(SRC) $(WX_CXXFLAGS_1)
	$(CXX) -o $(TARGET) $(TARGET).o $(WX_CXXFLAGS_2)
	mv $(TARGET).o obj/$(TARGET).o
	mv $(TARGET) bin/$(TARGET)
