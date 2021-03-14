#include <complex>
#include <iostream>
std::complex<double> impedence(double w, double R1, double R2, double L1,
                               double L2, double k, std::complex<double> ZL);

std::complex<double> impedence(std::complex<double> R1, std::complex<double> R2,
                               double L1, double L2, double M,
                               std::complex<double> ZL);
constexpr double toMilli(double d) { return d * 1000; }
constexpr double fromMilli(double d) { return d / 1000; }
int main() {
  double mult = 40.0 / 15.0;
    // HOW TO DEAL WITH PARALLEL, PERFORM THE RIGHT SIDE ALONE FROM THE LEFT SIDE
    // THEN CALCULATE THE PARALLEL RESISTANCE
    // AFTER THAT WE CAN DETERMINE THE CURRENT THROUGH IT WITH EASE BY VOLTAGE / RESISTANCE THROUGH LOOP
    // THIS COMMENT IS FOR ANYONE WHO WANTS TO KNOW PARALLELISM
  std::cout << impedence( )
            << std::endl;
}

std::complex<double> primaryImpedence(std::complex<double> R1, double L1) {
  return R1 + std::complex<double>(0, L1);
}
std::complex<double> primaryImpedence(double w, double R1, double L1) {
  return std::complex<double>(R1, L1 * w);
}
std::complex<double> reflectedImpedence(double w, std::complex<double> M,
                                        double R2, double L2,
                                        std::complex<double> ZL) {
  std::complex<double> top = w * w * std::pow(M, 2);
  std::complex<double> bottom = std::complex<double>(R2, w * L2) + ZL;
  return top / bottom;
}
std::complex<double> reflectedImpedence(std::complex<double> M,
                                        std::complex<double> R2, double L2,
                                        std::complex<double> ZL) {
  std::complex<double> top = std::pow(M, 2);
  std::complex<double> bottom = R2 + std::complex<double>(0, L2) + ZL;
  return top / bottom;
}
std::complex<double> impedence(std::complex<double> R1, std::complex<double> R2,
                               double L1, double L2, double M,
                               std::complex<double> ZL) {
  return primaryImpedence(R1, L1) + reflectedImpedence(M, R2, L2, ZL);
}
std::complex<double> impedence(double w, double R1, double R2, double L1,
                               double L2, double k, std::complex<double> ZL) {
  return primaryImpedence(w, R1, L1) +
         reflectedImpedence(w, k * std::sqrt(L1 * L2), R2, L2, ZL);
}