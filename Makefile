TESTEXE=Test.exe
TEST=test.o
OBJS=vec4.o

all: $(TESTEXE) $(OBJS)

$(TESTEXE) : $(TEST) $(OBJS)
	g++ -o $(TESTEXE) $(TEST) $(OBJS)

%.o : %.cpp
	g++ $< -c
