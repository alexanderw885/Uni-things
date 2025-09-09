.class public CountAlt
.super java/lang/Object

; the instance initialization method
.method public <init>()V
    ; call Object's initializer (i.e., the default)
    aload 0
    invokespecial java/lang/Object/<init>()V
    return
.end method

.method public static main([Ljava/lang/String;)V
    .limit stack 3
    .limit locals 4

    getstatic java/lang/System/out Ljava/io/PrintStream;

    ; Recall that A is an "atomic type" (i.e., a reference)
    astore 1

    ; there is our maximum loop count
    bipush 10  ; "bi" is for a integer the size of a byte
    istore 2

    Loop:
        bipush 10
        iload 2
        isub
        invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
        astore 3

        aload 1
        aload 3
        invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

        iinc 2 -1   ; increment local integer (effectively here a decr.)
        iload 2
        ifne Loop   ; value on stack not equal to zero? then branch
        return
.end method
