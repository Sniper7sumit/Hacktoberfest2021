#include<iostream>
using namespace std;

class complex
{
private:
 int real,imaginary;
 public:
 complex()
 {

 }
complex(int a, int b)
{
real= a;
imaginary =b;

}
friend void operator+(complex &c, complex &d);
friend void operator-(complex &e, complex &f);
friend void operator*(complex &g, complex &h);
friend void operator/(complex &i, complex &k);

};
void operator+(complex &c, complex &d)
{
complex temp;
temp.real= c.real + d.real;
temp.imaginary = c.imaginary + d.imaginary;
cout<<"Real sum is     :  "<<temp.real<<endl;
cout<<"Imaginary sum is     :  "<<temp.imaginary<<endl;



}
void operator-(complex &e, complex &f)
{
complex temp;
temp.real= e.real - f.real;
temp.imaginary = e.imaginary - f.imaginary;
cout<<"Real sub is     :  "<<temp.real<<endl;
cout<<"Imaginary sub is     :  "<<temp.imaginary<<endl;



}

void operator*(complex &g, complex &h)
{
complex temp;
temp.real= g.real * h.real;
temp.imaginary = g.imaginary * h.imaginary;
cout<<"Real mul is     :  "<<temp.real<<endl;
cout<<"Imaginary mul is     :  "<<temp.imaginary<<endl;



}

void operator/(complex &i, complex &k)
{
complex temp;
temp.real= i.real / k.real;
temp.imaginary = i.imaginary / k.imaginary;
cout<<"Real div is     :  "<<temp.real<<endl;
cout<<"Imaginary div is     :  "<<temp.imaginary<<endl;



}



int main()
{

complex c1(11,22);
complex d1(33,44);
c1+d1;
c1-d1;
c1*d1;
c1/d1;
return 0;


}