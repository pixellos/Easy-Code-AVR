 #include <avr/io.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <inttypes.h>
 #include <string.h>

 char  static volatile LedBuffer[33] = "00000000000000000000000000000000";
 void str_t_bfr_cpy(uint8_t x, char *c) // Very bad ecample
 {
	 for (uint8_t i = 0;(*(LedBuffer+x+i)) && *(c + i);*(LedBuffer+x+i) = *(c+i++));
 }