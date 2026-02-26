#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Operaciones
double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        throw runtime_error("Error: Division por cero");
    }
    return a / b;
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        cerr << "Ha ingresado valores inadecuados.\n";
        cerr << "USO ./operacion <num1> <operador> <num2>\n";
        return 1;
    }

    try {
        double num1 = stod(argv[1]);
        string operador = argv[2];
        double num2 = stod(argv[3]);

        double (*operacion)(double, double) = nullptr;

        if (operador == "+") {
            operacion = suma;
        } 
        else if (operador == "-") {
            operacion = resta;
        } 
        else if (operador == "*" || operador == "x") {
            operacion = multiplicacion;
        } 
        else if (operador == "/") {
            operacion = division;
        } 
        else {
            throw invalid_argument("Operador no valido");
        }

        double resultado = operacion(num1, num2);
        cout << "El resultado de la operacion es " << resultado << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
