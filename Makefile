all:
	make clean
	g++ main.cpp rivers.cpp -o rivers
	./rivers

clean:
	rm -f rivers
	rm -f tests

test:
	make clean
	g++ tests.cpp rivers.cpp -o tests
	./tests