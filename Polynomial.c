#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in the polynomial
typedef struct Node {
    int coefficient;
    int x_exponent;
    int y_exponent;
    int z_exponent;
    struct Node* next;
} Node;

// Function to create a new term node
Node* createTerm(int coeff, int x_exp, int y_exp, int z_exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->x_exponent = x_exp;
    newNode->y_exponent = y_exp;
    newNode->z_exponent = z_exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(Node** head, int coeff, int x_exp, int y_exp, int z_exp) {
    Node* newTerm = createTerm(coeff, x_exp, y_exp, z_exp);
    if (*head == NULL) {
        *head = newTerm;
        newTerm->next = newTerm;
    } else {
        Node* temp = (*head)->next;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newTerm;
        newTerm->next = *head;
    }
}

// Function to evaluate a polynomial at given values of x, y, and z
int evaluatePolynomial(Node* head, int x, int y, int z) {
    int result = 0;
    Node* current = head;
    do {
        result += current->coefficient *
                  pow(x, current->x_exponent) *
                  pow(y, current->y_exponent) *
                  pow(z, current->z_exponent);
        current = current->next;
    } while (current != head);
    return result;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* term1 = poly1;
    Node* term2 = poly2;
    
    do {
        insertTerm(&result, term1->coefficient, term1->x_exponent, term1->y_exponent, term1->z_exponent);
        term1 = term1->next;
    } while (term1 != poly1);
    
    do {
        insertTerm(&result, term2->coefficient, term2->x_exponent, term2->y_exponent, term2->z_exponent);
        term2 = term2->next;
    } while (term2 != poly2);
    
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* head) {
    Node* current = head;
    do {
        printf("%dx^%dy^%dz^%d + ", current->coefficient,
               current->x_exponent, current->y_exponent, current->z_exponent);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to destroy a polynomial
void destroyPolynomial(Node** head) {
    if (*head == NULL) return;
    Node* current = (*head)->next;
    while (current != *head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(*head);
    *head = NULL;
}

int main() {
    Node* POLY1 = NULL;
    Node* POLY2 = NULL;

    // Take input for POLY1
    int terms1;
    printf("Enter the number of terms for POLY1: ");
    scanf("%d", &terms1);

    for (int i = 0; i < terms1; i++) {
        int coeff, x_exp, y_exp, z_exp;
        printf("Enter coefficient, x exponent, y exponent, and z exponent for term %d: ", i + 1);
        scanf("%d %d %d %d", &coeff, &x_exp, &y_exp, &z_exp);
        insertTerm(&POLY1, coeff, x_exp, y_exp, z_exp);
    }

    // Take input for POLY2
    int terms2;
    printf("Enter the number of terms for POLY2: ");
    scanf("%d", &terms2);

    for (int i = 0; i < terms2; i++) {
        int coeff, x_exp, y_exp, z_exp;
        printf("Enter coefficient, x exponent, y exponent, and z exponent for term %d: ", i + 1);
        scanf("%d %d %d %d", &coeff, &x_exp, &y_exp, &z_exp);
        insertTerm(&POLY2, coeff, x_exp, y_exp, z_exp);
    }

    // Display the polynomials
    printf("POLY1: ");
    displayPolynomial(POLY1);
    printf("POLY2: ");
    displayPolynomial(POLY2);

    // Take input for x, y, and z for evaluation
    int x, y, z;
    printf("Enter values for x, y, and z for evaluation: ");
    scanf("%d %d %d", &x, &y, &z);

    // Evaluate POLY1 at the given values
    int result1 = evaluatePolynomial(POLY1, x, y, z);
    printf("Result of POLY1 at x=%d, y=%d, z=%d: %d\n", x, y, z, result1);

    // Add POLY1 and POLY2 and store the result in POLYSUM
    Node* POLYSUM = addPolynomials(POLY1, POLY2);
    printf("POLYSUM: ");
    displayPolynomial(POLYSUM);

    // Clean up memory
    destroyPolynomial(&POLY1);
    destroyPolynomial(&POLY2);
    destroyPolynomial(&POLYSUM);

    return 0;
}
