#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, k, n;

    cout << "=== Generador Pseudoaleatorio (Metodo Lineal Aditivo) ===" << endl;
    cout << "Ingrese el modulo (m): ";
    cin >> m;
    cout << "Ingrese el numero de semillas (k): ";
    cin >> k;

    vector<int> semillas(k);
    cout << "Ingrese las " << k << " semillas iniciales:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "X" << i << ": ";
        cin >> semillas[i];
    }

    cout << "Ingrese cuantos numeros pseudoaleatorios desea generar: ";
    cin >> n;

    vector<int> resultados = semillas;

    // Generación de los números
    for (int i = k; i < n + k; i++) {
        int suma = 0;
        for (int j = 1; j <= k; j++) {
            suma += resultados[i - j];
        }
        resultados.push_back(suma % m);
    }

    cout << "\n--- Numeros pseudoaleatorios generados ---\n";
    for (int i = k; i < n + k; i++) {
        cout << "X" << i << " = " << resultados[i] << endl;
    }

    return 0;
}
