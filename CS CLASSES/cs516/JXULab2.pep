
BR main
a: .BLOCK 2
b: .BLOCK 2
c: .BLOCK 2
temp: .BLOCK 2
msg1: .ASCII "Pierce College CS516 Fall 2019 Lab Assignment 2 - Upadhyay, Jay\n\x00"
msg2: .ASCII "Enter the values for a, b, and c.\n\x00"
msg3: .ASCII "Value \x00" 
msg32:.ASCII " is invalid -- re-enter\n\x00"
msg4: .ASCII "The discriminant is \x00"
msg5: .ASCII "The two roots are equal\n\x00"
msg6: .ASCII "The polynomial has two complex conjugate roots.\n\x00"
msg7: .ASCII "The polynomial has two distinct real roots.\n\x00"
msg8: .ASCII "The polynomial is too large for the PEP/9 and the result is not valid\n\x00"
msg9: .ASCII "Program execution is complete.\n\x00"
endLine: .ASCII ". \n\x00"

;; use for loop, iterate until second number is reached. add number agaisnt itself.
;answer+=a

 
mult:LDWX     2,s; LOAD C INTO X
LDWA     4,s; load a into accumulator
SUBX     1,i; OFFSET to fix loop
while:   ADDA     4,s; add a to accumulator
BRC error
BRV error
SUBX     1,i; subtract c by one;;; had an error here because wrong addressing mode

BRNE     while; if !=0 go to while loop
STWA     temp,d; store whats in accumulator in a
RET



main: STRO msg1,d ; output message one, begin main function
go:STRO msg2,d; output message 2
DECI a,d; take in an integer, used for go branch in case bad integer
LDWA a,d; load a into accumulator
BRLE if; if a is <=0 move to branch

DECI b,d; else take in new input
LDWA b,d; load input into accumulator
BRLE if ; if a is <=0 move to branch
DECI c,d; repeat ofabove for next 3 steps
LDWA c,d 
BRLE if



LDWA     a,d; STORE a into accum
STWA     -4,s; store accum into stack
LDWA     c,d
STWA     -6,s
SUBSP    6,i; subtract stack pointer

CALL     mult
ADDSP    6,i; pop 


LDWA     temp,d; STORE a into accum
STWA     -4,s; store accum into stack
LDWA     4,i     
STWA     -6,s
SUBSP    6,i
CALL     mult
ADDSP 6,i
LDWA     temp,d
STWA     a,d

LDWA     b,d; 
STWA     -4,s;  
STWA     -6,s
SUBSP    6,i
CALL     mult
ADDSP 6,i

LDWA     temp,d
SUBA     a,d
STWA     a,d




STRO msg4,d; output msg about discriminant
DECO a,d
STRO endLine,d 
LDWA     0,i
MOVAFLG ; clear flags then test
LDWA a,i
BREQ     zero
BRLT     less
BRGT     more     
STOP
more:STRO msg7,d
STRO msg9,d
STOP
less: STRO msg6,d
STRO msg9,d
STOP
zero:STRO msg5,d
STRO msg9,d
STOP

if: STRO msg3,d; error branch to ask for input again
STWA a,d
DECO a,d
STRO msg32,d
BREQ go ; works for some reason... 



STOP 

error:STRO msg8,d 
STOP

.END






