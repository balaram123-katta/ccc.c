#include <stdio.h>
#include <string.h>
#define MAX 100
// Stacks for BACK and FORWARD history
char backStack[MAX][50];
char forwardStack[MAX][50];
int backTop = -1, forwardTop = -1;
// Push page onto a stack
void push(char stack[][50], int *top, char page[]) {
 if(*top < MAX - 1) {
 (*top)++;
 strcpy(stack[*top], page);
 }
}
// Pop page from stack
void pop(char stack[][50], int *top, char page[]) {
 if(*top >= 0) {
 strcpy(page, stack[*top]);
 (*top)--;
 }
}
// MAIN PROGRAM
int main() {
 char currentPage[50] = "Home";
 int choice;
 char newPage[50], tempPage[50];
 while(1) {
 printf("\n--- Browser Navigation (STACK Simulation) ---\n");
 printf("Current Page: %s\n", currentPage);
 printf("1. Visit New Page\n");
 printf("2. Back\n");
 printf("3. Forward\n");
 printf("4. Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 if(choice == 1) {
 printf("Enter new page: ");
 scanf("%s", newPage);
 push(backStack, &backTop, currentPage); // save current in BACK stack
 strcpy(currentPage, newPage);
 forwardTop = -1; // Clear forward history when new page visited
 } else if(choice == 2) {
 if(backTop == -1) {
printf("No BACK history!\n");
 } else {
 push(forwardStack, &forwardTop, currentPage); // save current in FORWARD
 pop(backStack, &backTop, currentPage); // move back
 }
 } else if(choice == 3) {
 if(forwardTop == -1) {
 printf("No FORWARD history!\n");
 } else {
 push(backStack, &backTop, currentPage); // save current in BACK
 pop(forwardStack, &forwardTop, currentPage); // move forward
 }
 } else if(choice == 4) {
 printf("Exiting...\n");
 break;
 } 
 else {
 printf("Invalid choice.\n");
 }
 }
 return 0;
}