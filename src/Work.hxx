#ifndef _WORK_HXX_
#define _WORK_HXX_

//si aqui se pone "using namespace std", ya no hara falta poner std en el resto de sitios
using namespace std;

class Work {

private: std::string _title;

public:
	Work() //metodo constructor, mismo nombre de la clase
		: _title ("-- Untitled --") // manera de declarar valor para no hacerlo dos veces
	{
				//si se inicializase aqui, como en java, haria trabajo doble
	} 

		const std::string title() const { //si se pone const quiere decir que desde fuera no se puede cambiar el valor 
			return _title;
		}
		
		void title( const std::string &title) {
			_title = title;
		}
		
		 const int isbn() const{
            return 0;
        }
};

#endif
