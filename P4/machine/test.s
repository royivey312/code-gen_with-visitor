.DATA  1: a: 2: b: 6: c:
.CODE
0: PUSHW 2 PUSHW 2 GETSL PUSHW 3 PUSHW 0 GETSW MULI CVTIF ADDF PUTSL
/* Beginning of Loop */
.DATA 8: p: 12: d:
.CODE
/* Begining of If */
18: PUSHW 0 GETSW CVTIF PUSHW 2 GETSL SWAPL SUBF TSTLTF NOTW
31: RGOZ    25
/* Then */
34: PUSHW 6 PUSHW 3 PUSHW 8 GETSW MULI PUSHW 12 GETSW PUSHW 4 DIVI
                SUBI TSTLTI PUTSW
56: RGOTO    22
/* Else */
.DATA 14: c:
.CODE
59: PUSHW 2 PUSHW 8 GETSW PUSHW 14 GETSW SUBI PUSHW 17 PUSHW 0 GETSW
                DIVI ADDF PUTSW
/* End of If */
81: PUSHW 6 GETSW NOTW RGOZ 2 HALT
90: PUSHW 12 GETSW PUSHW 0 GETSW PUSHW 12 GETSW PUSHW 3 MULI PUSHW 5 DIVI
                PUSHW 8 GETSW DUPL DIVI MULI SUBI ADDI SWAPW SUBI TSTLTI NOTW RGOZ 3
126: RGOTO -111
/* End of Loop */
129: HALT .ENTRY 0 