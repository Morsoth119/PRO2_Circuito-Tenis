#include "Torneo.hh"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BinTree<int> Torneo::crear_cuadro(const int& h, const bool& conflicto, const int& n_part, int pos, int nivel) {
    if (nivel > h + 1) return BinTree<int>();
    else if (conflicto and (nivel == h) and pos <= (pow(2, h - 1) - n_part)) return BinTree<int>(pos);
    else {
        int m = pow(2, nivel - 1);
        return BinTree<int>(pos, crear_cuadro(h, conflicto, n_part, pos, nivel + 1), crear_cuadro(h, conflicto, n_part, m + 1 - pos, nivel + 1));
    }
}

void Torneo::escribir_cuadro(const BinTree<int>& e, const vector< pair<string, int> >& p) {
    if (not e.right().empty()) {
        cout << '(';
        escribir_cuadro(e.left(), p);
        cout << ' ';
        escribir_cuadro(e.right(), p);
        cout << ')';
    }
    else cout << e.value() << '.' << p[e.value() - 1].first;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Torneo::Torneo(string t, int c) {
    nombre = t;
    categoria = c;
}

void Torneo::anadir_participantes(const Cjn_Jugadores& j) { 
    int n, n_jug; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> n_jug;
        participantes.push_back(make_pair(j.jugador_ranking(n_jug), 0));
    }
}

void Torneo::crear_emparejamientos() {
    int sz = participantes.size();
    int h = 1 + ceil(log2(sz));
    int max = pow(2, h - 1);
    bool conflicto = (max != sz);
    
    emparejamientos = BinTree<int>(1, crear_cuadro(h, conflicto, sz, 1, 3), crear_cuadro(h, conflicto, sz, 2, 3));

    escribir_cuadro(emparejamientos, participantes);
    cout << endl;
}

/*
void Torneo::borrar_participantes() {

}
*/

string Torneo::consultar_nombre() const { return nombre; }

int Torneo::consultar_categoria() const { return categoria; }

Torneo::~Torneo() {}