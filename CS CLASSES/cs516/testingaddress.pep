BR main 
a: .block 2
b: .block 2
hpPtr: .ADDRSS heap
heap: .BLOCK     1
; A is number of bytes
; X is pointer to bytes
malloc: LDWX hpPtr,d
ADDA     hpPtr,d
STWA     hpPtr,d
RET

main: LDWA     1,i; preps malloc function to open one byte
CALL malloc; allocates one byte and stores location in x 
STWX     a,d; a is now holding the address for that byte
LDBA     'a',i
STBA     a,n
;ADDX     1,i
;LDBA     'B',i
;STBA     a,n
LDWA 1,i
CALL malloc; allocates one byte and stores location in x 
STWX     b,d; a is now holding the address for that byte
LDBA     'B',i
STBA     b,n
LDBA     a,n
STBA     charOut,d
LDWA     a,d
ADDA     1,i
STWA     a,d
LDBA     a,n
STBA     charOut,d

LDBA     b,n
STBA     charOut,d




.end

