#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const double g = 9.80;
const double G = 6.673 * pow(10,-11);

const double Pico = pow(10,-12);
const double Nano = pow(10,-9);
const double Micro = pow(10,-6);
const double Mili = pow(10,-3);
const double Centi = pow(10,-2);
const double Kilo = pow(10,3);
const double Mega = pow (10,6);
const double Giga = pow(10,9);
//Metric conversion functions
double inchesToMilimeters(double x)
{
    return(x * 25.4);
}
double inchesToCentimeters(double x)
{
    return(x * 2.54);
}
double inchesToMeters(double x)
{
    return(x / 39.37);
}
double inchesToKilometers(double x)
{
    return(x / 39370);
}
double feetToMilimeters(double x)
{
    return(x * 304.8);
}
double feetToCentimeters(double x)
{
    return(x * 30.48);
}
double feetToMeters(double x)
{
    return(x / 3.281);
}
double feetToKilometers(double x)
{
    return(x / 3281);
}
double milesToMilimeters(double x)
{
    return(x * 1609000);
}
double milesToCentimeters(double x)
{
    return(x * 160900);
}
double milesToMeters(double x)
{
    return(x * 1609);
}
double milesToKilometers(double x)
{
    return(x * 1.609);
}

//Imperial conversion functions
double milimeterToinches(double x)
{
    return(x / 25.4);
}
double milimetersToFeet(double x)
{
    return(x / 304.8);
}
double milimetersToMiles(double x)
{
    return(x / 1609000);
}
double centimetersToInches(double x)
{
    return(x / 2.54);
}
double centimetersToFeet(double x)
{
    return(x / 30.48);
}
double centimetersToMiles(double x)
{
    return(x / 160900);
}
double metersToInches(double x)
{
    return(x * 39.37);
}
double metersToFeet(double x)
{
    return(x * 3.281);
}
double metersToMiles(double x)
{
    return(x / 1609);
}
double kilometersToInches(double x)
{
    return(x * 39370);
}
double kilometersToFeet(double x)
{
    return(x * 3281);
}
double kilometersToMiles(double x)
{
    return(x / 1.609);
}

//One-Dimensional Kinematics
//x = position, v = velocity, t = time, a = acceleration
//Dr = scalar with magnitude, Dv = vector with magnitude

double x_by_v_t(double x0,double v,double t) //Accepts starting position,velocity, and time
{
    return(x0 + (v * t));
}
double x_by_startx_startv_a_t(double x0,double v0,double t,double a)
{
    return(x0 + (v0 * t) + (1/2)*(a * (t * t)));
}
double x_by_startx_Deltav_t(double x0,double v0,double v,double t)
{
    return(x0 + (1/2)*(v + v0)*t);
}
double v_by_deltax_t(double x0,double x,double t)//accepts starting position, final position, and time
{
    return((x - x0) /t );
}
double v_by_startv_a(double v0,double a,double t)
{
    return(v0 + (a*t));
}
double a_by_deltav_t(double v0,double v,double t)
{
    return((v - v0) / t);
}
//Two-Dimensional Kinematics
double scalarMagnitudeByStartScalMagAvergVecMagTime(double Dr0, double Dvavg,double t)
{
    return(Dr0 + (Dvavg * t));
}
//Tool functions
void gnuPlot()
{

}


int main(int argc,char* argv[])
{
}
