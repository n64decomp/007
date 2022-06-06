/**
 * This header file contains a library of advanced C Pre-Processor (CPP) macros
 * which implement various useful functions, such as iteration, in the
 * pre-processor.
 */
#ifndef CPPLIB_H
#define CPPLIB_H

/*#define EXPAND_EXAMPLES */

/**
 * Macros which expand to common values
 */

#define EMPTY()
#define COMMA()          ,
#define COMMA_IF(cond)   COMMA_IF_I(cond)
#define COMMA_IF_I(cond) IF_ELSE(cond)(COMMA)(EMPTY)()
#define LPAREN() (
#define RPAREN() )
#define PLUS() +
#define ZERO() 0
#define ONE()  1

#define EXPAND(a) a
#define EAT(x)
#define STR(n) #n


/**
 * Force the pre-processor to expand the macro a large number of times. Usage:
 *
 *   EVAL(expression)
 *
 * This is useful when you have a macro which evaluates to a valid macro
 * expression which is not subsequently expanded in the same pass. A contrived,
 * but easy to understand, example of such a macro follows. Note that though
 * this example is contrived, this behaviour is abused to implement bounded
 * recursion in macros such as FOR.
 *
 *   #define A(x) x+1
 *   #define EMPTY
 *   #define NOT_QUITE_RIGHT(x) A EMPTY (x)
 *   NOT_QUITE_RIGHT(999)
 *
 * Here's what happens inside the C preprocessor:
 *
 * 1. It sees a macro "NOT_QUITE_RIGHT" and performs a single macro expansion
 *    pass on its arguments. Since the argument is "999" and this isn't a macro,
 *    this is a boring step resulting in no change.
 * 2. The NOT_QUITE_RIGHT macro is substituted for its definition giving "A
 *    EMPTY() (x)".
 * 3. The expander moves from left-to-right trying to expand the macro:
 *    The first token, A, cannot be expanded since there are no brackets
 *    immediately following it. The second token EMPTY(), however, can be
 *    expanded (recursively in this manner) and is replaced with "".
 * 4. Expansion continues from the start of the substituted test (which in this
 *    case is just empty), and sees "(999)" but since no macro name is present,
 *    nothing is done. This results in a final expansion of "A (999)".
 *
 * Unfortunately, this doesn't quite meet expectations since you may expect that
 * "A (999)" would have been expanded into "999+1". Unfortunately this requires
 * a second expansion pass but luckily we can force the macro processor to make
 * more passes by abusing the first step of macro expansion: the preprocessor
 * expands arguments in their own pass. If we define a macro which does nothing
 * except produce its arguments e.g.:
 *
 *   #define PASS_THROUGH(...) __VA_ARGS__
 *
 * We can now do "PASS_THROUGH(NOT_QUITE_RIGHT(999))" causing "NOT_QUITE_RIGHT"
 * to be expanded to "A (999)", as described above, when the arguments are
 * expanded. Now when the body of PASS_THROUGH is expanded, "A (999)" gets
 * expanded to "999+1".
 *
 * The EVAL defined below is essentially equivalent to a large nesting of
 * "PASS_THROUGH(PASS_THROUGH(PASS_THROUGH(..." which results in the
 * preprocessor making a large number of expansion passes over the given
 * expression.
 */
#define EVAL(a)    EVAL512(EVAL256(EVAL128(EVAL64(EVAL32(EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a))))))))))
#define EVAL512(a) EVAL256(EVAL128(EVAL64(EVAL32(EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a)))))))))
#define EVAL256(a) EVAL128(EVAL64(EVAL32(EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a))))))))
#define EVAL128(a) EVAL64(EVAL32(EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a)))))))
#define EVAL64(a)  EVAL32(EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a))))))
#define EVAL32(a)  EVAL16(EVAL8(EVAL4(EVAL2(EVAL1(a)))))
#define EVAL16(a)  EVAL8(EVAL4(EVAL2(EVAL1(a))))
#define EVAL8(a)   EVAL4(EVAL2(EVAL1(a)))
#define EVAL4(a)   EVAL2(EVAL1(a))
#define EVAL2(a)   EVAL1(a)
#define EVAL1(VA)  IF_VA(EXPAND(DEFER(IS_PAREN)(VA)))(DEFER(EXPAND_ARGS_STACK)) VA

/**
 * Causes a function-style macro to require an additional pass to be expanded.
 * This is useful, for example, when trying to implement recursion since the
 * recursive step must not be expanded in a single pass as the pre-processor
 * will catch it and prevent it.
 *
 * Usage:
 *
 *   DEFER(IN_NEXT_PASS)(args, to, the, macro)
 *
 * Blocking a Second time can be done with DEFER2
 *
 * Usage:
 *
 *   DEFER2(IN_NEXT_NEXT_PASS)(args, to, the, macro)
 */

/**
 * As with DEFER1 except here n additional passes are required for DEFERn.
 *
 * The mechanism is analogous.
 */
#define DEFERA1024(a) DEFERA512(DEFERA512(a))
#define DEFERA512(a)  DEFERA256(DEFERA256(a))
#define DEFERA256(a)  DEFERA128(DEFERA128(a))
#define DEFERA128(a)  DEFERA64(DEFERA64(a))
#define DEFERA64(a)   DEFERA32(DEFERA32(a))
#define DEFERA32(a)   DEFERA16(DEFERA16(a))
#define DEFERA16(a)   DEFERA8(DEFERA8(a))
#define DEFERA8(a)    DEFERA4(DEFERA4(a))
#define DEFERA4(a)    DEFERA2(DEFERA2(a))
#define DEFERA2(a)    DEFERA1(DEFERA1(a))
#define DEFERA1(a)    EMPTY a
#define DEFERB1024(a) DEFERB512(DEFERB512(a))
#define DEFERB512(a)  DEFERB256(DEFERB256(a))
#define DEFERB256(a)  DEFERB128(DEFERB128(a))
#define DEFERB128(a)  DEFERB64(DEFERB64(a))
#define DEFERB64(a)   DEFERB32(DEFERB32(a))
#define DEFERB32(a)   DEFERB16(DEFERB16(a))
#define DEFERB16(a)   DEFERB8(DEFERB8(a))
#define DEFERB8(a)    DEFERB4(DEFERB4(a))
#define DEFERB4(a)    DEFERB2(DEFERB2(a))
#define DEFERB2(a)    DEFERB1(DEFERB1(a))
#define DEFERB1(a)    () a

#define DEFER1024(id) id DEFERA1024() DEFERB1024()
#define DEFER512(id)  id DEFERA512() DEFERB512()
#define DEFER256(id)  id DEFERA256() DEFERB256()
#define DEFER128(id)  id DEFERA128() DEFERB128()
#define DEFER64(id)   id DEFERA64() DEFERB64()
#define DEFER32(id)   id DEFERA32() DEFERB32()
#define DEFER16(id)   id DEFERA16() DEFERB16()
#define DEFER8(id)    id DEFERA8() DEFERB8()
#define DEFER4(id)    id DEFERA4() DEFERB4()
#define DEFER3(id)    id DEFERA1() DEFERA2() DEFERB2() DEFERB1()
#define DEFER2(id)    id DEFERA2() DEFERB2()
#define DEFER1(id)     id DEFERA1() DEFERB1()
#define DEFER(id)     id DEFERA1() DEFERB1()

#define INC(x) CAT(INC_, x)
#define INC_0  1
#define INC_1  2
#define INC_2  3
#define INC_3  4
#define INC_4  5
#define INC_5  6
#define INC_6  7
#define INC_7  8
#define INC_8  9
#define INC_9  0

#define DEC(x) CAT(DEC_, x)
#define DEC_0  (1/0)
#define DEC_1  0
#define DEC_2  1
#define DEC_3  2
#define DEC_4  3
#define DEC_5  4
#define DEC_6  5
#define DEC_7  6
#define DEC_8  7
#define DEC_9  8

/**
 * Indirection around the standard ## concatenation operator. This simply
 * ensures that the arguments are expanded (once) before concatenation.
 * @param a, b
 * @return Concantinated Token
 */
#define CAT(a, b)          PRIMITIVECAT(a, b)
#define PRIMITIVECAT(a, b) a##b

/**
 * Get the first argument and ignore the rest.
 */
#define FIRST_PRE_VA(a) a

/**
 * Get the second argument and ignore the rest.
 */
#define SECOND_PRE_VA(a, b) b

/**
 * Expects a single input (not containing commas). Returns 1 if the input is
 * PROBE() and otherwise returns 0.
 *
 * This can be useful as the basis of a NOT function.
 *
 * This macro abuses the fact that PROBE() contains a comma while other valid
 * inputs must not.
 */
#define IS_PROBE(a) SECOND_PRE_VA(a, 0)
#define PROBE()     ~, 1

/**
 * Detect Parenthesis 
 * @return TRUE/FALSE
 */
#define IS_PAREN(x)       IS_PROBE(IS_PAREN_PROBE x)
#define IS_PAREN_PROBE(A) PROBE(~)

#ifdef EXPAND_EXAMPLES
    IS_PAREN((S)) // Expands to 1
    IS_PAREN(xxx) // Expands to 0
#endif

/**
 * Detects if arg or macro is defined as nothing. 
 */
#define IS_EMPTY(x)  _IS_EMPTY(x)
#define _IS_EMPTY(x) IS_PROBE(CAT(_IS_EMPTY, _##x##_))
#define _IS_EMPTY__  PROBE(~) /*NULL*/

/**
 * Detects if arg or macro is a Bool (1 or 0). 
 * Use _IS_BOOL to prevent first expansion (TRUE/FALSE macro)
 * @return TRUE/FALSE
 */
#define IS_BOOL(x)      _IS_BOOL(x)
#define _IS_BOOL(x)     IS_PROBE(CAT(_IS_BOOL, _##x##_))
#define _IS_BOOL_TRUE_  PROBE(~)
#define _IS_BOOL_FALSE_ PROBE(~) 
#define _IS_BOOL_1_     PROBE(~)
#define _IS_BOOL_0_     PROBE(~)

    /**
 * Macro version of "defined" however its limited to 1/0/nothing. Any other value 
 * is indistuiguishable from a random name
 * Certain pre-defined definitions can be "NOTDEFINED" eg THIS.
 * so checking IF(DEFINED(THIS)) is asking if THIS is NOT defined
 * @return TRUE/FALSE
*/
#define DEFINED(x) _DEFINED(x)
#define _DEFINED(x) IS_PROBE(CAT(_DEFINED, _##x##_))
#define _DEFINED_0_ PROBE(~)
#define _DEFINED_1_ PROBE(~)
#define _DEFINED__  PROBE(~)

/*The following names are NOT defined and need to be regarded as NOTDEFINED */
#define _DEFINED_THIS_ PROBE(~)
#define _DEFINED_SETUPSUBROUTINES(ID) PROBE(~),

    /**
 * Logical negation. 0 or nothing is defined as false and everything else as
 * true.
 *
 * When 0, _NOT_0 will be found which evaluates to the PROBE. When 1 (or any
 * other value) is given, an appropriately named macro won't be found and the
 * concatenated string will be produced. IS_PROBE then simply checks to see if
 * the PROBE was returned, cleanly converting the argument into a 1 or 0.
 * @return TRUE/FALSE
 */
#define NOT(x)  _NOT(x)
#define _NOT(x) IS_PROBE(CAT(_NOT, _##x##_))
#define _NOT_0_ PROBE(~)
#define _NOT__  PROBE(~) /*NULL*/


#ifdef EXPAND_EXAMPLES
    NOT(1)                 // not 1
    NOT(0)                 // not 0
    NOT()                  // not
    NOT(NOT(IS_PAREN(()))) // not !1
    NOT(NOT(0))            // not !0
    NOT(NOT())             // not !
#endif

/**
 * Macro version of C's famous "cast to bool" operator (i.e. !!) which takes
 * anything and casts it to 0 if it is 0 and 1 otherwise.
 * @return TRUE/FALSE
*/
#define BOOL(x) NOT(NOT(x))

/* this little anoying block may look out of place, but it needs to be right here */

/**
    If Statement (Non-Expanding)
    @param c: If True, output the contents of parenthises else output nothing.
*/
#define IF_VA(c)    _IF_VA(BOOL(c))
#define _IF_VA(c)   CAT(_IF_VA_, c)
#define _IF_VA_1(a) a
#define _IF_VA_0(a)

/**
 * _VA_ARGS_ for c89 
 * Allows up to 32 Args on the stack
 */
#define EXPAND_ARGS_STACK(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF,ERROR) \
IF_VA(NOT(IS_EMPTY(A)))/*
*/(/*
	*/A /*
	*/IF_VA(NOT(IS_EMPTY(B)))/*
	*/(/*
		*/COMMA() B /*
		*/IF_VA(NOT(IS_EMPTY(C)))/*
		*/(/*
			*/COMMA() C /*
			*/IF_VA(NOT(IS_EMPTY(D)))/*
			*/(/*
				*/COMMA() D /*
				*/IF_VA(NOT(IS_EMPTY(E)))/*
				*/(/*
					*/COMMA() E/*
					*/IF_VA(NOT(IS_EMPTY(F)))/*
					*/(/*
						*/COMMA() F /*
						*/IF_VA(NOT(IS_EMPTY(G)))/*
						*/(/*
							*/COMMA() G /*
							*/IF_VA(NOT(IS_EMPTY(H)))/*
							*/(/*
								*/COMMA() H /*
								*/IF_VA(NOT(IS_EMPTY(I)))/*
								*/(/*
									*/COMMA() I /*
									*/IF_VA(NOT(IS_EMPTY(J)))/*
									*/(/*
										*/COMMA() J /*
										*/IF_VA(NOT(IS_EMPTY(K)))/*
										*/(/*
											*/COMMA() K /*
											*/IF_VA(NOT(IS_EMPTY(L)))/*
											*/(/*
												*/COMMA() L /*
												*/IF_VA(NOT(IS_EMPTY(M)))/*
												*/(/*
													*/COMMA() M /*
													*/IF_VA(NOT(IS_EMPTY(N)))/*
													*/(/*
														*/COMMA() N /*
														*/IF_VA(NOT(IS_EMPTY(O)))/*
														*/(/*
															*/COMMA() O /*
															*/IF_VA(NOT(IS_EMPTY(P)))/*
															*/(/*
																*/COMMA() P /*
																*/IF_VA(NOT(IS_EMPTY(Q)))/*
																*/(/*
																	*/COMMA() Q /*
																	*/IF_VA(NOT(IS_EMPTY(R)))/*
																	*/(/*
																		*/COMMA() R /*
																		*/IF_VA(NOT(IS_EMPTY(S)))/*
																		*/(/*
																			*/COMMA() S /*
																			*/IF_VA(NOT(IS_EMPTY(T)))/*
																			*/(/*
																				*/COMMA() T /*
																				*/IF_VA(NOT(IS_EMPTY(U)))/*
																				*/(/*
																					*/COMMA() U /*
																					*/IF_VA(NOT(IS_EMPTY(V)))/*
																					*/(/*
																						*/COMMA() V /*
																						*/IF_VA(NOT(IS_EMPTY(W)))/*
																						*/(/*
																							*/COMMA() W /*
																							*/IF_VA(NOT(IS_EMPTY(X)))/*
																							*/(/*
																								*/COMMA() X /*
																								*/IF_VA(NOT(IS_EMPTY(Y)))/*
																								*/(/*
																									*/COMMA() Y /*
																									*/IF_VA(NOT(IS_EMPTY(Z)))/*
																									*/(/*
																										*/COMMA() Z /*
																										*/IF_VA(NOT(IS_EMPTY(AA)))/*
																										*/(/*
																											*/COMMA() AA /*
																											*/IF_VA(NOT(IS_EMPTY(AB)))/*
																											*/(/*
																												*/COMMA() AB /*
																												*/IF_VA(NOT(IS_EMPTY(AC)))/*
																												*/(/*
																													*/COMMA() AC /*
																													*/IF_VA(NOT(IS_EMPTY(AD)))/*
																													*/(/*
																														*/COMMA() AD /*
																														*/IF_VA(NOT(IS_EMPTY(AE)))/*
																														*/(/*
																															*/COMMA() AE /*
																															*/IF_VA(NOT(IS_EMPTY(AF)))/*
																															*/(/*
																																*/COMMA() AF /*
																																*/IF_VA(NOT(IS_EMPTY(ERROR)))/*
																																*/(/*
																																	*/COMMA() undefinedlocal = 1/0 "_VA_ARGS Stack full"/*
																																*/)/*
*/)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	)	
/**
 * Push/Pop VA Args arrays
 */
#define POP_ARG(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF) /* 
    */(IF_VA(IS_PAREN(A))(_POP_ARG A) /*
    ELSE*/IF_VA(NOT(IS_PAREN(A)))(EXPAND_ARGS_STACK(B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF)))
#define _POP_ARG(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF) EXPAND_ARGS_STACK(B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF)
#define PUSH_ARG(A,B)(A, TRY_EXPAND(B))

/**
 * TRY Expand If Array
 */
#define TRY_EXPAND(c)     _TRY_EXPAND(IS_PAREN(c))(c)
#define _TRY_EXPAND(c)    CAT(__TRY_EXPAND_, c)
#define __TRY_EXPAND_1(a) EXPAND_ARGS_STACK a
#define __TRY_EXPAND_0(a) a

/**
 * Get the first argument and ignore the rest.
 */
#define FIRST(a) EXPAND(DEFER(FIRST_PRE_VA)(TRY_EXPAND(a)))

/**
 * Get the second argument and ignore the rest.
 */
#define SECOND(a, b) EXPAND(DEFER(SECOND_PRE_VA)(TRY_EXPAND(a), b))

#ifdef EXPAND_EXAMPLES
// POP ARG
    POP_ARG(THIS, IS, a, TEST, hy)
// push arg
    PUSH_ARG(test, (this, is, a, test, with, a , is, so, is, a, test, with, a , is, so, is, a, test, with, a , is, so, is, a, test, with, a , is, so))
#endif

/**
 * Logical OR. Simply performs a lookup.
 */
#define OR(a, b) CAT(CAT(_OR_, a), b)
#define _OR_00   0
#define _OR_01   1
#define _OR_10   1
#define _OR_11   1
/**
 * Logical XOR. Simply performs a lookup.
 */
#define XOR(a, b) CAT(CAT(_XOR_, a), b)
#define _XOR_00   0
#define _XOR_01   1
#define _XOR_10   1
#define _XOR_11   0
/**
 * Logical AND. Simply performs a lookup.
 */
#define AND(a, b) CAT(CAT(_AND_, a), b)
#define _AND_00   0
#define _AND_01   0
#define _AND_10   0
#define _AND_11   1

/**
 * Macro if statement. 
 * Usage:
 *   IF(condition)          \
 *   (                      \
 *     expansion when true  \
 *   )
 * @param condition
 * @return TRUE/FALSE
 */
#define IF(c)    _IF(BOOL(c))
#define _IF(c)   CAT(_IF_, c)
#define _IF_1(a) TRY_EXPAND(a)
#define _IF_0(a)

/** 
 * Macro if/else statement. 
 * Usage:
 *
 *   IF_ELSE(condition)     
 *   ((                     
 *     expansion when true  
 *   ))                     
 *   ((                     
 *     expansion when false 
 *   ))
 * @param condition
 * @return TRUE/FALSE
 */
#define IF_ELSE(c) _IF(CAT(E, BOOL(c)))
#define _IF_E1(a)  TRY_EXPAND(a) _IF_1_ELSE
#define _IF_E0(a)  _IF_0_ELSE
#define _IF_1_ELSE(a)
#define _IF_0_ELSE(a) TRY_EXPAND(a)


#ifdef EXPAND_EXAMPLES
    IF_ELSE(220)((it was, non - zero))(it was zero) // Expands to "non Zero"
    IF(06)(NONZERO)


/*
 * When
 */
#define WHEN(c) IF(c)(EVAL1)(EAT)
#endif
/**
 * Macro which checks if it has any arguments. Returns '0' if there are no
 * arguments, '1' otherwise. 
 * Limitation: HAS_ARGS(,1,2,3) returns 0 -- this check essentially only checks
 * that the first argument exists.
 * @return TRUE/FALSE
 */
#define HAS_ARGS(a)      BOOL(EXPAND(_END_OF_ARGUMENTS_ FIRST(a)()))
#define _END_OF_ARGUMENTS_() 0

/*
for_each(v.begin(), v.end(), [](int &number)
    {
        number++;
    });
*/
/**
 * foreach macro
 * @param 
 */
#define foreach(var, collection) for (var = *collection; var; var++)

#ifdef EXPAND_EXAMPLES
//do I have args?
//yes
HAS_ARGS(a, b, c)
HAS_ARGS((a, b, c))
//no
HAS_ARGS()
HAS_ARGS(())
HAS_ARGS((      ()))

#    define test() Im expanded
        DEFER8(test)() EVAL1(EVAL4(DEFER4(test)()))

#    define RECURSE(X) FIRST X DEFER(_RECURSE)()(POP_ARG X)
#    define _RECURSE() RECURSE
    // RECURSE
    EVAL16(RECURSE((this, is, a, test, WITH, MANY, ARGS)))
#endif

#define COUNTPARAMS(X) \
    IF_ELSE(IS_PAREN(X)) /*
    */( /*
        */EVAL8(COUNTPARAMS_INNER(X, 0)) /*
    */) /*
    */( /*
        */0() /*
    */)
#define COUNTPARAMS_INNER(X, COUNT) \
    IF_ELSE(HAS_ARGS(X))/*
    */( /*
        */DEFER3(_COUNTPARMS)()(POP_ARG(X), INC(COUNT))/*
    */) /*
    */( /*
        */COUNT /*
    */)
#    define _COUNTPARMS() COUNTPARAMS_INNER


#ifdef EXPAND_EXAMPLES
    // COUNTPARAMS - IT WORKS!!!, THIS WILL BE GREAT FOR AI
    COUNTPARAMS(())
    COUNTPARAMS((A))
    COUNTPARAMS((A, B))
    COUNTPARAMS((A, B, C))
    COUNTPARAMS((A, B, C, D))
    COUNTPARAMS((A, B, C, D, E))
    COUNTPARAMS((A, B, C, D, E, F))
    COUNTPARAMS((A, B, C, D, E, F, G))
    COUNTPARAMS((A, B, C, D, E, F,G,H))
    COUNTPARAMS((A, B, C, D, E,  F,G,H,I))

#enAdif
#define LIST_TO_TUPLE(list) \	
    IF_ELSE(IS_PAREN(list))\	
    (\	
        EVAL16((LIST_TO_TUPLE_INNER(SECOND list, FIRST list)))\	
    )\	
    (\	
        list\	
    )	
    	
#define LIST_TO_TUPLE_INNER(list, listb)        \	
    IF_ELSE(HAS_ARGS(list))      \	
    (\	
        EXPAND(DEFER4(_LIST_TO_TUPLE_INNER)()(TRY_EXPAND((POP_ARG list)), PUSH_ARG(FIRST list, listb)))\	
    )\	
    (\	
        0 listb\	
    )	
#define _LIST_TO_TUPLE_INNER() LIST_TO_TUPLE_INNER	
// list to tuple	
LIST_TO_TUPLE((this, (is, (a, (li8st, (lots, (of, (test, (another, )))))))))	
//SINGLE	
LIST_TO_TUPLE((this,(is)))

#define REPEAT(count, macro, a)                        \
    IF_ELSE(DEC(count))                                \
    (DEFER3(REPEAT_INDIRECT)()(DEC(count), macro, a))( \
        /* Do nothing, just terminate */) DEFER(macro)(DEC(count), a)

#define REPEAT_INDIRECT() REPEAT

#ifdAef EXPAND_EXAMPLES
// An example of using this macro
#    define M(i, _) i
        EVAL16(REPEAT(9, M, ~)) // 0 1 2 3 4 5 6 7
#endiAf

#define WHILE(pred, op, a) \
    IF(pred(a))            \
    (DEFER2(WHILE_INDIRECT)()(pred, op, op(a)), POP_ARG a)
#define WHILE_INDIRECT() WHILE

/**
 * Macro map/list comprehension. Usage:
 *
 *   MAP(op, sep, ...)
 *
 * Produces a 'sep()'-separated list of the result of op(arg) for each arg.
 *
 * Example Usage:
 *
 *   #define MAKE_HAPPY(x) happy_##x
 *   #define COMMA() ,
 *   MAP(MAKE_HAPPY, COMMA, 1,2,3)
 *
 * Which expands to:
 *
 *    happy_1 , happy_2 , happy_3
 */
#define MAP(op, sep, a) \
    IF_ELSE(HAS_ARGS a) \
    (EVAL(MAP_INNER(op, sep, a)))(/* Do nothing, just terminate */)
#define MAP_INNER(op, sep, a)                                       \
    DEFER(op)                                                       \
    (FIRST a) IF_ELSE(DEFER(HAS_ARGS) POP_ARG a)(EXPAND EMSPTY()(   \
        sep() OBSTRUCT(_MAP_INNER)()(op, sep, EXPAND(POP_ARG a))))( \
        /* Do nothing, just terminate */)
#define _MAP_INNER() MAP_INNER

/*MAP(MAKE_HAPPY, COMMA, (1,2,3,A))*/
#endif
#endif
