/*
 * author: Nadeem Elahi
 * nadeem.elahi@gmail.com
 * nad@3deem.com
 * license: gpl v3
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include  "openssl/bio.h"

#define BFSZ 1048

void httpGetResp (  struct bio_st *bio  ) {

	char respBuf[BFSZ] = {0};
	char *resp = respBuf;

	int ret = 0; //int cnt = 0;

	void read () {

		ret = BIO_read ( bio , resp , BFSZ );

		//printf( "\n\n ret: %d \n\n" , ret );
		//cnt = BIO_number_read ( bio ) ; // ret and cnt is same

		if ( ret > 0 ) {
			printf( "%s" , resp ) ;

			if ( 
					respBuf[ ret - 8 ] == '<'  
					&& respBuf[ ret - 7 ] == '/'  
					&& respBuf[ ret - 6 ] == 'h'  
					&& respBuf[ ret - 5 ] == 't'  
					&& respBuf[ ret - 4 ] == 'm'  
					&& respBuf[ ret - 3 ] == 'l'  
					&& respBuf[ ret - 2 ] == '>'  
					
					) {

				//printf( "tail: %s\n" , ( resp + (ret - 8 ) ) ); 
				// yes it is end of doc - no need to call BIO_read() again
				// and then have to wait(be blocked) for the server to close the socket
				return; 
			}
									    
			memset ( resp , '\0' , BFSZ ) ;
			read ();

		} else {

			printf ( "\n\nnothing was read\n\n" );
			if ( ret == 0 ) {

				fprintf ( stderr , "BIO_read() error - closed connection\n" );
				exit ( 1 ) ;

			} else if ( ret < 0 ) {

				fprintf ( stderr , "BIO_read() error - failed to read\n" );
				exit ( 1 ) ;
			}
		}
	}

	printf ( "\n\n" );
	read() ;

	printf ( "BIO_read() CHECK\n" );


}
