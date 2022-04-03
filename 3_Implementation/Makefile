#Target: Dependencies
#<TAB>commands
PROJ_NAME = Matrix_Operator
SRC= matrix.c  unity.c
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

Build : $(SRC)  
	gcc $(SRC) -Iinc -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm



Run :Build	
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

static_analysis:
     cppcheck  enable=all $(SRC)


Clean:
	$(RM) $(call FixPath,*.out)