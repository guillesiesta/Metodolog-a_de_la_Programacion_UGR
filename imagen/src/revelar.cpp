#include <cstdlib>
#include "procesar.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argv[1] != 0) {
        const int MAXBUFFER = 1000000;
        const int MAX_respuesta = ((MAXBUFFER / 8) - 8);
        unsigned char buffer[MAXBUFFER];
        char mensaje1[MAX_respuesta];

        //Lectura de una foto
        int resultado = Revelar(buffer, mensaje1, MAXBUFFER, argv[1]);
        //cout << "Revelando..." << endl;
        switch (resultado) {
            case 0:
                //cout << "\n\t El mensaje obtenido es: \n";
                cout << mensaje1 << "\n";
                break;
            case 1:
                cout << "\n\t La imagen codificada no contiene ningún carácter terminador de cadena.  \n";
                break;
            case 2:
                cout << "\n\t Ha ocurrido un error. \n";
                break;
            default:
                cout << "\n\t ERROR DESCONOCIDO: No se ha leido le foto correctamente. \n";
                break;
        }
    } else {
        cout << "ERROR: Los parametros introducidos no son los correctos." << endl;
    }

    return 0;
}

