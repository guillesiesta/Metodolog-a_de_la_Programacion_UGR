/**
  * @file imagen.h
  * @brief Fichero cabecera para almacenar las operaciones de la clase imagen
  *
  * 
  */
#include "imagenES.h"

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

class Imagen {
private:
    int filas;
    int columnas;
    unsigned char* punteroBuffer;
public:
/**
  * @brief Filas
  *
  * Devuelve el número de filas de la imagen
  *
  */
    int Filas() const;                                  // Devuelve el número filas de m
/**
  * @brief Columnas
  *
  * Devuelve el número de columnas de la imagen
  *
  */
    int Columnas() const;                               // Devuelve el número columnas de m
/**
  * @brief Set
  *
  * Introduce dentro dentro de un lugar específico de la imagen un valor
  * @param i es la posición de la fila
  * @param j es la posición en la columna 
  * @param v es el valor que introduciremos dentro de la posición (i,j)
  */
    void Set(int i, int j, unsigned char v);            // Hace img(i,j)=v
/**
  * @brief Get
  *
  * Devuelve el contenido de la posición (i,j) de la imagen
  *
  * @param i se refiere a la fila de la imagen
  * @param j se refiere a la columna de la imagen
  *
  */
    unsigned char Get(int i, int j) const ;             // Devuelve img(i,j)
/**
  * @brief LeerImagen
  *
  * Lee la imagen y la carga en el buffer
  *
  * @param file es el nombre de la imagen a leer
  *
  */
    bool LeerImagen(const char file[]);                 // Carga imagen file en img
/**
  * @brief EscribirImagen
  *
  * Escribe la imagen en disco
  *
  * @param file es el nombre de la imagen a escribir
  *
  */
    bool EscribirImagen(const char file[]) const;       // Salva img en file
/**
  * @brief Imagen
  *
  * Constructor por defecto de la clase imagen
  *
  */
    Imagen();                                           // Constructor por defecto
/**
  * @brief Imagen
  *
  * Constructor parametrizado de la clase imagen
  *
  * @param f es el número de filas con las que se inicializará la imagen
  * @param c es el número de columnas con las que se inicializará la imagen
  *
  */
    Imagen(int f, int c);                               // Constructor parametrizado
/**
  * @brief Imagen
  *
  * Constructor copia de la clase imagen
  *
  * @param img es la imagen donde se copiará la nueva inicialización.
  *
  */
    Imagen(const Imagen& img);                          // Constructor por copia
};
#endif
