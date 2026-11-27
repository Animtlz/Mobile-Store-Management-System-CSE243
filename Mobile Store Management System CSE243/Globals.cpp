#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Globals
{
	public:
		inline static string latestUserID   = "C110";
        inline static string latestMobileID = "P110";
        inline static string latestOrderID  = "O110";

        // Split a saved line on tabs.
        static vector<string> split(const string &line)
        {
            vector<string> parts;
            string cur;
            for (char c : line)
            {
                if (c == '\t') { parts.push_back(cur); cur.clear(); }
                else cur += c;
            }
            parts.push_back(cur);
            return parts;
        }

};