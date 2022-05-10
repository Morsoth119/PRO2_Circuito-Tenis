#include "Jugador.hh"

Jugador::Jugador(string p, int rank) {
    nombre = p;
    Rk = rank;
    puntos = Ts = WM = LM = WS = LS = WG = LG = 0;
}

void Jugador::modificar_stats(int pts, int Ts, int WM, int LM, int WS, int LS, int WG, int LG) { 
    puntos += pts;
    this->Ts += Ts;
    this->WM += WM;
    this->LM += LM;
    this->WS += WS;
    this->LS += LS;
    this->WG += WG;
    this->LG += LG;
}

string Jugador::consultar_nombre() const { return nombre; }

int Jugador::consultar_puntos() const { return puntos; }

void Jugador::escribir_jug() const {
    cout << nombre << " Rk:" << Rk << " Ps:" << puntos << " Ts:" << Ts << " WM:" << WM << " LM:" << LM << " WS:" << WS << " LS:" << LS << " WG:" << WG << " LG:" << LG << endl;
}

Jugador::~Jugador() {}