#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	int char_select = (rand() % (126 - 32 +1 )) + 32;
	char temp = (char)char_select;
    return temp;
}

char *inputString()
{
	/*int upper_limit = 20;
	int lower_limit = 5;*/
	int string_length, i = 0;
	//string_length = (rand() % (upper_limit - lower_limit+1)) + lower_limit;
	string_length = 6;
	char temp_string[string_length];

	for (i = 0; i < string_length - 1; i++) {
		int char_select = (rand() % (116 - 101 + 1)) + 101;
		char temp = (char)char_select;
		temp_string[i] = temp;
	}

	temp_string[string_length - 1] = '\0';
	char *final_string = temp_string;
	return final_string;
}
 
void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
