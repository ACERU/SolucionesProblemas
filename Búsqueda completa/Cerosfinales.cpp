#include <iostream>

using namespace std;

// Función para contar la cantidad de factores 5 en la descomposición de n
int countFactorsOf5(int n) {
    int count = 0;
    while (n % 5 == 0) {
        count++;
        n /= 5;
    }
    return count;
}

// Función para encontrar el número mínimo N tal que N! tiene exactamente Q ceros
int findNForZeros(int Q) {
    int N = 5;  // Empezamos con 5 ya que hay al menos un factor de 5 en 5!
    int zeros = 0;

    while (zeros < Q) {
        zeros += countFactorsOf5(N);
        N++;
    }

    return N - 1;  // Restamos 1 porque el bucle aumenta N antes de verificar la condición
}

int main() {
    int Q;
    cout << "Ingrese la cantidad de ceros Q: ";
    cin >> Q;

    int result = findNForZeros(Q);

    cout << "El número natural mínimo N tal que N! tiene exactamente " << Q << " ceros es: " << result << endl;

    return 0;
}