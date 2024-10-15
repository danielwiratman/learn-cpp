#pragma once

#include "utils.h"

struct DCTransaction
{
	array<unsigned char, 32> previousTransactionHash;
	string recipientAddress;
	double amount;

	array<unsigned char, 32> signature;

	array<unsigned char, 32> hash;

	DCTransaction(array<unsigned char, 32> previousTransactionHash,
				  string recipientAddress, double amount)
											: previousTransactionHash(
												  previousTransactionHash),
											  recipientAddress(
												  recipientAddress),
											  amount(amount) {};
};
