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
