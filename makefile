all : storageitems.o master.o  
		gcc storageitems.o master.o -o master


storageitems.o : storageitems.c
		gcc -c storageitems.c -std=c99

master.o : master.c
		gcc -c master.c -std=c99 

