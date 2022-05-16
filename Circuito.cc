/** @file Circuito.cc
    @brief Implementación de la clase Circuito 
*/

#include "Circuito.hh"

// public:

Circuito::Circuito() {}

void Circuito::anadir_categoria(Categoria c) { vec_categorias.push_back(c); }

void Circuito::anadir_niveles(int i, const vector<int>& v) { vec_categorias[i - 1].anadir_pts_nivel(v); }

void Circuito::anadir_torneo(string t, int c) { torneos.insert(make_pair(t, Torneo(t, c))); }

void Circuito::eliminar_torneo(const string& t, Cjn_Jugadores& j) {
    map<string, Torneo>::iterator it = torneos.find(t);
    it->second.restar_puntos(j);
    torneos.erase(it);
}

void Circuito::iniciar_torneo(const string& t, const Cjn_Jugadores& j) {
    map<string, Torneo>::iterator it = torneos.find(t);
    it->second.anadir_participantes(j);
    it->second.crear_emparejamientos();
}

void Circuito::finalizar_torneo(const string& t, Cjn_Jugadores& j) {
    map<string, Torneo>::iterator it = torneos.find(t);
    vector<int> pts_nvl(vec_categorias[0].num_niveles());
    for (int i = 0; i < vec_categorias[0].num_niveles(); ++i)
        pts_nvl[i] = vec_categorias[it->second.consultar_categoria() - 1].consultar_pts_nivel(i);    
    it->second.procesar_torneo(j, pts_nvl);
}

void Circuito::eliminar_jugador_torneos(const string& p) {
    map<string, Torneo>::iterator it = torneos.begin();
    while (it != torneos.end()) {
        it->second.borrar_jugador(p);
        ++it;
    }
}

Torneo Circuito::torneo(const string& t) const { return torneos.find(t)->second; }

int Circuito::num_categorias() const { return vec_categorias.size(); }

int Circuito::num_torneos() const { return torneos.size(); }

bool Circuito::existe_torneo(const string& t) const { return (torneos.find(t) != torneos.end()); }

void Circuito::escribir_categorias() const {
    int n_nvl = vec_categorias[0].num_niveles();
    cout << vec_categorias.size() << ' ' << n_nvl << endl;
    for (int i = 0; i < vec_categorias.size(); ++i) {
        cout << vec_categorias[i].consultar_nombre();
        for (int j = 0; j < n_nvl; ++j) cout << ' ' << vec_categorias[i].consultar_pts_nivel(j);
        cout << endl;
    }
}

void Circuito::escribir_torneos() const {
    map<string, Torneo>::const_iterator it = torneos.begin();
    cout << torneos.size() << endl;
    while (it != torneos.end()) {
        cout << it->first << ' ' << vec_categorias[it->second.consultar_categoria() - 1].consultar_nombre() << endl;
        ++it;
    }
}
