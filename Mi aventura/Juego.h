// Juego.h
#pragma once
#include <iostream>
#include <vector>
#include "Cuarto.h"
#include "Item.h"
#include "Enemigo.h"

class Juego {
public:
    Juego();

    void iniciarJuego();

private:
    std::vector<Cuarto> cuartos;
    std::vector<Item> inventario;
    int cuartoActual;

    void explorarCuarto();
    void enfrentarEnemigos();
    void recogerItems(Cuarto& cuarto);
    void usarItem();
    void mostrarInventario() const;
    bool verificarVictoria() const;
    bool esIndiceValido(int indice) const;
};

