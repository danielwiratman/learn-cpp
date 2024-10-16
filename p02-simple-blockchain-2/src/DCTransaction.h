#pragma once

#include "utils.h"

class TXInput
{
  public:
	array<unsigned char, 32> previousTxHash;
	int outputIndex;
	TXInput(array<unsigned char, 32> previousTxHash, int outputIndex)
											: previousTxHash(previousTxHash),
											  outputIndex(outputIndex)
	{
	}
};

class TXOutput
{
  public:
	string recipientAddress;
	double amount;
	TXOutput(string recipientAddress, double amount)
											: recipientAddress(
												  recipientAddress),
											  amount(amount)
	{
	}
};

class DCTransaction
{
	vector<TXInput> inputs;
	vector<TXOutput> outputs;

	array<unsigned char, 32> signature;

	array<unsigned char, 32> hash;

	vector<unsigned char>
	serialize_inputs_outputs()
	{
		vector<unsigned char> result;
		for (auto input : inputs)
		{
			auto outputIndexBytes = my_to_bytes(input.outputIndex);
			result.insert(result.end(),
						  outputIndexBytes.begin(),
						  outputIndexBytes.end());
			result.insert(result.end(),
						  input.previousTxHash.begin(),
						  input.previousTxHash.end());
		}
		for (auto output : outputs)
		{
			result.insert(result.end(),
						  output.recipientAddress.begin(),
						  output.recipientAddress.end());
			auto amountBytes = my_to_bytes(output.amount);
			result.insert(result.end(), amountBytes.begin(), amountBytes.end());
		}

		return result;
	}

  public:
	DCTransaction(vector<TXInput> inputs, vector<TXOutput> outputs)
											: inputs(inputs), outputs(outputs)
	{
		hash = my_sha256_hash(serialize_inputs_outputs());
	}

	vector<unsigned char>
	serialize()
	{
		vector<unsigned char> result;

		vector<unsigned char> io_serialized = serialize_inputs_outputs();
		result.insert(result.end(), io_serialized.begin(), io_serialized.end());

		result.insert(result.end(), hash.begin(), hash.end());

		result.insert(result.end(), signature.begin(), signature.end());

		return result;
	};

	vector<TXInput>
	get_inputs()
	{
		return inputs;
	}

	vector<TXOutput>
	get_outputs()
	{
		return outputs;
	}

	array<unsigned char, 32>
	get_hash()
	{
		return hash;
	}
};
