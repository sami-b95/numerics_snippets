CPPFLAGS=
CPP=g++
LD=g++
LDFLAGS=-lmpfr -lmpc
OBJS=main.o
BIN=boost_multiprecision

ALL: $(BIN)

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(BIN)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) $(OBJS)