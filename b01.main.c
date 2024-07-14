/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include  "openssl/bio.h"

int ssl_init();
struct bio_st * hostNport( char *hnp );
void httpGetReq( struct bio_st *bio , char *host ); 
void httpGetResp( struct bio_st *bio ); 

int main ( int argc , char * argv [ ] ) {

	if ( argc != 3 ) {
		fprintf ( stderr , "Error: Usage error.\n Expecting:\n ./a.out host port\n ex:\n ./a.out example.com 80\n" ) ;
		exit ( 1 ) ;
	}

	// https://developer.ibm.com/tutorials/l-openssl/
	
	printf ( "main()\n" ) ;

	// we do not need to initialize ssl for just using bio
	/*
	ret = ssl_init();
	if ( ret ) { 
		fprintf ( stderr , "Error: ssl_init()" );
		exit ( 1 );
	}
	printf ( "main(): initialized openssl() CHECK\n" );
	*/	

	struct bio_st *bio;

	// cmd line input data
	char hnpBuf[100];
	char *hnp = hnpBuf;

	sprintf( hnp , "%s:%s" , argv[1] , argv[2] ) ;

	// configure connection for hostname and port
	bio = hostNport ( hnp ); 
	printf ( "hostNport(): BIO_new_connect() , BIO_do_connect() CHECK\n" );

	// make an http get request
	httpGetReq ( bio , argv[1] ) ;
	printf ( "BIO_write() CHECK\n" );

	// process the http get response
	httpGetResp ( bio ) ;


	// finally closing the connection
	// BIO_reset ( bio ) ; // if want to re-use for a second connection
	BIO_free_all ( bio ) ;

	return 0;

}
