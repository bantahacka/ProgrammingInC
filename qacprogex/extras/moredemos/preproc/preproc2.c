#include <stdio.h>

#define dhe     "bye"
#define zhe     "good"
#define hed     "ll"
#define dz      "orl"
#define zd      "o w"

#define g(a, b, c)      #a  a ## c  a ## b(b, c)
#define hez(x, y)       x ## y  y ## x  #y

int main()
{
	puts( g(he, z, d) );

	/*
		g(he, z, d) =>
		#he he ## d he ## z (z,d) =>
		"he"  "ll"  hez(z,d) =>
		"he"  "ll"  z ## d d ## z #d =>
		"he"  "ll"  "o w" "orl" "d" =>
		"hello world"



	*/
}
