#include <cstdio>
#include <cmath>

using namespace std;

#define equ(a, b) (fabs(a - b) < eps)
const double eps = 1e-6;

double solve(int V, int D) {
    double s = (9.8*D)/pow((double)V,2);
    if(equ(s, 1.000000)) s = 1.000000;
    return asin(s)*180/(M_PI*2);
}

int main() {
    int T=0;
    scanf("%d", &T);
    for(int i=0; i<T; ++i) {
        int D, V=0;
        scanf("%d%d", &V, &D);
        printf("Case #%d: %.7lf\n", i+1, solve(V, D));
    }
}
