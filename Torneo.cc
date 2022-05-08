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

BinTree<int> Torneo::cuadro_final(const BinTree<int>& c, const vector<int>& pts_nvl, int nvl) {
    int WGa = 0, LGa = 0;
    if (not procesar_partido(WGa, LGa)) return BinTree<int>();

    BinTree<int> cleft = c.left();
    BinTree<int> cright = c.right();

    BinTree<int> left = cuadro_final(cleft, pts_nvl, nvl + 1);
    BinTree<int> right = cuadro_final(cright, pts_nvl, nvl + 1);

    int winner;
    if (WGa > LGa) {
        winner = cleft.value();
        participantes[cright.value() - 1].second = pts_nvl[nvl - 1];
    }
    else {
        winner = cright.value();
        participantes[cleft.value() - 1].second = pts_nvl[nvl - 1];
    }
    cout << nvl << endl;
    return BinTree<int>(winner, left, right);
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

void Torneo::procesar_torneo(const vector<int>& pts_nvl) {
    for (int i = 0; i < pts_nvl.size(); i++) cout << pts_nvl[i] << endl;
    
    resultados = cuadro_final(emparejamientos, pts_nvl, 1);
    for (int i = 0; i < participantes.size(); ++i)
        cout << i + 1 << "." << participantes[i].first << " " << participantes[i].second << endl;    
}

bool Torneo::procesar_partido(int& WGa, int& LGa) {
    string s; cin >> s;
    if (s == "0") return false;

    if (s == "1-0") ++WGa;
    else if (s == "0-1") ++LGa;
    else {
        int i = 0;
        while (i < s.size()) {
            if (int(s[i]) > int(s[i+2])) ++WGa;
            else ++LGa;
            i += 4;
        }
    }
    cout << "Juegos de A: " << WGa << " ; Juegos de B: " << LGa << endl;
    return true;
}

/*
void Torneo::borrar_participantes() {

}
*/

string Torneo::consultar_nombre() const { return nombre; }

int Torneo::consultar_categoria() const { return categoria; }

Torneo::~Torneo() {}