build:
	g++ main.cpp rivers.cpp -o rivers

run:
	./rivers

test:
	g++ tests.cpp rivers.cpp -o tests
	./tests

pack:
	dpkg-deb --build river-pkg river-pkg.deb