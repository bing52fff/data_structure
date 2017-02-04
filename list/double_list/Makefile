#Makefile

PRO=demo
SRC=demo.c double_list.c
OBJ=$(SRC:%.c=%.o)

FLAG=

.PHONY:all
all:$(PRO)

$(PRO):$(OBJ)
	gcc -o $@ $^
	
%.o:%.c
	gcc -c -o $@ $<

.PHONY:clean
clean:
	rm -rf $(OBJ) $(PRO)