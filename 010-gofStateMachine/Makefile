all: lockbox state_machine.png

lockbox: lockbox.cpp
	g++ -O0 -g -std=c++14 $< -o $@

state_machine.png: state_machine.dot
	dot -Tpng $< -o $@



clean:
	rm -vf lockbox state_machine.png *~
