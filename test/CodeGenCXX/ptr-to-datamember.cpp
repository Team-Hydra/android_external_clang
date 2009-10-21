// RUN: clang-cc -emit-llvm -o - %s

extern "C" int printf(...);

struct V {
  double d;
  int iV;
};

struct B  : virtual V{
  double d;
  int iB;
};

struct B1  : virtual V{
  double d;
  int iB1;
};

class A  : public B, public B1 {
public:
  A() : f(1.0), d(2.0), Ai(3) {}
  float f;
  double d;
  int Ai;
}; 

int main() 
{
  A a1;
  int A::* pa = &A::Ai;
  float A::* pf = &A::f;
  double A::* pd = &A::d;
  printf("%d %d %d\n", &A::Ai, &A::f, &A::d);
  printf("%d\n", &A::B::iB);
  printf("%d\n", &A::B1::iB1);
  printf("%d\n", &A::f);
  printf("%d\n", &A::B::iV);
  printf("%d\n", &A::B1::iV);
  printf("%d\n", &A::B::V::iV);
  printf("%d\n", &A::B1::V::iV);
  printf("%d, %f, %f  \n", a1.*pa, a1.*pf, a1.*pd);
}
