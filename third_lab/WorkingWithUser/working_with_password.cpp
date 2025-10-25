#include "working_with_password.h"
#include <conio.h>
#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>

std::string HidePassword::ReadPassword() {
	std::string password;

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;

	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	char ch;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!password.empty()) {
				password.pop_back();
				std::cout << "\b \b";
			}
		} else if (ch >= 32 && ch <= 126) {
			password.push_back(ch);
			std::cout << '*';
		}
	}
	SetConsoleMode(hStdin, mode);
	std::cout << std::endl;

	return password;
}

void Hash::SetHash(const std::string &hash) {
	this->hash_ = hash;
}

void Hash::SetSalt(const std::string &salt) {
	this->salt_ = salt;
}

std::string Hash::GetHash() const {
	return this->hash_;
}

std::string Hash::GetSalt() const {
	return this->salt_;
}

std::string HashPassword::GenerateSalt(size_t length){
	std::string generate_salt;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 255);
	for (size_t i = 0; i < length; ++i) {
		generate_salt += static_cast<char>(dis(gen));
	}
	return generate_salt;
}

Hash HashPassword::HashInputPassword(const std::string &password) {
	auto hash_password = Hash();
	const std::string new_salt= GenerateSalt(6);
	const std::string temp_password  = password+new_salt;
	hash_password.SetHash(HashAlgorithm(temp_password));
	hash_password.SetSalt(new_salt);
	return hash_password;
}

bool HashPassword::IsPasswordMatch(const std::string &check_password, const Hash &hash) {
	const std::string temp_salt = hash.GetSalt();
	const auto temp_password = HashAlgorithm(check_password+temp_salt);
	return temp_password== hash.GetHash();
}


std::string HashPassword::HashAlgorithm(const std::string& input) {
	HCRYPTPROV hProv = 0;
	HCRYPTHASH hHash = 0;
	std::string result;

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		return "";
	}

	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
		CryptReleaseContext(hProv, 0);
		return "";
	}

	if (!CryptHashData(hHash, (BYTE*)input.c_str(), input.length(), 0)) {
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	BYTE hash[32];
	DWORD hashLen = 32;

	if (CryptGetHashParam(hHash, HP_HASHVAL, hash, &hashLen, 0)) {
		std::stringstream ss;
		for (DWORD i = 0; i < hashLen; i++) {
			ss << std::hex << std::setfill('0') << std::setw(2)
			   << static_cast<int>(hash[i]);
		}
		result = ss.str();
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);

	return result;
}