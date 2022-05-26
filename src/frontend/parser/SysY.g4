grammar SysY;

// lexer rules
// lexer tokens should begin with *uppercase*

WhiteSpace: [ \t\n\r]+ -> skip;
LineComment: '//' ~[\r\n]* ('\r'? '\n' | EOF) -> skip;
BlockComment: '/*' .*? '*/' -> skip;

// keywords, should put in front, or it will be recognized as `Identifier`
Void: 'void';
Int: 'int';
Float: 'float';
Const: 'const';
If: 'if';
Else: 'else';
While: 'while';
Break: 'break';
Continue: 'continue';
Return: 'return';

Decimal: [1-9][0-9]*;
Octal: [0][0-7]*;
Hexadecimal: [0][xX][0-9a-fA-F]+;
FloatLiteral: [0-9]* '.' [0-9]* ([e|E][+|-]? [0-9]+)? [f|F]?;

Identifier: [a-zA-Z_][a-zA-Z0-9_]*;

// parser rules
// parser tokens should begin with *lowercase*

program: compUnit+;

compUnit: (funcDef | decl) compUnit?;

decl: constDecl | varDecl;

constDecl: Const bType constDefLi ';';

bType: Int | Float;

constDefLi: constDef (',' constDef)*;

constDef: Identifier constExpLi? '=' constInitVal;

constInitVal: constExp | '{' constInitValLi? '}';

constInitValLi: constInitVal (',' constInitVal)*;

constExpLi: ('[' constExp ']')+;

varDecl: bType varDefLi ';';

varDefLi: varDef (',' varDef)*;

varDef: Identifier constExpLi? ('=' initVal)?;

initVal: exp | '{' initValLi? '}';

initValLi: initVal (',' initVal)*;

funcDef: funcType Identifier '(' funcFParams? ')' block;

funcType: bType | Void;

funcFParams: funcFParam (',' funcFParam)*;

funcFParam: bType Identifier ('[' ']' expLi?)?; // ? THU is constExpLi

expLi: ('[' exp ']')+;

block: '{' blockItemLi? '}';

blockItemLi: blockItem+;

blockItem: decl | stmt;

stmt:
	lVal '=' exp ';'                          # assignment
	| exp? ';'                                # expStmt
	| block                                   # blockStmt
	| If '(' cond ')' stmt (Else stmt)?       # ifStmt
	| While '(' cond ')' stmt                 # whileStmt
	| Break ';'                               # breakStmt
	| Continue ';'                            # continueStmt
	| Return exp? ';'                         # returnStmt
	;

exp: addExp;

cond: lOrExp;

lVal: Identifier expLi?;

primaryExp: '(' exp ')' | lVal | number;

number: Decimal | Octal | Hexadecimal | FloatLiteral;

unaryExp:
	primaryExp                                # unary1
	| Identifier '(' funcRParams? ')'         # unary2
	| unaryOp unaryExp                        # unary3
	;

unaryOp: '+' | '-' | '!';

funcRParams: exp (',' funcRParams)?;

mulExp: unaryExp (('*' | '/' | '%') mulExp)?;

addExp: mulExp (('+' | '-') addExp)?;

relExp: addExp (('<' | '>' | '<=' | '>=') relExp)?;

eqExp: relExp (('==' | '!=') eqExp)?;

lAndExp: eqExp ('&&' lAndExp)?;

lOrExp: lAndExp ('||' lOrExp)?;

constExp: addExp;