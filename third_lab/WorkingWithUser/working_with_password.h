
#ifndef WORKING_WITH_PASSWORD_H
#define WORKING_WITH_PASSWORD_H
#include <string>
#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "crypt32.lib")
#endif

class HidePassword {
public:
	static std::string ReadPassword();
};

class Hash {
public:
	void SetHash(const std::string& hash);
	void SetSalt(const std::string& salt);
	std::string GetHash() const;
	std::string GetSalt() const;
private:
	std::string hash_;
	std::string salt_;
};

class HashPassword {
public:
	static std::string GenerateSalt(size_t length =4);
	static Hash HashInputPassword(const std::string& password);
	static bool IsPasswordMatch(const std::string& check_password, const Hash& hash);
private:
	static std::string HashAlgorithm(const std::string& input);
};


#endif //WORKING_WITH_PASSWORD_H
