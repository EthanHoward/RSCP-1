#include "Tokeniser.hpp"
#include <stdexcept>
#include <iostream>

namespace Parser
{

	using namespace std;

	vector<Token> Tokeniser::parse(const string &inProgram)
	{
		vector<Token> Tokens;
		Token currentToken;

		currentToken.mLineNumber = 1;

		for (char curChr : inProgram)
		{
			if (currentToken.mType == STRING_ESCAPE_SEQUENCE)
			{
				switch (curChr)
				{
				case 'n':
					currentToken.mText.append(1, '\n');
					break;
				case 'r':
					currentToken.mText.append(1, '\r');
					break;
				case 't':
					currentToken.mText.append(1, '\t');

				case '\\':
					currentToken.mText.append(1, '\\');
					break;

				default:
					throw runtime_error(string("[1]: Unknown excape sequence: \\" + string(1, curChr)) + " in string on line " + to_string(currentToken.mLineNumber) + ".");
					break;
				}
				currentToken.mType = STRING_LITERAL;
				continue;
			}

			switch (curChr)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (currentToken.mType == WHITESPACE)
				{
					currentToken.mType = INTEGER_LITERAL;
					currentToken.mText.append(1, curChr);
				} else if (currentToken.mType == POTENTIAL_DOUBLE) {
					currentToken.mType = DOUBLE_LITERAL;
					currentToken.mText.append(1, curChr);
				} else {
					currentToken.mText.append(1, curChr);
				}
				break;
//////////////////////
			case '.':
				if (currentToken.mType == WHITESPACE) {
					currentToken.mType = POTENTIAL_DOUBLE;
					currentToken.mText.append(1, curChr);
				} else if (currentToken.mType == INTEGER_LITERAL) {
					currentToken.mType = DOUBLE_LITERAL;
					currentToken.mText.append(1, curChr);
				} else if (currentToken.mType == STRING_LITERAL) {
					currentToken.mText.append(1, curChr);
				} else {
					endToken(currentToken, Tokens);
					currentToken.mType = OPERATOR;
					currentToken.mText.append(1, curChr);
					endToken(currentToken, Tokens);
				}
				break;
			case '{':
			case '}':
			case '(':
			case ')':
			case '=':
			case '-':
			case ';':
			case ',':
				if (currentToken.mType != STRING_LITERAL)
				{
					endToken(currentToken, Tokens);
					currentToken.mType = OPERATOR;
					currentToken.mText.append(1, curChr);
					endToken(currentToken, Tokens);
				}
				else
				{
					currentToken.mText.append(1, curChr);
				}
				break;
//////////////////////
			case ' ':
			case '\t':
				endToken(currentToken, Tokens);
				break;
			case '\r':
			case '\n':
				endToken(currentToken, Tokens);
				++currentToken.mLineNumber;
				break;
//////////////////////
			case '"':
				if (currentToken.mType != STRING_LITERAL)
				{
					endToken(currentToken, Tokens);
					currentToken.mType = STRING_LITERAL;
					currentToken.mText.append(1, curChr);
				}
				else if (currentToken.mType == STRING_LITERAL)
				{
					endToken(currentToken, Tokens);
				}
				break;
//////////////////////
			case '\\':
				if (currentToken.mType != STRING_LITERAL)
				{
					endToken(currentToken, Tokens);
					currentToken.mType = STRING_ESCAPE_SEQUENCE;
				}
				else if (currentToken.mType == STRING_LITERAL)
				{
					endToken(currentToken, Tokens);
					currentToken.mType = OPERATOR;
					currentToken.mText.append(1, curChr);
					endToken(currentToken, Tokens);
				}
				break;
//////////////////////
			case '/':
				if (currentToken.mType == STRING_LITERAL) {
					currentToken.mText.append(1, curChr);
				} else if (currentToken.mType == STRING_LITERAL) {
					currentToken.mType = COMMENT;
					currentToken.mText.erase();
				} else {
					endToken(currentToken, Tokens);
					currentToken.mType = POTENTIAL_COMMENT;
					currentToken.mText.append(1, curChr);
				}
				break;



			default:
				if (currentToken.mType == WHITESPACE || currentToken.mType == INTEGER_LITERAL || currentToken.mType == DOUBLE_LITERAL) {
					endToken(currentToken, Tokens);
					currentToken.mType = IDENTIFER;
					currentToken.mText.append(1, curChr);
				}
				else {
					currentToken.mText.append(1, curChr);
				}
				break;
			}
		}

		endToken(currentToken, Tokens);

		return Tokens;
	}

	void Tokeniser::endToken(Token &token, vector<Token> &tokens)
	{
		if (token.mType == COMMENT) {
			cout << "Ignoring comment " << token.mText << endl;
		} else if (token.mType == WHITESPACE) {
			tokens.push_back(token);
		} else if (token.mType == POTENTIAL_DOUBLE) {
			if (token.mText.compare(".") == 0) {
				token.mType = OPERATOR;
			}
			token.mType = DOUBLE_LITERAL;
		}
		token.mType = WHITESPACE;
		token.mText.erase();
	}

}