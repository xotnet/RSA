# RSA
simple C++ RSA lib

**Example usage**
```
int main() {
	std::string privateKey, publicKey;
	genPairRSA(&privateKey,&publicKey,7);
	std::cout << "Private key: " << privateKey << "\n\nPublic key: " << publicKey;
	std::string msg = "99999999";
	encryptRSA(&publicKey, &msg);
	std::cout << "\n\nEncrypted message: " << msg;
	decryptRSA(&privateKey, &msg);
	std::cout << "\n\nDecrypted message: " << msg << '\n';
}
```
**Example output**
```
Private key: 28183328108153,35644977120917

Public key: 65537,35644977120917

Encrypted message: 16021720101273
Decrypted message: 99999999
```


BitCoin DONATION ☕️: ```bc1q24sqqj6p6htuktap2vht2uzna9u7w3wlk8kfwk```

Monero DONATION ☕️: ```86FBJmZrMPcQvNQJ7fJ1Khg9Z1YMUBE2N6jzPiUbLtaKWQD1sTHbcB5JmCmxmNDkKXXQkic5pezv5hR6BLTvrSvvK7wA5LR```
