#pragma once
#include <String>
#include <vector>
#include <random>
class SequenceComparer {
	private:
		//std::vector<std::string*> _fullSequenceM;
		//std::vector<std::string*> _fullSequenceN;
		//std::string* sampleM;
		//std::string* sampleN;
	public:
		std::vector<std::string> _fullSequenceM;
		std::vector<std::string> _fullSequenceN;
		SequenceComparer() = default;
		virtual ~SequenceComparer() = default;
		void compareSequences();
		void genSequences();
};