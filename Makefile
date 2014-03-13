CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 $(INC_DIRS)

LIBS = 
TARGETS = test_broken_bank
OBJS = *.o
NON_MAIN = brokenbank.o
INC_DIRS = -I.

all: broken_bank

broken_bank: test_broken_bank.o $(NON_MAIN)
	$(CXX) -o  test_broken_bank test_broken_bank.o $(NON_MAIN) $(LIBS)

clean:
	rm -f $(OBJS) $(TARGETS)
