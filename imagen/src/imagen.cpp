#include "imagen.h"
#include <iostream>
using namespace std;

Imagen::Imagen(){
	filas = 0;
	columnas = 0;
	punteroBuffer = new unsigned char[filas*columnas];	

}

// _____________________________________________________________________________

Imagen::Imagen(int f, int c) {
    filas = f;
    columnas = c;
    punteroBuffer = new unsigned char[filas * columnas];
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            Set(f, c, 0);
        }
    }
}

// _____________________________________________________________________________

Imagen::Imagen(const Imagen& img) {
    filas = img.Filas();
    columnas = img.Columnas();
    punteroBuffer = new unsigned char[filas * columnas];
    
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            Set(f, c, img.Get(f,c));
        }
    }
}

// _____________________________________________________________________________

int Imagen::Filas() const {
    return filas;
}

// _____________________________________________________________________________

int Imagen::Columnas() const {
    return columnas;
}

// _____________________________________________________________________________

void Imagen::Set(int i, int j, unsigned char v) {
    punteroBuffer[(i*columnas)+(j+1)] = v;
}

// _____________________________________________________________________________

unsigned char Imagen::Get(int i, int j) const {
    return punteroBuffer[(i*columnas)+(j+1)];
}

// _____________________________________________________________________________

bool Imagen::LeerImagen(const char file[]){
	
	int f;
	int c;
	TipoImagen img;
	img = LeerTipoImagen(file,f,c);

	if(img != IMG_PGM){
			cout << "Tipo de imagen desconocido! No es PGM!";
			return false;
	}else if(img == IMG_PGM){
			//cout << "Es de tipo PGM!!"<<endl;
			delete[]punteroBuffer;
		
			filas = f;//Reconstruyo la imagen.
    		columnas = c;
    		punteroBuffer = new unsigned char[filas * columnas];
			/*Leer imagen PGM*/
			return LeerImagenPGM(file, f, c, punteroBuffer);

	}
	
	
    
}

// _____________________________________________________________________________

bool Imagen::EscribirImagen(const char file[]) const {
    return EscribirImagenPGM(file, punteroBuffer, filas, columnas);
}
