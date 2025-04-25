
## VT100 Codes ##

SAVECURSOR := \0337\033[s
RESTORECURSOR := \0338\033[u
SET_SCROLLREGION = \033[$(1);$(2)r
RESTORESCROLLREGION := \033[r
RESTORESCROLLREGION2 = $(SAVECURSOR)$(RESTORESCROLLREGION)$(RESTORECURSOR)\033[1A
CURSOR_GOTO = \033[$(1);$(2)H
SET_TEXTATTRIB = \033[$(1)$(if $(2),;$(2))$(if $(3),;$(3))m
BELL := \007
VT_ED := \033[2J
VT_CUU = \033[$(1)A
VT_CUD = \033[$(1)B
VT_CUF = \033[$(1)C
VT_CUB = \033[$(1)D

#Attributes
RESTORECOLOUR := \033[m
BOLD := 1
DIM := 2
UNDERSCORE := 4
BLINK := 5
INVERT := 7
HIDDEN := 8

#Colours
FG_BLACK:= 30
FG_MAROON:= 31
FG_GREEN:= 32
FG_OLIVE:= 33
FG_NAVY:= 34
FG_PURPLE:= 35
FG_TEAL:= 36
FG_SILVER:= 37
FG_GRAY:= 90
FG_RED:= 91
FG_LIME:= 92
FG_YELLOW:= 93
FG_BLUE:= 94
FG_VIOLET:= 95
FG_CYAN:= 96
FG_WHITE:= 97

BG_BLACK:= 40
BG_MAROON:= 41
BG_GREEN:= 42
BG_OLIVE:= 43
BG_NAVY:= 44
BG_PURPLE:= 45
BG_TEAL:= 46
BG_SILVER:= 47
BG_GRAY:= 100
BG_RED:= 101
BG_LIME:= 102
BG_YELLOW:= 103
BG_BLUE:= 104
BG_VIOLET:= 105
BG_CYAN:= 106
BG_WHITE:= 107

# define a "newline" variable to be used in make scripts
# use with ${\n}
# https://stackoverflow.com/questions/12528637/how-do-i-execute-each-command-in-a-list
define \n


endef
#end newline.

#Colour IDO Output (GCC does this automatically)
CLR_OUT := sed -E
#colour AI errors
CLR_OUT += -e 's/\(\(\x27E\x27\,\x27R\x27\,\x27R\x27\,\x27O\x27\,\x27R\x27,\s?((\x27?,?\s?\x27.)*)\x27,\s?\x27([^x27])\x27\)/((\x27ERROR\x27,\1\3\x27\)/g; :loop s/\(\((\x27ERROR)((\x27?,?\s?\x27.)*),?\s?\x27(.)\x27([^x27]*)\x27\)/((\1\2\5\x27\)/g; tloop; '
#colour errors
CLR_OUT += -e "s/(ERROR:[^\x27]*?\x27)|(^.*[Ee]rror.*)|(Mis-Match in)|(:\sFAILED)/$$(echo "$(call SET_TEXTATTRIB,$(FG_RED))")&$$(echo "$(RESTORECOLOUR)")/g"
#colour warnings
CLR_OUT += -e "s/^.*[Ww]arning.*/$$(echo "$(call SET_TEXTATTRIB,$(FG_YELLOW))")&$$(echo "$(RESTORECOLOUR)")/g"
#colour Info Tags
CLR_OUT += -e "s/^.*(([Bb]uilding)|(:\sOK)|([Ll]inkin)).*/$$(echo "$(call SET_TEXTATTRIB,$(FG_LIME))")&$$(echo "$(RESTORECOLOUR)")/g"
#colour filenames
CLR_OUT += -e "s/((([^\/]*([^s][^t][^d][^i][^n])\.c)|([^\/]*\.o))\s)/$$(echo "$(call SET_TEXTATTRIB,$(FG_WHITE))")&$$(echo "$(RESTORECOLOUR)")/g"

