####Variables####
#Compiler
CXX = g++

#Language version
CXXFLAGS = -std=c++0x

#Enforces standard
CXXFLAGS += -pedantic-errors

#Debug information
CXXFLAGS += -g


####Files####
#Source Files
SRC1 = changeSlow.cpp


#Executable files
PROG1 = proj2Slow
PROGS = ${PROG1}


####Build####
all: ${PROG1}

example: all
	./proj2Slow amountSlow.txt
	
${PROG1}: ${SRC1}
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PROG1}
	
clean:
	rm ${PROGS} amountSlowchange.txt 
