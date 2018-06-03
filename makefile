CC = g++
CFLAGS = -c -std=c++11 -Wall
OBJFILES = bit_tools.o token_triple.o \
		   list.o search_buffer.o tests.o
TARGET = run

all:$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)


bit_tools.o: bit_tools.cc
	$(CC) $(CFLAGS) bit_tools.cc

token_triple.o: token_triple.cc
	$(CC) $(CFLAGS) token_triple.cc 

list.o: list.cc
	$(CC) $(CFLAGS) list.cc 

search_buffer.o: search_buffer.cc
	$(CC) $(CFLAGS) search_buffer.cc 

tests.o: tests.cc
	$(CC) $(CFLAGS) tests.cc 


clean:
	rm -f $(OBJFILES) $(TARGET)