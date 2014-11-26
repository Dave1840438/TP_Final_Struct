// Classe permettant de calculer un temps d'exécution en microsecondes
// Merci à Francis Lemaire pour avoir trouvé le code brut à la source
// de cette classe.
//
// Usage : 
//   a) Instancier la classe
//   b) Faire appel à Start() pour démarrer le chrono
//   c) Faire appel à Stop() pour arrêter le chrono
//   d) Faire appel à Read() pour obtenir le temps calculé par le chrono
//      en microsecondes. 
//
// Note : on peut refaire Start(), Stop() et Read() pour obtenir une deuxième
//        lecture sans avoir à réinstancier la classe
//
// par Pierre Prud'homme, octobre 2014
//--------------------------------------------------------------------------------
#ifndef _CHRONO_H_
#define _CHRONO_H_
#include <Windows.h>

class Chrono
{
   LARGE_INTEGER StartingTime_;
   LARGE_INTEGER EndingTime_;
   LARGE_INTEGER ElapsedMicroseconds_;
   LARGE_INTEGER Frequency_;

public:
   Chrono()
   {
      QueryPerformanceFrequency(&Frequency_);
   }

   void Start()
   {
      QueryPerformanceCounter(&StartingTime_);
   }

   void Stop()
   {
      QueryPerformanceCounter(&EndingTime_);
   }

   LONGLONG Read()
   {
      ElapsedMicroseconds_.QuadPart = EndingTime_.QuadPart - StartingTime_.QuadPart;
      ////
      //// We now have the elapsed number of ticks, along with the
      //// number of ticks-per-second. We use these values
      //// to convert to the number of elapsed microseconds.
      //// To guard against loss-of-precision, we convert
      //// to microseconds *before* dividing by ticks-per-second.
      ////
      ElapsedMicroseconds_.QuadPart *= 1000000;
      ElapsedMicroseconds_.QuadPart /= Frequency_.QuadPart;
      return ElapsedMicroseconds_.QuadPart;
   }

};

#endif