1: clean
	g++ -Wall main.cpp -o 1_main
	./1_main

2: clean
	g++ -Wall test.cpp -o 2_test
	./2_test

3: clean
	g++ -Wall example.cpp -o 3_example
	./3_example

clean:
	@rm -f 1_main
	@rm -f 2_test
	@rm -f 3_example