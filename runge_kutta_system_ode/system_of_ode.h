#pragma once

#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


double dxdt(double x, double y);
double dzdt(double x);


double dxdt(double x, double y) {

	return log(abs(x)) - y;
}

double dzdt(double x) {
	return log(abs(x)) + x;
}