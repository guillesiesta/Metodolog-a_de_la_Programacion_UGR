#include <iostream>
#include <cstring>
#include "procesar.h"
#include "imagenES.h"
#include "imagen.h"
#include "transformacion.h"

using namespace std;

bool byteActivado(int numero1, int posiciones) {
    return (numero1 & (1 << posiciones) ? 1 : 0);
}

// _____________________________________________________________________________

int ocultar(unsigned char buffer[], char mensaje[], int tam, char nombre_imagen[], char nombre_imagen2[]) {
    //leo el tipo de imagen
    int filas, columnas;
    TipoImagen ti1 = LeerTipoImagen(nombre_imagen, filas, columnas);
    if (ti1 == IMG_PGM) {
        LeerImagenPGM(nombre_imagen, filas, columnas, buffer);
    } else {
        return 2;
    }

    //Segun el tipo de imagen...
    int salida = 0;

    cout << "Ocultando..." << endl;
    int i = 0;
    int tamcadena = strlen(mensaje);
    if (tamcadena <= tam) {
        for (int j = 0; j <= tamcadena; j++) {
            for (int k = 7; k >= 0; k--) {
                if (byteActivado(mensaje[j], k))
                    buffer[i] = buffer[i] | 1;
                else
                    buffer[i] = buffer[i]&(~1);
                i++;
            }
        }
    } else {
        salida = 1;
    }

    //Imprimo en el fichero
    bool imprimido;
    imprimido = EscribirImagenPGM(nombre_imagen2, buffer, filas, columnas);
    if (!imprimido) {
        salida = 3;
    }


    return salida;
}

// _____________________________________________________________________________

int Revelar(unsigned char buffer[], char mensaje1[], int tamBuffer1, char nombre_imagen[]) {
    //leo el tipo de imagen
    int filas, columnas;
    TipoImagen ti1 = LeerTipoImagen(nombre_imagen, filas, columnas);
    if (ti1 == IMG_PGM) {
        LeerImagenPGM(nombre_imagen, filas, columnas, buffer);
    } else {
        return 2;
    }

    int salida = 1; //Si no encuentra el caracter '\0'
    char caracter = '0';
    int byteActual = 0;
    int contCaracteres = 0;
    while (caracter != '\0' || byteActual <= tamBuffer1) {
        caracter = '0';
        //Para cada caracter . . . 
        for (int bit = 0; bit <= 7; bit++) {
            if (byteActivado(buffer[byteActual], 0)) {
                caracter = caracter << 1;
                caracter = caracter | 1;
            } else {
                caracter = caracter << 1;
            }

            if (bit == 7) {
                mensaje1[contCaracteres] = caracter;
                contCaracteres++;
            }

            if ((bit == 7) && (caracter == '\0')) {
                mensaje1[contCaracteres] = '\0';
                return 0; //Salida correcta
            }

            byteActual++;
        }
    }

    return salida;
    //Fin de la funcion.
}

void transformar(Imagen &img, Transformacion trf){

	int fila = img.Filas();
	int columna = img.Columnas();

	for (int i=0; i<fila; i++ ) {
            for (int j = 0; j < columna; j++) {
                img.Set(i,j, trf.Get(img.Get(i,j)));
            }
        }


}//FIN DE LA FUNCION TRANSFORMAR---------------------------------------------------------------
