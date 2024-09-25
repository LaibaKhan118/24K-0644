/*
OR (|):  a=1001
         b=1000
         ------
           1001 (ans is 1st operand)
       
AND (&):  a=1001
          b=1000 
	      -------
	        1000 (ans is 2nd operand)
	    
NOT(~):   a=1001
          ------
            0110 (true became false and vice versa)
		(we get minus 9 because NOT operation caused overflow which converts the sign)
		
Shift right (>>): a=1000
					a>>2
				  a=0010 (shifted MSB to right)
				  
Shift left (>>): a=1000
					a<<2
				 a=0010 (shifted LSB to left)
     
*/
#include<stdio.h>
int main() {
	int k = 9; int j = 8;
}