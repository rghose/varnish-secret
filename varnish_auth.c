#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CLI_AUTH_RESPONSE_LEN		64


void VCLI_AuthResponse( int S_fd, const char *challenge, char response[CLI_AUTH_RESPONSE_LEN + 1] );


int main(int argc, char **argv) {
	int fd;
	char challenge[200], response[200];

	if( argc <= 1 ) {
		printf ("No secret file name specified");
		return -1;
	}
	
  if ((fd = open( argv[1], O_RDONLY )) == -1 ) {
		printf ("Error in opening file." );
		return -2;
	}

	scanf( "%s", challenge );

	VCLI_AuthResponse( fd, challenge, response );

	printf( "%s", response );

	close(fd);
	return 0;
}
