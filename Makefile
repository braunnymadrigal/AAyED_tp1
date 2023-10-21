all: compilar ejecutar

compilar:
	g++ main.cc interfaz.cc -o algoritmos
	
ejecutar:
	./algoritmos
