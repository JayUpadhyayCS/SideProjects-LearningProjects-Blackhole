;// Upadhyay, Jay CS516 Section 11107 11/08/19
;// Third Laboratory Assignment - ZipCodes 
BR main
msg0: .ASCII "Pierce College CS516 Fall 2019 Lab Assignment 2 - Upadhyay, Jay\n\x00" 
msg1: .ASCII "Enter the Zip codes, two-character state codes, and state names. Enter a Zip code of -9999 to end the input.\n\x00"
msg2: .ASCII "Too many Zip code range records - maximum is 70\n\x00"
msg3: .ASCII     " Zip Code records read\n\x00"
msg4: .ASCII     "Enter 1 to get the Zip code range for a state, 2 to get the state name for a Zip code, or 3 to end\n\x00"
msg5: .ASCII     "Response must be 1, 2, or 3 - please try again\n\x00"
msg6: .ASCII     "Zip code range for state \x00"
msg61:.ASCII     " is \x00"
msg62:.ASCII     " through \x00"
msg63:.ASCII           "\n\x00" 
msg7: .ASCII     "State code \x00"
msg71: .ASCII " was not found in the table\n\x00"
msg8: .ASCII     "Zip code \x00"
msg81: .ASCII " is in state \x00"
msg82: .ASCII "\n\x00"
msg9: .ASCII     "Zip code \x00"
msg91: .ASCII" was not found in any state\n\x00" ;premade msgs
arrayL: .BLOCK 140
arrayH: .BLOCK 140
arrayCh: .BLOCK 140
index: .BLOCK 2
input: .BLOCK 2
memChar:.EQUATE 1
string: .BLOCK 140
hpPtr: .ADDRSS heap
heap: .BLOCK     500


malloc: LDWA hpPtr,d
again2:LDBX     charIn,d
CPBX     ' ',i; if a=\n do something
BREQ     again2
CPBX     '\t',i; if a=\n do something
BREQ     again2
STBX     hpPtr,n
LDBX     hpPtr,n
CPBX     '\n',i; if a=\n do something7
BREQ     return3
LDWX     hpPtr,d
ADDX     1,i
STWX     hpPtr,d
RET
return3:LDBX     1,i
ADDX     hpPtr,d
STWX     hpPtr,d
BR return
outstr: LDWA       string,x

rep2: STWA     hpPtr,d
LDBX     hpPtr,n

CPBX     '\n',i; if a=\n do something

BREQ     ret2; replace with next1
STBX     charOut,d
ADDA     1,i
BR       rep2
ret2: RET


main:STRO msg0,d
STRO msg1,d
LDWX 0,i
STWX index,d

for:DECI arrayL,x; Take first number
LDWA     -9999,i; check if -9999
CPWA     arrayL,x
BREQ     pt2; go part2
DECI arrayH,x; take in high zip


rep:LDBA     charIn,d; take in a character 
STBA     arrayCh,x; MAYBE condense
LDBA     '\t',i 
CPBA     arrayCh,x
BREQ     rep
LDBA     '\n',i 
CPBA     arrayCh,x
BREQ     rep
LDBA     ' ',i 
CPBA     arrayCh,x
BREQ     rep




ADDX     memChar,i; Add index by 1 to offset memory

LDBA     charIn,d; take character and store it
STBA     arrayCh,x

LDBA     arrayCh,x

SUBX     memChar,i; add index by 1;  changed to sub 11/7
CALL malloc; allocates one byte and stores location in  x 
LDWX     index,d
STWA     string,x
LDWA     string,x
more:CALL     malloc
br       more 
return:LDWX     index,d
ADDX     2,i
STWX     index,d;
CPWX     140,i
BREQ     error1
BR for

pt2:ASRX; divdes index by 2 to get accurate value
STWX     index,d; 
DECO     index,d;outputs index following message
ASLX
STWX     index,d; index back in form relevant to memory
STRO msg3,d

ask:STRO msg4,d; asks user for 3 inputs
DECI     input,d; take in user input
LDWA     1,i
CPWA     input,d; check input agaisnt the number input 1
BREQ     first; go to 1 if user input is 1
LDWA     2,i
CPWA     input,d
BREQ     second 
LDWA     3,i
CPWA     input,d
BREQ     end
STRO     msg5,d
BR       ask


second:LDWX      0,i 
DECI     input,d
LDWA     input,d
again:CPWX       index,d 
BREQ     noFound 
CPWA     arrayL,x
BRLT     next; next index, this index isnt right
CPWA     arrayH,x
BRGT     next;
STRO msg8,d
DECO input,d
STRO msg81,d
CALL outstr
;SUBX     1,i; cant make sense of this
;LDWA     arrayCh,x
;STBA     charOut,d
;ADDX     1,i
;LDWA     arrayCh,x
;STBA     charOut,d
STRO     msg82,d
STOP
next:ADDX 2,i
BR       again
;check if input is not less than high
;check if input is not higher than low

STRO     msg8,d               
BR       end
first: SUBSP    2,i; allocate space for a variable to hold user input
LDBA     charIn,d
STBA     0,s
LDBA     charIn,d
STBA     1,s
LDBA     0,s
LDWX     0,i
for2:CPWX index,d
BREQ     notFound
CPBA     arrayCh,x; compare user input with a character
BREQ     first2
ADDX     2,i
BRNE     for2; if its not= repeat
first2:ADDX     memChar,i;otherwise check second character for match
LDBA     1,s
CPBA     arrayCh,x
BREQ     found1
ADDX     memChar,i
LDBA     0,s
BR       for2; check this line 
found1: STRO msg6,d
LDBA     0,s
STBA     charOut,d
LDBA     1,s
STBA     charOut,d
STRO     msg61,d
SUBX     1,i
DECO     arrayL,x
STRO     msg62,d
DECO     arrayH,x
STRO     msg63,d

STOP
error1:STRO msg2,d
STOP
notFound:STRO msg7,d
LDBA     0,s
STBA     charOut,d
LDBA     1,s
STBA     charOut,d
STRO msg71,d
end:STOP
noFound:STRO msg9,d
DECO input,d
STRO msg91,d
STOP



STOP
.end