#pragma once

#include <ctime>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <string>


#ifndef FLY_BABE_TIMETOINT_H
#define FLY_BABE_TIMETOINT_H

#endif //FLY_BABE_TIMETOINT_H


std::string Format(std::string s) {
    std::string t;
    std::string p;
    for (auto c : s) {
        if (c == '/') {
            t += (p.size() > 1 ? "" : "0") + p + "/";
            p = "";
        } else {
            p += c;
        }
    }
    t += p;

    assert(t.size() == 10);
    assert(t[2] == '/' && t[5] == '/');

    return t;
}

long StrToInt(std::string s) {
    struct tm _tm;
    s = Format(s);

    assert(s[0] == '0' && isdigit(s[1]) || s[0] == '1' && s[1] <= '2');
    assert(s[3] <= '2' && isdigit(s[4]) || s[3] == '3' && s[4] <= '1');

    std::istringstream ss(s);
    ss >> std::get_time(&_tm, "%m/%d/%Y");
    _tm.tm_sec = 0;
    _tm.tm_min = 0;
    _tm.tm_hour = 0;
    _tm.tm_isdst = -1;
    time_t t = mktime(&_tm);

    assert(t > 0);

    return t;
}