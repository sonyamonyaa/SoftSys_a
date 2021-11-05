CC=gcc
AR=ar
OBJ_MAIN=main.o
OBJ_LOOP=advancedClassificationLoop.o
OBJ_REC=advancedClassificationRecursion.o
OBJ_BASIC=basicClassification.o
FLAGS= -Wall -g
all: mains maindrec maindloop
mains: $(OBJECTS_MAIN) recursives 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm
maindloop: $(OBJECTS_MAIN) loopd
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm
maindrec: $(OBJECTS_MAIN) recursived
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm
loopd: $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_LOOP)
recursived: $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_REC)
	$(CC) -shared -o libclassrec.so $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_REC)
loops: $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_LOOP)
	$(AR) -rcs libclassloops.a $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_LOOP)
recursives: $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_REC)
	$(AR) -rcs libclassrec.a $(OBJ_MAIN) $(OBJ_BASIC) $(OBJ_REC)
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

