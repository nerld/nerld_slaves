#ifndef BASE_SLAVE_H
#define BASE_SLAVE_H

class BaseSlave {
public:
	BaseSlave();
	BaseSlave(int addr);

	int m_address;
	int m_type;
};

#endif