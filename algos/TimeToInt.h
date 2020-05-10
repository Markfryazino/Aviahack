#pragma once

#include <ctime>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <string>



std::string Format(std::string s, char sep='.') {
    std::string t;
    std::string p;
    for (auto c : s) {
        if (c == sep) {
            t += (p.size() > 1 ? "" : "0") + p + ".";
            p = "";
        } else {
            p += c;
        }
    }
    t += p;

    assert(t.size() == 10);
    assert(t[2] == sep && t[5] == sep);

    return t;
}

long StrToInt(std::string s) {
    struct tm _tm;
    s = Format(s);

    assert(s[3] == '0' && isdigit(s[4]) || s[3] == '1' && s[4] <= '2');
    assert(s[0] <= '2' && isdigit(s[1]) || s[0] == '3' && s[1] <= '1');

    std::istringstream ss(s);
    ss >> std::get_time(&_tm, "%d.%m.%Y");
    _tm.tm_sec = 0;
    _tm.tm_min = 0;
    _tm.tm_hour = 0;
    _tm.tm_isdst = -1;
    time_t t = mktime(&_tm);

    assert(t > 0);

    return t / 86400 - 18261;
}