CPPFLAGS=
CPP=g++
LD=g++
LDFLAGS=
OBJS=main.o jacobian_theta_functions.o theta_functions.o
BIN=jacobi_theta

ALL: $(BIN)

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(BIN)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) $(OBJS)