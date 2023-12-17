all: DataStructures

DataStructures: DataStructuresSub
	ar rcs libdatastructures.a Node.o LinkedList.o Queue.o BinarySearchTree.o Entry.o Dictionary.o

DataStructuresSub: Node LinkedList Queue BinarySearchTree Entry Dictionary

Node:
	gcc -c Node.c

LinkedList:
	gcc -c LinkedList.c

Queue:
	gcc -c Queue.c
	
BinarySearchTree:
	gcc -c BinarySearchTree.c

Entry:
	gcc -c Entry.c

Dictionary:
	gcc -c Dictionary.c

clean:
	rm *.o libdatastructures.a