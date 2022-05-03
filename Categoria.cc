#include "Categoria.hh"

Categoria::Categoria(string s) { nombre = s; }

void Categoria::anadir_pts_nivel(vector<int>& v) { pts_nivel = v; }

string Categoria::consultar_nombre() const { return nombre; }

int Categoria::consultar_pts_nivel(int i) const { return pts_nivel[i]; }

int Categoria::num_niveles() const { return pts_nivel.size(); }