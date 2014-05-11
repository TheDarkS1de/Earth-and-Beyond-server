// WestwoodRSA.h

#ifndef _WESTWOOD_RSA_H_INCLUDED_
#define _WESTWOOD_RSA_H_INCLUDED_

#include <openssl/bn.h>

#define WWRSA_BLOCK_SIZE  64 // bytes

#define WWRSA_p "90336306034988608177990369937674942312598126945629080039358980696516831956279"
#define WWRSA_q "114965715011442463284112195027084055446504070890856867618584335022146211064213"
#define WWRSA_N "10385578014804950221065190195736491193847541479389728420426514083771326945639729736695791225573893793119489336012297845146104637691941242485732839277543427"
#define WWRSA_d "10088847214381951643320470475858305731166183151407164751271470824235003318621252307969752086088076499395823874814123350292603347408732347765156628342107995"
#define WWRSA_e "35"

class WestwoodRSA
{
public:
    WestwoodRSA();
    virtual ~WestwoodRSA();

public:
    bool Encrypt(unsigned char *in_buffer, unsigned int length, unsigned char *out_buffer);
    bool Decrypt(unsigned char *in_buffer, unsigned int length, unsigned char *out_buffer);
    unsigned int GetModulus(unsigned char **p_out_buffer);
    unsigned int GetPublicExponent(unsigned char **p_out_buffer);

private:
	BIGNUM *p;
	BIGNUM *q;
	BIGNUM *N;
	BIGNUM *d;
	BIGNUM *e;
	BN_CTX *temp;
};

#endif // _WESTWOOD_RSA_H_INCLUDED_
