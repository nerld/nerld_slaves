#ifndef BASE_SLAVE_H
#define BASE_SLAVE_H

class BaseSlave {
public:
	BaseSlave();
	BaseSlave(int addr);

	int m_address;
};

#endif