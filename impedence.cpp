#include <complex>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif
#pragma region operators
long double operator"" _km(long double d)
{
    return d * 1000;
}
long double operator"" _m(long double d)
{
    return d;
}
long double operator"" _mm(long double d)
{
    return d * 0.001;
}
unsigned long long int operator"" _mm(unsigned long long int d)
{
    return d / 1000;
}
long double operator"" _um(long double d)
{
    return d * 0.000001;
}
unsigned long long int operator"" _um(unsigned long long int d)
{
    return d / 1000000;
}
long double operator"" _nm(long double d)
{
    return d * 1e-09;
}
long double operator"" _hz(long double d)
{
    return d * (2 * M_PI);
}
long double from_kilometer(long double d)
{
    return d * 1000;
}
#pragma endregion
double bandwith_series(double R, double L, double C)
{
    return R / L;
}
double bandwith_parallel(double R, double L, double C)
{
    return 1 / (R * C);
}
double bandwidthfromHalf_parallel(double w1, double w2)
{
    return w2 - w1;
}
double bandwidthfromQuality(double Q, double resonance)
{
    return resonance / Q;
}
double capacitancefromQuality(double Q, double R, double resonance)
{
    return Q / (resonance * R);
}
double inductancefromQuality(double Q, double R, double resonance)
{
    return R / (Q * resonance);
}
double resonance_parallel(double R, double L, double C)
{
    return 1 / sqrt(L * C);
}
double qualityfromBandwidth(double B, double resonance)
{
    return resonance / B;
}
double qualityfromcapacitance(double R, double C, double resonance)
{
    return R * C * resonance;
}
double qualityfromInductance(double R, double L, double resonance)
{
    return R / (resonance * L);
}
double capacitancefromBandwidth_parallel(double B, double R)
{
    return 1 / (B * R);
}
double inductancefromw2_parallel(double w2, double R, double C)
{
    return R / (w2 * w2 * R * C - w2);
}
double resonance(double w1, double w2)
{
    return sqrt(w1 * w2);
}
std::complex<double> impedence(double w, double R1, double R2, double L1, double L2, double k, std::complex<double> ZL);

std::complex<double> impedence(std::complex<double> R1, std::complex<double> R2, double L1, double L2, double M,
                               std::complex<double> ZL);
constexpr double toMilli(double d)
{
    return d * 1000;
}
constexpr double toMicro(double d)
{
    return d * 1e+6;
}
constexpr double toNano(double d)
{
    return d * 1e+9;
}
int main()
{
    double mult = 40.0 / 15.0;
    double R = 2.0_km;
    double w1 = from_kilometer(86.0_hz);
    double w2 = from_kilometer(92.0_hz);
    // HOW TO DEAL WITH PARALLEL, PERFORM THE RIGHT SIDE ALONE FROM THE LEFT SIDE
    // THEN CALCULATE THE PARALLEL RESISTANCE
    // AFTER THAT WE CAN DETERMINE THE CURRENT THROUGH IT WITH EASE BY VOLTAGE / RESISTANCE THROUGH LOOP
    // THIS COMMENT IS FOR ANYONE WHO WANTS TO KNOW PARALLELISM
    double B = bandwidthfromHalf_parallel(w1, w2);
    double C = capacitancefromBandwidth_parallel(B, R);
    double L = inductancefromw2_parallel(w2, R, C);
    std::cout << resonance(w1, w2) / B << std::endl;
}

std::complex<double> primaryImpedence(std::complex<double> R1, double L1)
{
    return R1 + std::complex<double>(0, L1);
}
std::complex<double> primaryImpedence(double w, double R1, double L1)
{
    return std::complex<double>(R1, L1 * w);
}
std::complex<double> reflectedImpedence(double w, std::complex<double> M, double R2, double L2, std::complex<double> ZL)
{
    std::complex<double> top = w * w * std::pow(M, 2);
    std::complex<double> bottom = std::complex<double>(R2, w * L2) + ZL;
    return top / bottom;
}
std::complex<double> reflectedImpedence(std::complex<double> M, std::complex<double> R2, double L2,
                                        std::complex<double> ZL)
{
    std::complex<double> top = std::pow(M, 2);
    std::complex<double> bottom = R2 + std::complex<double>(0, L2) + ZL;
    return top / bottom;
}
std::complex<double> impedence(std::complex<double> R1, std::complex<double> R2, double L1, double L2, double M,
                               std::complex<double> ZL)
{
    return primaryImpedence(R1, L1) + reflectedImpedence(M, R2, L2, ZL);
}
std::complex<double> impedence(double w, double R1, double R2, double L1, double L2, double k, std::complex<double> ZL)
{
    return primaryImpedence(w, R1, L1) + reflectedImpedence(w, k * std::sqrt(L1 * L2), R2, L2, ZL);
}