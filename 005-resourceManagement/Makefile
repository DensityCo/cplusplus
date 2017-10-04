CC=g++ -O0 -g -std=c++14

all: scoping_example strings_no_leak temp_file_example

scoping_example: scoping_example.cpp
	$(CC) $< -o $@

strings_no_leak: strings_no_leak.cpp
	$(CC) $< -o $@

temp_file_example: temp_file_example.cpp
	$(CC) $< -o $@

clean:
	rm -vf *~ scoping_example strings_no_leak temp_file_example
