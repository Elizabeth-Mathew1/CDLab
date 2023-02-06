#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
char input_string[100]; char processed_string[100];
void removespace() 
{
    int k = 4;
    int len = strlen(input_string); 
    processed_string[0] = 'i'; 
    processed_string[1] = 'n';
    processed_string[2] = 't'; 
    processed_string[3] = ' ';
    for (int i = 4; i < len; i++)
    {
    if (input_string[i] != ' ') {
    processed_string[k++] = input_string[i]; }
    }
//printf("\n%s",processed_string); }
}
void analyze() {
// scanning if it is an integer array
if (input_string[0] == 'i' && input_string[1] == 'n' && input_string[2] == 't' && input_string[3] == ' ')
{
    printf("\n\nThe first identified token is: int");
} 
else 
{
    printf("\nERROR: Expected 'int', found '%c%c%c%c' instead.\n", input_string[0], input_string[1], input_string[2], input_string[3]);
    exit(0); 
}
removespace();
// scanning if the integer name is valid 
int ptr = 4;
if (isdigit(processed_string[ptr]))
{
    printf("\nERROR: Identifier can't start with a digit.\n");
    exit(0); }
    char id1[30];
    int k = 0;
    id1[k++] = processed_string[ptr]; // adding the first element of the identifier name ptr++;
    while (isalnum(processed_string[ptr]) || processed_string[ptr] == '_')
    {
    if (isalnum(processed_string[ptr]) || processed_string[ptr] == '_') 
    {
    id1[k] = processed_string[ptr];
    k++; 
    }
    else 
    {
    printf("\nERROR: Not a valid identifier.\n");
    exit(0); 
    }
    ptr++; 
    }
id1[k] = '\0';
printf("\n\nThe second identified token is: %s", id1);
// to check square brackets for size specification
if (processed_string[ptr] == '[' && processed_string[ptr + 1] == ']') {
printf("\n\nThe third identified token is: []"); }
else {
printf("\nERROR:Expected [], found '%c%c' instead", processed_string[ptr], processed_string[ptr + 1]);
exit(0); }
ptr = ptr + 2;
// checking for the '=' sign
if (processed_string[ptr] == '=') {
printf("\n\nThe fourth identified token is: =");
ptr++; }
else {
printf("\nERROR:Expected =, found '%c' instead", processed_string[ptr]);
exit(0); }
// checking for the '{' specification
if (processed_string[ptr] == '{') {
printf("\n\nThe fifth identified token is: {");
ptr++; }
else {
printf("\nERROR:Expected {, found '%c' instead", processed_string[ptr]); exit(0);
}
// analysing all the integer elements of the array
char idnum[20];
int ct = 0;
while (isdigit(processed_string[ptr]) || processed_string[ptr] == ',') {
if (isdigit(processed_string[ptr])) {
idnum[ct++] = processed_string[ptr];
ptr++; }
else if (processed_string[ptr] == ',') {
idnum[ct] = '\0';
printf("\n\nThe next identified token is :%s", idnum); printf("\n\nThe next identified token is :,");
idnum[0] = '\0';
ct = 0;
ptr++;
} else {
printf("\nERROR:Expected integer or ',' but found '%c' instead", processed_string[ptr]);
exit(0); }
}
idnum[ct] = '\0';
printf("\n\nThe next identified token is :%s", idnum); if (processed_string[ptr] == '}')
{
printf("\n\nThe next identified token is : } ");
ptr++; }
else {
printf("\nERROR:Expected integer or , or } but found '%c' instead", processed_string[ptr]);
exit(0); }
// checking for delimiter
if (processed_string[ptr] == ';') {
printf("\n\nDelimiter token succesfully identified :;");
printf("\n\nSuccessfully finished parsing"); }
else {
printf("\nERROR:Expected ; but found '%c' instead", processed_string[ptr]);
exit(0); 
}
}
int main() {
printf("\nEnter the statement to be parsed: "); 
scanf("%[^\n]s", input_string); 
printf("\n%s", input_string);
// to remove all white spaces in the input string 
analyze();
return 0;
}