SERVER=echo-server
CLIENT=echo-client
CPPFLAGS+=-Wall -O2
LDLIBS+=-pthread

all: $(SERVER) $(CLIENT)

$(SERVER): echo-server.o 
	g++ $^ $(LOADLIBES) $(LDLIBS) -o $@

$(CLIENT): echo-client.o
	g++ $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET) *.o
	rm $(SERVER) $(CLIENT)
