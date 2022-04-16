#include "MathFunction.h"
#include<iostream>
#include<string>

int main()
{
    int n;
    std::string nume;
    int nr_termeni;
    MathFunction** mathfunction;
    float* termeni;
    float exp_coeff, constant;
    float* x, * y;
    int nr_x, nr_y;
    int z;
    int k;
    int m, M;
    DiscreteFunction discretefunction("DiscreteFunction");
    std::cout << "Introdu numarul de functii pe care vrei sa le citesti:";
    std::cin >> n;
    std::cout << "\n";
    mathfunction = new MathFunction * [n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Introdu numele functiei(Polynomial, Quadratic, Exponential)\n";
        std::cin >> nume;
        if (nume == "Polynomial")
        {
            std::cout << "Cati termeni are functia ta?";
            std::cin >> nr_termeni;
            termeni = new float[nr_termeni];
            std::cout << "\nIntrodu termenii:";
            for (int j = 0; j < nr_termeni; j++)
            {
                std::cin >> termeni[j];
            }
            (*(mathfunction + i)) = new Polynomial(nume, termeni, nr_termeni);
            delete[] termeni;
        }
        else if (nume == "Quadratic")
        {
            std::cout << "Functia patratica are 3 termeni, introdu-i:";
            termeni = new float[3];
            for (int j = 0; j < 3; j++)
            {
                std::cin >> termeni[j];
            }
            (*(mathfunction + i)) = new Quadratic(nume, termeni, 3);
            delete[] termeni;
            std::cout << "\n";
        }
        else if (nume == "Exponential")
        {
            std::cout << "Functia exponentiala are 2 termeni, introdu-i:";
            std::cin >> constant;
            std::cin >> exp_coeff;
            (*(mathfunction + i)) = new Exponential(nume, constant, exp_coeff);
            std::cout << "\n";
        }
        else
        {
            std::cout << "Nu exista acest tip de functie";
            i--;
        }
    }

    while (1)
    {
        std::cout << "Meniu:\n1.Afisarea functiilor\n2.Calcularea radacinilor de grad 2 pentru functiile patratice\n3.Calcularea maximului functiilor\n4.Introdu 3 valori pentru x si 3 valori pentru y si afla care e cea mai buna aproximare facuta de functiile descrise de tine\n5.Exit\n";


        std::cin >> z;

        switch (z)
        {
        case 1:

            for (int i = 0; i < n; i++)
            {
                (*(mathfunction + i))->afisare();
                std::cout << "\n";
            }
            break;

        case 2:
            k = 0;

            for (int i = 0; i < n; i++)
            {
                if ((*(mathfunction + i))->get_name() == "Quadratic")
                {
                    (*(mathfunction + i))->calculare_radacini();
                    k++;
                }
            }

            if (k == 0)
            {
                std::cout << "Nu avem nicio functie patratica.\n";
            }
            break;


        case 3:

            std::cout << "Introdu domeniul de definitie al functiilor. Mai intai limita inferioara, apoi limita superioara.";
            std::cin >> m >> M;

            for (int i = 0; i < n; i++)
            {
                printf("%.2f\n", (*(mathfunction + i))->get_max_value(m, M));
            }
            break;

        case 4:

            std::cout << "Introdu cele 3 valori ale x-ului: ";
            x = new float[3];
            y = new float[3];

            for (int j = 0; j < 3; j++)
            {
                std::cin >> x[j];
            }

            std::cout << "Introdu cele 3 valori ale y-ului: ";

            for (int j = 0; j < 3; j++)
            {
                std::cin >> y[j];
            }

            discretefunction.adaugare(x, y, 3, 3);

            discretefunction.find_best_approximation(mathfunction, n);

            break;

        case 5:
            exit(1);
        }

    }



    return 0;
}

