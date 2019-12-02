CXX=g++
CXXFLAG2= -std=c++11 -g -fprofile-arcs -ftest-coverage
CXXFLAGS= -std=c++11 -g

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

BRUTE = brute
BRUTEC = bruteforce.cpp

CREATE = create
CREATEC = create.cpp

DIVIDE = divide
DIVIDEC = divideconquer.cpp

.PHONY: all
all:

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ *.gcov *.gcda *.gcno \
	$(BRUTE) $(CREATE) $(DIVIDE) \
	obj bin \
	output/* \

$(BRUTE):
	$(CXX) $(CXXFLAGS) ${INCLUDE} -o $(BRUTE) $(BRUTEC)

$(CREATE):
	$(CXX) $(CXXFLAGS) ${INCLUDE} -o $(CREATE) $(CREATEC)

$(DIVIDE):
	$(CXX) $(CXXFLAGS) ${INCLUDE} -o $(DIVIDE) $(DIVIDEC)
