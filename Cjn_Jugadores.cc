#include "Cjn_Jugadores.hh"

//bool cmp(const pair<string, int>& a, const pair<string, int>& b) { return a.second > b.second; }

Cjn_Jugadores::Cjn_Jugadores() {}

void Cjn_Jugadores::anadir_jugador(string s, Jugador p) { 
    ranking.push_back(make_pair(s, 0));
    jugadores.insert(make_pair(s, p));
}

void Cjn_Jugadores::eliminar_jugador(string p) {
    int i = 0;
    while (ranking[i].first != p) ++i;
    ranking.erase(ranking.begin() + i);
    jugadores.erase(jugadores.find(p));
}

void Cjn_Jugadores::actualizar_puntos_torneo(string t) {
    string s = t;
    // TODO
}

bool Cjn_Jugadores::existe_jugador(string s) const { return (jugadores.find(s) != jugadores.end()); }

string Cjn_Jugadores::jugador_ranking(int n) const { return ranking[n - 1].first; }

int Cjn_Jugadores::num_jugadores() const { return ranking.size(); }

void Cjn_Jugadores::escribir_ranking() const {
    for (int i = 0; i < ranking.size(); ++i) 
        cout << i + 1 << " " << ranking[i].first << " " << ranking[i].second << endl;
}

void Cjn_Jugadores::escribir_jugadores() const {
    map<string, Jugador>::const_iterator it = jugadores.begin();
    cout << jugadores.size() << endl;
    while (it != jugadores.end()) {
        int i = 0;
        while (ranking[i].first != (it)->first) ++i;
        (it)->second.escribir_jug(i + 1);
        ++it;
    }
}
//TODO: arreglar las posicion en el ranking

void Cjn_Jugadores::escribir_jugador(string s) const {
    int i = 0;
    while (ranking[i].first != s) ++i;
    jugadores.find(s)->second.escribir_jug(i + 1);
}
