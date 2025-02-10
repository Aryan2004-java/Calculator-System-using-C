#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *query = getenv("QUERY_STRING");
    double num1, num2, result = 0;
    char operation[10];

    if (query == NULL || sscanf(query, "num1=%lf&num2=%lf&operation=%s", &num1, &num2, operation) != 3) {
        printf("Content-Type: text/plain\n\n");
        printf("Invalid input");
        return 1;
    }

    if (strcmp(operation, "add") == 0) {
        result = num1 + num2;
    } else if (strcmp(operation, "subtract") == 0) {
        result = num1 - num2;
    } else if (strcmp(operation, "multiply") == 0) {
        result = num1 * num2;
    } else if (strcmp(operation, "divide") == 0) {
        if (num2 == 0) {
            printf("Content-Type: text/plain\n\n");
            printf("Error: Division by zero");
            return 1;
        }
        result = num1 / num2;
    } else {
        printf("Content-Type: text/plain\n\n");
        printf("Invalid operation");
        return 1;
    }

    printf("Content-Type: text/plain\n\n");
    printf("%.2f", result);

    return 0;
}
