;; first pass tester - By @AvivNaaman. Please NOT Re-use this input file in your project. I Share it so you can use it for testing. (c)

; label errors
LABEL: .data -2,-0,9470,+02894,+94,-12
CODELABEL: mov r0,r1
LOCALCODE: add r0,r1
LOCALDATA: .string "Let's Put some chars in here: !)@(#*$^%&"
LABEL: .string "That should make a small problem..."
CODELABEL: .data "WHY AGAIN?!"
.extern LOCALCODE
.extern LOCALDATA
.extern WHATEVEREXT
.extern LONGLONGLONGLONGLONGLONGLABEL
.extern 1nvalidLabel
.extern L@bel
.extern
WHATEVEREXT: .string "Another definition!"
VERY_VERY_VERY_VERY_VERY_LONG_LABEL_DEFINITION_SO_ITS_ILLEGAL: .data 0
SIGNS^ARE)HERE!: .data 5
1abelWithNumAgain: .data -6

; data and string errors
.string "No closing
.string No opening"
.string Not at all
.data ,1,-9,7
.data 1,-9,,7
.data 1,-9,7,
.data 1 -9 , 7
.data 1.9
.data -0.1
.data .1
.data 1.

; Operand count errors
mov
mov r0
cmp #-0,MYLABEL,HERE
add
add #-4,#-9,#7
sub LABEL
lea operand
clr
not
inc r-9,r1,r4
dec
jmp
bne &realtivelyjump,notToday
jsr
red alpha,beta
prn
rts hello
stop myprog

; Addressing type errors (by booklet p.34)


mov &op0, op1
mov &op0, &op1
mov op0, &op1
mov &op0, #2
mov op0, #2
mov #-4,#2

cmp &op0, op1
cmp &op0, r0
cmp r0, &op1

add &op0, #2
add &op0, op1
add #-4, &op1
add r0, &op1
add #-4,#2

sub &op0, #2
sub &op0, op1
sub &op0, &op1
sub r0, &op1
sub op0, #2

lea #-4, #2
lea #-4, r0
lea r0, op1
lea r0, &op1
lea &op0, r0

clr &op0
not &op0
inc #-1
dec &op0
red &op0

jmp op0
bne op0
jsr #-1

prn &op0

; More General syntax errors
mov $,#-4
mov -9.7
mov 123
mov THISISAVERYVERYLONGLABELWHICHISINVALIDHERE
.entry THISISAVERYVERYLONGLABELWHICHISINVALIDHERE
op operand,operand
label .data "Hello World!" mov r0,#-4