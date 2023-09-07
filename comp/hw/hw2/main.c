#include "hw1.h"

#include <string.h>
#include <time.h>
#include <stdlib.h>

void print_array( int array[], int size, FILE* out )
{
	for ( int i=0; i<size-1; i++ )
		fprintf( out,"%d, ", array[i]);
	if ( size > 0 )	
		fprintf( out,"%d", array[size-1]);
}

void test_absolute_value(char *line, FILE *out)
{
	int num;
	int offset = strlen( "absolute_value " );
	sscanf( line+offset, "%d", &num );
	fprintf(out, "absolute_value %d  = %d\n", num, absolute_value(num));
}

void test_sum_of_squares( char *line, FILE* out )
{
	int size = 10;
	int count = 0;
	int * array = malloc( size * sizeof(int) );
	int offset = strlen("sum_of_sqaures");
	int num;
	int num_read = sscanf(line+offset, "%d", &num );

	while( 	num_read > 0 )
	{
		if ( num > 0 )
		{
			if ( num > 10 )
				offset += 4;
			else
				offset += 3;
		}
		else
		{
			if ( num < -10 ) 
				offset += 5;
			else
				offset += 4;
		}

		if ( size == count )
		{
			array = realloc( array, size * 2 * sizeof(int) );
			size *= 2;
		}
		array[count] = num;
		count++;

		num_read = sscanf(line+offset, "%d", &num );
	}

	fprintf(out, "sum_of_sqaures ");
	print_array( array, count, out );
	fprintf( out, " is %d\n", sum_of_squares(array, count ));

	free( array );
}

void test_find_biggest( char *line, FILE* out )

{
	int size = 10;
	int count = 0;
	int * array = malloc( size * sizeof(int) );
	int offset = strlen("find_biggest  ");
	char o_o_e[5];
	int num;
	int num_read = sscanf(line+offset, "%s %d", o_o_e, &num );

	offset += strlen(o_o_e);

	while( 	num_read > 0 )
	{
		if ( num > 0 )
		{
			if ( num > 10 )
				offset += 4;
			else
				offset += 3;
		}
		else
		{
			if ( num < -10 ) 
				offset += 5;
			else
				offset += 4;
		}

		if ( size == count )
		{
			array = realloc( array, size * 2 * sizeof(int) );
			size *= 2;
		}
		array[count] = num;
		count++;

		num_read = sscanf(line+offset, "%d", &num );
	}

	enum odd_or_even odd_even;
	if ( strcmp( o_o_e, "EVEN" ) == 0 )
		odd_even = EVEN;
	else
		odd_even = ODD;

	fprintf(out, "find_biggest %s ", o_o_e);
	print_array( array, count, out );
	fprintf( out, " is %d\n", find_biggest(array, count, odd_even));

	free( array );
}
int main(int argc, char* argv[])
{
	if ( argc != 3 )
	{
		fprintf( stderr, "Usage: test-hw1 <input> <output>\n" );
		exit(1);
	}
	FILE* in = fopen( argv[1], "r" );
	FILE* out = fopen( argv[2], "w" );
	

	char line[256];
	fgets(line, 255, in );
	while ( !feof(in ) )
	{
		char command[256];
		sscanf( line, "%s(", command );
		if ( strcmp( command, "sum_of_squares" ) == 0 )
		{
			test_sum_of_squares(line, out );
		}
		else if ( strcmp( command, "find_biggest" ) == 0 )
		{
			test_find_biggest(line, out );
		}
		else if ( strcmp( command, "absolute_value" ) == 0 )
		{
			test_absolute_value( line, out );
		}
		else
		{
			printf( "Unknown command: %s\n", command );
		}
		
		fgets(line, 255, in );
	}

	fclose(in);
	fclose(out);

	return 0;
}
