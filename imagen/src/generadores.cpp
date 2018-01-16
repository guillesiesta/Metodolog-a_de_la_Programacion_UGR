#include <cstdlib>
#include "procesar.h"
#include "imagen.h"
#include "imagenES.h"
#include "transformacion.h"
#include <string.h>

using namespace std;


void Negativo(Transformacion &t){
	
	for(int i=0; i<256; i++){
		t.Set(i, 255 - i);
	}


}

void Desplazar(Transformacion &t, int n){
	
	for(int i=0; i<256; i++){
		t.Set(i, i<<n);
	}


}
void Umbralizar(Transformacion &t, int n){
	
	for(int i=0; i<256; i++){
		if(n >= i){
			t.Set(i,0);
		}else{
			t.Set(i,255);	
		}
	}


}
void Brillo(Transformacion &t, int n){
		
	for(int i=0; i<256; i++){
		if( n + i < 0){
			t.Set(i,0);
		}else if( n + i > 255 ){
			t.Set(i,255);
		}else{
			t.Set(i, i+n);
		}
	} 

}

