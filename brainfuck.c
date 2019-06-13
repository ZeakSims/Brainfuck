#include<stdio.h>
#include<string.h>

unsigned char buffer[30000]={0};
unsigned char* cp = buffer;

void interpret(char* input) {

        int current_char;
        int jump = 0;
        size_t i;

for (i = 0; input[i] != 0; i++) {
        
	current_char = input[i];
	//instruction(current_char); {

    
    switch(current_char){
    case '+':
        ++*cp;
        break;
    case '-':
        --*cp;
        break;
    case '>':
        ++cp;
        break;
    case '<':
        --cp;
        break;
    case '[':
        jump = i;
    case ']':
        if(*cp) {
                i = jump;
        }
        break;
    case '.':
        putchar(*cp);
        break;
    case ',':
        *cp = getchar();
        break;
    default:
        printf("Error: Encountered unknown instruction `%c`\n",current_char);
    }
//}
}
}
int main() {

	 interpret("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."); // outputs "Hello World!"
    return 0;
}
