#include <string>
#include <BigInt.hpp>
BigInt fastPow(BigInt base, BigInt exponent, BigInt mod) {
	BigInt result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exponent /= 2;
	}
	return result;
}
bool isPrime(BigInt n) {
	for (BigInt i = 2; i<sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void encryptRSA(std::string* publicKeyStr, std::string* intToBeEncrypted) {
	std::string es,ns;
	bool afterComma = false;
	for(char c : *publicKeyStr) {
		if (c == ',') {afterComma = true; continue;}
		if (!afterComma) {
			es = es + c;
		} else {
			ns = ns + c;
		}
	}
	BigInt e(es);
	BigInt n(ns);
	BigInt msg(*intToBeEncrypted);
    msg = fastPow(msg, e, n);
	*intToBeEncrypted = msg.to_string();
}
void decryptRSA(std::string* privateKeyStr, std::string* intToBeDecrypted) {
	std::string ds,ns;
	bool afterComma = false;
	for(char c : *privateKeyStr) {
		if (c == ',') {afterComma = true; continue;}
		if (!afterComma) {
			ds = ds + c;
		} else {
			ns = ns + c;
		}
	}
	BigInt d(ds);
	BigInt n(ns);
	BigInt msg(*intToBeDecrypted);
	msg = fastPow(msg, d, n);
	*intToBeDecrypted = msg.to_string();
}
BigInt extendedGCD(BigInt a, BigInt b, BigInt *x, BigInt *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	BigInt x1, y1;
	BigInt gcd = extendedGCD(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - (a / b) * y1;
	return gcd;
}
BigInt modInverse(BigInt a, BigInt m) {
	BigInt x, y;
	BigInt gcd = extendedGCD(a, m, &x, &y);
	if (gcd != 1)
		return -1;
	return (x % m + m) % m;
}
void genPairRSA(std::string* privateKey, std::string* publicKey, int size) {
	BigInt p = big_random(size);
	while (!isPrime(p)) {
		p = big_random(size);
	}
	BigInt q = big_random(size);
	while (!isPrime(q)) {
		q = big_random(size);
	}
	BigInt n = p*q;
	BigInt phi = (p-1)*(q-1);
	std::cout << "Phi: " << phi << '\n';
	BigInt e = 65537;
	BigInt d = modInverse(e, phi);
	*privateKey = d.to_string() + "," + n.to_string();
	*publicKey = e.to_string() + "," + n.to_string();
}
/*int main() {
	std::string privateKey, publicKey;
	genPairRSA(&privateKey,&publicKey,7);
	std::cout << "Private key: " << privateKey << "\n\nPublic key: " << publicKey;
	std::string msg = "99999999";
	encryptRSA(&publicKey, &msg);
	std::cout << "\n\n" << msg;
	decryptRSA(&privateKey, &msg);
	std::cout << "\n\n" << msg << '\n';
}*/