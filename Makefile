build:
	make clean
	g++ main.cpp rivers.cpp -o rivers

run:
	./rivers

test:
	g++ tests.cpp rivers.cpp -o tests
	./tests