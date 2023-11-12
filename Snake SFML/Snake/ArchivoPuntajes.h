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
        std::ifstream archivoPuntajes(archivo);
        int puntaje;
        while (archivoPuntajes >> puntaje) {
            puntajes.push_back(puntaje);
        }
        archivoPuntajes.close();
    }

    const std::vector<int>& obtenerPuntajes() const {
        return puntajes;
    }

    void actualizarArchivo() {
        std::ofstream archivoPuntajes(archivo);
        for (int puntaje : puntajes) {
            archivoPuntajes << puntaje << std::endl;
        }
        archivoPuntajes.close();
    }

};


#endif // ARCHIVOPUNTAJES_H_INCLUDED
