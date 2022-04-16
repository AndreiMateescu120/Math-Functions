#include "MathFunction.h"
#include<cmath>

//Functii MathFunction

MathFunction::MathFunction(std::string function_name) :function_name(function_name) {};

std::string MathFunction::get_name() { return function_name; };



//Functii Polynomial

Polynomial::Polynomial(std::string function_name, float coefficients[], int n) :MathFunction(function_name), n(n)
{
    (this->coefficients) = new float[n];

    for (int i = 0; i < n; i++)
        this->coefficients[i] = coefficients[i];
}

void Polynomial::afisare()
{
    std::cout << "Polynomial\nf(x) = ";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            std::cout << coefficients[i] << " ";
        else if (i == 1)
        {
            if (coefficients[i] < -1)
                std::cout << coefficients[i] << "x ";
            else if (coefficients[i] == -1)
                std::cout << "- x ";
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] == 1)
                std::cout << "+ x ";
            else
                std::cout << "+ " << coefficients[i] << "x";
        }
        else
        {
            if (coefficients[i] < -1)
                std::cout << coefficients[i] << "x^" << i;
            else if (coefficients[i] == -1)
                std::cout << " - x^" << i;
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] == 1)
                std::cout << " + x^" << i;
            else
                std::cout << " + " << coefficients[i] << "x^" << i;
        }
    }
}

void Polynomial::afisare2()
{
    std::cout << "f(x) = ";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            std::cout << coefficients[i] << " ";
        else if (i == 1)
        {
            if (coefficients[i] < -1)
                std::cout << " - " << abs(coefficients[i]) << "x ";
            else if (coefficients[i] == -1)
                std::cout << "- x ";
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] == 1)
                std::cout << "+ x ";
            else
                std::cout << "+ " << coefficients[i] << "x";
        }
        else
        {
            if (coefficients[i] < -1)
                std::cout << " - " << abs(coefficients[i]) << "x^" << i;
            else if (coefficients[i] == -1)
                std::cout << " - x^" << i;
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] == 1)
                std::cout << " + x^" << i;
            else
                std::cout << " + " << coefficients[i] << "x^" << i;
        }
    }
}

float Polynomial::get_max_value(int m, int M)
{
    float max = 0;
    float s;
    int aux;

    // int n;
    // float *coefficients;

    for (int i = m; i <= M; i++)
    {
        aux = i;
        s = coefficients[0];
        for (int j = 1; j < this->n; j++)
        {
            s = s + aux * coefficients[j];
            aux = aux * i;
        }
        if (s >= max)
            max = s;
    }

    return max;
}

float Polynomial::get_value(int x)
{
    float s = 0;
    float aux = 1;

    for (int j = 0; j < this->n; j++)
    {
        s = s + aux * coefficients[j];
        aux = aux * x;
    }

    return s;
}

//Functii Quadratic

Quadratic::Quadratic(std::string function_name, float coefficients[], int n) :Polynomial(function_name, coefficients, n) {}

void Quadratic::afisare()
{
    std::cout << "Quadratic\nf(x) = ";
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            std::cout << coefficients[i] << " ";
        else if (i == 1)
        {
            if (coefficients[i] < -1)
                std::cout << coefficients[i] << "x ";
            else if (coefficients[i] == -1)
                std::cout << "- x ";
            else if (coefficients[i] > -1 && coefficients[i] < 0)
                std::cout << coefficients[i] << "x ";
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] < 1 && coefficients[i]>0)
                std::cout << "+ " << coefficients[i] << "x";
            else if (coefficients[i] == 1)
                std::cout << "+ x ";
            else
                std::cout << "+ " << coefficients[i] << "x";
        }
        else
        {
            if (coefficients[i] < -1)
                std::cout << coefficients[i] << "x^" << i;
            else if (coefficients[i] == -1)
                std::cout << " - x^" << i;
            else if (coefficients[i] == 0)
                std::cout << "";
            else if (coefficients[i] == 1)
                std::cout << " + x^" << i;
            else
                std::cout << " + " << coefficients[i] << "x^" << i;
        }
    }
}

void Quadratic::calculare_radacini()
{
    int k = 0;

    if ((coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2]) < 0)
        {
        std::cout << "Radacinile ecuatiei sunt complexe\n";
        k++;
        }
    if (k==0)
    {
        float x1, x2;
        x1 = (-coefficients[1] + sqrt(coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2])) / (2 * coefficients[2]);
        x2 = (-coefficients[1] - sqrt(coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2])) / (2 * coefficients[2]);

        if (x1 == x2)
        {
            std::cout << "X1 = X2 = ";
            printf("%.2f\n", x1);
        }
        else
        {
            std::cout << "X1 = ";
            printf("%.2f\n", x1);

            std::cout << "X2 = ";
            printf("%.2f\n", x2);
        }
    }
}

//Functii Exponential

Exponential::Exponential(std::string function_name, float constant, float exp_coeff) :MathFunction(function_name), constant(constant), exp_coeff(exp_coeff) {}

void Exponential::afisare()
{
    std::cout << "Exponential\nf(x) = ";
    if (exp_coeff >= 0)
        std::cout << constant << " + " << exp_coeff << "e^x";
    else
        std::cout << constant << " " << exp_coeff << "e^x";

}

void Exponential::afisare2()
{
    std::cout << "f(x) = ";
    if (exp_coeff >= 0)
        std::cout << constant << " + " << exp_coeff << "e^x";
    else
        std::cout << constant << " " << exp_coeff << "e^x";

}

float Exponential::get_constant() { return constant; }

float Exponential::get_exp_coeff() { return exp_coeff; }

float Exponential::get_max_value(int m, int M)
{
    float max=0.0;
    float valoare;

    // const float e=2.71;
    // float constant;
    // float exp_coeff;

    for (int i = m; i <= M; i++)
    {
        valoare = constant + exp_coeff * pow(e, i);

        if (valoare > max)
            max = valoare;
    }


    return max;
}

float Exponential::get_value(int x)
{
    return constant + exp_coeff * pow(e, x);
}

//Functii DiscreteFunction


DiscreteFunction::DiscreteFunction(std::string function_name) :MathFunction(function_name) {};

void DiscreteFunction::adaugare(float* x_values, float* y_values, int nx, int ny)
{
    this->nx = nx;
    this->ny = ny;


    (this->x_values) = new float[nx];
    (this->y_values) = new float[ny];


    for (int i = 0; i < nx; i++)
        this->x_values[i] = x_values[i];

    for (int i = 0; i < ny; i++)
        this->y_values[i] = y_values[i];

}

void DiscreteFunction::find_best_approximation(MathFunction** mathfunction, int n)
{
    float y1 = (float)(*(mathfunction[0])).get_value(x_values[0]);
    float y2 = (*(mathfunction[0])).get_value(x_values[1]);
    float y3 = (*(mathfunction[0])).get_value(x_values[2]);
    float aproximare;
    float min;

    min = abs(y_values[0] - y1) + abs(y_values[1] - y2) + abs(y_values[2] - y3);


    for (int i = 0; i < n; i++)
    {
        y1 = (*(mathfunction[i])).get_value(x_values[0]);
        y2 = (*(mathfunction[i])).get_value(x_values[1]);
        y3 = (*(mathfunction[i])).get_value(x_values[2]);

        aproximare = abs(y_values[0] - y1) + abs(y_values[1] - y2) + abs(y_values[2] - y3);

        if (aproximare <= min)
            min = aproximare;
    }

    for (int i = 1; i < n; i++)
    {
        y1 = (*(mathfunction[i])).get_value(x_values[0]);
        y2 = (*(mathfunction[i])).get_value(x_values[1]);
        y3 = (*(mathfunction[i])).get_value(x_values[2]);

        aproximare = abs(y_values[0] - y1) + abs(y_values[1] - y2) + abs(y_values[2] - y3);

        if (aproximare == min)
            (*(mathfunction[i])).afisare2();
    }
    std::cout << "\n";
    std::cout << min << "\n";

}
