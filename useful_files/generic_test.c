#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define type_idx(T) _Generic((T), char : 1, int : 2, long : 3, default : 0)

int main() { 
	return type_idx("test");
}