#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <openssl/aes.h>
#include <string.h>

int main(void)
{
	//加密采用的密钥
    unsigned char userkey[AES_BLOCK_SIZE];
	
	//原始数据
    unsigned char *date = (unsigned char *)malloc(AES_BLOCK_SIZE);
	
	//密文数据
    unsigned char *encrypt = (unsigned char *)malloc(AES_BLOCK_SIZE);
	
	//明文数据
    unsigned char *plain = (unsigned char *)malloc(AES_BLOCK_SIZE);
	
	AES_KEY key;
	
	//设置密钥内容为全‘k’
    memset(userkey, 'k', AES_BLOCK_SIZE);
	
	//设置数据内容为全‘p’
    memset(date, 0xAA, AES_BLOCK_SIZE);

	//明文密文均初始化为0
    memset(encrypt, 0, AES_BLOCK_SIZE);
    memset(plain, 0, AES_BLOCK_SIZE);

    /*设置加密key及密钥长度*/
    AES_set_encrypt_key(userkey, AES_BLOCK_SIZE*8, &key);

    AES_encrypt(date, encrypt, &key);    
      
    AES_set_decrypt_key(userkey, AES_BLOCK_SIZE*8, &key);

    AES_decrypt(encrypt, plain, &key);    
     
	for(int i = 0; i < AES_BLOCK_SIZE; i++)
	{
		printf("%02X", *(encrypt + i));
	}
	printf("\n");
	for(int i = 0; i < AES_BLOCK_SIZE; i++)
	{
		printf("%02X", *(plain + i));
	}
	printf("\n");
    return 0;
}