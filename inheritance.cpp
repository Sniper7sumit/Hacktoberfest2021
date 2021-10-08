#include <iostream>
using namespace std;

class Triangle{
    public:
        void triangle(){
            cout<<"I am a triangle\n";
        }
};

class Isosceles : public Triangle{
    public:
        void isosceles(){
            cout<<"I am an isosceles triangle\n";
        }
};

class Equilateral : public Isosceles{
    public:
    void equilateral(){
        cout << "I am an equilateral triangle" << endl;
    }
        
};

int main(){
  
    Equilateral*eqr ;
    Equilateral obj_E;

    Isosceles*isr ;
    Isosceles obj_I;

    Triangle*tri ;
    Triangle obj_T;

    eqr = &obj_E;
    eqr->equilateral();
    
    isr = &obj_I;
    isr->isosceles();

    tri = &obj_T;
    tri->triangle();

    return 0;
}
