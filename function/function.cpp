#include <cmath>
#include <stdbool.h>

double calcolaAngoloGradi(double x, double y) {
    double angolo = std::atan2(y, x) * 180.0 / M_PI;
    return (angolo < 0) ? angolo + 360.0 : angolo;
}

double gestisciAngolo(double x, double y, bool r) {
    double angolo = calcolaAngoloGradi(x, y);
    return r ? -angolo : angolo;
}