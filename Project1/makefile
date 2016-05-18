####Variables####
#Compiler
CXX = g++

#Language version
CXXFLAGS = -std=c++0x

#Turns on all warnings
#CXXFLAGS += -Wall

#Enforces standard
CXXFLAGS += -pedantic-errors

#Debug information
CXXFLAGS += -g


####Files####
#Source Files
SRC1 = proj1Test.cpp


#Executable files
PROG1 = proj1Test
PROGS = ${PROG1}


####Build####
all: ${PROG1}

${PROG1}: ${SRC1}
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PROG1}

clean:
	rm -f ${PROGS} *.o *~
