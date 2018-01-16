/**
  * @file procesar.h
  * @brief Fichero que contiene distintos algoritmos con imágenes y transformaciones.
  *
  * Incluye algoritmos para ocultar/revelar un mensaje o para transformar una imagen.
  * 
  */
#include <iostream>
#include <cstring>
#include <string>
#include "imagen.h"
#include "imagenES.h"
#include "transformacion.h"

#ifndef _PROCESAR_H_
#define	_PROCESAR_H_
/**
  * @brief byteActivado
  *
  * Devuelve true en el caso de que el bit menos significativo de la imagen esté activado.
  *
  */
bool byteActivado(int numero1 ,int posiciones);
/**
  * @brief leerCadena
  *
  * Lee la cadena a introducir.
  *
  */
void leerCardena(char mensaje[], char respuesta1[100]);
/**
  * @brief ocultar
  *
  * Oculta el mensaje en la imagen.
  *
  *@param buffer Zona de memoria para obtener el valor de cada uno de los píxeles como un valor de gris desde la esquina superior izqda a la inferior drcha. 
  *@param mensaje es el mensaje que se insertará en la imagen
  *@param tam es el tamaño del buffer
  *@param nombre_imagen es el nombre de la imagen de entrada.
  *@param nombre_imagen es el nombre de la imagen de salida con el mensaje ocultado.
  *
  */
int ocultar(unsigned char buffer[], char mensaje[], int tam, char nombre_imagen[], char nombre_imagen2[]);
/**
  * @brief Revelar
  *
  * Revela el mensaje de la imagen.
  *
  *@param buffer Zona de memoria para obtener el valor de cada uno de los píxeles como un valor de gris desde la esquina superior izqda a la inferior drcha. 
  *@param mensaje1 es el mensaje que se revelará de la imagen
  *@param tamBuffer1 es el tamaño del buffer
  *
  */
int Revelar(unsigned char buffer[], char mensaje1[], int tamBuffer1, char nombre_imagen[]);
/**
  * @brief Transformar
  *
  * Aplica a una imagen la transformación.
  *
  *@param img es la imagen a la que aplicaremos la transformación
  *@param trf es la transformación que aplicaremos
  *
  */
void transformar(Imagen &img, Transformacion trf);

#endif	

