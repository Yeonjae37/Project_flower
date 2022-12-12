all: PROJECT

PROJECT: flower.c
	gcc -o flower flower.c

clean:
	rm flower