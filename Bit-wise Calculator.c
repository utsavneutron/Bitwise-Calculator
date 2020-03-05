#include <stdio.h>
#define BITS 8

void ConvertDecimalToBinary(int mnum, char binArray[])
{
    int bitmask=1;
    int i=0;
    for(i=1; mnum!=0; i++)
    {
        if(mnum & bitmask)
        {
            binArray[BITS-i]=49;
        }
        else
        {
            binArray[BITS-i]=48;
        }
        mnum=mnum>>1;
    }
}

int main(void)
{
    int op1=0,  op2=0, i;
    char mOp[2];
	char binArray1[BITS+1]={}, binArray2[BITS+1]={}, binArrayResult[BITS+1]={};
	int solved;

    while((op1||op2>255) || (op1||op2<=0))
    {
        
        printf("Bitwise Calculator\n\n Enter two base 10 values with a bitwise operator to see the decimal result\nand the 	binary result. The format is\n\nFirstNumber BitwiseOperator SecondNumber\n\nFor example, enter the expression\n\n2 & 3\n\nThis calculator can be used with &, |, ^, << and >>\n\nPlease note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");
    
        printf("Enter expression ");
        for(i=0; i<2; i++)
        {
        scanf("%d %c%d", &op1, &mOp[i], &op2);
        }
    }
    
    for(i=0; i<2; i++)
    {
        if(mOp[i]!=('&','|','^','<','>'))
        {
            printf(" Operator %c is not supported by this calculator", mOp[i]);
            return 0;
        }
    
        if(mOp[i]=='&')
	    {
		   char op1Bin, op2Bin, resultBin;
		   solved= op1&op2;
		   ConvertDecimalToBinary(op1, binArray1);
		   ConvertDecimalToBinary(op2, binArray2);
		   ConvertDecimalToBinary(solved, binArrayResult);
		   int j=0, k=0, l=0;
		   for(j=0; j<BITS; j++)
		   {
			   op1Bin=op1Bin+ binArray1[j];
		   }
		   for(k=0; k<BITS; k++)
		   {
			   op2Bin=op2Bin+binArray2[k];
		   }
		   for(l=0; l<BITS; l++)
		   {
			   resultBin=resultBin+binArrayResult[l];
		   }
		   
		   printf("In base 10...\n\n%d %c %d= %d", op1, mOp[i], op2, solved);
		   printf("\n\n\n In 8-bit base 2...\n\n  %c\n&\n  %c\n  ========\n  %c",op1Bin, op2Bin, resultBin);
	    }
	   
	    else if(mOp[i]=='|')
	    {
		   char op1Bin, op2Bin, resultBin;
		   solved= op1|op2;
		   ConvertDecimalToBinary(op1, binArray1);
		   ConvertDecimalToBinary(op2, binArray2);
		   ConvertDecimalToBinary(solved, binArrayResult);
		   int j=0, k=0, l=0;
		   for(j=0; j<BITS; j++)
		   {
			   op1Bin=op1Bin+ binArray1[j];
		   }
		   for(k=0; k<BITS; k++)
		   {
			   op2Bin=op2Bin+binArray2[k];
		   }
		   for(l=0; l<BITS; l++)
		   {
			   resultBin=resultBin+binArrayResult[l];
		   }
		   
		   printf("In base 10...\n\n%d %c %d= %d", op1, mOp[i], op2, solved);
		   printf("\n\n\n In 8-bit base 2...\n\n  %c\n&\n  %c\n  ========\n  %c",op1Bin, op2Bin, resultBin);
	    }
	   
		   
    }
    
 
    return 0;
}
