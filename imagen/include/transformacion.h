/**
  * @file transformar.h
  * @brief Mediante el cual según nuestra elección aplicaremos memoria dinámica o no
  *
  * 
  * 
  */
#include <fstream>

using namespace std;
#define CUAL_COMPILO 1

#if CUAL_COMPILO==1
  #include "transformacion1.h"
#elif CUAL_COMPILO==2
  #include "transformacion2.h"
#endif
