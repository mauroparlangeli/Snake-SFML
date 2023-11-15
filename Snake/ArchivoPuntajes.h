#ifndef ARCHIVOPUNTAJES_H_INCLUDED
#define ARCHIVOPUNTAJES_H_INCLUDED
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
        if (archivoPuntajes.is_open()) {
            int puntaje;
            while (archivoPuntajes.read(reinterpret_cast<char*>(&puntaje), sizeof(puntaje))) {
                puntajes.push_back(puntaje);
            }
            archivoPuntajes.close();
        }
    }

    const std::vector<int>& obtenerPuntajes() const {
        return puntajes;
    }

    void actualizarArchivo() {
        std::ofstream archivoPuntajes(archivo, std::ios::binary);
        if (archivoPuntajes.is_open()) {
            for (int puntaje : puntajes) {
                archivoPuntajes.write(reinterpret_cast<const char*>(&puntaje), sizeof(puntaje));
            }
            archivoPuntajes.close();
        }
    }
};

#endif // ARCHIVOPUNTAJES_H_INCLUDED
