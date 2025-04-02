#include <stdio.h>
 #include <string.h>
 
 #define MAX 1000
 typedef struct {
     char data[MAX];
     int top;
 } Stack;
 
 void init(Stack *s) {
     s->top = -1;
 }
 
 int isEmpty(Stack *s) {
     return s->top == -1;
 }
 
 void push(Stack *s, char c) {
     if (s->top < MAX - 1) {
         s->data[++(s->top)] = c;
     }
 }
 
 char pop(Stack *s) {
     if (!isEmpty(s)) {
         return s->data[(s->top)--];
     }
     return '\0';
 }
 
 char peek(Stack *s) {
     if (!isEmpty(s)) {
         return s->data[s->top];
     }
     return '\0';
 }
 const char* isBalanced(const char *str) {
     Stack s;
     init(&s);
     
     for (int i = 0; str[i] != '\0'; i++) {
         char c = str[i];
         if (c == '(' || c == '{' || c == '[') {
             push(&s, c);
         } else {
             if (isEmpty(&s)) return "NO";
             
             char top = pop(&s);
             if ((c == ')' && top != '(') ||
                 (c == '}' && top != '{') ||
                 (c == ']' && top != '[')) {
                 return "NO";
             }
         }
     }
     
     return isEmpty(&s) ? "YES" : "NO";
 }
 
 int main() {
     int t;
     scanf("%d", &t);
     
     while (t--) {
         char str[MAX];
         scanf("%s", str);
         printf("%s\n", isBalanced(str));
     }
     
     return 0;
 }
