# Makefile for Homework 0.25 | CSCI 2410 | GWU
# 
# this Makefile supports the following commands:
## make: to build the sort executable
## make tests: to run tests after building the sort executable
## make clean: to remove object files and executable

CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = sort.o helper_functions.o sorting_function.o
TARGET = sort
TEMP = sols/
.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c sorting_function.h helper_functions.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(OBJ) $(TARGET) $(TEMP)
tests: $(TARGET)
	mkdir -p tests/test_outputs
	@ for file in tests/*.txt; do \
		echo "--------------------------------"; \
		echo "Test: $$file\n"; \
		output_a_file=tests/test_outputs/$$(basename $$file).a; \
		output_d_file=tests/test_outputs/$$(basename $$file).d; \
		./$(TARGET) a $$file $$output_a_file; \
		./$(TARGET) d $$file $$output_d_file; \
		echo "Output ASCENDING: $$output_a_file\n"; \
		echo "Output DESCENDING: $$output_d_file\n"; \
		echo "--------------------------------"; \
	done

frame:
	gcc test_script.c sorting_function.c helper_functions.c -o test_script -I .