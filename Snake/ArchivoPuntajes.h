#ifndef ARCHIVOPUNTAJES_H_INCLUDED
#define ARCHIVOPUNTAJES_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class ArchivoPuntajes {
private:
    std::string archivo;
    std::vector<int> puntajes;

public:

    ArchivoPuntajes(const std::string& archivo) : archivo(archivo) {
        cargarPuntajes();
    }

    void guardarPuntaje(int puntaje) {
        puntajes.push_back(puntaje);
        std::sort(puntajes.rbegin(), puntajes.rend());
        actualizarArchivo();
    }


    void cargarPuntajes() {
        std::ifstream archivoPuntajes(archivo, std::ios::binary);

        if (!archivoPuntajes) {
            // El archivo no existe, así que se creará uno nuevo
            std::ofstream nuevoArchivo(archivo, std::ios::binary);
            // No es necesario escribir nada, el archivo estará vacío
        } else {
            // El archivo existe, entonces se cargan los puntajes
            int puntaje;
            while (archivoPuntajes.read(reinterpret_cast<char*>(&puntaje), sizeof(int))) {
                puntajes.push_back(puntaje);
            }
        }

        archivoPuntajes.close();
    }

    const std::vector<int>& obtenerPuntajes() const {
        return puntajes;
    }

    void actualizarArchivo() {
        std::ofstream archivoPuntajes(archivo, std::ios::binary);
        for (int puntaje : puntajes) {
            archivoPuntajes.write(reinterpret_cast<char*>(&puntaje), sizeof(int));
        }
        archivoPuntajes.close();
    }
};


#endif // ARCHIVOPUNTAJES_H_INCLUDED
