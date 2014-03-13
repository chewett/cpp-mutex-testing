CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 $(INC_DIRS)

LIBS = -pthread
TARGETS = test_broken_bank test_fixed_bank test_dining
OBJS = *.o
NON_MAIN = brokenbank.o fixedbank.o chopstick.o
INC_DIRS = -I.

all: broken_bank fixed_bank test_dining

broken_bank: test_broken_bank.o $(NON_MAIN)
	$(CXX) -o  test_broken_bank test_broken_bank.o $(NON_MAIN) $(LIBS)

fixed_bank: test_fixed_bank.o $(NON_MAIN)
	$(CXX) -o  test_fixed_bank test_fixed_bank.o $(NON_MAIN) $(LIBS)

test_dining: test_dining.o $(NON_MAIN)
	$(CXX) -o test_dining test_dining.o $(NON_MAIN) $(LIBS)

clean:
	rm -f $(OBJS) $(TARGETS)
