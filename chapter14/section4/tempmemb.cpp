// template members
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Beta {
  private:
    template <typename V>
    class Hold {
      private:
        V val;

      public:
        Hold(V v = 0): val(v) {}
        void show() const { cout << val << endl; }
        V value() const { return val; }
    };
    Hold<T> q;
    Hold<int> n;

  public:
    Beta(T t, int i): q(t), n(i) {}
    template <typename U>
    U blab(U u, T t) { return (n.value() + q.value()) * u / t; }
    void show() const { q.show(); n.show(); }
};

int main() {
  Beta<double> guy(3.5, 3);
  cout << "T was set to double\n";
  guy.show();
  cout << "V was set to T, which is double, then V was set to int\n";
  cout << guy.blab(10, 2.3) << endl;
  cout << "U was set to int\n";
  cout << guy.blab(10.0, 2.3) << endl;
  cout << "U was set to double\n";
  cout << "Done\n";

  return 0;
}
