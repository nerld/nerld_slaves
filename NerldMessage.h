#ifndef NERLD_MESSAGE_H
#define NERLD_MESSAGE_H
#define SWITCH 0
#define SERVO 1
#define MOTOR 2
#define TMP36 3

class NerldMessage {
public:
	int m_addr;
	int m_type;
	float m_float_val;
	int m_int_val;
};


#endif