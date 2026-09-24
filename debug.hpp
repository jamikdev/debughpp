#pragma once

#include <bits/stdc++.h>
using namespace std;

namespace debug_impl {

    template <typename T>
    void print(const T& x);

    template <typename A, typename B>
    void print(const pair<A, B>& p) {
        cerr << "{";
        print(p.first);
        cerr << ", ";
        print(p.second);
        cerr << "}";
    }

    template <typename T>
    void print(const vector<T>& v) {
        cerr << "[";
        for (int i = 0; i < (int)v.size(); i++) {
            if (i) cerr << ", ";
            print(v[i]);
        }
        cerr << "]";
    }

    template <typename T>
    void print(const set<T>& s) {
        cerr << "{";
        bool first = true;
        for (const auto& x : s) {
            if (!first) cerr << ", ";
            first = false;
            print(x);
        }
        cerr << "}";
    }

    template <typename K, typename V>
    void print(const map<K, V>& m) {
        cerr << "{";
        bool first = true;
        for (const auto& [k, v] : m) {
            if (!first) cerr << ", ";
            first = false;
            print(k);
            cerr << ": ";
            print(v);
        }
        cerr << "}";
    }

    template <typename T>
    void print(const T& x) {
        cerr << x;
    }

    template <typename T>
    void debug_one(const char* name, const T& value) {
        while (*name == ' ') name++;
        cerr << name << " = ";
        print(value);
    }

    template <typename T, typename... Args>
    void debug_one(const char* names, const T& value, const Args&... args) {
        const char* comma = strchr(names, ',');

        if (comma) {
            string name(names, comma - names);

            while (!name.empty() && name.front() == ' ')
                name.erase(name.begin());

            while (!name.empty() && name.back() == ' ')
                name.pop_back();

            cerr << name << " = ";
            print(value);
            cerr << " | ";

            debug_one(comma + 1, args...);
        } else {
            debug_one(names, value);
        }
    }

    template <typename... Args>
    void debug(const char* names, const Args&... args) {
        cerr << "[DEBUG] ";
        debug_one(names, args...);
        cerr << '\n';
    }
}

#define debug(...) debug_impl::debug(#__VA_ARGS__, __VA_ARGS__)