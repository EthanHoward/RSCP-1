#pragma once

#include <vector>
#include <string>

namespace Parser
{

	using namespace std;

	enum TokenType
	{
		WHITESPACE, // No Token::TokenType should have this set, if it does have this set it should only be a whitespace
		IDENTIFER,
		INTEGER_LITERAL,
		DOUBLE_LITERAL,
		STRING_LITERAL,
		OPERATOR, // = / ? > < . - + *
		STRING_ESCAPE_SEQUENCE,
		POTENTIAL_DOUBLE,
		POTENTIAL_COMMENT,
		COMMENT
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
		vector<Token> parse(const std::string &inProgram);

	private:
		void endToken(Token &token, vector<Token> &tokens);
	};

};
