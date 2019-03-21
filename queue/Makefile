objects = main.o queue.o
queue_test : $(objects)
	gcc -o queue_test $(objects)

main.o: queue.h
queue.o: queue.h

.PHONY: clean
clean:
	-rm  $(objects) queue_test
