#include <iostream>
#include <stdexcept>
#include "parser.h"

int main(int argc, char* argv[])
{
	int i ;
	parser_t p;

	for(i = 1; i < argc; ++i)
	{
		cout<<endl<<endl;
		
		try
		{
			p.parserFile(argv[i]);
		}
		catch (runtime_error& e)
		{
			cerr<<"Error with "<<argv[i]<<" -- "<<e.what()<<endl<<endl;
		} 
	}
	
	return 0;
}