#include <stdio.h>

// complex is datatype which can hold real and imaginary part of a number
typedef struct complex
{
    /* data */
    double real;
    double imag;
};


// Function to add two complex numbers
struct complex ADD(struct complex n1, struct complex n2)
{
    struct complex result;
    result.real = n1.real + n2.real;
    result.imag = n1.imag + n2.imag;

    return result;
}

struct complex MUL(struct complex n1, struct complex n2)
{
    struct complex result;
    /*
        (a+ib) * (c+id) =   (ac + iad + ibc + (i^2)bd)  
                            // i^2 = (-1)
                        =   (ac - bd) + i(ad + bc)
    */
    result.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    result.imag = (n1.real * n2.imag) + (n1.imag * n2.real); 

    return result;
}



int main()
{

    struct complex c_num;
    struct complex num1, num2;

    printf("Enter first complex num(real, imag): \n");
    scanf("%lf%lf",&num1.real,&num1.imag);

    printf("Enter second complex num(real, imag): \n");
    scanf("%lf%lf",&num2.real,&num2.imag);

    c_num = ADD(num1,num2);
    printf("Sum: %.2lf + %.2lfi\n",c_num.real,c_num.imag);

    c_num = MUL(num1,num2);
    printf("MUL: %.2lf + %.2lfi\n",c_num.real,c_num.imag);

    // Square of complex num
    c_num = MUL(num1, num1);
    printf("Square of num1: %.2lf + %.2lfi\n",c_num.real,c_num.imag);
    c_num = MUL(num2, num2);
    printf("Square of num2: %.2lf + %.2lfi\n",c_num.real,c_num.imag);


    return 0;
}