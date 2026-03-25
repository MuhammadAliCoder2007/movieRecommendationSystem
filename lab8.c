#include <stdio.h>

struct Rectangle {
    float length;
    float width;
};

struct Rectangle createRectangle(float length, float width) {
    struct Rectangle r;
    r.length = length;
    r.width = width;
    return r;
}

void printRectangle(struct Rectangle r) {
    float a = r.length * r.width;
    float p = 2 * (r.length + r.width);
    printf("Length: %.1f, Width: %.1f, Area: %.1f, Perimeter: %.1f\n",
           r.length, r.width, a, p);
}

void updateRectangleByPointer(struct Rectangle *r) {
    (*r).length +=1;
    (*r).width +=1;
    
}
struct Rectangle doubleRectangle(struct Rectangle r) {
    struct Rectangle nr;
    nr.length = r.length*2;
    nr.width = r.width*2;

    return nr;
}

int main() {
    float length, width;
    printf("Enter length and width of rectangle: ");
    scanf("%f %f", &length, &width);

    struct Rectangle rect = createRectangle(length, width);
    printf("Initial Rectangle -->");
    printRectangle(rect);

    updateRectangleByPointer(&rect);
    printf("After Update -->");
    printf("Length: %.2f, Width: %.2f\n", rect.length, rect.width);

    struct Rectangle doubled = doubleRectangle(rect);
    printf("Doubled rectangle--> ");
    printRectangle(doubled);

    return 0;

}