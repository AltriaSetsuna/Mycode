#include <iostream>
#include<cmath>
#include<iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double dis(double x1, double y1, double x2, double y2)
{
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}
int main(int argc, char** argv)
{
	double c;
	double R, x1, y1, x2, y2;
	std::cin >> R >> x1 >> y1 >> x2 >> y2;
	double d = dis(x1, y1, x2, y2);
	if (d == 0)
	{
		double r = R / 2;
		double x = x1 + r;
		double y = y1;
		std::cout<<std::fixed<<std::setprecision(16)<<x<<' '<<y<<' '<<r;
	}
	else if (d >= R)
	{
		std::cout <<std::fixed<<std::setprecision(16)<< x1 << ' ' << y1 << ' ' << R;
	}
	else
	{
		double r = (d + R) / 2;
		double si = (y1 - y2) / d;
		double co = (x1 - x2) / d;
		double x = x2 + r * co;
		double y = y2 + r * si;
		std::cout<<std::fixed<<std::setprecision(16)<<x<<' '<<y<<' '<<r;
	   //std::fixed
	}
	return 0;
}
