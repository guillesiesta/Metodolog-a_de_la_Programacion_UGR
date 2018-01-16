#include <cstdlib>
#include "procesar.h"
#include "imagen.h"
#include "imagenES.h"
#include "transformacion.h"
#include "generadores.h"
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
	
	int modo;

	if(argc==1){ //ningún parámetro
		cout << "Tienes estas posibilidades: "<< endl;
		cout << "\n1.-Negativo"<< endl;
		cout << "\n2.-Desplazamiento de bits"<< endl;
		cout << "\n3.-Umbralización"<< endl;
		cout << "\n4.-Brillo"<< endl;
	}else if(argc > 1){
				

					// argv[1] = b
					// argv[2] = negativo_bin.trf
					// argv[3] = negativo
					Transformacion trf;			
	

				    if(strcmp(argv[3],"negativo")==0){
						Negativo(trf);
						if(strcmp(argv[1],"b")==0){ 								//si el archivo es de tipo binario
							modo = 0;
							trf.EscribirTransformacion(argv[2], modo);
						}else if(strcmp(argv[1],"t")==0){ 							//si el archivo es de tipo texto
							modo = 1;
							trf.EscribirTransformacion(argv[2], modo);				
						}
						cout << "Negativo creado con exito!" << endl;
					}else{
						cout << "No se puede crear el negativo" << endl;
					}

					
					

					if(strcmp(argv[3],"desplazar")==0 && atoi(argv[4])!=0){
						if(atoi(argv[4])<0){
							cout << "El parámetro de desplazar no puede ser negativo!"<<endl;
						}else{

							Desplazar(trf,atoi(argv[4]));
							if(strcmp(argv[1],"b")==0){ 								//si el archivo es de tipo binario
								modo = 0;
								trf.EscribirTransformacion(argv[2], modo);
							}else if(strcmp(argv[1],"t")==0){ 							//si el archivo es de tipo texto
								modo = 1;
								trf.EscribirTransformacion(argv[2], modo);				
							}
							cout << "Desplazar creado con exito!" << endl;
						}
					}else{
						cout << "No se puede crear el desplazar" << endl;
					}
	
					
					if(strcmp(argv[3],"umbralizar")==0 && atoi(argv[4])!=0){
						
						if(atoi(argv[4])<0){
							cout << "El parámetro de umbralizar no puede ser negativo!"<<endl;				
						}else{
							Umbralizar(trf,atoi(argv[4]));
							if(strcmp(argv[1],"b")==0){ 								//si el archivo es de tipo binario
								modo = 0;
								trf.EscribirTransformacion(argv[2], modo);
							}else if(strcmp(argv[1],"t")==0){ 							//si el archivo es de tipo texto
								modo = 1;
								trf.EscribirTransformacion(argv[2], modo);				
							}
							cout << "Umbralizar creado con exito!" << endl;
						}
					}else{
						cout << "No se puede crear el umbralizar" << endl;
					}


					if(strcmp(argv[3],"brillo")==0 && atoi(argv[4])!=0){
						Brillo(trf,atoi(argv[4]));
						if(strcmp(argv[1],"b")==0){ 								//si el archivo es de tipo binario
							modo = 0;
							trf.EscribirTransformacion(argv[2], modo);
						}else if(strcmp(argv[1],"t")==0){ 							//si el archivo es de tipo texto
							modo = 1;
							trf.EscribirTransformacion(argv[2], modo);				
						}
						cout << "Brillo creado con exito!" << endl;
					}else{
						cout << "No se puede crear el brillo" << endl;
					}

		
		}
		


}//FIN DEL MAIN-----------------------------------------------------------------------------------------------
