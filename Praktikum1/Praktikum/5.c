#include <stdio.h>

typedef struct {
    double real;
    double imag;
} complex;

complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex subtract(complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

complex multiply(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

complex divide(complex a, complex b) {
    complex result;
    double denom = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

void print_complex(complex z) {
    printf("%.2f + %.2fi\n", z.real, z.imag);
}

void main() {
    complex a, b, result;
    int operator;
    printf("Masukan bilangan kompleks pertama: ");
    scanf("%lf %lf", &a.real, &a.imag);
    printf("Masukan bilangan kompleks kedua: ");
    scanf("%lf %lf", &b.real, &b.imag);
    printf("1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n");
    printf("Masukan operator: ");
    scanf("%d", &operator);

    switch(operator) {
        case 1:
            result = add(a, b);
            break;
        case 2:
            result = subtract(a, b);
            break;
        case 3:
            result = multiply(a, b);
            break;
        case 4:
            result = divide(a, b);
            break;
        default:
            printf("Operator tidak ditemukan");
            return;
    }

    print_complex(result);


}
