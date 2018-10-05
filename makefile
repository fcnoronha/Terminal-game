all:testador3000
 
testador3000: 
	gcc hashTable.c ListaValores.c testador3000.c -o testador3000
