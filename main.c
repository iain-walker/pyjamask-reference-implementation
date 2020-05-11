#include "pyjamask.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void tobyte(uint8_t x[], char *hexstring) {

  int i;

   uint8_t str_len = strlen(hexstring);

    for (i = 0; i < (str_len / 2); i++) {
     
        sscanf(hexstring+2*i, "%02X", &x[i]);
     

    }
}

int main() {


  uint8_t key[16];
  uint8_t plain[17];
  uint8_t cipher[16];

  char *msghex="50796a616d61736b2d3132383a293a29";
  char *keyhex="00112233445566778899aabbccddeeff";

  tobyte(plain,msghex); // hex string to byte array
  tobyte(key,keyhex);

  pyjamask_128_enc(plain,  key, cipher);

  printf("Plain:\t");
  for (int i = 0; i < 16; i++) printf("%02x ",plain[i]);
  printf("\nKey:\t");
  for (int i = 0; i < 16; i++) printf("%02x ",key[i]);
  printf("\nCipher:\t");
  for (int i = 0; i < 16; i++) printf("%02x ",cipher[i]);
  
  pyjamask_128_dec(cipher, key, plain);
  printf("\nDecrypting.....................");
  printf("\nPlain:\t");
  for (int i=0; i<16; i++) printf("%02x ", plain[i]);

}