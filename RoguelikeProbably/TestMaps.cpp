#pragma once
#include <string>
using namespace std;

class TestMaps
{
public:
	static string* testMap1()
	{
		string* map = new string[20] {
			"##############################",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"#                            #",
			"##############################"
		};
		return map;
	};
};