SOURCE  := $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))

TARGET  := myserver
CC      := g++
LIBS := -lpthread -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs # the lib of imgcodecs.hpp
INCLUDE := -I /usr/include/opencv4 # opencv include path in system
CFLAGS  := -std=c++11 -g -Wall -O3 $(INCLUDE)
CXXFLAGS:= $(CFLAGS)

.PHONY : objs clean veryclean rebuild all
all : $(TARGET)
objs : $(OBJS)
rebuild: veryclean all
clean :
	rm -fr *.o
veryclean : clean
	rm -rf $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)