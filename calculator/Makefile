     .PHONY: all clean

     CXX = g++
     CXXFLAGS = -Wall -g
     EXEC = calculator
     SOURCE = calculator.cpp

     all: $(EXEC)

     $(EXEC): $(SOURCE)
         $(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXEC)

     clean:
         rm -f $(EXEC)
     
