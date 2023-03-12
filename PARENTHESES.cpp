#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{

    stack<char> st;

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
            continue;
        }

        if (st.empty())
        {
            return false;
        }

        if (s[i] == '}')
        {
            char c = st.top();
            st.pop();
            if (c != '{')
                return false;
        }
        else if (s[i] == ')')
        {
            char c = st.top();
            st.pop();
            if (c != '(')
                return false;
        }
        else
        {
            char c = st.top();
            st.pop();
            if (c != '[')
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    if (isValid(s))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
