# declarations
CC = g++
OBJ = binary_write.o

# Rules
make: binary_write.o
	$(CC) -o bin.x $(OBJ)

clean: 
	rm -vf $(OBJ) bin.x
	rm -vf file.*


run:
	./bin.x && du -sh * | grep file. && ./read.py

all: clean make run
