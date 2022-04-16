

#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H
#include<iostream>
#include<string>

class MathFunction
{
protected:
	std::string function_name;

public:
	virtual float get_max_value(int, int) { return 0; };
	std::string get_name();
	MathFunction(std::string);
	virtual void afisare() = 0;
	virtual void afisare2() = 0;
	virtual ~MathFunction() {};
	virtual float get_constant() { return 0; };
	virtual float get_exp_coeff() { return 0; };
	virtual void calculare_radacini() {};
	virtual float get_value(int) { return 0; };
};

class Polynomial : public MathFunction
{
protected:
	int n;
	float* coefficients;
public:
	Polynomial(std::string, float[], int);
	void afisare();
	void afisare2();
	~Polynomial() {};
	float get_max_value(int, int);
	virtual float get_value(int);

};

class Quadratic : public Polynomial
{

public:
	void print_roots();
	Quadratic(std::string, float*, int);
	void afisare();
	~Quadratic() {};
	void calculare_radacini();

};

class Exponential : public MathFunction
{
private:
	const float e = 2.71;
	float constant;
	float exp_coeff;
public:
	Exponential(std::string, float, float);
	virtual float get_value(int);
	float get_constant();
	float get_exp_coeff();

	void afisare();
	void afisare2();
	~Exponential() {};
	float get_max_value(int, int);

};

class DiscreteFunction : public MathFunction
{
private:
	int nx;
	int ny;
	float* y_values;
	float* x_values;

public:
	void find_best_approximation(MathFunction**, int);
	DiscreteFunction(std::string);
	void adaugare(float*, float*, int, int);
	void afisare() {};
	void afisare2() {};
	~DiscreteFunction() {};

};







#endif