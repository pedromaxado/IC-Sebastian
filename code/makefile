CC = g++

CFLAGS =

RM = rm -f

VPATH = src

OBJS = Data.o CompatFunction.o Alg1.o Alg2.o AlgQT.o AlgT.o main.o

MAIN = main

$(MAIN): $(OBJS)
	@echo ""
	@echo " --- COMPILANDO PROGRAMA ---"
	@$(CC) $(CFLAGS) $(OBJS) -o $(MAIN)
	@echo ""

%.o: %.c %.h
	@echo " --- COMPILANDO OBJETO \"$@\""
	@$(CC) $(CFLAGS) $< -c

clean:
	$(RM) *.o *.gch

run: $(MAIN)
	./$(MAIN)
