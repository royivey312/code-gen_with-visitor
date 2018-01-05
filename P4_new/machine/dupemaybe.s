.DATA 0: a: 0W 2: b: 0W 4: c: 0W /* Integer and Boolean 2 bytes */

.CODE
PUSHW a
PUSHW 20
PUTSW         /* a := 20 */

PUSHW b
PUSHW 32
PUTSW         /* b := 32 */

PUSHW a GETSW
PUSHW b GETSW
ADDI          /* a + b  */

PUSHW b GETSW
PUSHW 32
MULI          /* b * 32  */

SUBI		  /* (a+b)-(b*32)	
TSTLTI       
PUSHW c
SWAPW
PUTSW		  /* c := a + b < b * 32; */

HALT