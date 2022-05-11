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

void Torneo::escribir_cuadro(const BinTree<int>& e) {
    if (not e.right().empty()) {
        cout << '(';
        escribir_cuadro(e.left());
        cout << ' ';
        escribir_cuadro(e.right());
        cout << ')';
    }
    else cout << e.value() << '.' << participantes[e.value() - 1].first->first;
}

BinTree<int> Torneo::crear_cuadro_final(const BinTree<int>& c, const vector<int>& pts_nvl, int nvl) {
    int WSa = 0, LSa = 0, WGa = 0, LGa = 0;
    if (not procesar_partido(WSa, LSa, WGa, LGa)) return BinTree<int>(c.value(), BinTree<int>(), BinTree<int>());
    
    BinTree<int> cleft = c.left();
    BinTree<int> cright = c.right();

    BinTree<int> left = crear_cuadro_final(cleft, pts_nvl, nvl + 1);
    BinTree<int> right = crear_cuadro_final(cright, pts_nvl, nvl + 1);

    if (WSa > LSa) {
        participantes[left.value() - 1].first->second.modificar_stats("wm", 1);
        participantes[right.value() - 1].first->second.modificar_stats("lm", 1);
    }
    else {
        participantes[left.value() - 1].first->second.modificar_stats("lm", 1);
        participantes[right.value() - 1].first->second.modificar_stats("wm", 1);
    }
    if (not (WSa == 1 and LSa == 0) and not (WSa == 0 and LSa == 1)) {
        participantes[left.value() - 1].first->second.modificar_stats("ws", WSa);
        participantes[left.value() - 1].first->second.modificar_stats("ls", LSa);
        participantes[right.value() - 1].first->second.modificar_stats("ws", LSa);
        participantes[right.value() - 1].first->second.modificar_stats("ls", WSa);

        participantes[left.value() - 1].first->second.modificar_stats("wg", WGa);
        participantes[left.value() - 1].first->second.modificar_stats("lg", LGa);
        participantes[right.value() - 1].first->second.modificar_stats("wg", LGa);
        participantes[right.value() - 1].first->second.modificar_stats("lg", WGa);
    }

    int winner;
    if (WSa > LSa) {
        winner = left.value();
        if (nvl == 1) participantes[left.value() - 1].second = pts_nvl[0];
        participantes[right.value() - 1].second = pts_nvl[nvl];
    }
    else {
        winner = right.value();
        if (nvl == 1) participantes[right.value() - 1].second = pts_nvl[0];
        participantes[left.value() - 1].second = pts_nvl[nvl];
    }
    //cout << winner << endl;

    return BinTree<int>(winner, left, right);
}

void Torneo::escribir_cuadro_final(const BinTree<int>& c) {
    if (not c.right().empty()) {
        cout << '(';
        escribir_cuadro(c.left());
        cout << ' ';
        escribir_cuadro(c.right());
        cout << ')';
    }
    else cout << c.value() << '.' << participantes[c.value() - 1].first->first;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Torneo::Torneo(string t, int c) {
    nombre = t;
    categoria = c;
}

void Torneo::anadir_participantes(const Cjn_Jugadores& j) {
    participantes.clear();
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

    escribir_cuadro(emparejamientos);
    cout << endl;
}

void Torneo::procesar_torneo(const vector<int>& pts_nvl) {
    resultados = crear_cuadro_final(emparejamientos, pts_nvl, 1);
    for (int i = 0; i < participantes.size(); ++i)
        cout << i + 1 << "." << participantes[i].first->first << " " << participantes[i].second << endl;    
    anadir_puntos();
}

bool Torneo::procesar_partido(int& WSa, int& LSa, int& WGa, int& LGa) {
    string s; cin >> s;
    if (s == "0") return false;

    list_resultados.emplace_back(s);

    if (s == "1-0") ++WSa;
    else if (s == "0-1") ++LSa;
    else {
        int i = 0;
        while (i < s.size()) {
            if (int(s[i]) > int(s[i+2])) ++WSa;
            else ++LSa;
            WGa += int(s[i] - '0');
            LGa += int(s[i+2] - '0');
            i += 4;
        }
    }
    return true;
}

void Torneo::anadir_puntos() {
    for (int i = 0; i < participantes.size(); ++i) {
        participantes[i].first->second.modificar_stats("ps", participantes[i].second);
        participantes[i].first->second.modificar_stats("ts", 1);
    }
    restar_puntos();
    borrar_participantes();
}

// problemas cuando se borra un Jugador de un torneo antiguo
void Torneo::restar_puntos() {
    if (not antiguos_participantes.empty()) {
        for (int i = 0; i < antiguos_participantes.size(); ++i)
            antiguos_participantes[i].first->second.modificar_stats("ps", -antiguos_participantes[i].second);
    }
}

void Torneo::borrar_participantes() {
    antiguos_participantes.clear();
    for (int i = 0; i < participantes.size(); ++i) antiguos_participantes.push_back(participantes[i]);
        //antiguos_participantes.push_back(make_pair(participantes[i].first->second.consultar_nombre(), participantes[i].second))
    participantes.clear();
}

string Torneo::consultar_nombre() const { return nombre; }

int Torneo::consultar_categoria() const { return categoria; }

Torneo::~Torneo() {}