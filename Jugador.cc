#include "Jugador.hh"

Jugador::Jugador(string p, int rank) {
    nombre = p;
    Rk = rank;
    puntos = Ts = WM = LM = WS = LS = WG = LG = 0;
}

void Jugador::modificar_stats(string stat, int n) { 
    if (stat == "ps") puntos += n;
    else if (stat == "rk") Rk = n;
    else if (stat == "ts") Ts += n;
    else if (stat == "wm") WM += n;
    else if (stat == "lm") LM += n;
    else if (stat == "ws") WS += n;
    else if (stat == "ls") LS += n;
    else if (stat == "wg") WG += n;
    else if (stat == "lg") LG += n;
}

string Jugador::consultar_nombre() const { return nombre; }

int Jugador::consultar_puntos() const { return puntos; }

int Jugador::consultar_ranking() const { return Rk; }

void Jugador::escribir_jug() const {
    cout << nombre << " Rk:" << Rk << " Ps:" << puntos << " Ts:" << Ts << " WM:" << WM << " LM:" << LM << " WS:" << WS << " LS:" << LS << " WG:" << WG << " LG:" << LG << endl;
}

Jugador::~Jugador() {}