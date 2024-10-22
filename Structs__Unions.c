// Task 1
// #include <stdio.h>

// struct Time {
//     int hours;
//     int minutes;
//     int seconds;
// };

// struct Time addTimes(struct Time t1, struct Time t2) {
//     struct Time result;

//     result.seconds = t1.seconds + t2.seconds;
//     result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
//     result.seconds %= 60;
//     result.hours = t1.hours + t2.hours + (result.minutes / 60);
//     result.minutes %= 60;

//     return result;
// }

// int main() {
//     struct Time t1, t2, result;
//     printf("Enter first time (hours minutes seconds): ");
//     scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

//     printf("Enter second time (hours minutes seconds): ");
//     scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

//     result = addTimes(t1, t2);

//     printf("Sum of times: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);

//     return 0;
// }





// Task 2
// #include <stdio.h>

// struct Complex {
//     float real;
//     float imaginary;
// };

// struct Complex addComplex(struct Complex c1, struct Complex c2) {
//     struct Complex result;
//     result.real = c1.real + c2.real;
//     result.imaginary = c1.imaginary + c2.imaginary;
//     return result;
// }

// struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
//     struct Complex result;
//     result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
//     result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
//     return result;
// }

// int main() {
//     struct Complex c1, c2, sum, product;
//     printf("Enter first complex number (real and imaginary): ");
//     scanf("%f %f", &c1.real, &c1.imaginary);

//     printf("Enter second complex number (real and imaginary): ");
//     scanf("%f %f", &c2.real, &c2.imaginary);

//     sum = addComplex(c1, c2);
//     product = multiplyComplex(c1, c2);

//     printf("Sum: %.2f + %.2fi\n", sum.real, sum.imaginary);
//     printf("Product: %.2f + %.2fi\n", product.real, product.imaginary);

//     return 0;
// }




// Task 3
#include <stdio.h>

// Union to store different sensor data types
union SensorData {
    int temperature;
    float pressure;
    float humidity;
};

int main() {
    union SensorData sensor;
    int sensorType;

    printf("Enter sensor type (1 for Temperature, 2 for Pressure, 3 for Humidity): ");
    scanf("%d", &sensorType);

    if (sensorType == 1) {
        printf("Enter temperature (in degrees Celsius): ");
        scanf("%d", &sensor.temperature);
        printf("Temperature: %d°C\n", sensor.temperature);
    } 
    else if (sensorType == 2) {
        printf("Enter pressure (in Pascals): ");
        scanf("%f", &sensor.pressure);
        printf("Pressure: %.2f Pa\n", sensor.pressure);
    } 
    else if (sensorType == 3) {
        printf("Enter humidity (in percentage): ");
        scanf("%f", &sensor.humidity);
        printf("Humidity: %.2f%%\n", sensor.humidity);
    } 
    else {
        printf("Invalid sensor type.\n");
    }

    return 0;
}
