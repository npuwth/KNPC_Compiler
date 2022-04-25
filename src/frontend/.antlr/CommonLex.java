// Generated from /home/yang/桌面/compiler/src/frontend/CommonLex.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CommonLex extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Int=1, Return=2, If=3, Else=4, For=5, While=6, Do=7, Break=8, Continue=9, 
		Lparen=10, Rparen=11, Lbrkt=12, Rbrkt=13, Lbrace=14, Rbrace=15, Comma=16, 
		Semicolon=17, Question=18, Colon=19, Minus=20, Exclamation=21, Tilde=22, 
		Addition=23, Multiplication=24, AND=25, Division=26, Modulo=27, LAND=28, 
		LOR=29, EQ=30, NEQ=31, LT=32, LE=33, GT=34, GE=35, Interger=36, Identifier=37, 
		WS=38;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Int", "Return", "If", "Else", "For", "While", "Do", "Break", "Continue", 
			"Lparen", "Rparen", "Lbrkt", "Rbrkt", "Lbrace", "Rbrace", "Comma", "Semicolon", 
			"Question", "Colon", "Minus", "Exclamation", "Tilde", "Addition", "Multiplication", 
			"AND", "Division", "Modulo", "LAND", "LOR", "EQ", "NEQ", "LT", "LE", 
			"GT", "GE", "Interger", "Identifier", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'int'", "'return'", "'if'", "'else'", "'for'", "'while'", "'do'", 
			"'break'", "'continue'", "'('", "')'", "'['", "']'", "'{'", "'}'", "','", 
			"';'", "'?'", "':'", "'-'", "'!'", "'~'", "'+'", "'*'", "'&'", "'/'", 
			"'%'", "'&&'", "'||'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Int", "Return", "If", "Else", "For", "While", "Do", "Break", "Continue", 
			"Lparen", "Rparen", "Lbrkt", "Rbrkt", "Lbrace", "Rbrace", "Comma", "Semicolon", 
			"Question", "Colon", "Minus", "Exclamation", "Tilde", "Addition", "Multiplication", 
			"AND", "Division", "Modulo", "LAND", "LOR", "EQ", "NEQ", "LT", "LE", 
			"GT", "GE", "Interger", "Identifier", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public CommonLex(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "CommonLex.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2(\u00c8\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\3\2\3\2\3\2\3\2\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3"+
		"\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3"+
		"\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3"+
		"\35\3\36\3\36\3\36\3\37\3\37\3\37\3 \3 \3 \3!\3!\3\"\3\"\3\"\3#\3#\3$"+
		"\3$\3$\3%\6%\u00ba\n%\r%\16%\u00bb\3&\3&\7&\u00c0\n&\f&\16&\u00c3\13&"+
		"\3\'\3\'\3\'\3\'\2\2(\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27"+
		"\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33"+
		"\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(\3\2\6\3\2\62;\5\2C\\aac|\6\2"+
		"\62;C\\aac|\5\2\13\f\17\17\"\"\2\u00c9\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2"+
		"\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2"+
		"\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3"+
		"\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3"+
		"\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65"+
		"\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3"+
		"\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2"+
		"\2\3O\3\2\2\2\5S\3\2\2\2\7Z\3\2\2\2\t]\3\2\2\2\13b\3\2\2\2\rf\3\2\2\2"+
		"\17l\3\2\2\2\21o\3\2\2\2\23u\3\2\2\2\25~\3\2\2\2\27\u0080\3\2\2\2\31\u0082"+
		"\3\2\2\2\33\u0084\3\2\2\2\35\u0086\3\2\2\2\37\u0088\3\2\2\2!\u008a\3\2"+
		"\2\2#\u008c\3\2\2\2%\u008e\3\2\2\2\'\u0090\3\2\2\2)\u0092\3\2\2\2+\u0094"+
		"\3\2\2\2-\u0096\3\2\2\2/\u0098\3\2\2\2\61\u009a\3\2\2\2\63\u009c\3\2\2"+
		"\2\65\u009e\3\2\2\2\67\u00a0\3\2\2\29\u00a2\3\2\2\2;\u00a5\3\2\2\2=\u00a8"+
		"\3\2\2\2?\u00ab\3\2\2\2A\u00ae\3\2\2\2C\u00b0\3\2\2\2E\u00b3\3\2\2\2G"+
		"\u00b5\3\2\2\2I\u00b9\3\2\2\2K\u00bd\3\2\2\2M\u00c4\3\2\2\2OP\7k\2\2P"+
		"Q\7p\2\2QR\7v\2\2R\4\3\2\2\2ST\7t\2\2TU\7g\2\2UV\7v\2\2VW\7w\2\2WX\7t"+
		"\2\2XY\7p\2\2Y\6\3\2\2\2Z[\7k\2\2[\\\7h\2\2\\\b\3\2\2\2]^\7g\2\2^_\7n"+
		"\2\2_`\7u\2\2`a\7g\2\2a\n\3\2\2\2bc\7h\2\2cd\7q\2\2de\7t\2\2e\f\3\2\2"+
		"\2fg\7y\2\2gh\7j\2\2hi\7k\2\2ij\7n\2\2jk\7g\2\2k\16\3\2\2\2lm\7f\2\2m"+
		"n\7q\2\2n\20\3\2\2\2op\7d\2\2pq\7t\2\2qr\7g\2\2rs\7c\2\2st\7m\2\2t\22"+
		"\3\2\2\2uv\7e\2\2vw\7q\2\2wx\7p\2\2xy\7v\2\2yz\7k\2\2z{\7p\2\2{|\7w\2"+
		"\2|}\7g\2\2}\24\3\2\2\2~\177\7*\2\2\177\26\3\2\2\2\u0080\u0081\7+\2\2"+
		"\u0081\30\3\2\2\2\u0082\u0083\7]\2\2\u0083\32\3\2\2\2\u0084\u0085\7_\2"+
		"\2\u0085\34\3\2\2\2\u0086\u0087\7}\2\2\u0087\36\3\2\2\2\u0088\u0089\7"+
		"\177\2\2\u0089 \3\2\2\2\u008a\u008b\7.\2\2\u008b\"\3\2\2\2\u008c\u008d"+
		"\7=\2\2\u008d$\3\2\2\2\u008e\u008f\7A\2\2\u008f&\3\2\2\2\u0090\u0091\7"+
		"<\2\2\u0091(\3\2\2\2\u0092\u0093\7/\2\2\u0093*\3\2\2\2\u0094\u0095\7#"+
		"\2\2\u0095,\3\2\2\2\u0096\u0097\7\u0080\2\2\u0097.\3\2\2\2\u0098\u0099"+
		"\7-\2\2\u0099\60\3\2\2\2\u009a\u009b\7,\2\2\u009b\62\3\2\2\2\u009c\u009d"+
		"\7(\2\2\u009d\64\3\2\2\2\u009e\u009f\7\61\2\2\u009f\66\3\2\2\2\u00a0\u00a1"+
		"\7\'\2\2\u00a18\3\2\2\2\u00a2\u00a3\7(\2\2\u00a3\u00a4\7(\2\2\u00a4:\3"+
		"\2\2\2\u00a5\u00a6\7~\2\2\u00a6\u00a7\7~\2\2\u00a7<\3\2\2\2\u00a8\u00a9"+
		"\7?\2\2\u00a9\u00aa\7?\2\2\u00aa>\3\2\2\2\u00ab\u00ac\7#\2\2\u00ac\u00ad"+
		"\7?\2\2\u00ad@\3\2\2\2\u00ae\u00af\7>\2\2\u00afB\3\2\2\2\u00b0\u00b1\7"+
		">\2\2\u00b1\u00b2\7?\2\2\u00b2D\3\2\2\2\u00b3\u00b4\7@\2\2\u00b4F\3\2"+
		"\2\2\u00b5\u00b6\7@\2\2\u00b6\u00b7\7?\2\2\u00b7H\3\2\2\2\u00b8\u00ba"+
		"\t\2\2\2\u00b9\u00b8\3\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00b9\3\2\2\2\u00bb"+
		"\u00bc\3\2\2\2\u00bcJ\3\2\2\2\u00bd\u00c1\t\3\2\2\u00be\u00c0\t\4\2\2"+
		"\u00bf\u00be\3\2\2\2\u00c0\u00c3\3\2\2\2\u00c1\u00bf\3\2\2\2\u00c1\u00c2"+
		"\3\2\2\2\u00c2L\3\2\2\2\u00c3\u00c1\3\2\2\2\u00c4\u00c5\t\5\2\2\u00c5"+
		"\u00c6\3\2\2\2\u00c6\u00c7\b\'\2\2\u00c7N\3\2\2\2\5\2\u00bb\u00c1\3\b"+
		"\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}