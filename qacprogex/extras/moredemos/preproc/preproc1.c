#include <stdio.h>

#define	g(a, b)		a a ## b(nd)
#define	oo		"th"
#define	oodbye(a)	"e e" # a

int	main()
{
	puts( g(oo, dbye) );
	/*
	g(oo, dbye) => 
	oo oo ## dbye(nd) =>
	"th" oodbye(nd) =>
	"th" "e e" #nd
	"th" "e e" "nd"
	"the end"
	*/
}	
