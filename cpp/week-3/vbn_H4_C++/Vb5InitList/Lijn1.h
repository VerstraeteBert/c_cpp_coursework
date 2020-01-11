#ifndef LIJN1_H
#define LIJN1_H

#include "Punt.h"

class Lijn1 {

   public:
      Lijn1(); 
      Lijn1(int, int, int, int);
      Lijn1(const Punt &, const Punt &);
      void print() const;
   
   private:
      Punt p1, p2;
};

#endif
