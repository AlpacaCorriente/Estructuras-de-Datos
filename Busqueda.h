class Busqueda {
 private:
  int tam;
  int *vec;
 public:
  Busqueda(int n);
  ~Busqueda();
  int size();
  int lineal(int num);
  int binariaRecursiva(int num, int l, int r);
  int binariaIterativa(int num);
};
