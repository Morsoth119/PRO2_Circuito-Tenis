#include "Cjn_Jugadores.hh"

// public:

Cjn_Jugadores::Cjn_Jugadores() {}

void Cjn_Jugadores::anadir_jugador(const string& s, int rk) {
    jugadores.insert(make_pair(s, Jugador(s, rk)));
    ranking.push_back(jugadores.find(s));
}

void Cjn_Jugadores::eliminar_jugador(const string& p) {
    int i = 0;
    while (ranking[i]->first != p) ++i;
    ranking.erase(ranking.begin() + i);
    jugadores.erase(jugadores.find(p));
    while(i < ranking.size()) {
        ranking[i]->second.modificar_stats("rk", i + 1);
        ++i;
    }
}

void Cjn_Jugadores::modificar_jugador(const string& p, const string& stat, int n) {
    map<string, Jugador>::iterator it = jugadores.find(p);
    (*it).second.modificar_stats(stat, n);
}

void Cjn_Jugadores::actualizar_ranking() {
    stable_sort(ranking.begin(), ranking.end(), cmp);
    for (int i = 0; i < ranking.size(); ++i) ranking[i]->second.modificar_stats("rk", i + 1);
}

bool Cjn_Jugadores::existe_jugador(const string& p) const { return (jugadores.find(p) != jugadores.end()); }

string Cjn_Jugadores::jugador_ranking(int n) const { return ranking[n - 1]->first; }

int Cjn_Jugadores::num_jugadores() const { return ranking.size(); }

void Cjn_Jugadores::escribir_ranking() const {
    for (int i = 0; i < ranking.size(); ++i) 
        cout << i + 1 << ' ' << ranking[i]->first << ' ' << ranking[i]->second.consultar_puntos() << endl;
}

void Cjn_Jugadores::escribir_jugadores() const {
    map<string, Jugador>::const_iterator it = jugadores.begin();
    cout << jugadores.size() << endl;
    while (it != jugadores.end()) {
        (it)->second.escribir_jug();
        ++it;
    }
}

void Cjn_Jugadores::escribir_jugador(const string& p) const {
    jugadores.find(p)->second.escribir_jug();
}

// private:

bool Cjn_Jugadores::cmp(const map<string, Jugador>::iterator& a, const map<string, Jugador>::iterator& b) { 
    return a->second.consultar_puntos() > b->second.consultar_puntos();
}