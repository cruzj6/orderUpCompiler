# orderUpCompiler
Compiler for my OrderUp language

#Make Instructions
###Make Libraries
  From ./compiler directory with g++ installed run:
    ```
    make
    ```
###Make Code Generator
  From ./compiler directory with g++ installed run:
  ```
  make main
  ```

###Run Code Generation
  Run: ```oupc <sourceFile>.oup```

  Intermediate code is output to the ./compile/temp directory as <sourceFile>.i

###Make Analyzer Test Program
From ./compiler directory with g++ installed run:
  ```
  make analyzerTest
  ```
###Make Lexer Test Program
From ./compiler directory with g++ installed run:
  ```
  make lexerTest
  ```
##Run Test Programs
Run: ```analyzerTest <sourceFile>.oup``` or ```lexerTest <sourceFile>.oup```
