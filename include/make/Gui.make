
#Only Draw PBar if NOT verbose
ifeq ($(VERBOSE),0)

# Separate "constant" drawing from variable drawing to speed up PBar rendering
# draws a box and fills it grey ready for blue bar
SetupProgressBar =                                                                                           \
	{                                                                                                        \
		str="$(SAVECURSOR)$(call SET_SCROLLREGION,4,0)$(call CURSOR_GOTO,2,999)$(VT_ED)$(call CURSOR_GOTO,1)";\
		str=$$str"\033(0lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk";   \
		str=$$str"\nx$(call SET_TEXTATTRIB,$(BG_GRAY))%78s$(RESTORECOLOUR)x\n";                              \
		str=$$str"mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\033(B";   \
		str=$$str"$(RESTORECURSOR)";                                                                         \
		printf $$str "";                                                                                     \
	}

#(call DrawProgressBar,Percent)
# OR
#(call DrawProgressBar,NumberOfItemsDone,TotalNumberOfItems)
# If second param is given, use it to work out a percentage.
# divide the percentage into a 80 char long bar
# paint the whole bar grey
# paint the first half, then text, then second half.
# clear colour codes
DrawProgressBar =                                       \
	{                                                   \
		$(if $(2),                                      \
			if [ "$(1)" -ne "$(2)" ];                   \
			then                                        \
				_pdone=`expr 100 / $(2) \* $(1)`;       \
			else                                        \
				_pdone=100;                             \
			fi                                          \
			,_pdone=$(1)                                \
		);                                              \
		pdone=`expr $$_pdone \* 74 / 100`;              \
		pdoneb=0;                                       \
		str="$(SAVECURSOR)$(call CURSOR_GOTO,2,2)";\
		str=$$str"$(call SET_TEXTATTRIB,$(BOLD),$(FG_WHITE),$(BG_NAVY))" ;    \
		                                                \
		if [ "$$pdone" -lt "36" ];                      \
		then                                            \
			str=$$str"%$${pdone}s";                     \
			str=$$str"$(call SET_TEXTATTRIB,$(BG_GRAY))";\
			pdoneb=`expr 36 - $$pdone`;                 \
			str=$$str"%$${pdoneb}s%3d%%";               \
		else                                            \
			pdoneb=`expr $$pdone - 36`;                 \
			str=$$str"%1s%35s%3d%%%$${pdoneb}s";        \
		fi;                                             \
		str=$$str"$(RESTORECURSOR)$(RESTORECOLOUR)";    \
		printf $$str "" "" $$_pdone;                 \
	}
# Increment Progress Bar From percentage (1), and increase by 1 every (2) seconds.
# Continue doing so until calling process ends
IncrementProgressBarFromAtRate =         \
	{                                    \
		i=$(1);                          \
		while [ -d /proc/$$! ] && [ $$i -le 100 ]; do       \
			$(call DrawProgressBar,$$i); \
			i=$$((i+1));                 \
			sleep $(2);                  \
		done;                            \
	}
endif #Verbose No Draw PBar

# Ask to continue
# (1) Prompt,
# (2) Do if Yes,
# (3) Do if No [can be blank],
# (4) Do if anything else [can be blank]
# (5) Timeout [can be blank]
ContinuePrompt =                                    \
	{                                               \
		echo "$1 [y/n]";                            \
		$(if $(5), readchr(){ old=$$(stty -g);  stty raw -echo min 0 time 30; printf '%s' $$(dd bs=1 count=1 2>/dev/null); stty $$old;}; REPLY=$$(readchr) ,read REPLY ); \
		echo $$REPLY; case $$REPLY in                             \
			y|Y) $2;;                               \
			n|N) $3;;                               \
			*) $4;;                                 \
		esac;                                       \
	}
