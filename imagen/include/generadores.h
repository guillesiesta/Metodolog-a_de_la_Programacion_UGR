/**
  * @file generadores.h
  * @brief Fichero que contiene distintos métodos para transformaciones.
  *
  * Contiene las distintas funciones para realizar distintas transformaciones.
  *
  */
#include <fstream>
#include <transformacion.h>
using namespace std;


#ifndef _GENERADORES_
#define _GENERADORES_

/**
  * @brief Negativo
  *
  * Recibe por referencia una transformación y la negativiza
  *
  * @param t es la transformacion que pasamos por referencia
  */
void Negativo(Transformacion &t);
/**
  * @brief Desplazar
  *
  * Recibe por referencia una transformación y un entero para crear una transformacion que desplace píxeles.
  *
  * @param t es la transformacion que pasamos por referencia
  * @param n es el entero que recibe para desplazar "n" bits.
  */
void Desplazar(Transformacion &t, int n);
/**
  * @brief Umbralizar
  *
  * Recibe por referencia una transformación y un entero para crear una transformacion que umbralice la imagen.
  *
  * @param t es la transformacion que pasamos por referencia
  * @param n es el entero que recibe para saber el nivel de umbralización.
  */
void Umbralizar(Transformacion &t, int n);
/**
  * @brief Umbralizar
  *
  * Recibe por referencia una transformación y un entero para crear una transformacion que aumente o disminuya el brillo de
  * la imagen
  *
  * @param t es la transformacion que pasamos por referencia
  * @param n es el entero que recibe para aumentar o disminuir el brillo.
  */
void Brillo(Transformacion &t, int n);

#endif
