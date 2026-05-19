#include <iostream>
#include <thread>
#include <chrono>

#include "Microfone.hpp"

using namespace std;

Microfone::Microfone() {
}

void Microfone::liga() {

    cout << "\033[32m";

    cout << "Microfone ligado"
         << endl;

    cout << "\033[0m";
}

void Microfone::desliga() {

    cout << "\033[31m";

    cout << "Microfone desligado"
         << endl;

    cout << "\033[0m";
}

void Microfone::passa_tempo(int tempo) {

    cout << "Tempo: "
         << tempo
         << " segundos"
         << endl;

    this_thread::sleep_for(
        chrono::seconds(2)
    );
}
