CC = g++
CFLAGS = -c -std=c++11 -Wall
OBJFILES = sandbox.o bit_tools.cc token_triple.cc \
		   list.cc search_buffer.cc
TARGET = run

all:$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)

sandbox.o: sandbox.cc
	$(CC) $(CFLAGS) sandbox.cc

bit_tools.o: bit_tools.cc
	$(CC) $(CFLAGS) bit_tools.cc

token_triple.o: token_triple.cc
	$(CC) $(CFLAGS) token_triple.cc 

list.o: list.cc
	$(CC) $(CFLAGS) list.cc 

search_buffer.o: search_buffer.cc
	$(CC) $(CFLAGS) search_buffer.cc 

clean:
	rm -f $(OBJFILES) $(TARGET)