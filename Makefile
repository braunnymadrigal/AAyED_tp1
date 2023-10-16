all: compilar ejecutar

compilar:
	#g++ main.cc colaLSE.cc arbolASP.cc interfaz.cc -o algoritmos
	#g++ main.cc colaLSE.cc arbolHMIHD.cc interfaz.cc -o algoritmos
	#g++ main.cc colaLSE.cc arbolHMIHD2.cc interfaz.cc -o algoritmos
	g++ main.cc colaLSE.cc arbolLSE.cc interfaz.cc -o algoritmos
	
ejecutar:
	./algoritmos