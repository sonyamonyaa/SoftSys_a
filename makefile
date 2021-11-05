CC=gcc
AR=ar
OBJ_MAIN=main.o
OBJ_LOOP=advancedClassificationLoop.o
OBJ_REC=advancedClassificationRecursion.o
OBJ_BASIC=basicClassification.o
FLAGS= -Wall -g
all: mains maindrec maindloop
#make all mains
mains: $(OBJ_MAIN) recursives 
	$(CC) $(FLAGS) -o mains $(OBJ_MAIN) libclassrec.a -lm
maindloop: $(OBJ_MAIN) loopd
	$(CC) $(FLAGS) -o maindloop $(OBJ_MAIN) ./libclassloops.so -lm
maindrec: $(OBJ_MAIN) recursived
	$(CC) $(FLAGS) -o maindrec $(OBJ_MAIN) ./libclassrec.so -lm
#dynamic
loopd: $(OBJ_BASIC) $(OBJ_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJ_BASIC) $(OBJ_LOOP)
recursived: $(OBJ_BASIC) $(OBJ_REC)
	$(CC) -shared -o libclassrec.so $(OBJ_BASIC) $(OBJ_REC)
#static
loops: $(OBJ_BASIC) $(OBJ_LOOP)
	$(AR) -rcs libclassloops.a $(OBJ_BASIC) $(OBJ_LOOP)
recursives: $(OBJ_BASIC) $(OBJ_REC)
	$(AR) -rcs libclassrec.a $(OBJ_BASIC) $(OBJ_REC)
#objects
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c 
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all 
clean:
	rm -f *.o *.a *.so mains maindrec maindloop

