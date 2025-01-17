#include <stdio.h>
#include <stdlib.h>

#define ODD(X) ((X) & 01)
#define BITON(X,N) ODD((X) >> N)
//-- Define a mask that sets all bits from Start to End to 1 by first shifting a 1 (E-S)
//-- +1 places to the right, then subtrating 1 which will give us (E-S) +1 1's, then 
//-- shift S bits away from the least significant bit to have S -> E bits all be 1
#define MASK(S,E) (((1 << ((E-S) + 1)) - 1) << S)
//-- Check if the 
#define ALLON(X,S,E) (((X) & MASK(S,E)) == MASK(S,E))
//-----------------------------------------------------------------------------
int main(void) {

    unsigned int U1,BitNumber,Start,End;

    printf("Enter an integer : ");
    scanf("%ud",&U1);
    printf("%u is %s\n",U1,ODD(U1)?"odd":"even");

    printf("Enter an integer and a bit number : ");
    scanf("%u %d",&U1,&BitNumber);
    printf("%u has bit %d %s\n",U1,BitNumber,BITON(U1,BitNumber)?"on":"off");

    printf("Enter an integer, start and end bit numbers : ");
    scanf("%u %u %u",&U1,&Start,&End);
    printf("%u has %s those bits on\n",U1,ALLON(U1,Start,End)?"all":"not all");

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
