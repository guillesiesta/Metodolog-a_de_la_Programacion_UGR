#include <cstdlib>
#include "procesar.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argv[1] != 0 && argv[2] != 0) {
        const int MAXBUFFER = 1000000;
        const int MAX_respuesta = ((MAXBUFFER / 8) - 8);
        unsigned char buffer[MAXBUFFER];
        char respuesta[MAX_respuesta];
        cin.read(respuesta,MAX_respuesta);
        
        int resultadoEscribir = ocultar(buffer, respuesta, MAXBUFFER, argv[1], argv[2]);

        switch (resultadoEscribir) {
            case 0:
                cout << "\n\t El mensaje se ha imprimido correctamente. \n";
                break;
            case 1:
                cout << "\n\t ERROR: El tamano del mensaje es mayor que el del buffer. \n";
                break;
            case 2:
                cout << "\n\t ERROR: La imagen introducida es de tipo no válido o desconocido. \n";
                break;
            case 3:
                cout << "\n\t ERROR: No se ha podido escrbir en el fichero de destino. \n";
                break;
            default:
                cout << "\n\t ERROR DESCONOCIDO: El mensaje NO se ha imprimido correctamente. \n";
                break;
        }


    } else {
        cout << "ERROR: Los parametros introducidos no son los correctos." << endl;
    }

    return 0;
}
