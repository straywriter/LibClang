template <class T> bool f( T x )
{
  return x % 2;
}
struct aa;

enum Enum
{
  RED = 10,
  GREEN = 10 << 2,
  BLUE = RED + GREEN
};

struct sample
{
aa ab;
  int aa;
};

enum class Cpp11Enum
{
  RED = 10,
  BLUE = 20
};

struct Wowza
{
  Wowza();
  virtual ~Wowza() = default;
  virtual void foo(int i = 0) = 0;
};

struct Badabang : Wowza
{
  void foo(int) override;

  void foo1(int a,float ,int ,int,double);

  bool operator==(const Badabang& o) const;
};

template <typename T>
void bar(T&& t);



