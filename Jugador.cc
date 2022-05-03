#include "Jugador.hh"

Jugador::Jugador(string p) {
    nombre = p;
    puntos = 0;
}

void Jugador::modificar_pts(int pts) { puntos += pts; }

string Jugador::consultar_nombre() const { return nombre; }

int Jugador::consultar_puntos() const { return puntos; }

void Jugador::escribir_jug(int pos) const {
    cout << nombre << " Rk:" << pos << " Ps:" << puntos << " Ts:0 WM:0 LM:0 WS:0 LS:0 WG:0 LG:0" << endl;
}

Jugador::~Jugador() {}