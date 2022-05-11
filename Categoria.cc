#include "Categoria.hh"

// public:

Categoria::Categoria(string s) { nombre = s; }

void Categoria::anadir_pts_nivel(const vector<int>& v) { pts_nivel = v; }

string Categoria::consultar_nombre() const { return nombre; }

int Categoria::consultar_pts_nivel(int i) const { return pts_nivel[i]; }

vector<int> Categoria::consultar_niveles() const { return pts_nivel; }

int Categoria::num_niveles() const { return pts_nivel.size(); }