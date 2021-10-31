#pragma once

#include <vector>
#include <string>

namespace Parser
{

	using namespace std;

	enum TokenType
	{
		WHITESPACE, // No token has this type
		IDENTIFER,
		INTEGER_LITERAL,
		STRING_LITERAL,
		OPERATOR,
		STRING_ESCAPE_SEQUENCE
	};

	class Token
	{
	public:
		enum TokenType mType
		{
			WHITESPACE
		};
		string mText;
		size_t mStartOffset{0};
		size_t mEndOffset{0};
		size_t mLineNumber{0};
	};

	class Tokeniser
	{
	public:
		vector<Token> parse(const string &inProgram);

	private:
		void endToken(Token &token, vector<Token> &tokens);
	};

};
