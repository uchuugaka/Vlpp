#include "ParsingJson_Parser.h"

namespace vl
{
	namespace parsing
	{
		namespace json
		{
/***********************************************************************
ParserText
***********************************************************************/

const wchar_t parserTextBuffer[] = 
L"\r\n" L""
L"\r\n" L"class Node"
L"\r\n" L"{"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Literal:Node"
L"\r\n" L"{"
L"\r\n" L"\tenum Value"
L"\r\n" L"\t{"
L"\r\n" L"\t\tTrue,"
L"\r\n" L"\t\tFalse,"
L"\r\n" L"\t\tNull,"
L"\r\n" L"\t}"
L"\r\n" L""
L"\r\n" L"\tValue value;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class String:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content(JsonUnescapingString)\t\t\t\t@Color(\"String\");"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Number:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Array:Node"
L"\r\n" L"{"
L"\r\n" L"\tNode[] items;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class ObjectField:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken name(JsonUnescapingString)\t\t\t\t@Color(\"AttName\");"
L"\r\n" L"\tNode value;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Object:Node"
L"\r\n" L"{"
L"\r\n" L"\tObjectField[] fields;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"token TRUEVALUE = \"true\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token FALSEVALUE = \"false\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token NULLVALUE = \"null\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token OBJOPEN = \"\\{\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token OBJCLOSE = \"\\}\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token ARROPEN = \"\\[\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token ARRCLOSE = \"\\]\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token COMMA = \",\";"
L"\r\n" L"token COLON = \":\";"
L"\r\n" L"token NUMBER = \"[\\-]?\\d+(.\\d+)?([eE][+\\-]?\\d+)?\"\t@Color(\"Number\");"
L"\r\n" L"token STRING = \"\"\"([^\\\\\"\"]|\\\\[^u]|\\\\u\\d{4})*\"\"\"\t\t@ContextColor();"
L"\r\n" L""
L"\r\n" L"discardtoken SPACE = \"\\s+\";"
L"\r\n" L""
L"\r\n" L"rule Node JLiteral"
L"\r\n" L"\t= STRING:content as String"
L"\r\n" L"\t= NUMBER:content as Number"
L"\r\n" L"\t= \"true\" as Literal with {value = \"True\"}"
L"\r\n" L"\t= \"false\" as Literal with {value = \"False\"}"
L"\r\n" L"\t= \"null\" as Literal with {value = \"Null\"}"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule ObjectField JField"
L"\r\n" L"\t= STRING:name \":\" JValue:value as ObjectField"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Object JObject"
L"\r\n" L"\t= \"{\" [JField:fields {\",\" JField:fields} ] \"}\" as Object"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Array JArray"
L"\r\n" L"\t= \"[\" [JValue:items {\",\" JValue:items} ] \"]\" as Array"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Node JValue"
L"\r\n" L"\t= !JLiteral"
L"\r\n" L"\t= !JObject"
L"\r\n" L"\t= !JArray"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Node JRoot"
L"\r\n" L"\t= !JObject"
L"\r\n" L"\t= !JArray"
L"\r\n" L"\t;"
;

			vl::WString JsonGetParserTextBuffer()
			{
				return parserTextBuffer;
			}

/***********************************************************************
SerializedTable
***********************************************************************/

const vint parserBufferLength = 3788; // 17748 bytes before compressing
const vint parserBufferBlock = 1024;
const vint parserBufferRemain = 716;
const vint parserBufferRows = 4;
const char* parserBuffer[] = {
"\x00\x0B\x00\x02\x83\x80\x07\x7D\x00\x82\x03\xFF\x45\x08\x82\x83\x86\x81\x21\x6F\x6C\x2F\x32\x37\x84\x86\x02\x86\x00\x17\x82\x93\x24\x3A\x39\x34\x37\x67\x06\x98\x8A\x88\x8E\x84\x00\x88\x12\x94\x98\x87\x0B\x93\x81\x20\x3A\x74\x4E\x21\x2D\x35\x32\x90\x86\x92\x0C\xA6\xA8\x93\x85\x88\x84\x96\x86\x3F\x80\x0B\x25\x39\x3F\x3B\x88\x32\x36\x88\xB8\x88\x8A\x99\x88\x9F\x96\x40\x83\x83\xA5\xA7\xA1\xA4\x83\xA5\x04\xCD\xA9\x9D\x94\x81\xA1\xAE\xA9\x44\xC6\xB2\x28\xAC\xA9\x86\x93\xAC\x03\xBB\xAA\x8C\x88\x00\x8D\xB6\x81\x42\x6F\x35\x2E\x34\x31\x32\x39\x3C\x56\xE6\xA5\x89\xBE\xA3\xB4\x85\xB7\x7F\x83\xB1\xB3\xB5\xBF\xB9\xBC\x81\x58\x83\x9A\xAF\xAC\xB6\xB6\xC0\xB9\x74\xF6\xB8\xA5\xB8\xC7\xB2\xC4\xBE\x5B\x8E\xCD\xD0\xB0\xCD\xC3\xC9\x91\x96\x8D\x98\xCC\xC8\x82\x8D\xD3\x81\x4E\x75\x2D\x22\x35\x32\x3B\xC3\x82\x0C\x18\xB1\xCF\x8F\x36\x34\x3B\x32\x78\x74\x2A\xB8\x80\x06\xAF\xCB\x9C\x2E\xF2\x32\x21\x38\xBF\x7E\xE3\xE3\xFF\x3E\xC2\x81\xAC\x21\x37\xDB\xE1\x6C\x48\xC8\xE4\x08\x8C\xEA\x80\x27\x6F\x64\x35\x92\xE6\xE6\xD0\x82\xD3\xA9\xAB\xED\xDC\xED\xE8\x8E\xD3\x27\x62\x6A\x25\x23\x34\x3C\xF3\x7F\x80\x0C\xF0\xC0\x08\xFA\xF4\xF6\x23\x34\x65\x6C\x08\xA4\xFE\xEB\x82\xD2\x8E\x1E\x60\x4E\x7A\x72\x00\x21\x65\x81\x70\xC3\x79\x16\x82\x49\xCE\x65\x1D\x1B\x1C\x03\x90\x50\x01\x73\xCF\x61\x1C\x1B\x82\x03\x76\x16\x85\x1D\xDB\x5C\x7D\x7E\x40\xE0\x6A\x6C\x6A\x1C\x04\x81\x53\x19\x6D\xB7\x76\x6E\x7B\x87\x19\x43\x44\x7F\x7A\x74\x2C\x86\x6A\x19\xF8\x7A\x70\x84\x79\xF2\x44\x42\x7F\x8B\xF6\x75\x84\x1A\x75\x08\x40\x9E\x1B\x4C\x65\x14\x60\x40\x46\x3B\xA9\x70\x8F\x7D\xF9\x64\x18\x86\x40\x1A\xAC\x1C\x87\x8A\xE6\x43\x40\x83\x47\x67\x25\x83\x43\x89\xB6\x65\x16\x6C\x6F\x0F\x18\x44\x08\x46\x61\xBC\x66\x9A\x52\xEE\x64\x77\x9B\x4D\x69\x9C\x7B\x98\x9A\x6D\x88\x7F\x9B\x55\x71\x88\x79\x00\x46\x77\x82\x44\x16\x14\x55\x05\x16\x15\x10\x4C\x3D\x90\x90\x41\x40\x9D\x4C\x84\x6F\x02\x18\x4A\x02\xA2\x03\x46\x10\xA3\x14\x7E\x80\xAD\x9F\x93\x00\x26\x16\x87\x1C\x45\x98\x43\x00\x9E\x9C\x97\x75\x14\x13\x4C\x3F\x91\xA1\x11\x83\x83\x42\x91\x1D\x6C\x2C\x19\xA0\x43\xA5\x8B\x72\x87\x13\x42\x0A\x1F\x10\x14\x45\x0E\x1B\xA8\x42\xB7\x9C\x1B\x1F\xA6\xC0\x5B\x61\x62\x40\xB0\x8A\x13\x10\x13\x4F\x10\xA7\xAC\x41\xB9\xBD\x1D\xA9\x8B\x51\x4D\xB0\x01\x10\x52\x12\x13\xAD\xAD\xC7\x83\x49\xAF\x16\x06\x84\x80\x60\x41\x80\x50\xB2\x17\xB0\xC5\x85\x15\xB6\x40\xB9\x9D\x1C\x8B\xB6\xBF\x4C\x59\x5B\x13\x4D\x0D\x11\x12\x91\x3D\x6C\x04\x82\x7B\x94\x83\x1F\x10\xB1\x4E\x30\xB3\x42\x0E\xE8\x88\x6C\x7D\x95\x9E\x8D\x12\x11\x11\x52\x1F\x08\x46\xC1\x02\x5B\x1C\x15\x0B\x5D\x3F\x0C\x14\x19\x2B\x28\x0E\x0B\xC3\x2B\x29\x0F\x0C\x0A\x5B\x25\x15\x11\x17\x5B\x2B\x0B\xC1\xC3\x14\xD6\xC9\x9C\x42\x23\xDF\x70\xC0\x00\x53\x3B\x99\x12\x13\x47\x1B\x08\x46\xCB\x02\x62\x08\xC6\x17\x5C\x1C\x12\x09\x17\x7C\x35\xCB\x16\x17\x75\x38\xC5\xCD\x1D\x0F\xFB\x14\x0D\x1F\x29\x2A\x02\x0B\xA2\x0C\x48\xD8\x42\x91\x94\x93\x10\x15\x10\x43\x05\x1C\xAC\x42\x53\xDC\x13\x1F\x0A\x39\x89\x44\x7B\x98\x16\x67\xCA\x11\x10\xC2\x44\x70\x04\x46\x63\xC2\x4F\xD5\xD8\x79\x2E\x02\x17\x1B\x6F\x34\x1C\x46\x5D\x74\x19\xD2\x42\x7C\x40\x20\x04\x08\x0F\x67\xC9\x8E\x0E\x8C\x03\x79\xD4\x73\x6C\x08\x40\xEE\xDD\xDA\x6F\xF2\x14\x1E\xD2\x04\x4A\xD5\xDC\xDE\x60\xFA\xDC\xDE\xD9\x8D\xC4\x7D\xBC\x00\x80\x43\xEE\x09\x0C\x45\x18\x49\xE6\x40\x8C\xE8\xDE\x0E\x0E\x20\x22\x0B\x16\x08\x75\xDB\x10\x0A\x12\x56\x1B\x85\x18\x08\xA0\xCD\x8F\x80\x08\x7B\x21\xEC\x0A\x08\xA7\xE9\xE2\x97\xEA\xAD\xF7\x6F\xE9\x1F\x20\x1D\x11\xE9\x17\xB4\xE1\x13\x1C\x08\x91\xF9\x1F\xE0\x00\x83\xD3\xE5\xE5\xF1\x2E\x33\x0B\xE4\x42\xCF\xDD\xEA\xDC\xE8\xA2\xF4\xE6\xE8\xEA\xAA\xEC\xE0\x0A\xEB\xC3\xF1\xE2\x0B\xEC\xB5\xD9\xF9\xEE\x83\xC3\xFC\xEE\xEF\xCD\xC1\xC3\xF5\xF0\x10\xCA\xFD\xD4\x85\x6B\x16\x88\xE3\x42\xD2\x4A\x2F\xF0\x77\xE5\xFA\x18\x49\xFC\xE7\xF5\xCD\x80\x77\xE7\x20\x0E\x09\x15\x02\x64\x60\xED\x5C\x49\x45\x74\x00\x06\xF0\x01\x82\x45\xD6\x00\x0D\x01\x0A\x18\x6E\xFD\x16\x40\x80\x11\x16\x54\x0D\x98\x49\x7C\x08\x13\x8C\x0D\xBA\x77\x0E\x39\x68\x10\x74\x08\x51\x4C\x42\x10\x3D\x01\x74\x46\x17\x51\x19\x34\x7D\x0E\x08\x92\x86\x7F\x14\x94\x7A\xA1\x2B\x8A\x81\xE1\x5C\x86\x83\x20\x82\x84\x09\xAB\x77\x84\x11\x14\x0A\x0E\x1C\x4C\x86\x0B\xFD\x75\x42",
"\x36\x15\x86\x0D\xA8\x4C\x0E\x06\xB7\x80\x05\x0F\xB4\x09\x84\xB1\x7B\x86\x09\xA1\x79\x35\x54\x42\x89\x82\x44\x90\x7E\x11\xA0\x79\x64\x29\x2B\x67\x08\x06\x88\x46\x97\x09\x8B\x81\x2B\x60\x20\x08\x5A\x46\x6C\x8F\x74\x05\x65\x81\x23\x62\x56\x4A\x4C\x3F\xE5\x49\x08\x22\x3A\xBC\x7B\x8D\x15\x9B\x0C\xE9\x20\x07\x7A\x26\x7A\x3A\x7B\x34\x4D\x49\xF7\x32\x74\x76\x25\x3E\x8C\x0C\x80\x9E\x45\xF9\x3D\x71\x75\x3E\x1A\x83\x8D\xC7\x63\x72\x03\x18\x23\x92\xC8\x68\x6A\x6D\x6C\x74\x0D\x11\x74\x22\x6F\x23\x42\x27\x6E\x83\x7E\x04\x08\x40\x01\x92\xDB\x5C\x45\x7D\x66\x66\x95\x19\x17\x7D\x06\x8C\x2D\x94\x7F\xAA\x80\x81\x08\x03\x7F\x80\x2C\xB1\x90\x74\xB3\x8B\x8D\x2D\xF8\x67\x96\x10\x33\x97\x86\x94\x4A\x0B\xDA\x6D\x69\x8C\xE4\x43\x9C\x0E\x97\x65\x04\x46\x4A\x9C\x7F\x63\xB2\x90\x8E\xF5\x34\x0F\x2E\xC2\x99\x93\x67\xAB\x78\x95\xC8\x7C\x81\xD9\x08\x2B\x9B\x2C\xB7\x7F\x98\x9B\x84\x0D\x03\x18\x23\x9D\x4F\xAF\x85\x88\xA2\x88\x8E\x84\x50\x90\x47\x36\x82\x27\x8D\x6B\x8E\x06\x0C\x76\x88\x20\x7A\xB8\x68\x8F\xD4\x7A\x8C\x1F\xA7\x77\x91\x44\x82\x92\x84\xDF\x65\x91\x3F\xA0\x71\x90\x1B\x60\x06\x7C\x8D\x8F\x91\x1C\xD2\x91\x93\x43\x98\x9E\x90\x3E\x57\x72\x0E\x18\x23\xA2\xFE\x47\x90\x80\x5D\x9F\x8A\xF6\x43\x44\x27\xBA\x62\x02\x07\x85\x8A\x96\xF6\x52\x8B\x81\x35\x87\x91\x92\xC5\x6F\xA0\xF3\x32\x0C\x10\x8C\x2D\xA4\x7F\xC5\x75\x83\xE8\x7B\x98\x7B\xDB\x5A\x7C\x7B\x75\x7E\x78\xF8\x35\xA5\x85\xF1\x7B\x74\x91\xE8\x75\x84\xF1\x68\x63\x89\x98\x94\x7B\xA6\xD7\x62\xA6\x4F\xC3\x70\x08\x9D\xA1\xA2\x7C\xDB\x7A\x77\x22\xE7\x70\x78\xA1\x85\x7D\xA1\x3E\x4F\xA3\x21\xCD\x75\xA2\x84\x1D\xA8\x6F\x17\xBC\x8A\xCA\x2C\x6B\xA2\x22\x61\x70\xA4\xE1\x76\xA4\xE8\x24\xA3\x78\x93\xBE\x44\x94\x5E\x6A\x95\x25\x88\x23\xAE\x9E\xAB\x90\x9C\x9C\x88\x4B\x40\x20\x91\x97\x51\x81\x9F\x98\xE5\x88\x21\x60\xD4\x9D\x6C\x4C\xAD\x69\x9C\xF2\x62\x22\xD2\x20\x9E\x99\x51\x85\x9C\x9D\xEC\x25\x4C\x42\x12\xB0\xB2\x64\xB8\xAC\x0C\x80\x64\x20\xE0\x20\x98\x8F\x51\x98\xAD\x49\x5A\xB1\xA2\x0C\x5D\xA4\x21\xAF\x90\xA5\x49\x18\xA3\xAC\x18\xA0\x7C\xA3\xD5\x5F\xA3\x8F\x76\xA3\xA5\xF6\x25\xAB\xA1\x93\x9E\x69\xA5\x9A\x28\x78\xF3\x34\x0F\x78\x82\x11\x79\x94\x47\xB6\x79\x5A\xBD\xA1\xAA\xF2\x40\xA3\x76\x75\x71\xB7\x52\x87\xA0\xA9\xAA\x8B\x87\xAA\x5E\x67\x93\x5C\x84\x25\xAF\xAD\x97\xB5\x93\xF2\x20\x97\x45\x8E\xBB\x9D\x35\xAE\x98\x00\xF0\x8B\xA2\x0B\x35\x04\x12\x8C\x25\xBF\x8E\x0B\xB9\x8E\x70\xA7\xBF\x8E\x82\x8A\x93\x94\x4E\xBC\x9E\x8F\x7E\x96\xA0\x84\xA2\x06\x91\x42\xAB\x8F\x10\xF8\x91\x74\x7D\xBD\x8B\xBE\xEE\xA2\x91\x4E\x84\x92\xBF\x26\x74\xBC\x0C\x53\xA9\xA1\x7E\x8B\xAF\xB0\xEF\x9D\x50\x79\xF1\x93\x04\x3D\x84\x26\x9F\xCA\xAA\xBC\xA6\x03\xA0\x05\x41\x88\xC7\xB8\xD8\x99\xC3\xC3\x09\xD7\xBE\x42\xD1\x9F\xB2\xFD\x1B\x9C\x20\xDD\x96\xB9\x26\x85\x71\x6E\xBD\x82\x25\x6E\xDA\xBE\x47\xDE\x51\xBE\x47\xCC\x83\x22\x70\x5B\xAC\xC5\x62\x80\x0A\x70\x10\x20\xAA\xC6\xA5\x8A\x77\x89\x83\x2D\x9A\x55\x86\xB6\x6D\x74\x10\x6C\x76\x83\x20\xC6\x5E\xAA\x73\xC6\x5D\x69\x96\xEA\x36\xC2\x20\xC1\x46\xCA\xC7\x8C\x4F\xC6\x8F\xF6\xAE\x07\x87\x9C\x82\x02\x18\x20\xCE\xD9\x1C\x87\xC8\x16\xC1\xB4\x20\x81\xAD\xCA\x37\x94\x8E\xCA\x18\xAC\x0B\xBA\x03\x35\xAC\x99\xAC\xC4\xCA\x00\x00\x73\x71\x6B\xC6\x89\x83\x8B\xA1\x02\x8C\x3D\xCA\x8D\xE2\xA7\x98\x9D\xB2\x3C\xC8\xBB\x77\x99\xBD\x7B\xD1\x9B\x99\x83\x23\xB1\x78\xAC\xC3\xC9\x5A\xC7\xD1\x34\xBE\x0F\xAF\x4C\x92\xB4\x20\x94\xA7\x99\x99\xC9\xC6\x71\x1D\xFD\xC4\xB1\xD5\x95\xD1\xDB\x10\xD6\x99\x4C\xAE\x04\xC5\xDF\xA3\x64\x9E\xCE\x98\xA4\xB4\x6A\xA7\x92\x35\x1D\xB7\x40\x3F\xB6\xA9\xD0\x48\xAB\xB8\xB8\x65\xBB\xEB\x71\xBA\xB8\x5D\xE1\xC6\xB9\xEA\x68\x6C\x5C\xD1\xC8\x78\x87\xB9\xB4\xBD\x64\x0E\x04\x0D\x24\xBB\x5F\x81\x3F\xC0\xB5\x62\xBE\x88\x59\xAC\xB6\xAD\xD7\xB8\xD2\xB6\x36\xB4\xB5\x34\x87\x9C\x7D\x63\xDC\x86\xD3\xEE\x6E\xCE\x3C\xFB\x78\x20\x72\xE7\x9A\x8B\x15\x97\x81\x06\xC2\xAC\x83\x26\xB9\x81\x8A\xD9\x7D\x85\x0A\x98\x84\x87\x3E\x13\x9C\x83\x47\x89\x8B\x12\xEE\xCE\xDD\x27\xBA\x81\xDE\x54\x9A\xDF\x41\xF7\xDE\xCC\x00\x82\x84\x80\x52\x01\x8D\x97\x36\x32\xA9\xF0\x23\x44\xE0\xE8\x92\x84\x10\xB4\x8B\x81\x76\xCE\x88\x8A\x23\x80\xE2\x0F\x93\xEC\x84\x88\xE8\xD9\xDA\x1A\xA0\x77\x01\xE3\x82\xA8\x33\xA7\x0A\x9D\xCE\x55\xB1\xAA\xFD\x61\x9E\x1A",
"\x13\xC3\x20\x15\xDC\xBE\x08\x7E\xB5\xC1\xF6\x9A\xC7\xBD\xBC\xDF\xC3\x7B\xF6\xB8\xBE\x6D\xF0\x43\xD8\xA7\x24\xDB\xE0\x14\x55\x79\x39\x5A\x6E\x43\x34\xCD\x48\xA9\xEE\xAD\x48\xDE\x16\x03\x24\xFF\x42\xEA\x2A\xCB\x50\x48\xEC\x1A\x3C\x37\x18\x10\xE8\x77\x6D\xC5\x88\xAA\xE8\x31\x3B\x65\x1C\x36\x06\x5A\xE2\x3B\x44\xF0\x47\x78\x6B\x9C\x34\x07\x64\xE8\x38\x51\xF4\x0E\xEB\xD7\x20\xEC\x6F\x1E\x0C\xED\xE3\x1C\x03\x5C\xAF\x3F\x1C\x6F\x46\x46\xE9\xBE\xFE\xE8\x31\x46\x5F\x1F\x77\xE3\x5F\xEF\xBF\xF9\xE8\xEE\x85\xE6\x57\x5E\x0C\x24\xF0\xBF\xED\xD1\x41\x06\x59\x01\xE2\xA6\x62\xEA\xD5\x4B\x5C\x37\x94\x5B\x84\xE2\xBF\x87\x94\x6F\xEE\xCE\xEF\xC5\x9C\x80\x6F\x5C\xEA\x8B\xBC\xC6\x47\xF2\x7D\xEB\x5A\x81\x0D\xFD\xEF\xC7\xC4\x39\xF2\x93\xFE\x3D\x5C\x96\xFD\xEF\xCC\xEA\x74\x52\xF3\xD8\x50\xE9\xD0\x30\xF4\x09\x62\xF1\xB7\xDC\x41\xDD\x11\xF9\xEC\x44\xD4\xC6\xEA\xF5\x18\x2C\xF6\xD1\xAE\xFA\x40\x8C\x12\xF1\xF6\xCC\x41\xE8\xF2\x53\xE5\xF7\xC5\xC0\x02\xF3\xD5\x28\x35\x12\xBB\xF6\x43\xDE\xCE\x5F\xF7\xBE\x41\xFB\x98\xEE\xC9\xEE\x02\x46\x46\xEF\x84\xEB\xF4\xF4\xD1\xF4\xF2\xDD\xA8\x68\xF6\xD0\xE1\xCB\xED\x05\x21\xF1\xC1\xEB\xF9\xFD\xC9\xEB\xFC\xF3\xF0\xF1\xF6\xF9\xD3\x49\xF0\x3B\x63\x35\xEB\x73\x12\x81\x7B\x68\x02\x16\x7C\x73\x28\x7C\x8C\x7A\x7F\xB7\x5F\x7E\xCE\x7C\x80\x95\x77\x3B\x7C\x72\x21\x5F\x12\x10\x23\x7F\x25\xC0\x73\x10\x95\x30\x7E\x73\x27\x3C\x0E\x7D\x1A\xA3\x7E\x79\xC3\x71\x78\x70\x67\x80\xEB\x7A\x80\xB8\x20\x81\xD2\x73\x74\x0F\x81\x7F\xB3\x72\x81\x7D\x75\x4C\x17\x84\x07\x21\x8E\x2B\x79\x6E\x78\x27\x36\x72\x35\x8F\x2B\xD9\x4F\x79\x79\x76\x24\x2C\x2E\x77\x13\x86\x74\x44\x78\x36\xBC\x1C\x7C\xFF\x04\x78\x49\x89\x81\x67\x26\x24\x08\x34\x35\xEB\x75\x84\x09\x27\x84\x0D\x89\x20\x2C\x2F\x84\x93\x7C\x7C\x02\x83\x80\xE9\x28\x16\x66\x37\x4C\x4B\x8E\x2C\x6F\x26\x24\xCF\x70\x85\xD0\x72\x85\xC4\x14\x85\x42\x70\x5D\x0C\x15\x86\x59\x85\x85\xC4\x1B\x85\x5C\x8C\x7E\xB2\x72\x65\xF3\x7F\x26\x3F\x8F\x60\x73\x80\x78\x23\x14\x78\x04\x2B\x77\x2D\x89\x82\xC4\x64\x10\x6E\x89\x78\xDC\x7C\x06\x72\x8C\x85\xFE\x71\x76\x89\x79\x77\x93\x3B\x63\x7B\x8C\x87\x37\x15\x82\x9E\x41\x7B\xF8\x7D\x2B\xB1\x76\x76\xEC\x13\x84\x41\x29\x7D\x02\x1D\x5A\x6A\x8B\x82\x87\x4E\x77\x79\x8C\x10\x94\x83\x80\xFF\x09\x88\x61\x81\x38\x7D\x76\x24\x62\x62\x88\xD2\x74\x10\xAF\x8F\x86\x11\x8C\x21\xCA\x7A\x2E\x98\x8C\x3D\xA1\x8D\x7E\x83\x3B\x8A\x68\x6D\x8A\x7E\x69\x7F\x83\x83\x10\x7F\x6D\x7F\x2F\x8C\x21\x9C\x8E\x85\xB8\x87\x7D\xAA\x3B\x8B\x75\x85\x6C\x3E\x2E\x8B\x37\x60\x8C\x0B\x85\x8D\xB1\x86\x2D\x2A\x8C\x8B\xAA\x47\x8B\xCA\x8A\x8C\xBA\x87\x32\xBC\x85\x74\x78\x81\x78\x46\x27\x69\x91\x81\x89\xA5\x8C\x4D\xEB\x79\x8C\x6B\x28\x76\x0B\x5C\x1B\x9A\x8D\x1E\x4A\x84\x78\x93\x30\x88\x0C\x18\x85\x03\x19\x88\x38\x84\x6C\x69\x74\x81\x03\x11\x14\x95\x57\x85\xEB\x71\x8F\xFA\x81\x85\xD6\x74\x58\xF2\x8E\x8F\x4D\x81\x88\x04\x15\x90\xCB\x77\x32\xFD\x82\x86\xFF\x8C\x72\x0B\x5C\x22\x85\x85\x78\x04\x97\x8E\x20\x27\x8C\x8C\x80\x7D\x79\x75\x67\xC5\x8A\x91\x67\x29\x77\x01\x82\x92\x79\x7D\x49\xB3\x86\x92\xE4\x88\x11\x13\x0B\x8E\xEB\x7B\x74\xB5\x5E\x23\xCE\x8B\x91\x66\x37\x48\xD2\x88\x18\x84\x74\x01\xD4\x88\x10\x15\x0A\x29\x2F\x9E\x62\xF3\x11\x93\x4D\x70\x8E\xCF\x88\x6C\x2C\x2D\x93\x2E\x82\x74\x87\x4C\x8D\xCF\x8D\x7E\x20\x60\x8F\xDD\x5B\x50\x37\x90\x00\x3A\x96\x74\x4C\x3E\x93\xD0\x70\x93\xDB\x62\x93\x44\x94\x93\xD0\x8D\x24\x2C\x27\x7E\xAD\x79\x74\xFA\x1C\x94\x5E\x9E\x94\x8A\x40\x95\x29\x71\x91\x22\x9B\x87\x87\x7E\x89\xB1\x78\x82\x04\x11\x92\x89\x75\x62\x4E\x2C\x90\x75\x9C\x91\x08\x8D\x8D\xE9\x28\x7D\xAC\x23\x10\x9C\x75\x06\x87\x8E\x7D\x3E\x13\x10\x1C\x82\x7E\x3C\x89\x67\xA6\x70\x97\x93\x72\x97\xC4\x89\x8D\x45\x97\x48\xFC\x74\x8B\x2B\x84\x7D\x44\x86\x7D\x3B\x48\x7B\x2A\x43\x98\x31\x8E\x7B\x9F\x7C\x84\x94\x32\x7C\xA5\x71\x78\xC5\x77\x82\xD6\x73\x97\x90\x9E\x95\xC8\x63\x99\x79\x95\x8B\x65\x0B\x97\x5D\x8D\x97\xB4\x7F\x97\xD7\x1B\x7D\x22\x8A\x45\x84\x95\x81\x13\x2F\x99\xE1\x7A\x81\xA2\x90\x1D\xE5\x77\x9A\x89\x77\x89\x08\x14\x97\x85\x76\x97\xAC\x97\x9C\x1C\x94\x7F\x23\x16\x7F\xD0\x74\x9C\xA8\x99\x94\xA2\x8E\x23\xC9\x9F\x77\x8B\x89\x10\x05\x8C\x98\x89\x7E\x98\x02\x16\x9C\xD6\x94\x96\x77\x9D\x86\xA9\x91\x7D\x76\x5C\x8E\xAE\x2E\x2C\x33\x8B\x83",
"\x88\x97\x83\x63\x94\x6C\x1F\x82\x07\xEA\x9E\x9B\xE3\x73\x82\x23\x14\x89\xB0\x97\x26\xDC\x90\x00\xDE\x9B\x8F\xD3\x9D\x24\xD5\x9C\x9F\xDA\x8A\x3A\xE6\x9D\x1B\x12\x29\x9E\xA0\x9B\x81\xBC\x9D\x81\x39\x8D\x11\x58\x21\x9F\x02\x18\xA0\x45\x47\x15\x81\x78\x78\x8D\x92\x9C\x02\x19\x92\xCA\x9B\x86\x0E\x82\x9E\xD2\x91\xA0\xB7\x37\x9F\x07\x28\x89\x7E\x9D\x89\x7A\x23\x71\x9C\x96\x74\xA1\x79\xA0\x88\x9B\x9E\x1C\x4B\x98\xB4\x91\x97\x16\xA0\x00\x18\xAF\x9D\x1A\xA0\x79\x78\x99\xA1\x95\x93\x9B\x73\x26\x7B\xB7\x3A\x99\xF4\x67\xA2\x73\x29\xA2\x11\xA7\xA0\xBF\x96\x21\xC4\x7A\x9D\x85\x79\x9F\x33\xA0\xA0\x45\x95\x3C\xFF\x9D\x9E\x39\xAF\xA1\xD5\x72\xA2\x3A\xA4\x28\xDA\x79\x2A\x40\xAF\x26\x42\xA8\x9B\x44\xA3\x9F\xA3\x93\x12\xE6\x77\x7F\x31\xAB\xA4\x50\xA1\x8E\x1B\xA8\x10\x17\x94\xA3\x51\xA7\x28\x79\x7E\x9C\x96\x83\xA6\xE3\x96\x1A\x2C\x8C\xA1\xC6\x8E\x9A\xD8\x93\x12\x06\x80\x00\x20\xAC\x1B\x4A\xA1\xA7\x7D\x3E\xA4\x37\xAA\xA6\x1E\xA8\x8C\x9D\x98\x9E\x62\x48\x81\xBD\x9F\xA0\x45\xAC\x06\x4C\xAE\x95\xEF\x9E\xA0\xA1\x9E\xA5\xC0\x94\x82\x48\xAF\x77\x7D\xAD\xA1\x4D\xA7\xA6\x84\x8E\xA7\x76\x84\xA8\x28\xA5\xA0\x87\xA4\x83\x5D\xAD\x83\x43\xAF\x90\xC4\x6A\x83\xA3\xAC\x9E\xB1\x7E\x88\x59\x6A\x92\x23\x1D\x49\x48\x9D\x96\x46\x79\x77\x94\x8D\x49\xE8\x71\xA3\xB1\xA3\x79\xF1\x83\xA0\x88\x70\x8A\x5D\x94\x9E\x36\x91\x78\xBC\x17\x01\xB2\xA3\x87\xB4\xA0\x94\x93\x7A\x2F\xC7\x70\x97\xBE\xA3\x8C\xAA\x91\xAC\x23\x1C\x1B\x69\xA5\xAC\xBC\x1F\x96\x2F\xA3\x79\x89\x8F\xA4\xA6\xAB\xA6\xAF\x93\xA5\xCB\x83\xA2\x56\xA5\xA2\x9D\x76\x83\x87\x9B\x26\x5B\xAC\x7B\xA9\xAD\xA2\x81\x77\x7A\xEB\x79\xAD\x81\xAD\xA8\xE4\x96\x99\x3B\xA8\x99\xB7\x76\x7D\xB9\x72\x98\xB7\x98\xAE\x9F\xAF\x7D\x2A\xA2\x9F\x89\x9A\xAE\x23\x15\x9A\xD0\x7E\xAE\x74\xA4\x99\x83\xAD\xAD\x97\x94\xA5\x52\xAF\xA2\x55\x4C\x06\x59\xA6\xAE\x9E\x95\xAA\x3C\x8C\xA2\xE4\x71\x78\x61\xA0\x7D\x57\x95\xB0\xAD\x9C\xAD\xCC\x97\x13\x6E\xA9\xAC\x31\xA3\xAD\x65\xA5\x94\xAA\x47\xA7\x37\x19\xA7\x7B\xA8\x95\xCB\x8B\xA9\x98\xAA\x9A\xAA\x43\xA0\x32\x81\xAA\x90\xA0\xA1\x5C\xAB\xAD\xED\x7F\xA8\xE9\xA5\xB1\xF5\x95\xA9\x7E\x74\xB0\x68\xAC\xA9\xD3\x72\xA0\x85\xA5\x98\x16\x82\xB3\x39\xB2\xB1\x6F\x27\x3C\xA8\xA9\xA8\x91\xA4\xAA\x5F\xA7\x13\xBC\x10\x33\xD4\xA3\x8E\x23\x14\xA1\xC3\x9C\xB3\x31\xA6\x12\xE0\xAA\x78\xE2\xA8\xAF\xE4\xAD\xAF\x67\x27\xAE\xDD\x77\xB4\x4F\xBA\x14\xEC\xAF\x9C\x58\xB8\x89\xCA\x89\x99\xF6\xAB\x99\xF9\xA3\xB6\xFB\xA4\xB4\xBB\x98\xB4\xFE\xA4\xB1\xF4\x97\x13\x02\xBF\xA6\xD7\xAB\x26\x3C\xAC\x21\x88\x7D\xB0\x0F\xB1\xB6\x11\xB5\xB3\x13\xBE\xAF\xAA\xA6\xB2\x4A\x18\xB2\x62\xAC\x10\x30\xB0\xAA\x0B\x72\xAA\x4C\xB4\xB3\xFA\xAA\xA0\xEE\x9D\x40\xF0\x94\xB6\x93\xAB\xB3\x7B\xB5\x78\x84\x7D\xB8\x86\xAF\xB8\x33\xBB\xA8\xF0\xAF\x1F\x0C\xA0\x12\xA1\xB2\xA9\x46\xA2\xAC\x18\x1D\x01\x53\xB4\x8A\x16\xB1\xA3\xAE\xA0\xB5\x07\x3D\xBA\x7D\x71\x9C\x6A\xB9\x78\x19\xB8\x10\xF8\x85\x78\x6E\x7D\xB1\x4A\x1F\xB1\xB8\xB1\xA3\xBB\xBF\x77\xBD\xB4\xBB\x73\x80",
};

			void JsonGetParserBuffer(vl::stream::MemoryStream& stream)
			{
				vl::stream::MemoryStream compressedStream;
				for (vint i = 0; i < parserBufferRows; i++)
				{
					vint size = i == parserBufferRows - 1 ? parserBufferRemain : parserBufferBlock;
					compressedStream.Write((void*)parserBuffer[i], size);
				}
				compressedStream.SeekFromBegin(0);
				vl::stream::LzwDecoder decoder;
				vl::stream::DecoderStream decoderStream(compressedStream, decoder);
				vl::collections::Array<vl::vuint8_t> buffer(65536);
				while (true)
				{
					vl::vint size = decoderStream.Read(&buffer[0], 65536);
					if (size == 0) break;
					stream.Write(&buffer[0], size);
				}
				stream.SeekFromBegin(0);
			}
/***********************************************************************
Unescaping Function Foward Declarations
***********************************************************************/

			extern void JsonUnescapingString(vl::parsing::ParsingToken& value, const vl::collections::List<vl::regex::RegexToken>& tokens);

/***********************************************************************
Parsing Tree Conversion Driver Implementation
***********************************************************************/

			class JsonTreeConverter : public vl::parsing::ParsingTreeConverter
			{
			public:
				using vl::parsing::ParsingTreeConverter::SetMember;

				bool SetMember(JsonLiteral::JsonValue& member, vl::Ptr<vl::parsing::ParsingTreeNode> node, const TokenList& tokens)
				{
					vl::Ptr<vl::parsing::ParsingTreeToken> token=node.Cast<vl::parsing::ParsingTreeToken>();
					if(token)
					{
						if(token->GetValue()==L"True") { member=JsonLiteral::JsonValue::True; return true; }
						else if(token->GetValue()==L"False") { member=JsonLiteral::JsonValue::False; return true; }
						else if(token->GetValue()==L"Null") { member=JsonLiteral::JsonValue::Null; return true; }
						else { member=JsonLiteral::JsonValue::True; return false; }
					}
					member=JsonLiteral::JsonValue::True;
					return false;
				}

				void Fill(vl::Ptr<JsonNode> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
				}

				void Fill(vl::Ptr<JsonLiteral> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->value, obj->GetMember(L"value"), tokens);
				}

				void Fill(vl::Ptr<JsonString> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->content, obj->GetMember(L"content"), tokens))
					{
						JsonUnescapingString(tree->content, tokens);
					}
				}

				void Fill(vl::Ptr<JsonNumber> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->content, obj->GetMember(L"content"), tokens);
				}

				void Fill(vl::Ptr<JsonArray> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->items, obj->GetMember(L"items"), tokens);
				}

				void Fill(vl::Ptr<JsonObjectField> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->name, obj->GetMember(L"name"), tokens))
					{
						JsonUnescapingString(tree->name, tokens);
					}
					SetMember(tree->value, obj->GetMember(L"value"), tokens);
				}

				void Fill(vl::Ptr<JsonObject> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->fields, obj->GetMember(L"fields"), tokens);
				}

				vl::Ptr<vl::parsing::ParsingTreeCustomBase> ConvertClass(vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)override
				{
					if(obj->GetType()==L"Literal")
					{
						vl::Ptr<JsonLiteral> tree = new JsonLiteral;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"String")
					{
						vl::Ptr<JsonString> tree = new JsonString;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Number")
					{
						vl::Ptr<JsonNumber> tree = new JsonNumber;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Array")
					{
						vl::Ptr<JsonArray> tree = new JsonArray;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"ObjectField")
					{
						vl::Ptr<JsonObjectField> tree = new JsonObjectField;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Object")
					{
						vl::Ptr<JsonObject> tree = new JsonObject;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else 
						return 0;
				}
			};

			vl::Ptr<vl::parsing::ParsingTreeCustomBase> JsonConvertParsingTreeNode(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				JsonTreeConverter converter;
				vl::Ptr<vl::parsing::ParsingTreeCustomBase> tree;
				converter.SetMember(tree, node, tokens);
				return tree;
			}

/***********************************************************************
Parsing Tree Conversion Implementation
***********************************************************************/

			vl::Ptr<JsonLiteral> JsonLiteral::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonLiteral>();
			}

			vl::Ptr<JsonString> JsonString::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonString>();
			}

			vl::Ptr<JsonNumber> JsonNumber::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonNumber>();
			}

			vl::Ptr<JsonArray> JsonArray::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonArray>();
			}

			vl::Ptr<JsonObjectField> JsonObjectField::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonObjectField>();
			}

			vl::Ptr<JsonObject> JsonObject::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonObject>();
			}

/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

			void JsonLiteral::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

			void JsonString::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

			void JsonNumber::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

			void JsonArray::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

			void JsonObjectField::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

			void JsonObject::Accept(JsonNode::IVisitor* visitor)
			{
				visitor->Visit(this);
			}

/***********************************************************************
Parser Function
***********************************************************************/

			vl::Ptr<vl::parsing::ParsingTreeNode> JsonParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"JRoot");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				return node;
			}

			vl::Ptr<vl::parsing::ParsingTreeNode> JsonParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return JsonParseAsParsingTreeNode(input, table, errors, codeIndex);
			}

			vl::Ptr<JsonNode> JsonParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"JRoot");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				if(node && errors.Count()==0)
				{
					return JsonConvertParsingTreeNode(node, state.GetTokens()).Cast<JsonNode>();
				}
				return 0;
			}

			vl::Ptr<JsonNode> JsonParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return JsonParse(input, table, errors, codeIndex);
			}

/***********************************************************************
Table Generation
***********************************************************************/

			vl::Ptr<vl::parsing::tabling::ParsingTable> JsonLoadTable()
			{
				vl::stream::MemoryStream stream;
				JsonGetParserBuffer(stream);
				vl::Ptr<vl::parsing::tabling::ParsingTable> table=new vl::parsing::tabling::ParsingTable(stream);
				table->Initialize();
				return table;
			}

		}
	}
}
namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			using namespace vl::parsing::json;

#define PARSING_TOKEN_FIELD(NAME)\
			CLASS_MEMBER_EXTERNALMETHOD_TEMPLATE(get_##NAME, NO_PARAMETER, vl::WString(ClassType::*)(), [](ClassType* node) { return node->NAME.value; }, L"*", L"*")\
			CLASS_MEMBER_EXTERNALMETHOD_TEMPLATE(set_##NAME, { L"value" }, void(ClassType::*)(const vl::WString&), [](ClassType* node, const vl::WString& value) { node->NAME.value = value; }, L"*", L"*")\
			CLASS_MEMBER_PROPERTY_REFERENCETEMPLATE(NAME, get_##NAME, set_##NAME, L"$This->$Name.value")\

			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonNode, system::JsonNode)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonLiteral, system::JsonLiteral)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonLiteral::JsonValue, system::JsonLiteral::JsonValue)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonString, system::JsonString)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonNumber, system::JsonNumber)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonArray, system::JsonArray)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonObjectField, system::JsonObjectField)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonObject, system::JsonObject)
			IMPL_TYPE_INFO_RENAME(vl::parsing::json::JsonNode::IVisitor, system::JsonNode::IVisitor)

			BEGIN_CLASS_MEMBER(JsonNode)
				CLASS_MEMBER_METHOD(Accept, {L"visitor"})
			END_CLASS_MEMBER(JsonNode)

			BEGIN_CLASS_MEMBER(JsonLiteral)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonLiteral>(), NO_PARAMETER)

				CLASS_MEMBER_FIELD(value)
			END_CLASS_MEMBER(JsonLiteral)

			BEGIN_ENUM_ITEM(JsonLiteral::JsonValue)
				ENUM_ITEM_NAMESPACE(JsonLiteral::JsonValue)
				ENUM_NAMESPACE_ITEM(True)
				ENUM_NAMESPACE_ITEM(False)
				ENUM_NAMESPACE_ITEM(Null)
			END_ENUM_ITEM(JsonLiteral::JsonValue)

			BEGIN_CLASS_MEMBER(JsonString)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonString>(), NO_PARAMETER)

				PARSING_TOKEN_FIELD(content)
			END_CLASS_MEMBER(JsonString)

			BEGIN_CLASS_MEMBER(JsonNumber)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonNumber>(), NO_PARAMETER)

				PARSING_TOKEN_FIELD(content)
			END_CLASS_MEMBER(JsonNumber)

			BEGIN_CLASS_MEMBER(JsonArray)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonArray>(), NO_PARAMETER)

				CLASS_MEMBER_FIELD(items)
			END_CLASS_MEMBER(JsonArray)

			BEGIN_CLASS_MEMBER(JsonObjectField)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonObjectField>(), NO_PARAMETER)

				PARSING_TOKEN_FIELD(name)
				CLASS_MEMBER_FIELD(value)
			END_CLASS_MEMBER(JsonObjectField)

			BEGIN_CLASS_MEMBER(JsonObject)
				CLASS_MEMBER_BASE(JsonNode)

				CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<JsonObject>(), NO_PARAMETER)

				CLASS_MEMBER_FIELD(fields)
			END_CLASS_MEMBER(JsonObject)

			BEGIN_INTERFACE_MEMBER(JsonNode::IVisitor)
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonLiteral* node))
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonString* node))
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonNumber* node))
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonArray* node))
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonObjectField* node))
				CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(JsonNode::IVisitor::*)(JsonObject* node))
			END_INTERFACE_MEMBER(JsonNode)

#undef PARSING_TOKEN_FIELD

			class JsonTypeLoader : public vl::Object, public ITypeLoader
			{
			public:
				void Load(ITypeManager* manager)
				{
					ADD_TYPE_INFO(vl::parsing::json::JsonNode)
					ADD_TYPE_INFO(vl::parsing::json::JsonLiteral)
					ADD_TYPE_INFO(vl::parsing::json::JsonLiteral::JsonValue)
					ADD_TYPE_INFO(vl::parsing::json::JsonString)
					ADD_TYPE_INFO(vl::parsing::json::JsonNumber)
					ADD_TYPE_INFO(vl::parsing::json::JsonArray)
					ADD_TYPE_INFO(vl::parsing::json::JsonObjectField)
					ADD_TYPE_INFO(vl::parsing::json::JsonObject)
					ADD_TYPE_INFO(vl::parsing::json::JsonNode::IVisitor)
				}

				void Unload(ITypeManager* manager)
				{
				}
			};
#endif

			bool JsonLoadTypes()
			{
#ifndef VCZH_DEBUG_NO_REFLECTION
				ITypeManager* manager=GetGlobalTypeManager();
				if(manager)
				{
					Ptr<ITypeLoader> loader=new JsonTypeLoader;
					return manager->AddTypeLoader(loader);
				}
#endif
				return false;
			}
		}
	}
}
