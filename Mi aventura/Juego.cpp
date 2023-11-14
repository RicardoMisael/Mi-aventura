#include "Juego.h"
#include <iostream>
#include <string>
#include <algorithm>

Juego::Juego() : cuartoActual(0) {
    // Crear cuartos con sus respectivos items y enemigos
    cuartos.emplace_back("Sala de Entrada", "Una sala grande con una puerta principal.");
    cuartos[0].agregarItem(Item("Llave"));

    cuartos.emplace_back("Pasillo Oscuro", "Un pasillo oscuro y estrecho.");
    cuartos[1].agregarItem(Item("Antorcha"));
    cuartos[1].agregarEnemigo(Enemigo("Arana Gigante"));

    cuartos.emplace_back("Sala de Tesoros", "Una sala llena de tesoros brillantes.");
    cuartos[2].agregarItem(Item("Gema Preciosa"));

    cuartos.emplace_back("Biblioteca Abandonada", "Una biblioteca con estantes llenos de libros polvorientos.");
    cuartos[3].agregarItem(Item("Libro Antiguo"));

    cuartos.emplace_back("Cocina", "Una cocina con un aroma delicioso en el aire.");
    cuartos[4].agregarItem(Item("Manzana"));

    cuartos.emplace_back("Cuarto de las Trampas", "Un cuarto lleno de trampas mortales.");
    cuartos[5].agregarEnemigo(Enemigo("Esqueleto"));
    cuartos[5].agregarItem(Item("Espada"));

    cuartos.emplace_back("Jardín Encantado", "Un hermoso jardín lleno de flores y mariposas.");
    cuartos[6].agregarItem(Item("Flor Mágica"));

    cuartos.emplace_back("Sala de Enigmas", "Una sala llena de enigmas desafiantes.");
    cuartos[7].agregarItem(Item("Pergamino Misterioso"));

    cuartos.emplace_back("Sala de las Sombras", "Una sala oscura llena de sombras inquietantes.");
    cuartos[8].agregarEnemigo(Enemigo("Sombra Malévola"));
    cuartos[8].agregarItem(Item("Amuleto"));

    cuartos.emplace_back("Cuarto Final", "¡Felicidades! Has llegado al final de la aventura.");
}

void Juego::iniciarJuego() {
    std::cout << "¡Bienvenido a la Aventura de Gomi!" << std::endl;

    while (!verificarVictoria()) {
        explorarCuarto();
        enfrentarEnemigos();
    }

    std::cout << "¡Felicidades! Has completado la aventura." << std::endl;
}

void Juego::explorarCuarto() {
    if (esIndiceValido(cuartoActual)) {
        Cuarto& cuartoActualObj = cuartos[cuartoActual];
        cuartoActualObj.mostrarInfo();

        // Lógica para que el jugador elija qué hacer en el cuarto
        std::cout << "¿Que deseas hacer?" << std::endl;
        std::cout << "1. Moverse a otro cuarto" << std::endl;
        std::cout << "2. Recoger items" << std::endl;
        std::cout << "3. Usar item" << std::endl;
        std::cout << "4. Mostrar inventario" << std::endl;
        std::cout << "5. Salir del juego" << std::endl;

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            // Implementar lógica para moverse a otro cuarto
            std::cout << "Elige el número del cuarto al que deseas moverte: ";
            std::cin >> cuartoActual;
            break;
        case 2:
            // Recoger items
            recogerItems(cuartoActualObj);
            break;
        case 3:
            // Usar item
            usarItem();
            break;
        case 4:
            // Mostrar inventario
            mostrarInventario();
            break;
        case 5:
            // Salir del juego
            cuartoActual = cuartos.size() - 1; // Mover al cuarto final para salir del juego
            break;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
            break;
        }
    }
    else {
        std::cout << "Índice de cuarto no válido. No se puede explorar el cuarto." << std::endl;
    }
}

void Juego::enfrentarEnemigos() {
    if (esIndiceValido(cuartoActual)) {
        // Lógica de combate (simplificada)
        if (!cuartos[cuartoActual].obtenerEnemigos().empty()) {
            std::cout << "¡Te encuentras con enemigos en este cuarto!" << std::endl;
            std::cout << "¡Combate simplificado! Has derrotado a los enemigos." << std::endl;
            // Aquí podrías implementar una lógica más avanzada de combate si lo deseas.
        }
    }
    else {
        std::cout << "Índice de cuarto no válido. No se pueden enfrentar enemigos." << std::endl;
    }
}

void Juego::recogerItems(Cuarto& cuarto) {
    if (esIndiceValido(cuartoActual)) {
        const std::vector<Item>& itemsCuarto = cuarto.obtenerItems();

        if (!itemsCuarto.empty()) {
            std::cout << "Puedes ver los siguientes items: ";
            for (size_t i = 0; i < itemsCuarto.size(); ++i) {
                std::cout << i + 1 << ". " << itemsCuarto[i].obtenerNombre() << " ";
            }
            std::cout << std::endl;

            std::cout << "Elige el número del item que deseas recoger (o 0 para cancelar): ";
            int opcion;
            std::cin >> opcion;

            if (opcion >= 1 && opcion <= static_cast<int>(itemsCuarto.size())) {
                inventario.push_back(itemsCuarto[opcion - 1]);
                cuarto.eliminarItem(itemsCuarto[opcion - 1]);
                std::cout << "Has recogido: " << itemsCuarto[opcion - 1].obtenerNombre() << std::endl;
            }
            else if (opcion != 0) {
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
            }
        }
        else {
            std::cout << "No hay items en este cuarto." << std::endl;
        }
    }
    else {
        std::cout << "Índice de cuarto no válido. No se pueden recoger items." << std::endl;
    }
}

void Juego::usarItem() {
    if (esIndiceValido(cuartoActual)) {
        if (!inventario.empty()) {
            std::cout << "Inventario actual: ";
            for (size_t i = 0; i < inventario.size(); ++i) {
                std::cout << i + 1 << ". " << inventario[i].obtenerNombre() << " ";
            }
            std::cout << std::endl;

            std::cout << "Elige el número del item que deseas usar (o 0 para cancelar): ";
            int opcion;
            std::cin >> opcion;

            if (opcion >= 1 && opcion <= static_cast<int>(inventario.size())) {
                std::cout << "Has usado: " << inventario[opcion - 1].obtenerNombre() << std::endl;
                // Aquí podrías implementar la lógica específica del item (si es necesario).
            }
            else if (opcion != 0) {
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
            }
        }
        else {
            std::cout << "Tu inventario está vacío." << std::endl;
        }
    }
    else {
        std::cout << "Índice de cuarto no válido. No se pueden usar items." << std::endl;
    }
}

void Juego::mostrarInventario() const {
    if (esIndiceValido(cuartoActual)) {
        if (!inventario.empty()) {
            std::cout << "Inventario actual: ";
            for (size_t i = 0; i < inventario.size(); ++i) {
                std::cout << i + 1 << ". " << inventario[i].obtenerNombre() << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Tu inventario está vacío." << std::endl;
        }
    }
    else {
        std::cout << "Índice de cuarto no válido. No se puede mostrar el inventario." << std::endl;
    }
}

bool Juego::verificarVictoria() const {
    return esIndiceValido(cuartoActual) && cuartoActual == cuartos.size() - 1;
}

bool Juego::esIndiceValido(int indice) const {
    return indice >= 0 && indice < static_cast<int>(cuartos.size());
}
