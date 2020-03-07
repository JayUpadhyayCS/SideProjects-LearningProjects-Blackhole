; Upadhyay, Jay CS516 Section 11107 Date completed 11/26/19
; Lab 5 - Bresenham's Algorithm
; Converted from wiki at https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm: ; {insert web link here} 
;PLOTTING POINTS ONE BY ONE
;plotLine(x0,y0, x1,y1)
;  dx = x1 - x0
;  dy = y1 - y0
;  D = 2*dy - dx
;  y = y0
;
;  for x from x0 to x1
;    plot(x,y)
;    if D > 0
;       y = y + 1
;       D = D - 2*dx
;    end if
;    D = D + 2*dy

;        ;  D = 2*dx - dy
;; for y from y0 to y1
 ;   plot(x,y)
 ;   if D > 0
 ;      x = x + 1
 ;      D = D - 2*dy
 ;   end if
 ;   D = D + 2*dx

BR main
y1:.block 2
y2:.block 2
x1:.block 2
x2:.block 2
dx: .block 2
tempdx: .block 2
dy: .block 2
D: .block 2
D2: .block 2
Y: .block 2
msg1: .ASCII "Pierce College CS516 Fall 2019 Lab Assignment 5 - Upadhyay, Jay \n\x00"
msg2: .ASCII "Enter two pairs of point coordinates in the range of 0-599.\x00"
msg3: .ASCII "Value out of range, ending.\n\X00"
msg4: .ASCII " \x00"
msg5: .ASCII "\n\x00"
msg6: .ASCII "EOF\n\x00"

main: STRO msg1,d
STRO msg2,d
DECI x1,d
DECI y1,d
DECI x2,d
DECI y2,d

; ERROR CHECKING
LDWA x1,d
CPWA 0,i
BRLT error
CPWA 600,i
BRGE     error
LDWA y1,d
CPWA 0,i
BRLT error
CPWA 600,i
BRGE     error
LDWA x2,d
CPWA 0,i
BRLT error
CPWA 600,i
BRGE     error
LDWA y2,d
CPWA 0,i
BRLT error
CPWA 600,i
BRGE     error

LDWA x2,d
SUBA x1,d
STWA     dx,d

LDWA y2,d
SUBA y1,d
STWA     dy,d

ASLA
SUBA dx,d
STWA D,d
LDWA     y1,d
STWA Y,d

LDWA dx,d
ASLA
SUBA dy,d
STWA D2,d

;; start for loop
LDWX x1,d
SUBX 1,i
for:ADDX 1,i
STWX x1,d

DECO x1,d
STRO msg4,d
DECO Y,d
STRO msg5,d
LDWA D,d
CPWA 0,i
BRGT if
back: LDWA dy,d
ASLA
ADDA D,d
STWA D,d
CPWX x2,d
BRLT  for

;DECO Y,d 
;DECO y1,d
;STRO msg5,d
;STRO msg5,d
LDWA Y,d
SUBA 1,i
CPWA     y2,d
BRNE     if3 
STRO msg6,d
STOP
;;;; 




LDWX y1,d
SUBX 1,i
for1:ADDX 1,i 
STWX y1,d

DECO x1,d
STRO msg4,d
DECO y1,d
STRO msg5,d


if3:LDWA D2,d
CPWA 0,i
BRGT if1 
back1: LDWA dx,d
ASLA
ADDA D2,d
STWA D2,d
CPWX y2,d
BRLT  for1   
STRO msg6,d
STOP

if1:LDWA x1,d
ADDA 1,i
STWA x1,d
LDWA     dy,d
ASLA     
STWA tempdx,d
LDWA     D2,d
SUBA tempdx,d
STWA D2,d
BR back1
STOP




if:LDWA Y,d
ADDA 1,i
STWA Y,d
LDWA     dx,d
ASLA     
STWA tempdx,d
LDWA     D,d
SUBA tempdx,d
STWA D,d
BR back

STOP
error:STRO msg3,d 
.end






