#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdint>
using namespace std;

// Función para extraer los dígitos centrales
int extraerCentrales(int64_t numero, int d) {
    string numStr = to_string(numero);
    int totalDigitos = numStr.length();
    if (totalDigitos < d) {
        numStr = string(d - totalDigitos, '0') + numStr;
        totalDigitos = d;
    }
    int inicio = (totalDigitos - d) / 2;
    return stoi(numStr.substr(inicio, d));
}

// Función para obtener los dígitos centrales (4 dígitos)
int obtenerCuatroCentrales(long long numero) {
    string numeroStr = to_string(numero);
    while (numeroStr.length() < 8)
        numeroStr = "0" + numeroStr;
    return stoi(numeroStr.substr(2, 4));
}

// Método del cuadrado medio
void metodoCuadradoMedio(int semilla, int cantidad) {
    if (semilla < 1000 || semilla > 9999) {
        cout << "La semilla debe tener 4 dígitos." << endl;
        return;
    }

    cout << "Generando " << cantidad << " números usando el método del cuadrado medio:" << endl;
    cout << fixed << setprecision(4);

    vector<double> numeros;
    for (int i = 0; i < cantidad; i++) {
        long long cuadrado = (long long)semilla * semilla;
        semilla = obtenerCuatroCentrales(cuadrado);
        double aleatorio = semilla / 10000.0;
        numeros.push_back(aleatorio);
        cout << "R" << i + 1 << " = " << aleatorio << endl;
    }

    int intervalos[10] = {0};
    for (double numero : numeros) {
        int indice = min(int(numero * 10), 9);
        intervalos[indice]++;
    }

    cout << "\nHistograma de frecuencias:" << endl;
    for (int i = 0; i < 10; i++) {
        double limiteInferior = i / 10.0;
        double limiteSuperior = (i + 1) / 10.0;
        cout << fixed << setprecision(1);
        cout << "[" << limiteInferior << " - " << limiteSuperior << "): ";
        for (int j = 0; j < intervalos[i]; j++) {
            cout << "*";
        }
        cout << " (" << intervalos[i] << ")" << endl;
    }
}

// Generador congruencial multiplicativo
std::vector<double> generadorCongruencialMultiplicativo(
    unsigned long long semilla,
    unsigned long long a,
    unsigned long long m,
    int iteraciones
) {
    std::vector<double> resultados;
    unsigned long long x = semilla;
    for (int i = 0; i < iteraciones; ++i) {
        x = (a * x) % m;
        resultados.push_back(static_cast<double>(x) / m);
    }
    return resultados;
}

// Método Lineal
void mtl(void) {
    int semilla, cantidad;
    cout << "Ingrese una semilla de 4 dígitos: ";
    cin >> semilla;
    cout << "Ingrese la cantidad de números a generar: ";
    cin >> cantidad;
    metodoCuadradoMedio(semilla, cantidad);
}

// Método Lineal Aditivo
void mla(void) {
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
}

// Método Multiplicador Constante
void mpc(void) {
    int64_t semilla, a;
    int digitos, iteraciones;

    cout << "=== Algoritmo Multiplicador Constante ===\n";
    cout << "Ingrese la semilla (S0): ";
    cin >> semilla;
    cout << "Ingrese la constante multiplicadora (a): ";
    cin >> a;
    cout << "Ingrese la cantidad de dígitos a extraer (D): ";
    cin >> digitos;
    cout << "Ingrese la cantidad de iteraciones (e): ";
    cin >> iteraciones;

    int64_t xi = semilla;
    cout << "\nNúmeros pseudoaleatorios generados:\n";
    for (int i = 0; i < iteraciones; ++i) {
        int64_t producto = xi * a;
        xi = extraerCentrales(producto, digitos);
        double ri = static_cast<double>(xi) / pow(10, digitos);
        cout << "X" << i + 1 << " = " << setw(digitos) << setfill('0') << xi
             << "   R" << i + 1 << " = " << fixed << setprecision(digitos) << ri << endl;
    }
}

// Método Congruencial Multiplicativo
void cgm(void) {
    int64_t semilla, a;
    int digitos, iteraciones;

    cout << "=== Método Congruencial Multiplicativo (sin módulo) ===\n";
    cout << "Ingrese la semilla (X0): ";
    cin >> semilla;
    cout << "Ingrese la constante multiplicadora (a): ";
    cin >> a;
    cout << "Ingrese la cantidad de dígitos a extraer (D): ";
    cin >> digitos;
    cout << "Ingrese la cantidad de iteraciones: ";
    cin >> iteraciones;

    int64_t xi = semilla;
    cout << "\nNúmeros pseudoaleatorios generados:\n";
    for (int i = 0; i < iteraciones; ++i) {
        int64_t producto = xi * a;
        xi = extraerCentrales(producto, digitos);
        double ri = static_cast<double>(xi) / pow(10, digitos);
        cout << "X" << i + 1 << " = " << setw(digitos) << setfill('0') << xi
             << "   R" << i + 1 << " = " << fixed << setprecision(digitos) << ri << endl;
    }
}

// Función principal
int main(void) {
    int opt;
    while (true) {
        cout << "\n--- Menú de Generadores Pseudoaleatorios ---\n";
        cout << "1) Lineal\n";
        cout << "2) Aditivo\n";
        cout << "3) Multiplicativo\n";
        cout << "4) Congruencial\n";
        cout << "5) Terminar el programa\n";
        cout << "Elíge una opción: ";
        cin >> opt;
        cout << endl;

        if (opt == 1) mtl();
        else if (opt == 2) mla();
        else if (opt == 3) mpc();
        else if (opt == 4) cgm();
        else if (opt == 5) break;
        else cout << "Opción no reconocida\n";
    }
    return 0;
}
