#include <cstdlib>
#include "procesar.h"
#include "imagen.h"
#include "imagenES.h"
#include "transformacion.h"


using namespace std;

int main(int argc, char* argv[]) {

if (argv[1] != 0 && argv[2] != 0 && argv[3] != 0) {
       
	const int MAXBUFFER = 1000000;
	unsigned char buffer[MAXBUFFER]; 
	bool leida = false;
	int filas;
	int columnas;
	//argv[1] = "lenna.pgm"
	//argv[2] = "carboncillo_txt.trf"
	//argv[3] = "lenna_carbon.pgm"

	Imagen img;
	Transformacion trf;
	
	leida = img.LeerImagen(argv[1]);

	/*if(leida){
		cout << "imagen leida correctaamente"<< endl;
	}else{
		cout << "imagen NOOOO leida correctaamente"<< endl;
	}*/

	trf.LeerTransformacion(argv[2]);		

	transformar(img, trf);

	img.EscribirImagen(argv[3]);
	
	/*if(img.LeerImagen(argv[1]) && trf.LeerTransformacion(argv[2])) {
		
		if(img.Filas() * img.Columnas() > MAXBUFFER){
			cout << "ERROR! Imagen demasiado grande \n" <<endl;
			return -1;
		}else{

			transformar(img, trf);

			bool hecho = img.EscribirImagen(argv[3]);

			cout << "Transformando..\n";	
			if(hecho){
			  cout << "¡Imagen transformada correctamente!";
			}else{
			  cout << "¡Imagen no transformada!";	
			}
		}	

	}else{   
			cout << "Imagen no leída correctamente";
	}//Fin del primer if
*/


}

}/*Fin del main----------------------------------------------------------------------*/
