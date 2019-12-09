#include "asciiIO_t.h"
#include "binIO_t.h"

template <class T>
void writeTest(virtIO_t *vir)
{
	T i;
	char c = ' ';
	cin >> i;
	(*vir) << i << c;
}

template <class T>
void readTest(virtIO_t *vir)
{
	T i;
	(*vir) >> i;
	cout << "The data: " << i << " ";
}

void vpTestWrite(virtIO_t *vir)
{
	
}

void vpTestRead(virtIO_t *vir)
{
	
}

void readToFile(virtIO_t *vir)
{
	char c;
	int i = 1;
	while (i)
	{
		cout << endl
			 << "i - int | l - long | f - float | c - char | d - double | v - void* | e - exit " << endl;
		cin >> c;
		switch (c)
		{
		case 'i':
		{
			readTest<int>(vir);
			break;
		}
		case 'l':
		{
			readTest<long>(vir);
			break;
		}
		case 'f':
		{
			readTest<float>(vir);
			break;
		}
		case 'c':
		{
			readTest<char>(vir);
			break;
		}
		case 'd':
		{
			readTest<double>(vir);
			break;
		}
		case 'v':
		{
			//vpTestRead(vir);
			break;
		}
		case 'e':
		{
			i = 0;
			break;
		}
		default:
			break;
		}
	}
}

void writeToFile(virtIO_t *vir)
{
	char c;
	int i = 1;
	while (i)
	{
		cout << endl
			 << "i - int | l - long | f - float | c - char | d - double | v - void*  | e - exit" << endl;
		cin >> c;
		switch (c)
		{
		case 'i':
		{
			writeTest<int>(vir);
			break;
		}
		case 'l':
		{
			writeTest<long>(vir);
			break;
		}
		case 'f':
		{
			writeTest<float>(vir);
			break;
		}
		case 'c':
		{
			writeTest<char>(vir);
			break;
		}
		case 'd':
		{
			writeTest<double>(vir);
			break;
		}
		case 'v':
		{
			//vpTestWrite(vir);
			break;
		}
		case 'e':
		{
			i = 0;
			break;
		}
		default:
			break;
		}
	}
}

void fileTest(virtIO_t *vir)
{
	string name;
	string mode;
	cout << "enter file name" << endl;
	cin >> name;
	cout << "enter mode " << endl;
	cin >> mode;
	try
	{
		vir->Fopen(name.c_str(), mode.c_str());
	}
	catch (string e)
	{
		cout << e << endl;
		vir->Fclose();
		return;
	}

	// if (vir->getStatus() != virtIO_t::ok_e)
	// {
	// 	cout << "ERROR - wrong input" << endl;
	// }

	char c;
	while (1)
	{
		cout << endl
			 << "r - read | w - write |  p - get position | s - set position | l - get length | e - exit " << endl;
		cin >> c;
		bool boo = 0;
		try
		{
			switch (c)
			{
			case 'r':
			{
				readToFile(vir);

				break;
			}
			case 'w':
			{

				writeToFile(vir);

				break;
			}
			case 'p':
			{
				cout << "The position: " << vir->getPosition() << endl;
				break;
			}
			case 's':
			{
				size_t s;
				cin >> s;
				vir->setPosition(s);
				break;
			}
			case 'l':
			{
				cout << "The lenght: " << vir->getfileLen() << endl;
				break;
			}
			case 'e':
			{
				boo = 1;
				break;
			}
			default:
				break;
			}
			if (boo)
			{
				break;
			}
		}
		catch (string ex)
		{
			cout << ex << endl;
		}
	}
	vir->Fclose();
}
int main()
{
	int i = 1;
	while (i)
	{
		cout << "choose a - ascii | b - binary | e - exit " << endl;
		char c;
		cin >> c;
		if (c == 'a')
		{
			asciiIO_t a1;
			fileTest(&a1);
		}
		else if (c == 'b')
		{
			binIO_t b1;
			fileTest(&b1);
		}
		else if (c == 'e')
		{
			i = 0;
		}
	}
	return 0;
}