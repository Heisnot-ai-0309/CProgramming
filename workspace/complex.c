#include <stdio.h>

struct Complex {
    double a;
    double b;
};

void printComplex(struct Complex z){
    if (z.b > 0)    printf("%.5lf + j%.5lf\n", z.a, z.b);
    else            printf("%.5lf - j%.5lf\n", z.a, -z.b);
}

struct Complex addComplex(struct Complex z1, struct Complex z2){
    struct Complex z = {z1.a + z2.a, z1.b + z2.b};
    return z;
}

struct Complex subComplex(struct Complex z1, struct Complex z2){
    struct Complex z = {z1.a - z2.a, z1.b - z2.b};
    return z;
}

struct Complex mulComplex(struct Complex z1, struct Complex z2){
    struct Complex z = {z1.a*z2.a - z1.b*z2.b, z1.a*z2.b + z1.b*z2.a};
    return z;
}

struct Complex divComplex(struct Complex z1, struct Complex z2){
    float a = (z1.a*z2.a + z1.b*z2.b)/(z2.a*z2.a + z2.b*z2.b);
    float b = (-z1.a*z2.b + z1.b*z2.a)/(z2.a*z2.a + z2.b*z2.b);
    struct Complex z = {a, b};
    return z;
}

struct Complex conj(struct Complex z1){
    struct Complex z = {z1.a, -z1.b};
    return z;
}

int main(){
    struct Complex z1 = {3, 4};
    struct Complex z2 = {1, -2};
    
    printf("z1 = "); printComplex(z1);
    printf("z2 = "); printComplex(z2);

    printf("z1 + z2 = "); printComplex(addComplex(z1, z2));
    printf("z1 - z2 = "); printComplex(subComplex(z1, z2));
    printf("z1 * z2 = "); printComplex(mulComplex(z1, z2));
    printf("z1 / z2 = "); printComplex(divComplex(z1, z2));
    printf("conj(z1) = "); printComplex(conj(z1));
    printf("conj(z2) = "); printComplex(conj(z2));

    return 0;
}
