#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Just for information : 
char * mystrcat( char * destination, const char * source ) {
    char * returnValue = destination;
    while( *destination ) ++destination;
    while( *destination++ = *source++ );
    return returnValue;
}
*/

int main() {

    char * firstName = (char *) malloc( 40 );
    char * lastName = (char *) malloc( 40 );
    char * fullName;
    size_t fullSize;

    printf( "Please, enter your first name: " );
    scanf( "%s", firstName );

    printf( "Enter your last name: " );
    scanf( "%s", lastName );
       
    /* The last +1 is for the last nul ASCII code for the string */
    fullSize = strlen( firstName ) + 1 +  strlen( lastName ) + 1;
       
    /* Memory allocation and copy */
    fullName = (char *) malloc( fullSize );
    strcpy( fullName, firstName );
    strcat( fullName, " " );
    strcat( fullName, lastName );
    /* You can also write :
    strcat( strcat( strcpy( fullName, firstName ), " " ), lastName );
    */
        
    printf( "Full name is: %s\n", fullName );
        
    free( fullName );
    free( lastName );
    free( firstName );
    
    return 0;
}