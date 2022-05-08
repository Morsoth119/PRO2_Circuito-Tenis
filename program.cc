#include "Circuito.hh"
#include "Cjn_Jugadores.hh"

/** @brief Lee y configura los valores iniciales del Circuito y del Cjn_Jugadores (conjunto de jugadores). */
void setup(Circuito& circuito, Cjn_Jugadores& jugadores);

/** @brief Lee y añade un nuevo Jugador al Cjn_Jugadores (conjunto de jugadores). */
void nuevo_jugador(Cjn_Jugadores& j);
/** @brief Lee un nuevo Torneo y lo añade al Circuito. */
void nuevo_torneo(Circuito& c);
/** @brief Da de baja en a un Jugador del Cjn_Jugadores (conjunto de jugadores). */
void baja_jugador(Cjn_Jugadores& j);
/** @brief Da de baja en el Circuito a un Torneo. */
void baja_torneo(Circuito& c, Cjn_Jugadores& j);
/** @brief Lee la inscripción en el Torneo y se confecciona e imprime el cuadro de emparejamientos de los jugadores inscritos. */
void iniciar_torneo(Circuito& c, Cjn_Jugadores& j);
/** @brief Se leen los resultados del Torneo, se produce e imprime el cuadro oficial de resultados, y se listan los puntos para el ranking ganados por cada uno de los participantes; también se actualiza el ranking y las estadísticas de los jugadores. */
void finalizar_torneo(Circuito& c);
/** @brief Se listan, por orden creciente de ranking actual, la posición, el nombre y los puntos de cada Jugador del Circuito. */
void listar_ranking(Cjn_Jugadores& j);
/** @brief Se listan, por orden creciente de identificador (nombre), el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada Jugador del Circuito. */
void listar_jugadores(Cjn_Jugadores& j);
/** @brief Escribe el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de un Jugador del Circuito. */
void consultar_jugador(Cjn_Jugadores& j);
/** @brief Se listan, por orden creciente de identificador (nombre), el nombre y la categoría de cada Torneo del Circuito. */
void listar_torneos(Circuito& c);
/** @brief Se listan, por orden creciente de identificador, el nombre y la tabla de puntos por niveles (en orden creciente de nivel) de cada Categoria del Circuito. */
void listar_categorias(Circuito& c);

/** @brief Programa principal. */
int main() {
    Circuito circuito;
    Cjn_Jugadores jugadores;
    setup(circuito, jugadores);

    string com;
    while (cin >> com and com != "fin") {
        cout << "#" << com;

        if (com == "nuevo_jugador" or com == "nj") nuevo_jugador(jugadores);
        else if (com == "nuevo_torneo" or com == "nt") nuevo_torneo(circuito);
        else if (com == "baja_jugador" or com == "bj") baja_jugador(jugadores);
        else if (com == "baja_torneo" or com == "bt") baja_torneo(circuito, jugadores);
        else if (com == "iniciar_torneo" or com == "it") iniciar_torneo(circuito, jugadores);
        else if (com == "finalizar_torneo" or com == "ft") finalizar_torneo(circuito);
        else if (com == "listar_ranking" or com == "lr") listar_ranking(jugadores);
        else if (com == "listar_jugadores" or com == "lj") listar_jugadores(jugadores);
        else if (com == "consultar_jugador" or com == "cj") consultar_jugador(jugadores);
        else if (com == "listar_torneos" or com == "lt") listar_torneos(circuito);
        else if (com == "listar_categorias" or com == "lc") listar_categorias(circuito);
    }
}

void setup(Circuito& circuito, Cjn_Jugadores& jugadores) {
    int num_cat, max_nvl, num_tor, num_jug;
    cin >> num_cat >> max_nvl;
    for (int i = 0; i < num_cat; ++i) {
        string s; cin >> s;
        circuito.anadir_categoria(Categoria(s));
    }
    for (int i = 1; i <= num_cat; ++i) {
        vector<int> pts_nvl(max_nvl);
        for (int j = 0; j < max_nvl; ++j) cin >> pts_nvl[j];
        circuito.anadir_niveles(i, pts_nvl);
    }

    cin >> num_tor;
    for (int i = 0; i < num_tor; ++i) {
        string t; cin >> t;
        int c;  cin >> c;
        circuito.anadir_torneo(Torneo(t, c));
    }
    cin >> num_jug;
    for (int i = 0; i < num_jug; ++i) {
        string p; cin >> p;
        jugadores.anadir_jugador(p, Jugador(p));
    }
}

void nuevo_jugador(Cjn_Jugadores& j) {
    string p; cin >> p;
    cout << " " << p << endl;
    if (j.existe_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
    else {
        j.anadir_jugador(p, Jugador(p));
        cout << j.num_jugadores() << endl;
    }
}

void nuevo_torneo(Circuito& c) {
    string t; int cat; cin >> t >> cat;
    cout << " " << t << " " << cat << endl;
    if (cat <= 0 or cat > c.num_categorias()) cout << "error: la categoria no existe" << endl;
    else if (c.existe_torneo(t)) cout << "error: ya existe un torneo con ese nombre" << endl;
    else {
        c.anadir_torneo(Torneo(t, cat));
        cout << c.num_torneos() << endl;
    }
}

void baja_jugador(Cjn_Jugadores& j) {
    string p; cin >> p;
    cout << " " << p << endl;
    if (not j.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
    else {
        j.eliminar_jugador(p);
        cout << j.num_jugadores() << endl;
    }
}

void baja_torneo(Circuito& c, Cjn_Jugadores& j) {
    string t; cin >> t;
    cout << " " << t << endl;
    if (not c.existe_torneo(t)) cout << "error: el torneo no existe" << endl;
    else {
        c.eliminar_torneo(t);
        j.actualizar_puntos_torneo(t); //restar los puntos a los jugadores
        cout << c.num_torneos() << endl;
    }
}

void iniciar_torneo(Circuito& c, Cjn_Jugadores& j) {
    string t; cin >> t;
    cout << " " << t << endl;
    c.iniciar_torneo(t, j);
}

void finalizar_torneo(Circuito& c) {
    string t; cin >> t;
    cout << " " << t << endl;
    c.finalizar_torneo(t);
}

void listar_ranking(Cjn_Jugadores& j) {
    cout << endl;
    j.escribir_ranking();
}

void listar_jugadores(Cjn_Jugadores& j) {
    cout << endl;
    j.escribir_jugadores();
}

void consultar_jugador(Cjn_Jugadores& j) {
    string p; cin >> p;
    cout << " " << p << endl;
    if (not j.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
    else j.escribir_jugador(p);
}

void listar_torneos(Circuito& c) {
    cout << endl;
    c.escribir_torneos();
}

void listar_categorias(Circuito& c) {
    cout << endl;
    c.escribir_categorias();
}