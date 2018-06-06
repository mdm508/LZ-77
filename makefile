CC = g++
CFLAGS = -c -std=c++11 -Wall
OBJFILES = token_triple.o list.o search_buffer.o bits.o misc.o LZ.o

TARGET = run

all:$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET)


token_triple.o: token_triple.cc
	$(CC) $(CFLAGS) token_triple.cc 

list.o: list.cc
	$(CC) $(CFLAGS) list.cc 

search_buffer.o: search_buffer.cc
	$(CC) $(CFLAGS) search_buffer.cc 

bits.o: bits.cc
	$(CC) $(CFLAGS) bits.cc

misc.o: misc.cc
	$(CC) $(CFLAGS) misc.cc

LZ.o: LZ.cc
	$(CC) $(CFLAGS) LZ.cc

clean:
	rm -f $(OBJFILES) $(TARGET)
