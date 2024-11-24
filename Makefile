1: clean
	g++ -Wall test.cpp -o 1_test
	./1_test

2: clean
	g++ -Wall example.cpp -o 2_example
	./2_example

clean:
	@rm -f 1_test
	@rm -f 2_example