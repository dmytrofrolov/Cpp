#include <stdio.h>
#include <stdint.h>

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}



void main(void){
	char * p  		= (char*) allocateString ("HwithmmaHello23320");
	char * string2 	= (char*) allocateString ("mamma miall what is that0");
	
	//char *str = (char*) allocateString( "This is a simple string0\0" );
	char *key = (char*) allocateString( "aeiou0" );

	//printf("%d\n", strspn(p, string2));
	
	//print p
	//char * p2 = (char*) to_c_string(p);
	//printf("%s\n", p2);
	//free(p2);
	// test str len
	unsigned int i, totalCalc = 10000000;
	unsigned long int sum = 0;
	
	for(i = 0; i < totalCalc; i++){
		uint64_t i1 = rdtsc();
		//strpbrk (str, key);
		uint64_t i2 = rdtsc();
		sum += i2 - i1;
	}
	
	printf("%d\n", sum/totalCalc);

	//printf("%d\n", end-start);
	printf("\n");

  char str[] ="- This, a sample string.0";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-0");
  while (pch != NULL)
  {
    printf ("%s\n",to_c_string(pch) );
    pch = strtok (NULL, " ,.-");
  }

  	printf("%s\n", str);
  	



}