all:
	gcc -o toggledtr toggledtr.c

install:
	sudo cp -v toggledtr /usr/bin

clean:
	rm -v toggledtr
