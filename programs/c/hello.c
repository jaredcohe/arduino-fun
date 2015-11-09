#include <stdio.h>
// to compile: gcc hello.c -o hello
// then run with ./hello

int main()
{
    printf( "Hello, World.\n" );
}

// if conditional
int x = 1;
if (x == 1)
    printf("correct");
else
    printf("wrong");

// switch conditional
switch (x) {
    case 0: 
        y = 1;
        break;
    case 1:
        y = 2;
        break;
    default:
        y = 3;
}

// while loop
int i = 0;
while (i < 3) {
    printf("%i", i);
    i = i + 1;
}

// for loop
int i;
for (i=0; i < 3; i++) {
    print("%i", i);
}

// function
void foo() {
    int x, y=2, x=3;
    y = y + x;
    x = y;
    printf("%i", x);
}

// to run foo function
int main() {
    foo();
}

void foo(int a, int b) {
    int x, temp;
    temp = a + b;
    x = temp;
    return (x);
}

int main() {
    p = foo(2, 3);
    printf("%i", p);
}
