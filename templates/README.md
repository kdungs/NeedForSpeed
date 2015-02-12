# Templates
Here are two examples where the use of templates is superior to what some people
might call the intuitive way.

The clang-specific `__attribute__ ((noinline))` is used in the examples
whenever it is necessary to prevent inlining for the sake of the argument. Just
imagine the function could not be inlined in the real world because it was more
complex than the examples. (Note this is different from using the `-O0` compiler
flag.)

The function `doNotOptimizeAway` uses dark magic to make sure the compiler does
just not eliminate our otherwise empty function calls.

## Flags
In `branching.cc` there are two functions that supposedly do the same thing:
`funWithFlagParam` and `funWithFlagTpl`. The former takes a boolean as its
parameter (by value) and depending on the value of the boolean calls another
function. `funWithFlagTpl` does the exact same thing except that here the
boolean is a template parameter. 
Compiling the example with the attached Makefile will give a file `branching.s`
containing the generated assembly code.

Even without knowledge of assembly, it can easily been seen that, and why, the
templated function is superior. First of all it can be seen that there is a
single definition of `funWithFlagParam` called `__Z16funWithFlagParamb` while
there are two individual definitions for `funWithFlagTpl` called
`__Z14funWithFlagTplILb0EEvv` and `__Z14funWithFlagTplILb1EEvv`. Looking at main
we find essentially four `call`s as expected:

```asm
	call	__Z16funWithFlagParamb
	xor	edi, edi
	call	__Z16funWithFlagParamb
	call	__Z14funWithFlagTplILb1EEvv
	call	__Z14funWithFlagTplILb0EEvv
```

The important difference in the actual functions stems from these two lines in
`__Z16funWithFlagParamb`:
```asm
	test	dil, dil
	je	LBB1_2
```
where a conditional jump is executed. This means whenever our flag is `false`,
the function performs an additional (and potentially expensive) jump.

_This is not the whole story._ In reality a CPU performs speculative branching
and other optimizations, that probably deserve another example...


## Functions as Parameters
