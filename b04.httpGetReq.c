/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <string.h>
# include  "openssl/bio.h"

void httpGetReq( struct bio_st *bio , char *host ) {

	char getBuf[100] = {0};
	char *get = getBuf;

	sprintf ( get , "GET / HTTP/1.1\r\nHost: %s\r\n\r\n" , host );

	int ret =  BIO_write ( bio , get , strlen ( get ) ); 

	if ( ret < 1 ) {
		fprintf ( stderr , "BIO_write() error" );
		exit ( 1 ) ;
	}
}
