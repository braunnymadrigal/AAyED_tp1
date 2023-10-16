#ifndef COLALSE_HH
#define COLALSE_HH


struct Caja {
	char elemento;
	Caja* siguiente;
};

class Cola {
	public:
		Cola();
		~Cola();
		
	  	void Iniciar(); //req:C no Init
	  	void Destruir(); //req:C init
	  	void Vaciar();   //req:C init
	  	bool Vacio();	 
	  	void Encolar(char);
	  	char Desencolar(); //req:C Init No Vacia
	  	char Frente();	   //req: C Init NO vacia
	 	Caja* getPrimero() { return primero;}

	private:
		Caja* primero;
		Caja* ultimo;		
};

#endif
