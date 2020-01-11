#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
  public:
    Rectangle(int w = 1, int h = 1) : width(w),height(h) {}
	int area() const {
	   return width * height;
	}
    void convert(const Square &a);
};

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square(int a) : side(a) {}
};

void Rectangle::convert(const Square &a) {
  width = a.side;
  height = a.side;
}
  
int main () {
  Rectangle rect(6,8);
  cout << rect.area() << endl;
  Square sqr(4);
  rect.convert(sqr);
  cout << rect.area();
  return 0;
}
