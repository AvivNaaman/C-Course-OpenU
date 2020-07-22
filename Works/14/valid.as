; All the valid commands/instruction:
; Some data at start..
X: .string "Hello, World! *()"
label00: .data -1, 1, -2, 78, 90, 45328, -95743
label89: .string "StrCatChrTokLen.h"
.extern label1
XYZ123XYZ: .data 0	 ,  	0 	,	 0  ,  0,	0 	
.entry XYZ123XYZ

; mov 013,13
mov #0, label00
mov #-1, r0
mov r0, r1
mov r0, label00
mov label00, label1
mov label00, r0

; cmp 013,013
cmp #-1, r0
cmp r0, r1
cmp r0, label00
cmp label00, label1
cmp label00, r0
;.;;,; ; Complicated;;;;;4321489352@!$&#(%$*) Comment

; add 013,13
add #3957, label00
add r7, label89
add label00, r6

sub #-1, r0
sub r2, r3
sub fasdiu3245dghfgshdsf78dhkj12345, label11
sub label00, r6

lea label00, fasdiu3245dghfgshdsf78dhkj12345
lea label11, r4

; Although the symbol is defined later, that should not be a problem!
clr LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

not r6
not X

inc r7
inc X1234YZASFJKFDSA524bsdasfjdgdaf

dec r0
dec fasdiu3245dghfgshdsf78dhkj12345

C0: jmp label00
jmp &C0

; Put some data here randomally:

DataIsNiceSoLearnDataSc: .string "DataIsNiceSoLearnDataSc"
.entry DataIsNiceSoLearnDataSc

; bne 12
CCC1: bne X
bne &CCC1

; jsr 12
C5: jsr X
jsr &C5

; red 13
red r4
red label00

; prn 013
prn r5
prn #-32
prn mychars

rts
rts

stop

label11: .data 9
LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL: .string " "
.entry LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
X1234YZASFJKFDSA524bsdasfjdgdaf: .data 5
.entry X1234YZASFJKFDSA524bsdasfjdgdaf
label01: .data -000000, +000000, +000001, -000004
mychars: .string "RANDOM1234567890!*&#(@%!&E(1"
	
.extern fasdiu3245dghfgshdsf78dhkj12345