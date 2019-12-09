#include "asciiIO_t.h"
asciiIO_t &asciiIO_t::operator<<(int num) { return Write(num, "%d"); }
asciiIO_t &asciiIO_t::operator>>(int &num) { return Read(num, "%d"); }

asciiIO_t &asciiIO_t::operator<<(char c) { return Write(c, "%c"); }
asciiIO_t &asciiIO_t::operator>>(char &c) { return Read(c, "%c"); }

asciiIO_t &asciiIO_t::operator<<(unsigned char uc) { return Write(uc, "%c"); }
asciiIO_t &asciiIO_t::operator>>(unsigned char &uc) { return Read(uc, "%c"); }

asciiIO_t &asciiIO_t::operator<<(short s) { return Write(s, "%hd"); }
asciiIO_t &asciiIO_t::operator>>(short &s) { return Read(s, "%hd"); }

asciiIO_t &asciiIO_t::operator<<(float f) { return Write(f, "%f"); }
asciiIO_t &asciiIO_t::operator>>(float &f) { return Read(f, "%f"); }

asciiIO_t &asciiIO_t::operator<<(unsigned short us) { return Write(us, "%hu"); }
asciiIO_t &asciiIO_t::operator>>(unsigned short &us) { return Read(us, "%hu"); }

asciiIO_t &asciiIO_t::operator<<(unsigned int num) { return Write(num, "%u"); }
asciiIO_t &asciiIO_t::operator>>(unsigned int &num) { return Read(num, "%u"); }

asciiIO_t &asciiIO_t::operator<<(long int num) { return Write(num, "%ld"); }
asciiIO_t &asciiIO_t::operator>>(long int &num) { return Read(num, "%ld"); }

asciiIO_t &asciiIO_t::operator<<(unsigned long int num) { return Write(num, "%lu"); }
asciiIO_t &asciiIO_t::operator>>(unsigned long int &num) { return Read(num, "%lu"); }

asciiIO_t &asciiIO_t::operator<<(double num) { return Write(num, "%lf"); }
asciiIO_t &asciiIO_t::operator>>(double &num) { return Read(num, "%lf"); }

