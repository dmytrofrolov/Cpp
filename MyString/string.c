/*

*/

#define BOOL short
#define bool short
#define FALSE 0
#define false 0
#define TRUE 1
#define true 1
#define NULL 0
// all functions
const unsigned char TERM_SYMBOL = '0';
typedef unsigned int size_t;

void *allocateString(const char *);
char *to_c_string(const void *);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memchr(const void *s, char c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memset(void *, int z, size_t);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *, size_t);
char *strchr(const char *, int);
char *strrchr(const char *, int);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
int strcoll(const char *, const char *);
char *strcpy(char *toHere, const char *fromHere);
char *strncpy(char *toHere, const char *fromHere, size_t n);
char *strerror(int);
size_t strlen(const char *);
size_t c_strlen(const char * source);
size_t strspn(const char *s, const char *accept);
size_t strcspn(const char *s, const char *reject);
char *strpbrk(const char *s, const char *accept);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *, const char *);
size_t strxfrm(char *dest, const char *src, size_t n);

void *allocateString(const char *cString){
	char * newString = (char*)malloc(c_strlen(cString)+1);
	memcpy(newString, cString, c_strlen(cString));
	*(newString+c_strlen(cString))=TERM_SYMBOL;
	return newString;
}

char *to_c_string(const void * source){
	char * newCString = (char*)malloc(strlen(source) + 1);
	memcpy(newCString, source, strlen(source));
	newCString[strlen(source)+1] = '\0';
	return newCString;
}

void *memchr(const void *ptr, char value, size_t num){
	const void *endS = ptr+num;
	for(;ptr!=endS;++ptr)
		if (*(char*)ptr==value) 
			return (void*)ptr;
	return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n){
	unsigned int i;
	for(i=0;i<n;++i){
		if(*(char*)s1>*(char*)s2)return 1;
		else if(*(char*)s1<*(char*)s2)return -1;
		++s1;
		++s2;
	}
	return 0;
}

void *memcpy(void *dest, const void *src, size_t n){
	unsigned int i;
	unsigned int diff = dest-src;
	char signOfDiff = (diff<0)?-1:1;
	if(diff * signOfDiff < n)return NULL;
	//if( ( ((dest-src)<0) ?(-(dest-src)):(dest-src) ) >= n )
	for(i = 0; i < n; ++i)
		*(((char*)dest)+i)=*(((char*)src)+i);
	return dest;
}

void *memmove(void *dest, const void *src, size_t n){
	unsigned int i;
	for(i = 0; i < n; ++i)
		*(((char*)dest)+i)=*(((char*)src)+i);
	return dest;
}

void *memset(void *dest, int z, size_t size){
	void *newDest = dest;
	
	int lessThanSize = 0;
	
	// if destination string size less than we want to fill
	// remember it in lessThanSize variable
	if(strlen(dest) <= size)lessThanSize=1;
	while(size){
		* ( (char*)dest ) = (char)z;
		++dest;
		--size;
	}
	
	// if we set more than destination was, write new eol symbol at the end
	if(lessThanSize)
		*(char*)dest = TERM_SYMBOL;
	return newDest;

}

char *strcat(char *dest, const char *src){
	memcpy(dest+strlen(dest), src, strlen(src)+1);
	return dest;
}

char *strncat(char *dest, const char *src, size_t size){
	size_t srcSize = strlen(src);
	size_t destSize = strlen(dest);
	
	if(size<=srcSize){
		memcpy(dest+destSize, src, size);
		*(dest+destSize+size)= TERM_SYMBOL;
	}
	else 
		memcpy(dest+destSize, src, srcSize+1);
	return dest;
}

char *strchr(const char *src, int value){
	for(;*src!=TERM_SYMBOL;++src)
		if (*src==value) 
			return (char*)src;
	return NULL;
}

char *strrchr(const char *src, int value){
	const char *endS = src+strlen(src);
	for(;endS!=src;--endS)
		if (*endS==value) 
			return (void*)endS;
	return NULL;
}

int strcmp(const char *s1, const char *s2){
	while(*s1!=TERM_SYMBOL && *s2!=TERM_SYMBOL){
		if(*s1>*s2)return 1;
		else if(*s1<*s2)return -1;
		++s1;
		++s2;
	}
	if(*s1==TERM_SYMBOL && *s2==TERM_SYMBOL)return 0;
	else if(*s2==TERM_SYMBOL)return 1;
	else return -1;
}

int strncmp(const char * s1, const char * s2, size_t size){
	while(*s1!=TERM_SYMBOL && *s2!=TERM_SYMBOL && size){
		if(*s1>*s2)return 1;
		else if(*s1<*s2)return -1;
		++s1;
		++s2;
		size--;
	}
	if( size==0 || (*s1==TERM_SYMBOL && *s2==TERM_SYMBOL) )return 0;
	else if(*s2==TERM_SYMBOL)return 1;
	else return -1;
}

// int strcoll(const char *, const char *);

char *strcpy(char *dest, const char *src){
	return memcpy(dest, src, strlen(src)+1);
}

char *strncpy(char *dest, const char *src, size_t size){
	while(size && *dest!=TERM_SYMBOL && *src!=TERM_SYMBOL){
		*dest++ = *src++;
		--size;
	}
	return dest;
}

// char *strerror(int);

size_t strlen(const char * source){
	const char * startSource = source;
	for(source; *source!=TERM_SYMBOL; ++source);
	return source-startSource;
}

size_t c_strlen(const char * source){
	size_t len = 0;
	while( *(source++)!= '\0')len++;
	return len;
}

size_t strspn(const char *str1, const char *str2){
	size_t n = 0;
	while(*str1!=TERM_SYMBOL){
		if(strchr(str2, *str1++)!=NULL)++n;
		else return n;
	}
	return n;
}

size_t strcspn(const char *str1, const char *str2){
	size_t n = 0;

	while(*str1!=TERM_SYMBOL){
		if(strchr(str2, *str1++)==NULL)++n;
		else return n;
	}
	return n;
}

char *strpbrk(const char *str1, const char *str2){
	while(*str1!=TERM_SYMBOL){
		if(strchr(str2, *str1++)!=NULL)return (char*)(str1-1);
	}
	return (char *)NULL;
}

char *strstr(const char *str1, const char *str2){
	const char *str1TempCopy;
	const char *str2TempCopy;
	bool found = true;

	while(*str1!=TERM_SYMBOL){
		str1TempCopy = str1;
		str2TempCopy = str2;
		while(*str2TempCopy!=TERM_SYMBOL){
			if(*str2TempCopy!=*str1TempCopy){
				found = false;
				break;
			}
			++str2TempCopy;
			++str1TempCopy;
		}
		if(found == true){
			return (char*)str1;
		}else{
			found = true;
		}
		++str1;
	}
	return NULL;
}

char *strtok(char *str, const char *delimiters){
	char * tempToken;
	static char * strSt = NULL;
	if(delimiters == NULL) return NULL;
	if(str != NULL) 
		strSt = str;
	else if(strSt == NULL) return NULL;
	do{
		tempToken = strSt;
		strSt = strpbrk(strSt, delimiters);
		if(tempToken!=strSt){
			break;
		}else{
			++strSt;
		}
	}while(1);
	if(strSt == NULL) return tempToken;

	*(strSt) = TERM_SYMBOL;
	++strSt;

	return tempToken;

	
}
// size_t strxfrm(char *dest, const char *src, size_t n);