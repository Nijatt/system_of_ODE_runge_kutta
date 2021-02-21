
//#include "runge_kutta.h"
#include "system_of_ode.h"
#include <iostream>

using namespace std;


int main()
{
	double t_initial;
	double delta_t;
	double t_final;


	double x;
	double y;

	double k1, k2, k3, k4;
	double l1, l2, l3, l4;


	double K = 1;
	double M = 1;
	double C = 1;

	//initial state
	x = 10;
	y = 5;

	// time variables
	delta_t = 0.01;
	t_initial = 0.0;
	t_final = 300;


	ofstream fout("OUTCAR_system_ode.cvs");
	if (!fout) {
		cout << "\n Error" << endl;
	}

	// scientific precision
	fout << scientific;
	fout.precision(8);




	fout << "# Time: " << " , " << " x " << " , " << " y " << " , " << "\n";


	while (t_initial <= t_final) {


		k1 = dxdt(x, y);
		l1 = dzdt(x);

		k2 = dxdt(x, y + delta_t / 2 * l1);
		l2 = dzdt(x + delta_t / 2 * k1);

		k3 = dxdt(x, y + delta_t / 2 * l2);
		l3 = dzdt(x + delta_t / 2 * k2);

		k4 = dxdt(x, y + delta_t * l3);
		l4 = dzdt(x + delta_t * k3);



		//update domain
		x = x + (delta_t / 6)*(k1 + 2 * k2 + 3 * k3 + k4);
		y = y + (delta_t / 6)*(l1 + 2 * l2 + 3 * l3 + l4);


		// write into the csv file.
		fout << t_initial << " , " << x << " , " << y << " , " << "\n";

		// update current time
		t_initial += delta_t;


	}


	cout << "Program has completed successfully. Please, check output files." << endl;

	cout << "Final time: " << t_initial << endl;

	system("pause");
}

