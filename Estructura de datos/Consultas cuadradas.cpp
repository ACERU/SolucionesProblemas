#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tamaño de la cuadrícula N
    int N;
    cout << "Ingrese el tamaño de la cuadrícula N: ";
    cin >> N;

    // Inicializar la cuadrícula con números aleatorios (puedes cambiar esto según tus necesidades)
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = rand() % 100;  // Números aleatorios entre 0 y 99
        }
    }

    // Mostrar la cuadrícula inicial
    cout << "Cuadrícula inicial:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Juego: el usuario ingresa i, j, s
    int i, j, s;
    cout << "Ingrese i, j, s para el cuadrado (i, j) a (i + s - 1, j + s - 1): ";
    cin >> i >> j >> s;

    // Validar las entradas del usuario
    if (i < 1 || i + s - 1 > N || j < 1 || j + s - 1 > N) {
        cout << "Entrada no válida. El cuadrado está fuera de los límites de la cuadrícula." << endl;
        return 1;  // Salir con código de error
    }

    // Encontrar el número más grande en el cuadrado especificado
    int maxNumber = grid[i - 1][j - 1];
    for (int row = i - 1; row < i + s - 1; ++row) {
        for (int col = j - 1; col < j + s - 1; ++col) {
            maxNumber = max(maxNumber, grid[row][col]);
        }
    }

    // Mostrar el resultado al usuario
    cout << "El número más grande en el cuadrado es: " << maxNumber << endl;

    return 0;
}
