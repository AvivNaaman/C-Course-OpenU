;; second pass tester - By @AvivNaaman. Please NOT Re-use this input file 
;  in your project. I Share it so you can use it for testing. (c)

; will be used later
DataIsNice: .data -1,5,-99,1024
DATALABEL: .string "Very Generic String"
MathFacts: .string "sigma is sum, pi is mult."
MyOtherOtherString: .string "My other string"

.entry MyFirstString
.entry CODELABEL
CODELABEL: mov r0, r1

; eMathFactsternal label cannot be defined as an entry one as well
.entry EMathFactsTERNLABEL

; jumping to data label is invalid - relative addr mode to data
jmp &MyFirstString

prn MyOtherOtherStringS
prn YSTRING
prn MYSTRIN
prn MyOtherOtherString0
prn MyOtherOtherString123

dec MathFactsMathFacts
inc MathFacts
inc Y
dec MathFacts0

.entry SOMEUNKNOWNLABEL
.entry 0DataIsNice
.entry DataIsNice0
.entry 0
.entry 0MyOtherOtherString
.entry MyOtherOtherString
.entry NULL
.entry DataIsNice

; Assembler will ignore
IgnoreMe:

jmp &IgnoreMe
