#include "Cjn_Jugadores.hh"

bool cmp(const map<string, Jugador>::iterator& a, const map<string, Jugador>::iterator& b) { return a->second.consultar_puntos() > b->second.consultar_puntos(); }

Cjn_Jugadores::Cjn_Jugadores() {}

void Cjn_Jugadores::anadir_jugador(string s, Jugador p) {
    jugadores.insert(make_pair(s, p));
    ranking.push_back(jugadores.find(s));
    ranking.sort(cmp);
}

void Cjn_Jugadores::eliminar_jugador(string p) {
    list< map<string, Jugador>::iterator >::iterator it = ranking.begin();
    while ((*it)->first != p) ++it;
    ranking.erase(it);
    jugadores.erase(jugadores.find(p));
}

void Cjn_Jugadores::actualizar_puntos_torneo(string t) {
    string s = t;
    // TODO
}

bool Cjn_Jugadores::existe_jugador(string s) const { return (jugadores.find(s) != jugadores.end()); }

map<string, Jugador>::iterator Cjn_Jugadores::jugador_ranking(int n) const {
    list< map<string, Jugador>::iterator >::const_iterator it = ranking.begin();
    advance(it, n - 1);
    return (*it)->first;
}

int Cjn_Jugadores::num_jugadores() const { return ranking.size(); }

void Cjn_Jugadores::escribir_ranking() const {
    list< map<string, Jugador>::iterator >::const_iterator it = ranking.begin();
    int pos = 1;
    while (it != ranking.end()) {
        cout << pos << " " << (*it)->first << " " << (*it)->second.consultar_puntos() << endl;
        ++it; ++pos;
    }
}

void Cjn_Jugadores::escribir_jugadores() const {
    map<string, Jugador>::const_iterator it1 = jugadores.begin();
    cout << jugadores.size() << endl;
    while (it1 != jugadores.end()) {
        int pos = 1;
        list< map<string, Jugador>::iterator >::const_iterator it2 = ranking.begin();
        while ((*it2)->first != it1->first) { ++it2; ++pos; }
        (it1)->second.escribir_jug(pos);
        ++it1;
    }
}
//TODO: arreglar las posicion en el ranking
//TODO: ver que es Ts, WM, LM, WS, LS, WG, LG

void Cjn_Jugadores::escribir_jugador(string s) const {
    list< map<string, Jugador>::iterator >::const_iterator it = ranking.begin();
    int pos = 1;
    while ((*it)->first != s) { ++it; ++pos; }
    jugadores.find(s)->second.escribir_jug(pos);
}
