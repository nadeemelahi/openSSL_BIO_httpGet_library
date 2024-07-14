/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include <stdlib.h>

# include  "openssl/bio.h"


struct bio_st * hostNport( char *hnp ) {

	struct bio_st *bio = BIO_new_connect ( hnp ) ;
	//bio = BIO_new_connect ( "localhost:80" ) ;

	if ( bio == NULL ) {
		fprintf ( stderr , "BIO_new_connect() error" );
		exit ( 1 ) ;
	}

	int ret = BIO_do_connect ( bio ) ;

	if ( ret < 1 ) {
		fprintf ( stderr , "BIO_do_connect() error" );
		exit ( 1 ) ;
	}


	return bio;
}
