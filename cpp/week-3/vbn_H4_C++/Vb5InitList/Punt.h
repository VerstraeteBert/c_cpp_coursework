#ifndef PUNT_H
#define PUNT_H

class Punt {
   public:
      Punt();
	  Punt(int, int);
	  Punt(const Punt &);
      void print() const;
      
   private:
   	  int x, y;
};

#endif
