BR main 
index: .BLOCK 2
a: .block 2
string: .BLOCK 140
hpPtr: .ADDRSS heap
heap: .BLOCK     500
; A is number of bytes
; X is pointer to bytes
malloc: LDWA hpPtr,d
LDBX     charIn,d
STBX     hpPtr,n
LDBX     hpPtr,n
;STBX     charOut,d
CPBX     '\n',i; if a=\n do something
BREQ     test
LDBX     1,i
ADDX     hpPtr,d
STWX     hpPtr,d
RET

main:LDWA 0,i
STWA     index,d
CALL malloc; allocates one byte and stores location in  x 
LDWX     index,d
STWA     string,x
LDWA     string,x
;STWA     a,d
;LDBA     a,n
;STBA     charOut,d
more:CALL     malloc
br       more 

;;BR end
; if Accumulator is equivalent to \n do something else
;;CALL malloc

;ADDX     1,i
;LDBA     'B',i
;STBA     a,n
test:LDWX        index,d
LDWA       string,x

rep: STWA     hpPtr,d
LDBX     hpPtr,n

CPBX     '\n',i; if a=\n do something

BREQ     end; replace with next1
STBX     charOut,d
ADDA     1,i
BR       rep

STOP



end:.end

