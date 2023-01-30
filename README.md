# VMTranslator

The code for VMTranslator for translating VM code into Hack assembly. (A project in Nand2Tetris course)

### 1) CodeGen for push memSeg i

```
//push memSeg i
//D = i
@i
D=A

//A = memSeg + i
@LCL
A=M+D

//RAM[SP] = RAM[ADDR]
D=M
@SP
A=M
M=D

//SP++
@SP
M=M+1
```
