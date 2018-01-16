/**
  * @file transformacion2.h
  * @brief Fichero que contiene la clase transformación dinámica.
  *
  * Incluye los métodos y atributos, públicos y privados.
  * 
  */
#include <fstream>
using namespace std;


#ifndef _TRANSFORMACION_2_
#define _TRANSFORMACION_2_
using namespace std;

class Transformacion{

private:
	int reservados = 256;
	int n;
	int *datos;
/**
  * @brief formato
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de transformaciones que se pueden manejar.
  *
  */
	enum formato {TRF_DESCONOCIDO, TRF_TXT, TRF_BIN};
/**
  * @brief Ampliar
  *
  * Duplica el espacio de la memoria
  *
  */
	void Ampliar();
/**
  * @brief Copiar
  *
  * Copia una transformación en otra
  * @param vd es el vector donde se copiara la transformación.
  */	
	void Copiar(const Transformacion &vd);
/**
  * @brief Borrar
  *
  * Libera el espacio en la memoria
  *
  */
	void Borrar();

public:
/**
  * @brief Transformacion
  *
  * Constructor por defecto de la clase Transformacion
  *
  */
	Transformacion();                                       //Constructor por defecto
/**
  * @brief Transformacion
  *
  * Constructor por parámetro de la clase Transformacion
  * @param tam es el tamaño del nuevo vector dinámico
  */
	Transformacion(int tam);								//Constructor parametrizado
/**
  * @brief Transformacion
  *
  * Constructor copia de la clase Transformacion
  * @param vd es el vector transformacion donde se copiara
  */
	Transformacion(const Transformacion & vd);				//Constructor copia
/**
  * @brief ~Transformacion
  *
  * Destructor de la clase transformacion
  */
	~Transformacion();										//Destructor
	Transformacion & operator=(const Transformacion & vd);  //Operador asignacion
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
	void Insertar(int pos, int nuevo);
	void Eliminar(int pos);
	//int & operator[](int pos)const;
	const int & operator[](int pos)const;
	Transformacion operator+(const Transformacion & v);     //Operador +
	Transformacion operator+(int a); 						//Operador +
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
/**
  * @brief LeerTransformacion
  *
  * Lee la transformacion y la guarda.
  *
  * @param cadena es el nombre del archivo a leer.
  */
	bool LeerTransformacion(const char cadena[]);
	bool Transformacion::operator==(const Transformacion &v);
	bool Transformacion::operator!=(const Transformacion &v);
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
