CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 $(INC_DIRS)

LIBS = 
TARGETS = broken_bank
OBJS = *.o
NON_MAIN = 
INC_DIRS = -I.

all: broken_bank

broken_bank: broken_bank.o $(NON_MAIN)
	$(CXX) -o broken_bank broken_bank.o $(NON_MAIN) $(LIBS)

clean:
	rm -f $(OBJS) $(TARGETS)
