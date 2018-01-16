/**
  * @file transformacion1.h
  * @brief Fichero que la clase transformación estática.
  *
  * Incluye los métodos y atributos, públicos y privados.
  * 
  */
#include <iostream>
#include <fstream>

#ifndef _TRANSFORMACION_1_
#define _TRANSFORMACION_1_

using namespace std;

class Transformacion{

private:
/**
  * @brief vector estático
  *
  * Declara un vector estático inicializado en 256
  *
  */
	int v[256];
	int n;
/**
  * @brief formato
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de transformaciones que se pueden manejar.
  *
  */
	enum formato {TRF_DESCONOCIDO,
						TRF_TXT,
						TRF_BIN};
/**
  * @brief LeerTipo
  *
  * Lee el tipo de la imagen pasándole el flujo.
  *
  * @param f es el flujo que le pasamos una vez leído el archivo en LeerTipoTRF.
  * @see LeerTipoTRF
  */
	formato LeerTipo(ifstream& f);
/**
  * @brief LeerTipoTRF
  *
  * Abrimos el flujo de la imagen.
  *
  * @param cadena es el nombre del archivo.
  */
	formato LeerTipoTRF(const char cadena[]);
public:
/**
  * @brief size
  *
  * Devuelve el tamaño del vector
  *
  */
	int size()const;
/**
  * @brief Get
  *
  * Devuelve el contenido de una posición del vector transformación.
  *
  * @param pos es la posición que queremos buscar en el vector transformación. 
  */
	int Get(int pos)const;
/**
  * @brief Set
  *
  * Introduce un nuevo entero en una posición del vector transformación.
  *
  * @param pos es la posición que queremos buscar en el vector transformación.
  * @param nuevo es el nuevo valor a introducir en el vector transformación. 
  */
	void Set(int pos, int nuevo);
/**
  * @brief LeerTransformacion
  *
  * Lee la transformacion y la guarda.
  *
  * @param cadena es el nombre del archivo a leer.
  */
	bool LeerTransformacion(const char cadena[]);
/**
  * @brief operator<<
  *
  * Función friend para el operador <<
  *
  */
	friend ostream & operator<<(ostream &os, const Transformacion &v);
/**
  * @brief operator >>
  *
  * Función friend para el operador >>
  *
  */
	friend istream & operator>>(istream &is, Transformacion &v);
/**
  * @brief EscribirTransformacion
  *
  * Devuelve true en el caso de que la transformación haya sido leída correctamente.
  *
  * @param cadena es la cadena del nuevo archivo 
  * @param modo es el modo en el que se hará la escritura: 0 modo binario y 1 modo texto.
  */
	bool EscribirTransformacion(const char cadena[], int modo);
};

#endif
