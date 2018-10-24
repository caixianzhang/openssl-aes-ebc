CXX = g++
CXXFLAGS = -O2 -g -Wall
LDFLAGS = -lpthread -lssl -lcrypto 

OBJS = main.cpp

TARGET = module
$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	
.PHONY:clean
clean:
	rm -rf *.o $(TARGET) 