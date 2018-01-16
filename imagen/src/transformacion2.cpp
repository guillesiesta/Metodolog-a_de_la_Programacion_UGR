#include "transformacion2.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


//----------------------------------------------------------------------------------
void Transformacion::Copiar(const Transformacion &vd){
	reservados = vd.reservados;
	n = vd.n;
	datos = new int[reservados];
	for(int i=0; i<n; i++){
		datos[i] = vd.datos[i];
	}
}

//---------------------------------------------------------------------------------
void Transformacion::Borrar(){
	if(datos!=0)
		delete[]datos;
	
}

//Constructor por defecto----------------------------------------------------------
Transformacion::Transformacion(){
	reservados = 256;
	n=0;
	datos = new int[reservados];
}

//---------------------------------------------------------------------------------
Transformacion::Transformacion(int tam){
	reservados = tam;
	n=0;
	datos = new int[reservados];
}
//Constructor copia----------------------------------------------------------------
Transformacion::Transformacion(const Transformacion &vd){
		Copiar(vd);
}
//Destructor-----------------------------------------------------------------------
Transformacion::~Transformacion(){
	Borrar();
}

//---------------------------------------------------------------------------------
Transformacion & Transformacion::operator=(const Transformacion & vd){
	if(this != &vd){
		Borrar();
		Copiar(vd);	
	}
	return *this;
}
//---------------------------------------------------------------------------------
int Transformacion::size()const{
	return 256;
}
//---------------------------------------------------------------------------------
int Transformacion::Get(int pos)const{
	return datos[pos];
}
//---------------------------------------------------------------------------------
void Transformacion::Set(int pos, int nuevo){
	datos[pos] = nuevo;
}
//---------------------------------------------------------------------------------
void Transformacion::Insertar(int pos, int nuevo){
	if(n=reservados)  //no tenemos memoria
		Ampliar();
	for(int i=n; i>pos; i--)
		datos[i] = datos[i-1];
	datos[pos]= nuevo;
	n++;
}
//---------------------------------------------------------------------------------
void Transformacion::Ampliar(){
	reservados = reservados *2;
	int *aux = new int[reservados];
	for(int i=0; i<n; i++)
		aux[i] = datos[i];
	delete[]datos;
	datos = aux;
}
//---------------------------------------------------------------------------------
void Transformacion::Eliminar(int pos){
	for(int i=pos; i<n-1; i++)
		datos[i] = datos [i+1];

	n--;
}
//---------------------------------------------------------------------------------
/*int Transformacion::operator[](int pos)const{
	return datos[pos];
}*/
//---------------------------------------------------------------------------------
const int & Transformacion::operator[](int pos)const{
	return datos[pos];
}
//---------------------------------------------------------------------------------
Transformacion Transformacion::operator+(const Transformacion & v){
	int mayor = (n > v.n) ? n: v.n;
	Transformacion vout(mayor);
	for(int i=0; i<mayor; i++){
		if(i<v.n && i<n){
			vout.datos[i] = datos[i] + v.datos[i];
		}else if(i<v.n){
 			vout.datos[i] = v.datos[i];	
		}else{ //i<n
			vout.datos[i] = datos[i];
		}

	}

	return vout;
}

//---------------------------------------------------------------------------------
Transformacion Transformacion::operator+(int a){
	Transformacion vout(*this);
	for(int i=0; i<n; i++)
		vout.datos[i]+=a;
	return vout;
}

//---------------------------------------------------------------------------------
friend ostream & operator<<(ostream &os, const Transformacion &v){
	os << v.n << endl;
	for(int i=0; i<v.n; i++)
		os << v.datos[i] << ' ';
	
	return os;

}

//---------------------------------------------------------------------------------
friend istream & operator>>(istream &is, Transformacion &v){
	int nele;
	is >> nele;
	Transformacion vl(nele);
	for(int i=0; i<nele; i++){
		int a;
		is >> a;
		vl.Insertar(i,a);
	}
	v = vl;
	return is;
}
//---------------------------------------------------------------------------------
bool Transformacion::operator==(const Transformacion &v){
	if(this->n != v.n)
		return false;
	for(int i=0; i<this->n; i++){
		if(datos[i]!=v.datos[i])
			return false;
	}

	return true;
}
//---------------------------------------------------------------------------------
bool Transformacion::operator !=(const Transformacion &v){
	return !(*this==v);
}
//---------------------------------------------------------------------------------
Transformacion::formato Transformacion::LeerTipo(ifstream& f){
	char magica[9];
	formato trf= TRF_DESCONOCIDO;
	
	if(f){
		f.read(magica,8); //leo los primeros 8 primeros caracteres del archivo.
		magica[8]='\0';
		
		if(strcmp(magica,"MP-TRF-T")==0){
			trf = TRF_TXT;
		}else if(strcmp(magica,"MP-TRF-B")==0){
			//cout << "Es de tipo BINARIO. Cadenas comparadas T2" << endl;
			trf = TRF_BIN;
		}
		
	}

	return trf;
	
}
//---------------------------------------------------------------------------------

Transformacion::formato Transformacion::LeerTipoTRF(const char cadena[]){ 
	ifstream f(cadena);
	return LeerTipo(f);	

}
//---------------------------------------------------------------------------------

bool Transformacion::LeerTransformacion(const char cadena[]){
	
	formato t = TRF_DESCONOCIDO;
	//Transformacion tr(256);
	bool exito = false;

	t = LeerTipoTRF(cadena);

	switch(t){
		case TRF_DESCONOCIDO:
		{
			cout << "ERROR! La transformacion es de tipo desconocido" << endl;
			exito = false;
		}
		break;

		case TRF_TXT:
		{
			ifstream f(cadena);

			if(!f){
				cerr << "No se puede leer el fichero TXT: " << cadena << endl;
			}else{
				f.ignore(8,'\0');
				int n;
				int pos=0;
				while(f>>n){
					Set(pos,n);
					//cout << n << endl
					pos++;
				}
				/*for(int i=0; i<=256; i++){
					cout <<"\nTrans "<<i<<": "<< Get(i) << endl;
				}*/
				exito = true;
			}
 		}
		break;

		case TRF_BIN:
		{
				//cout << "Es de tipo BINARIO T2" << endl;
				ifstream g(cadena, ios::in|ios::binary);
				if(!g){
					cerr << "No se puede leer el fichero Binario" << cadena << endl; 
					return 0;				
				}
				g.ignore(8,'\n');
				int n;
				g>>n;
				int dat[n];
				g.read(reinterpret_cast<const char *>(dat), sizeof(int)*n);
		
				for(int i=0; i<n; i++){
					Set(i,dat[i]);
					//cout << Get(i) << endl;
					//cout <<"i:"<<i << " = "<< dat[i] << endl;
				}			
				//cout <<"n vale: "<<n << endl;
			
				exito = true;
		}
		break;

	}//Fin del switch
	
	return exito;
}


//---------------------------------------------------------------------------------

bool Transformacion::EscribirTransformacion(const char cadena[], int modo){
	
	ofstream f1(cadena);
  	bool exito = true;

	if(modo==0){ //modo binario
		ofstream f1(cadena, ios::out|ios::binary);
		f1 << "MP-TRF-B 256" << endl;
		if(!f1){
			cerr << "Error no se puede escribir la transformacion de tipo Binario" << endl;
			return 0;
		}

		f1.write(reinterpret_cast<const char *>(v),sizeof(int)*256);
		f1.close();
		
		exito = true;
	
	}else if (modo==1){ //modo texto
		
		//cout << "MODO TEXTO Escribir" <<endl;
		ofstream f2(cadena,ios::out);

		f2 << "MP-TRF-T 256" << endl;
		if(!f2){
			cerr << "Error no se puede escribir la transformacion de tipo Texto" << endl;
			return 0;
		}

		for(int i=0;i<256;i++){
			f2 << v[i] << endl;
		}
		
		f2.close();

		exito = true;
	}

	
	
	
}

//---------------------------------------------------------------------------------
