/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include  "openssl/ssl.h"

int ssl_init( ) {

	printf ( "ssl_init()\n" ) ;

	SSL_load_error_strings();
	//ERR_load_BIO_strings(); // warning: depreciated since OpenSSL 3.0
	// not needed anymore
	OpenSSL_add_all_algorithms();
	printf ( "initialized openssl() \n" );

	return 0;
}
