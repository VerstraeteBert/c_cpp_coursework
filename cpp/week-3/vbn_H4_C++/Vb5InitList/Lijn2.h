#ifndef LIJN2_H
#define LIJN2_H

#include "Punt.h"

class Lijn2 {

   public:
      Lijn2(); 
      Lijn2(int, int, int, int);
      Lijn2(const Punt &, const Punt &);
      void print() const;
   
   private:
      Punt p1, p2;
};

#endif
