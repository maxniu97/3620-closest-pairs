CXX=g++
CXXFLAG2= -std=c++11 -g -fprofile-arcs -ftest-coverage
CXXFLAGS= -std=c++11 -g

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

BRUTE = brute

MAINC = bruteforce.cpp

.PHONY: all
all: 

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ *.gcov *.gcda *.gcno \
	$(BRUTE) \
	obj bin \

$(BRUTE):
	$(CXX) $(CXXFLAGS) ${INCLUDE} -o $(BRUTE) $(MAINC)

