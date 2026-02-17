


.PHONY all run run-file clean

TARGET = program
SOURCE = main.c stack.c sort_megre.c sort_insertion.c 

all:
	gcc $(SOURCE) -o $(TARGET)

run: $(TARGET)

	./$(TARGET)

benchmark: $(TARGET)
	@echo
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
	