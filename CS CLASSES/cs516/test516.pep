BR main 

exam1: .BLOCK 2
exam2: .Block 2
score: .BLOCK 2
bonus: .EQUATE 10

main:DECI     exam1,d 
DECI     exam2 ,d            
LDWA     exam1,d
CPWA     255,d
BRGE
ADDA     exam2,d
ASRA     
ADDA     bonus,i
STWA     score,d
STRO     msg,d
DECO     score,d
STOP    
msg:    .ASCII "score = \x00"
.END