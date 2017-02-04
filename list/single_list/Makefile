#Makefile

PRO = demo
SRC = single_list.c demo.c
OBJ = $(SRC:%.c=%.o)

FLAG = 

$(PRO):$(OBJ)
	echo $(OBJ)
	gcc -o $@ $^ $(FLAG)
	
%.o:%.c
	gcc -c -o $@ $< $(FLAG)
	
.PHONY:clean
clean:
	rm $(OBJ) $(PRO) -rf