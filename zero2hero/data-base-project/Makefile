TARGET = bin/dbview
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

run: clean default
				./$(TARGET) -f ./mynewdb.db -n
				./$(TARGET) -f ./mynewdb.db -a "Timmy H., Sheshire Ln.,120"
				./$(TARGET) -f ./mynewdb.db -a "Aldo Sierra., Sheshire Ln.,120"
				./$(TARGET) -f ./mynewdb.db -a "PENDEJI Sierra., Sheshire Ln.,120"
				./$(TARGET) -f ./mynewdb.db -r -i "1"
				./$(TARGET) -f ./mynewdb.db -e "Shinji Sierra., Sheshire Ln.,121" -i "1"

default: $(TARGET)

clean:
				rm -f obj/*.o
				rm -f bin/*
				rm -f *.db

$(TARGET): $(OBJ)
				gcc -o $@ $?

obj/%.o: src/%.c
				gcc -c $< -o $@ -Iinclude